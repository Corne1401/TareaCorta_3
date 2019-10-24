#pragma once

#include <string>
#include <utility>

using namespace std;
class CacheNode{

public:
    int id;
    string name;
    explicit CacheNode(int id, string name){
        this->id = id;
        this->name = std::move(name);
    }
};

