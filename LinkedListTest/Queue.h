//
//  Queue.h
//  LinkedListTest
//
//  Created by Alexander Rivera on 10/19/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#ifndef __LinkedListTest__Queue__
#define __LinkedListTest__Queue__

#include <stdio.h>

//struct

// Estructura que contiene los "Nodos"
class Client {

public:
    // Metodos que manegen data de clientes
    void setNumber(int number);
    void setServiceTime(int serviceTime);
    int clientNumber() { return _clientNumber; }
    int serviceTime()  { return _serviceTime;  }
    Client* nextClient(){ return _nextClient; }
    
    // Constructores y Clases
    Client();
    
    // Control de Queue
    void pop();
    void push(Client* client);
    bool isEmpty();
    
    
private:
    // Campos de Datos por Cliente
    int _clientNumber;
    float _serviceTime;
    
    Client* _nextClient     = NULL;
    Client* _firstClient    = NULL;
    Client* _lastClient     = NULL;
};

#endif /* defined(__LinkedListTest__Queue__) */
