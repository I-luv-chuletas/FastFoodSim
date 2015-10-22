//
//  progress.h
//  fast_food
//
//  Created by Krystal N. Medina Rios on 10/20/15.
//  Copyright (c) 2015 Krystal N. Medina Rios. All rights reserved.
//

#ifndef __fast_food__progress__
#define __fast_food__progress__

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Client_Progress
{

private:
    
    std::vector<int> _servicePerClient;
    std::vector<int> _clientWaitingTime;
    double clientsPerMinute;    //clients per minute
    int initial_time;           //opening
    int end_time;               //closure
    //int arrivalMinutes;         //maximum service time per client
    double average;             //stores waiting average
    int total_minutes;          //converts hours to minutes
    double total_hrs;           //stores the difference between end time and initial time
    int clients;                //acumulates clients per minute
    int service_acumulator;
    int serviceTime;            //time serving client
    int probability;            //generates a random numer which we assign a probability
    int arrivalTime;            //cada cuanto tiempo llega alguien
    int waitTime;               //tiempo de espera
    
public:
    
    Client_Progress();                          //constructor
    void input();                               //prompts the user
    void waiting_average();                     //promedio de espera por cliente
    void total_service();                       //acumula el tiempo de servicio de cada cliente
    void total_clients();                       //total clients during simulation time
    int  simulation_time();                     //calcula el tiempo simulado en minutos
    void process();
    void probabilities();                       //calcular aleatoriamente las probabilidades de tiempo de servicio
    void output();                              //prints results
    void distributionMinutes();
};
#endif /* defined(__fast_food__progress__) */
