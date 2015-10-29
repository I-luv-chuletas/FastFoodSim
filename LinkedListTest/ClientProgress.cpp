//
//  progress.cpp
//  fast_food
//
//  Created by Krystal N. Medina Rios on 10/20/15.
//  Copyright (c) 2015 Krystal N. Medina Rios. All rights reserved.
//

#include <iostream>
#include "ClientProgress.h"
#include "Queue.h"

using namespace std;

//constructor initializes atributes
Client_Progress::Client_Progress()
{

    clientsArrivalMinutes       =   0;
    end_time                    =   0;
    initial_time                =   0;
    total_hrs                   =   0;
    total_minutes               =   0;
    clientsArriving             =   0;
    service_acumulator          =   0;
    serviceTime                 =   0;
    probability                 =   0;
    multiplicator               =   0;
}

//prompt the user to enter values for specific atributes
void Client_Progress::input()
{
    cout<<"How often (in minutes) clients arrive: ";
    cin>>clientsArrivalMinutes;
    
    cout<<endl<<endl;
    
    cout<<"How many clients arrive during that time: ";
    cin>>clientsArriving;
    cout<<endl<<endl;
    
    clientArrivalTimeRate();
    cout<<endl<<endl;

    cout<<"Opening Hour: ";
    cin>>initial_time;
    
    cout<<endl;
    
    cout<<"Closing Hour: ";
    cin>>end_time;
    
    cout<<endl<<endl;
    simulation_time();
    
    //cout<<endl<<endl;
    
}


/*void Client_Progress::waiting_average()
{
    //arreglar estoooo
    //average =   waiting_acumulator / clients;
}
*/

/*void Client_Progress::total_clients()
{
    clients =   clientsPerMinute * total_minutes;
    cout<<"El total de clientes atendidos en el tiempo de simulacion fue de "<<clients<<" clientes."<<endl;
}
*/

void Client_Progress::total_service()
{
    getServiceTime();
}


void Client_Progress::simulation_time()
{
    total_hrs = end_time - initial_time;
    
    total_minutes = total_hrs * 60;
    
    cout<<"El tiempo total en minutos es: "<<total_minutes<<endl;
}


void Client_Progress::probabilities()
{
    int total_prob = 0;
    
    
    
    while (total_prob < 100)
    {
        cout<<"Enter probability and service time: ";
        cin>>probability>>serviceTime;
        total_prob += probability;
        probability /= 10;

        for (int i = 0; i < probability; i++)
        {
            _servicePerClient.push_back(serviceTime);
        }
    }
    cout<<"Tiempo de servicio de acuerdo a sus probabilidades: ";
    for (int i=0; i < _servicePerClient.size(); i++)
    {
        cout<<_servicePerClient[i]<<" ";
    }
    cout<<endl;
}


float Client_Progress::clientArrivalTimeRate()
{
    cout<<"Every "<<clientsArrivalMinutes/clientsArriving<<" minutes a client arrives."<<endl;
    
    /*if (serviceTime > clientsArrivalMinutes)
    {
        multiplicator = serviceTime/clientsArrivalMinutes;
        
        clientsArriving * multiplicator;
    }*/
    
    return clientsArrivalMinutes/clientsArriving;
}


int Client_Progress::getServiceTime()
{
    int randomService = 0;
    int nodeData = 0;
    
    
    randomService = rand() % _servicePerClient.size();
    nodeData = _servicePerClient.at(randomService);
    
    service_acumulator += nodeData;
    
    // cout<<"El total de tiempo de servicio dado fue de "<<service_acumulator * _servicePerClient.size()<<"."<<endl;
    return nodeData;
}


// GETTERS ///////////////////////////////////////////////////////////////////
int Client_Progress::totalHours() { return total_hrs; }
