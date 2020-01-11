/*
 * абсолютная пропускная способность — среднее число заявок, которое может обслужить система за единицу времени.
 * относительная пропускная способность — средняя доля поступивших заявок, обслуживаемая системой (отношение среднего числа заявок,
   обслуживаемых системой в единицу времени, к среднему числу поступающих за это время заявок)
 * коэфициент использования = лямбда / мю,
   где лямбда - интенсивность входящего потока (среднее число требований в единичном интервале)
   мю - интенсивность потока обслуживания (среднее число требований, обрабатываемых каналом в единичном интервале)


 */

#define QUEUE_LIMIT 36
#define BUISY      1
#define IDLE       0
#define N_SERVERS  2

#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QueuingSystem.h"

using namespace std;

//int next_event_type, n_reqests_served, n_reqests_arrived, num_delays_required, num_events;
//int num_in_q, server_status[N_SERVERS];
//
//double area_num_in_q, area_server_status, mean_interarrival, mean_service;
//double system_time, time_arrival[QUEUE_LIMIT+1], time_last_event, time_next_event[N_SERVERS+2];
//double total_waiting_in_queue, total_being_in_system;
//
//bool get_events_log, debug_log;
//
//void initialize();
//void timing();
//void arrive();
//void depart(int server_index);
//void report();
//void update_time_avg_stats();
//double expon(double mean);


int main(int argc, char *argv[])
{
    freopen("report.txt", "w", stdout);
    srand(time(NULL));
    QueuingSystem queuing_system(0.8, 0.8, 100);
    queuing_system.run();
    cout<<queuing_system.report();
//    num_events = N_SERVERS+1;
//    mean_service = 0.8;
//    mean_interarrival = 0.8;
//    num_delays_required = 100;
//    get_events_log = false;
//    debug_log = false;
//
//
//    cout<<"Система массового обслуживания\n\n";
//    cout<<"Среднее время между поступлениями "<<mean_interarrival<<" мин\n\n";
//    cout<<"Среднее время обслуживания "<<mean_service<<" мин\n\n";
//    cout<<"Число требований "<<num_delays_required<<"\n\n";
//
//    initialize();
//    if(get_events_log) cout<<"----------------------------------\n\n";
//    while (n_reqests_served<num_delays_required){
//        timing();
//        update_time_avg_stats();
//        if(next_event_type == 1){
//            arrive();
//        } else {
//            depart(next_event_type - 2);
//        }
//    }
//    if(get_events_log) cout<<"----------------------------------\n\n";
//    report();
    return 0;
}

//void initialize(){
//    system_time = 0;
//    // all servers are free
//    for (int &status : server_status) {
//        status = IDLE;
//    }
//    total_waiting_in_queue = 0;
//    total_being_in_system = 0;
//    num_in_q = 0;
//    time_last_event = 0;
//
//    n_reqests_served = 0;
//    n_reqests_arrived = 0;
//    area_num_in_q = 0;
//
//    time_next_event[1] = system_time + expon(mean_interarrival);
//    for(int i = 2; i<N_SERVERS+2; i++){
//        time_next_event[i] = 1.0e+30;
//    }
//}
//
//double expon(double mean){
//    return -mean * log((double) rand()/RAND_MAX);
//}
//
//void timing(){
//    double min_time_next_event = 1.0e+29;
//
//    next_event_type = 0;
//    if(debug_log){
//        cout<<"timing:\n";
//    }
//    for(int i = 1; i<=num_events; i++){
//        if(debug_log) cout<<" - event type "<<i<<"; time: "<<time_next_event[i]<<"\n";
//        if(time_next_event[i] < min_time_next_event){
//            min_time_next_event = time_next_event[i];
//            next_event_type = i;
//        }
//    }
//
//    if(next_event_type == 0){
//        cout<<"Список событий пуст в момент времени "<<system_time<<"\n\n";
//        exit(1);
//    }
//
//    system_time = min_time_next_event;
//}
//
//void arrive(){
//    double delay;
//    bool served = false;
//    time_next_event[1] = system_time + expon(mean_interarrival);
//    n_reqests_arrived++;
//    if(get_events_log) cout<<"Прибыл запрос в момент времени "<<system_time<<"\n\n";
//    for(int i = 0; i<N_SERVERS; i++){
//        if(server_status[i] == IDLE){
//            //delay = 0;
//            n_reqests_served++;
//            server_status[i] = BUISY;
//            time_next_event[i+2] = system_time+expon(mean_service);
//            total_being_in_system += time_next_event[i+2]-system_time;
//            served = true;
//            if(get_events_log)  cout<<"Запрос обработан сервером "<<i<<" в момент времени "<<system_time<<" с задержкой "<<delay<<"\n\n";
//            break;
//        }
//    }
//    if(!served){
//        num_in_q++;
//        if(num_in_q > QUEUE_LIMIT){
//            cout<<"Очередь переполнена в момент времени "<<system_time<<"\n\n";
//            exit(2);
//        }
//        time_arrival[num_in_q] = system_time;
//    }
//}
//
//void depart(int server_index){
//    double delay;
//    if(debug_log) cout<<"depart  server_index = "<<server_index<<"  system time = "<<system_time<<"\n\n";
//    if(num_in_q == 0){
//        server_status[server_index] = IDLE;
//        time_next_event[server_index+2] = 1.0e+30;
//    } else {
//        num_in_q--;
//        time_next_event[server_index+2] = system_time + expon(mean_service);
//        delay = system_time - time_arrival[1];
//        total_waiting_in_queue += delay;
//        total_being_in_system += (delay + (time_next_event[server_index+2]-system_time));
//        n_reqests_served++;
//
//        if(get_events_log) cout<<"Запрос обработан сервером "<<server_index<<" в момент времени "<<system_time<<" с задержкой "<<delay<<"\n\n";
//        for(int i = 1; i <= num_in_q; i++){
//            time_arrival[i] = time_arrival[i+1];
//        }
//    }
//}
//
//void report(){
//    cout<<"\n\nКоэфициент использования "<<(total_being_in_system-total_waiting_in_queue)/(system_time*N_SERVERS);
//    cout<<"\n\nСреднее время ожидания в очереди "<<total_waiting_in_queue / n_reqests_served <<" с";
//    cout<<"\n\nСреднее время пребывания в системе "<<total_being_in_system / n_reqests_served <<" с";
//    cout<<"\n\nСреднее число требований в очереди "<<total_waiting_in_queue / system_time;
//    cout<<"\n\nСреднее число требований в системе "<<total_being_in_system / system_time;
//    cout<<"\n\nАбсолютная пропускная способность "<<n_reqests_served/system_time; //среднее число заявок, которое может обслужить система за единицу времени.
//    cout<<"\n\nОтносительная пропускная способность "<<n_reqests_served/n_reqests_arrived; //отношение среднего числа заявок, обслуживаемых системой в единицу времени, к среднему числу поступающих за это время заявок
//
//    cout<<"\n\nЧисло обслуженных требований "<<n_reqests_served;
//    cout<<"\n\nВремя завершения моделирования "<<system_time <<" с";
//
//    //cout<<"\n\n"<<total_waiting_in_queue<<"\n\n"<<area_num_in_q;
//}
//
//void update_time_avg_stats(){
//    double time_since_last_event = system_time - time_last_event;
//    time_last_event = system_time;
//
//    area_num_in_q += num_in_q*time_since_last_event;
//    //area_server_status += server_status*time_since_last_event;
//}