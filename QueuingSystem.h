#ifndef SMO_ALPHA_QUEUING_SYSTEM_H
#define SMO_ALPHA_QUEUING_SYSTEM_H

#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

#define BUISY      1
#define IDLE       0
//#define N_SERVERS  2

using namespace std;

/* TODO
 * Изменить критерий останова на время   +
 * Реализовать приоритет                 +
 * Выбор размера накопителя              +
 * Выбор количества устройств            +
 * Матожидание, дисперсия, дов интервал  -
 *
*/

class QueuingSystem {
private:


    int next_event_type, n_requests_served, n_requests_arrived, n_priorities, queue_limit, num_events;
    int n_requests_rejected, n_servers;
    //int server_status[N_SERVERS];
    int *server_status;

    double area_num_in_q, mean_service;
    double system_time, time_limit, time_last_event;//, time_next_event[N_SERVERS+2];
    double *time_next_event;
    double total_waiting_in_queue, total_being_in_system;

    bool get_events_log, get_debug_log;
    string report_string;

    priority_queue<pair<int, double>> requests_queue;

    //void initialize();
    void timing();
    void arrive();
    void depart(int server_index);

    void update_time_avg_stats();
    double expon(double mean);
    int generate_priority();
    string get_stats(string spacer = " ");

public:
    string report();
    void run();
    QueuingSystem(double mean_service, double mean_interarrival, double  time_limit, int queue_limit = 36,
                  int n_servers = 2, bool get_events_log = false, bool get_debug_log = false);
    ~QueuingSystem();
};


#endif //SMO_ALPHA_QUEUING_SYSTEM_H