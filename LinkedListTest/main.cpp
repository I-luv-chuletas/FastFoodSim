//
//  main.cpp
//  LinkedListTest
//
//  Created by Alexander Rivera on 10/19/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#include <iostream>
#include "Queue.h"
#include "ClientProgress.h"


int main(int argc, const char * argv[]) {
    
    int temp = 0;
    int serviceTimeInMin            = 0;    // Time that it has taken to make the order and get rid of the client.
    //int timeSinceLastOrder          = 0;    // Will contain the time that has passed since the last order taken.
    //int minutesPassed               = 0;    // Will contain the time that has passed in the process
    
    int accumulatedWaitingTime      = 0;    // Contains the amount of time that has been waited
    int accumulatedServiceTime      = 0;    // Contains the amount of service time in general
    
    Client_Progress* heladera = new Client_Progress();
    // Creamos el head de la lista
    Client* clientQueue = new Client();
    
    // Recogemos los datos principales del programa:
    heladera->input();
    
    // Sacamos los datos de las probabilidades:
    heladera->probabilities();
    
    // We make sure serviceTimeInMin initially is higher than the arrival rate, so that we create a new client in our first run
    serviceTimeInMin = heladera->clientArrivalTimeRate() + 1;
    
    //------------------------------------MAIN LOOP------------------------------------//
    while (heladera->totalHours() > accumulatedServiceTime) {  // Mientras que el tiempo total de apertura sea mayor que el tiempo que ha pasado
        std::cout << "\n DENTRO DEL MAINLOOP BITCHES \n"; 
        
        // First Phase: We take the order of the first client:
        if(!clientQueue->isEmpty())
        {
            
            std::cout<< "Arranca y brega con el fokin cliente pai" << std::endl;
            
            // Sacamos el serviceTime para el cliente
            serviceTimeInMin += heladera->getServiceTime();
            clientQueue->setServiceTime(serviceTimeInMin); // Innecesario
            clientQueue->pop();
            
        }
        
        
        //Second Phase: Se añaden los clientes necesarios:
        while (serviceTimeInMin >= heladera->clientArrivalTimeRate()) { // Si se lleva esperando mas tiempo de lo que llega un cliente
            
            Client* client = new Client();  // Llega un nuevo cliente
            clientQueue->push(client);      // The new client will locate itself on the queue
            std::cout << " Pario el hijuepu LOLROFLLMAO" << std::endl;
            std::cin >> temp;
            

            // Third Phase: Apply the waiting time to the clients in queue
            int waitingTime = serviceTimeInMin - heladera->clientArrivalTimeRate();
            clientQueue->setClientWaitingTime(waitingTime);
            accumulatedWaitingTime += waitingTime;
            
            
            serviceTimeInMin -= heladera->clientArrivalTimeRate();
        }
        
        
//        // Third Phase: Apply the waiting time to the clients in queue
//        if (serviceTimeInMin > heladera->clientArrivalTimeRate() && clientQueue->firstClient()->nextClient() != NULL) {
//
//            int waitingTime = serviceTimeInMin - heladera->clientArrivalTimeRate();
//            clientQueue->firstClient()->setClientWaitingTime(waitingTime);
//            accumulatedWaitingTime += waitingTime;
//            
//        }
        
        std::cout<< "\nTiempo de servicio acumulado es: "<<clientQueue->serviceTime() << std::endl;
        
        
    }
    
    // Se saca la cantidad de cliente que se atendieron.
    
    return 0;
}
