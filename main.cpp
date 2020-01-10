#define QEUE_LIMIT 100
#define BUISY     1
#define IDLE      0

#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int next_event_type, num_custs_delayed, num_delays_required, num_events;
int num_in_q, server_status;

double area_num_in_q, area_server_status, mean_interarrival, mean_service;
double sim_time, time_arrival[QEUE_LIMIT+1], time_last_event, time_next_event[3];
double total_of_delays;

void initialize(void);
void timing(void);
void arrive(void);
void depart(void);
void report(void);
void update_time_avg_stats(void);
double expon(double mean);

void example();

int main(int argc, char *argv[])
{
    freopen("report.txt", "w", stdout);
    srand ( time(NULL) );

    num_events = 2;
    mean_interarrival = 1;
    mean_service = 0.5;
    num_delays_required = 1000;

    cout<<"Система массового обслуживания\n\n";
    cout<<"Среднее время между поступлениями "<<mean_interarrival<<" мин\n\n";
    cout<<"Среднее время обслуживания "<<mean_service<<" мин\n\n";
    cout<<"Число требований "<<num_delays_required<<"\n\n";

    initialize();

    while (num_custs_delayed < num_delays_required){
        timing();
        update_time_avg_stats();
        switch (next_event_type){
            case 1:
                arrive();
                break;
            case 2:
                depart();
                break;
        }
    }
    report();
    return 0;
}

void initialize(void){
    sim_time = 0;
    server_status = IDLE;
    num_in_q = 0;
    time_last_event = 0;

    num_custs_delayed = 0;
    total_of_delays = 0;
    area_num_in_q = 0;
    area_server_status = 0;

    time_next_event[1] = sim_time + expon(mean_interarrival);
    time_next_event[2] = 1.0e+30;
}

double expon(double mean){
    return -mean * log((double) rand()/RAND_MAX);
}

void timing(void){
    double min_time_next_event = 1.0e+29;

    next_event_type = 0;

    for(int i = 1; i<=num_events; i++){
        if(time_next_event[i] < min_time_next_event){
            min_time_next_event = time_next_event[i];
            next_event_type = i;
        }
    }

    if(next_event_type == 0){
        cout<<"Список событий пуст в момент времени "<<sim_time<<"\n\n";
        exit(1);
    }

    sim_time = min_time_next_event;
}

void arrive(void){
    double delay;

    time_next_event[1] = sim_time + expon(mean_interarrival);

    if(server_status == BUISY){
        num_in_q++;
        if(num_in_q > QEUE_LIMIT){
            cout<<"Очередь переполнена в момент времени "<<sim_time<<"\n\n";
            exit(2);
        }
        time_arrival[num_in_q] = sim_time;
    }
    else{
        delay = 0;
        total_of_delays += delay;

        num_custs_delayed++;
        server_status = BUISY;

        time_next_event[2] = sim_time + expon(mean_service);
    }
}

void depart(void){
    double delay;
    if(num_in_q == 0){
        server_status = IDLE;
        time_next_event[2] = 1.0e+30;
    } else {
        num_in_q--;

        delay = sim_time - time_arrival[1];
        total_of_delays += 1;

        num_custs_delayed++;
        time_next_event[2] = sim_time + expon(mean_service);

        for(int i = 1; i <= num_in_q; i++){
            time_arrival[i] = time_arrival[i+1];
        }
    }
}

void report(void){
    cout<<"\n\nСредняя задержка в очереди "<<total_of_delays / num_custs_delayed <<" мин";
    cout<<"\n\nСреднее число требований в очереди "<<area_num_in_q / sim_time;
    cout<<"\n\nКоэфициент занятости устройства обслуживания "<<area_server_status / sim_time;
    cout<<"\n\nВремя завершения моделирования "<<sim_time <<" мин";
}

void update_time_avg_stats(void){
    double time_since_last_event = sim_time - time_last_event;
    time_last_event = sim_time;

    area_num_in_q += num_in_q*time_since_last_event;
    area_server_status += server_status*time_since_last_event;
}
