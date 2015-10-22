//
//  main.cpp
//  LinkedListTest
//
//  Created by Alexander Rivera on 10/19/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#include <iostream>
#include "Queue.h"
#include "progress.h"


int main(int argc, const char * argv[]) {
    
    Client_Progress* heladera = new Client_Progress();
    
    // Creamos el head de la lista
    Client* client = new Client();
    
    client->push(client);
    client->setNumber(1);
    
    Client* client1 = new Client();
    
    client->push(client1);
    client1->setNumber(2);
    
    Client* client2 = new Client();
    
    client1->push(client2);
    client2->setNumber(3);
    
    // Probamos
    std::cout<< "El numero del cliente: " << client->clientNumber() << std::endl;
    std::cout<< "El proximo cliente es: " << client->nextClient()->clientNumber();
    
    heladera->input();
    return 0;
}
