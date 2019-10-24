#pragma once

#include <iostream>
#include <fstream>
#include "BST.h"
#include "CacheNode.h"
#include "simpleList.h"

using namespace std;


void clientReadHelper(ofstream &newClient, ofstream &index, simpleList &list, const string& fullString, char delimiter, int &indexNum){
    string data1;
    string data2;
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
            default:
                dataCount=0;
                data1 = "";
                data2 = "";
                break;
        }
    }

    try{
        int data1Num = stoi(data1);
        if(!list.findByElement(data1Num)){
            list.appendAtEnd(data1Num);
            newClient<< fullString+";"+"0"<<endl;
            index<< fullString+";" <<indexNum<<endl;
            indexNum++;
        }
    }catch (std::invalid_argument& e) {
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << data2 << endl;
        cout << "******************************************************************************************************" << endl;
    }
}

void clientRead(){
    ifstream clients ("../Tests/Clientes.txt");
    ofstream index ("../Out/indices.txt");
    ofstream newClient("../Out/newClients.txt");
    simpleList list;

    string line;
    if(clients.is_open()){
        int indexNum = 0;
        while(getline(clients, line)){
            clientReadHelper(newClient, index, list, line, ';', indexNum);
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
        cout << it.first << " | " << it.second.id << "; " << it.second.name << " | "<< endl;
    }
}

void updateCacheHelper(map<int, CacheNode> &cacheMemory, const string& fullString, char delimiter, int &index, int &count, int &countLines, BSTTree &tree){
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
        if(countLines==index && cacheMemory.size()<20){
            cacheMemory.insert(make_pair(index, CacheNode(data1Int, data2)));
            index++;
            count++;
        }

    }catch (std::invalid_argument& e) {
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << data2 << endl;
        cout << "******************************************************************************************************" << endl;
    }
}

void updateCache(map<int, CacheNode> &cacheMemory, int &index, BSTTree &tree){
    string line;
    ifstream arch1("../Out/newClients.txt");
    int countLines = 0;
    int count = 0;

    //Cleans cache
    cacheMemory.clear();

    while (getline(arch1, line)) {
        if(!line.empty()){
            updateCacheHelper(cacheMemory, line, ';', index, count, countLines, tree);
            countLines++;
        }
    }
    arch1.close();

    if(count<20){
        index = 0;
        countLines = 0;
        ifstream arch2("../Out/newClients.txt");
        while (getline(arch2, line)) {
            if(!line.empty()){
                updateCacheHelper(cacheMemory, line, ';', index, count, countLines, tree);
                countLines++;
            }
        }
        arch2.close();
    }
}


void purgeClientHelper(const string& fullString, char delimiter, ofstream &file){
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
        if(data3 == "0"){
            file << fullString<<endl;
        };
    }catch (std::invalid_argument& e) {
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << data2 << endl;
        cout << "******************************************************************************************************" << endl;
    }
}

void purgeClient(){
    string line;
    ifstream arch1("../Out/newClients.txt");
    ofstream purgedFile("../Out/purgedClients.txt");

    while (getline(arch1, line)) {
        if(!line.empty()){
            purgeClientHelper(line, ';', purgedFile);
        }
    }
    arch1.close();
    remove("../Out/newClients.txt");
    rename("../Out/purgedClients.txt", "../Out/newClients.txt");
    
}



void getClientFromFileHelper(const string& fullString, char delimiter, int &index, int &count){
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
        if(count==index){
            cout << "Client ID: " << data1 << ", Name: " << data2 << endl;
        }

    }catch (std::invalid_argument& e) {
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << data2 << endl;
        cout << "******************************************************************************************************" << endl;
    }
}

void getClientFromFile(int index){
    string line;
    ifstream arch1("../Out/newClients.txt");
    int countLines = 0;

    while (getline(arch1, line)) {
        if(!line.empty()){
            getClientFromFileHelper(line, ';', index, countLines);
            countLines++;
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

            if(tree.isIdOnTree(tree.root, clientId)){
                int index = tree.getClientById(tree.root, clientId)->index;

                if(check_key(cacheMemory, index)){
                    auto client = cacheMemory.at(index);
                    cout << "Client found in Cache" << endl;
                    cout << "Client ID: " << client.id << " , Name: " << client.name << endl;
                    updateCache(cacheMemory, index, tree);
                } else {
                    cout << "Client found in file" << endl;
                    getClientFromFile(index);
                    updateCache(cacheMemory, index, tree);
                }
            } else {
                cout << "ERROR. No such client with ID: " << clientId << endl;
            }



            break;
        } catch (std::invalid_argument &e){

        }
    }
}

void markAsDeletedInFileHelper(){

}


void markAsDeletedInFile(int &clientId){
    string line;
    ifstream arch1("../Out/newClients.txt");
    int countLines = 0;

    while (getline(arch1, line)) {
        if(!line.empty()){
            markAsDeletedInFileHelper(line, ';', clientId, countLines);
            countLines++;
        }
    }
    arch1.close();
}

void deleteClient(BSTTree &tree, map<int, CacheNode> &cacheMemory){
    string clientIdString;
    while (true){
        try {
            cout << "Type Client id to search: " << endl;
            cin >> clientIdString;
            int clientId = stoi(clientIdString);

            if(tree.isIdOnTree(tree.root, clientId)){
                markAsDeletedInFile(clientId);

                //Proceed to re-index tree and cache
                cacheMemory.clear();
                tree.deleteTree(tree.root);
                defaultCacheInit(cacheMemory);
            } else {
                cout << "ERROR. No such client with ID: " << clientId << endl;
            }



            break;
        } catch (std::invalid_argument &e){

        }
    }
}