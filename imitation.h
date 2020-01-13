#ifndef IMITATION_H
#define IMITATION_H


#include <string>
#include <QTextStream>

#define QUEUE_LIMIT 36
#define BUISY      1
#define IDLE       0
#define N_SERVERS  2

using namespace std;

class Imitation {
private:


    int next_event_type, n_requests_served, n_requests_arrived, num_requests_required, num_events;
    int num_in_q, nonserved_requests, server_status[N_SERVERS];

    double area_num_in_q, area_server_status, mean_interarrival, mean_service;
    double system_time, time_arrival[QUEUE_LIMIT+1], time_last_event, time_next_event[N_SERVERS+2];
    double total_waiting_in_queue, total_being_in_system;

    bool get_events_log, get_debug_log;
    string report_string, logs, arrivings, services;
    //void initialize();
    void timing();
    void arrive();
    void depart(int server_index);
    void update_time_avg_stats();
    double expon(double mean);
    string get_stats(string spacer = " ");

public:
    string report();
    string get_timing_stats();
    string get_arrivings();
    string get_services();
    void run();
    Imitation(double mean_service, double mean_interarrival, int num_requests_required,
            bool get_events_log = false, bool get_debug_log = false);
    ~Imitation();
};

#endif // IMITATION_H
