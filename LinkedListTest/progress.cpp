//
//  progress.cpp
//  fast_food
//
//  Created by Krystal N. Medina Rios on 10/20/15.
//  Copyright (c) 2015 Krystal N. Medina Rios. All rights reserved.
//

#include <iostream>
#include "progress.h"

using namespace std;

//constructor initializes atributes
Client_Progress::Client_Progress()
{
    clientsPerMinute    =   0.0;
    //arrivalMinutes      =   0;
    end_time            =   0;
    initial_time        =   0;
    average             =   0.0;
    total_hrs           =   0;
    total_minutes       =   0;
    clients             =   0;
    service_acumulator  =   0;
    serviceTime         =   0;
    probability         =   0;
    arrivalTime         =   0;
    waitTime            =   0;
}
//prompt the user to enter values for specific atributes
void Client_Progress::input()
{
    cout<<"Entra la cantidad de clientes que llegan por minuto: ";
    cin>>clientsPerMinute;
    
    cout<<endl<<endl;
    
    cout<<"Hora Inicial: ";
    cin>>initial_time;
    
    cout<<endl<<endl;
    
    cout<<"Hora Final: ";
    cin>>end_time;
    
    cout<<endl<<endl;
    
    //cout<<endl<<endl;
    
    
    //INCOMPLETO
}


void Client_Progress::waiting_average()
{
    //arreglar estoooo
    //average =   waiting_acumulator / clients;
}


void Client_Progress::total_clients()
{
    clients =   clientsPerMinute * total_minutes;
}


/*void Client_Progress::total_service(int service)
{
    service_acumulator += serviceTime;
}*/


int Client_Progress::simulation_time()
{
    total_hrs = end_time - initial_time;
    
    total_minutes = total_hrs * 60;
    
    return  total_minutes;
}


void Client_Progress::process()
{
    
    //analisis de tiempo de servicio y tiempo de espera
    
}

void Client_Progress::probabilities()
{
    int total_prob = 0;
    
    cout<<"Enter probability and service time: ";
    cin>>probability>>serviceTime;
    total_prob += probability;
    
    while (total_prob != 100)
    {
        while (probability > 0)
        {
            for (int i = 0; i < probability; i++)
            {
                _servicePerClient.push_back(serviceTime);
            }
        }
        
        cout<<"Vuelva entrar la probabilidad y el tiempo de servicio deseado: ";
        cin>>probability>>serviceTime;
        total_prob += probability;
        
    }
}
void Client_Progress::distributionMinutes()
{
    for (int i = 0; i <= 10; i++)
    {
        arrivalTime = clientsPerMinute * i;
        
        if (arrivalTime == 1)
        {
            arrivalTime=i;
            i += 10;
        }
    }
}
