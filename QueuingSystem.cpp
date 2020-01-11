//
// Created by Vladimir on 11.01.2020.
//
#define QUEUE_LIMIT 36
#define BUISY      1
#define IDLE       0
#define N_SERVERS  2

#include "QueuingSystem.h"
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

QueuingSystem::QueuingSystem(double mean_service, double mean_interarrival, int num_requests_required,
                               bool get_events_log, bool get_debug_log) {
    srand(time(NULL));

    this->num_events = N_SERVERS+1;
    this->mean_service = mean_service;
    this->mean_interarrival = mean_interarrival;
    this->num_requests_required = num_requests_required;
    this->get_events_log = get_events_log;
    this->get_debug_log = get_debug_log;
}

void QueuingSystem::run() {
    system_time = 0;
    report_string = "Система массового обслуживания\n\nСреднее время между поступлениями " +
                    to_string(mean_interarrival) + " мин\n\nСреднее время обслуживания " +
                    to_string(mean_service)+" мин\n\nЧисло требований " + to_string(num_requests_required);
    // all servers are free
    for (int &status : server_status) {
        status = IDLE;
    }
    total_waiting_in_queue = 0;
    total_being_in_system = 0;
    num_in_q = 0;
    time_last_event = 0;

    n_requests_served = 0;
    n_requests_arrived = 0;
    area_num_in_q = 0;

    time_next_event[1] = system_time + expon(mean_interarrival);
    for(int i = 2; i<N_SERVERS+2; i++){
        time_next_event[i] = 1.0e+30;
    }

    if(get_events_log) report_string+="----------------------------------\n\n";
    while (n_requests_served<num_requests_required){
        timing();
        update_time_avg_stats();
        if(next_event_type == 1){
            arrive();
        } else {
            depart(next_event_type - 2);
        }
    }
    if(get_events_log) report_string+="----------------------------------\n\n";
}

double QueuingSystem::expon(double mean) {
    return -mean * log((double) rand()/RAND_MAX);
}

void QueuingSystem::timing() {
    double min_time_next_event = 1.0e+29;

    next_event_type = 0;
    if(get_debug_log){
        report_string+="timing:\n";
    }
    for(int i = 1; i<=num_events; i++){
        if(get_debug_log) report_string+=" - event type "+to_string(i)+"; time: "+to_string(time_next_event[i])+"\n";
        if(time_next_event[i] < min_time_next_event){
            min_time_next_event = time_next_event[i];
            next_event_type = i;
        }
    }

    if(next_event_type == 0){
        report_string+="Список событий пуст в момент времени "+to_string(system_time)+"\n\n";
        exit(1);
    }

    system_time = min_time_next_event;
}

void QueuingSystem::arrive() {
    double delay;
    bool served = false;
    time_next_event[1] = system_time + expon(mean_interarrival);
    n_requests_arrived++;
    if(get_events_log) report_string+="Прибыл запрос в момент времени "+to_string(system_time)+"\n\n";
    for(int i = 0; i<N_SERVERS; i++){
        if(server_status[i] == IDLE){
            //delay = 0;
            n_requests_served++;
            server_status[i] = BUISY;
            time_next_event[i+2] = system_time+expon(mean_service);
            total_being_in_system += time_next_event[i+2]-system_time;
            served = true;
            if(get_events_log)  report_string+="Запрос обработан сервером "+to_string(i)+" в момент времени " +
                    to_string(system_time) + " с задержкой " + to_string(delay) + "\n\n";
            break;
        }
    }
    if(!served){
        num_in_q++;
        if(num_in_q > QUEUE_LIMIT){
            report_string+="Очередь переполнена в момент времени "+to_string(system_time)+"\n\n";
            exit(2);
        }
        time_arrival[num_in_q] = system_time;
    }
}

void QueuingSystem::depart(int server_index) {
    double delay;
    if(get_debug_log) report_string+="depart  server_index = "+to_string(server_index) +
            "  system time = " + to_string(system_time) + "\n\n";
    if(num_in_q == 0){
        server_status[server_index] = IDLE;
        time_next_event[server_index+2] = 1.0e+30;
    } else {
        num_in_q--;
        time_next_event[server_index+2] = system_time + expon(mean_service);
        delay = system_time - time_arrival[1];
        total_waiting_in_queue += delay;
        total_being_in_system += (delay + (time_next_event[server_index+2]-system_time));
        n_requests_served++;

        if(get_events_log){
            report_string+="Запрос обработан сервером " + to_string(server_index) +
                    " в момент времени " + to_string(system_time) + " с задержкой " + to_string(delay) + "\n\n";
        }
        for(int i = 1; i <= num_in_q; i++){
            time_arrival[i] = time_arrival[i+1];
        }
    }
}

void QueuingSystem::update_time_avg_stats() {
    double time_since_last_event = system_time - time_last_event;
    time_last_event = system_time;
    area_num_in_q += num_in_q*time_since_last_event;
}

string QueuingSystem::report() {
    string suffix = "";
    suffix+="\n\nКоэфициент использования "+to_string((total_being_in_system-total_waiting_in_queue)/(system_time*N_SERVERS));
    suffix+="\n\nСреднее время ожидания в очереди " + to_string(total_waiting_in_queue / n_requests_served) + " с";
    suffix+="\n\nСреднее время пребывания в системе " + to_string(total_being_in_system / n_requests_served) + " с";
    suffix+="\n\nСреднее число требований в очереди " + to_string(total_waiting_in_queue / system_time);
    suffix+="\n\nСреднее число требований в системе " + to_string(total_being_in_system / system_time);
    suffix+="\n\nАбсолютная пропускная способность " + to_string(n_requests_served/system_time); //среднее число заявок, которое может обслужить система за единицу времени.
    suffix+="\n\nОтносительная пропускная способность " + to_string(n_requests_served/n_requests_arrived); //отношение среднего числа заявок, обслуживаемых системой в единицу времени, к среднему числу поступающих за это время заявок

    suffix+="\n\nЧисло обслуженных требований " + to_string(n_requests_served);
    suffix+="\n\nВремя завершения моделирования "+ to_string(system_time) +" с";
    return report_string+suffix;
}

QueuingSystem::~QueuingSystem() {

}

