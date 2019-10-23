#pragma once

#include <iostream>
#include <fstream>
using namespace std;


void clientRead(){
    ifstream clients ("../Tests/Clientes.txt");
    ofstream index ("../Out/indices.txt");
    string line;
    if(clients.is_open()){
        int indexNum = 0;
        while(getline(clients, line)){
            index<< line+";" <<indexNum<<endl;
            indexNum++;
        }
    }
}
