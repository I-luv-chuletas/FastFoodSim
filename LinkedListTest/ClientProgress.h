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
    
    int clientsArrivalMinutes;     //clients per minute
    int initial_time;           //opening
    int end_time;               //closure
    int total_minutes;          //converts hours to minutes
    int total_hrs;           //stores the difference between end time and initial time
    int clientsArriving;
    int service_acumulator;
    int serviceTime;            //time serving client
    int probability;            //generates a random numer which we assign a probability
    int multiplicator;

public:
    
    Client_Progress();                          //constructor
    void input();                               //prompts the user
    void total_clients();                       //total clients during simulation time
    void simulation_time();                     //calcula el tiempo simulado en minutos
    void probabilities();                       //calcular aleatoriamente las probabilidades de tiempo de servicio
    int  getServiceTime();
    float clientArrivalTimeRate();              // Devuelve cada cuantos minutos llega un cliente
    void total_service();
    
    // GETTERS ///////////////////////////
    int totalHours();
};

#endif /* defined(__fast_food__progress__) */
