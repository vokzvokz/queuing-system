/*
 * абсолютная пропускная способность — среднее число заявок, которое может обслужить система за единицу времени.
 * относительная пропускная способность — средняя доля поступивших заявок, обслуживаемая системой (отношение среднего числа заявок,
   обслуживаемых системой в единицу времени, к среднему числу поступающих за это время заявок)
 * коэфициент использования = лямбда / мю,
   где лямбда - интенсивность входящего потока (среднее число требований в единичном интервале)
   мю - интенсивность потока обслуживания (среднее число требований, обрабатываемых каналом в единичном интервале)


 */

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

int main(int argc, char *argv[])
{
    freopen("report.txt", "w", stdout);
    srand(time(NULL));
    QueuingSystem queuing_system(0.8, 0.8, 1000, 10, 5);
    queuing_system.run();
    cout<<queuing_system.report();
    return 0;
}
