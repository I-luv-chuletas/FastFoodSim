//
//  Queue.cpp
//  LinkedListTest
//
//  Created by Alexander Rivera on 10/19/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#include "Queue.h"

Client::Client(){
    _clientNumber   = 0;
    _serviceTime    = 0;
}

void Client::setNumber(int number){
    _clientNumber = number;
}

void Client::setServiceTime(int serviceTime){
    _serviceTime = serviceTime;
}


//--------------------------------QUEUE--------------------------------//
void Client::pop(){
    
    // Guardamos el proximo nodo en un puntero temporero
    Client* temp;
    temp = _firstClient->_nextClient;
    
    _firstClient = NULL;
    _firstClient = temp;
    
}


void Client::push(Client *client){
    // Aqui metemos un nuevo cliente al final de la fila
    
    // Verificamos si es la primera corrida
    if (isEmpty()) {
        _firstClient    = new Client();  // Inicializamos los objetos
        _nextClient     = new Client();
        _lastClient     = new Client();
    }
    
    
    // Apuntamos en la lista al proximo cliente
    _lastClient->_nextClient = client;
    
    // Ahora mi ultimo cliente sera el cliente de parametro
    _lastClient = client;
    
    // El proximo cliente del last client sera NULL ya que es el ultimo en la lista
    _lastClient->_nextClient = NULL;
    
}


bool Client::isEmpty() {
    if (_firstClient == NULL && _nextClient == NULL) {
        return true;
    } else
        return false;
}