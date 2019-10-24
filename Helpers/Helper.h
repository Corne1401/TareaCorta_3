#pragma once

#include <iostream>
#include <fstream>
#include "BST.h"
#include "CacheNode.h"

using namespace std;


void clientRead(){
    ifstream clients ("../Tests/Clientes.txt");
    ofstream index ("../Out/indices.txt");
    ofstream newClient("../Out/newClients.txt");
    string line;
    if(clients.is_open()){
        int indexNum = 0;
        while(getline(clients, line)){
            newClient<< line+";"+"0"<<endl;
            index<< line+";" <<indexNum<<endl;
            indexNum++;
        }
        index.close();
        newClient.close();
    }
}

void loadBSTHelper(BSTTree &tree, const string& fullString, char delimiter, int count){
    string data1;
    string data2;
    string data3;
    int dataCount = 0;
    for (auto x : fullString){
        switch(dataCount){
            case 0:
                if(x==delimiter){
                    //cout << data1 << endl;
                    dataCount++;
                } else {
                    data1+=x;
                }
                break;
            case 1:
                if(x==delimiter){
                    //cout << data2 << endl;
                    dataCount++;
                } else {
                    data2+=x;
                }
                break;
            case 2:
                if(x==delimiter){
                    //cout << data3 << endl;
                    dataCount++;
                } else {
                    data3+=x;
                }
                break;
            default:
                dataCount=0;
                data1 = "";
                data2 = "";
                data3 = "";
                break;
        }
    }

    try{
        int data1Int = stoi(data1);
        if(!tree.isIdOnTree(tree.root, data1Int)) {
            tree.root = tree.insert(tree.root, data1Int, count);
        }
    }catch (std::invalid_argument& e) {
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << data2 << endl;
        cout << "******************************************************************************************************" << endl;
    }
}

void loadBST(BSTTree &tree){
    string line;
    ifstream arch1("../Out/newClients.txt");
    int count = 0;
    while (getline(arch1, line)) {
        if(!line.empty()){
            loadBSTHelper(tree, line, ';', count);
            count++;
        }
    }
    arch1.close();
}

bool check_key(map<int, CacheNode> m, int key){
    return !(m.find(key) == m.end());
}

void defaultCacheInitHelper(map<int, CacheNode> &cacheMemory, const string& fullString, char delimiter, int count){
    string data1;
    string data2;
    string data3;
    int dataCount = 0;
    for (auto x : fullString){
        switch(dataCount){
            case 0:
                if(x==delimiter){
                    //cout << data1 << endl;
                    dataCount++;
                } else {
                    data1+=x;
                }
                break;
            case 1:
                if(x==delimiter){
                    //cout << data2 << endl;
                    dataCount++;
                } else {
                    data2+=x;
                }
                break;
            case 2:
                if(x==delimiter){
                    //cout << data3 << endl;
                    dataCount++;
                } else {
                    data3+=x;
                }
                break;
            default:
                dataCount=0;
                data1 = "";
                data2 = "";
                data3 = "";
                break;
        }
    }

    try{
        int data1Int = stoi(data1);




        if (!check_key(cacheMemory, count) && cacheMemory.size()<20) {
            cacheMemory.insert(make_pair(count, CacheNode(data1Int, data2)));
            cout << cacheMemory.size() << endl;
        }
    }catch (std::invalid_argument& e) {
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << data2 << endl;
        cout << "******************************************************************************************************" << endl;
    }
}

void defaultCacheInit(map<int, CacheNode> &cacheMemory){
    string line;
    ifstream arch1("../Out/newClients.txt");
    int count = 0;
    while (getline(arch1, line)) {
        if(!line.empty()){
            defaultCacheInitHelper(cacheMemory, line, ';', count);
            count++;
        }
    }
    arch1.close();
}

void printCache(map<int, CacheNode> &cacheMemory){
    for (auto& it: cacheMemory) {
        cout << it.first << " | " << it.second.id << "; " << it.second.id << " | "<< endl;
    }
}

void updateCacheHelper(map<int, CacheNode> &cacheMemory, const string& fullString, char delimiter, int index, int count){
    string data1;
    string data2;
    string data3;
    int dataCount = 0;
    for (auto x : fullString){
        switch(dataCount){
            case 0:
                if(x==delimiter){
                    //cout << data1 << endl;
                    dataCount++;
                } else {
                    data1+=x;
                }
                break;
            case 1:
                if(x==delimiter){
                    //cout << data2 << endl;
                    dataCount++;
                } else {
                    data2+=x;
                }
                break;
            case 2:
                if(x==delimiter){
                    //cout << data3 << endl;
                    dataCount++;
                } else {
                    data3+=x;
                }
                break;
            default:
                dataCount=0;
                data1 = "";
                data2 = "";
                data3 = "";
                break;
        }
    }

    try{
        int data1Int = stoi(data1);

        if (!check_key(cacheMemory, count) && cacheMemory.size()<20) {
            cacheMemory.insert(make_pair(count, CacheNode(data1Int, data2)));
            cout << cacheMemory.size() << endl;
        }
    }catch (std::invalid_argument& e) {
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << data2 << endl;
        cout << "******************************************************************************************************" << endl;
    }
}

void updateCache(map<int, CacheNode> &cacheMemory, int index, BSTTree &tree){
    string line;
    ifstream arch1("../Out/newClients.txt");
    int count = 0;

    //Cleans cache
    cacheMemory.clear();

    while (getline(arch1, line)) {
        if(!line.empty()){
            updateCacheHelper(cacheMemory, line, ';', index, count);
        }
    }
    arch1.close();
}

void findClient(BSTTree &tree, map<int, CacheNode> &cacheMemory){
    string clientIdString;
    while (true){
        try {
            cout << "Type Client id to search: " << endl;
            cin >> clientIdString;
            int clientId = stoi(clientIdString);

            int index = tree.getClientById(tree.root, clientId)->index;

            if(check_key(cacheMemory, index)){
                //TODO CLIENT IN CACHE
                auto client = cacheMemory.at(index);
                cout << "Client ID: " << client.id << " , Name: " << client.name << endl;
                updateCache(cacheMemory, index, tree);
            } else {
                //TODO CLIENT NOT IN CACHE
            }

            break;
        } catch (std::invalid_argument &e){

        }
    }
}