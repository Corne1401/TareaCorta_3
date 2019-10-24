#pragma once

#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

class node{
public:
    explicit node(string op){
        this->op = std::move(op);
        this->nextNode= nullptr;
        this->number = 0;
    }

    explicit node(int number){
        this->number = number;
        this->nextNode = nullptr;
    }

    explicit node(int number, node *next){
        this->number = number;
        this->nextNode = next;
    }

    explicit node(string op, node *next){
        this->number = 0;
        this->op = std::move(op);
        this->nextNode = next;
    }

private:
    int number;
    string op;
    node *nextNode;

    friend class list;
};


class list{
public:
    list(){
        firstNode=aux= nullptr;
    }


    void appendAtStart(int num);
    void appendAtStart(string op);
    void appendAtEnd(int num);
    int dataInPosition(int pos);
    void deleteInPos(int pos);
    void evenDigits(int num);
    void number1(int num);
    void number2(int num1, int num2);
    void tareaOpcional(int num1, int num2);
    bool findByElement(int num);
    bool findByElAndPos(int index, int num);
    void flipList();
    int numSize(int num);
    int listSize();
    void next();
    void printList();
    void deleteAtStart();
    node *getIndex(int pos);
    void numToList(int num);

private:
    node *aux;
    node *firstNode;

    bool isEmpty();


};


void list::appendAtStart(int num) {
    if(firstNode == nullptr){
        firstNode = new node(num);
    } else {
        firstNode = new node(num, firstNode);
    }
}

void list::appendAtEnd(int num) {
    if (firstNode == nullptr){
        firstNode = new node(num);
    } else {
        aux = firstNode;
        while (aux->nextNode != NULL){
            next();
        }
        aux->nextNode = new node(num);
    }
}


int list::dataInPosition(int pos){
    int i = 0;
    aux = firstNode;
    while(i<pos && aux != nullptr){
        i++;
        next();
    }
    if (aux == nullptr){
        cout << "Index out of bounds" << endl;
        return 0;
    } else {
        return aux->number;
    }
}

node *list::getIndex(int pos) {
    int i = 0;
    aux = firstNode;
    while(aux != nullptr){
        if(i==pos){
            return aux;
        }
        i++;
        next();
    }
    return nullptr;
}



void list::next(){
    aux = aux->nextNode;
}

void list::evenDigits(int num) {
    while (num!=0){
        int x = num%10;
        num/=10;
        appendAtStart(x);
    }
    int evenCount = 0;
    aux = firstNode;
    while (aux->nextNode!= nullptr){
        if(aux->number%2==0){
            evenCount++;
        }
        next();
    }
    cout << "Number of even digits is: " << evenCount;
}

void list::number1(int num) {
    while (num!=0){
        int x = num%10;
        num/=10;
        appendAtStart(x);
    }
    int res = 0;
    int count = 0;
    aux = firstNode;
    while (aux!=nullptr){
        if(aux->number%2==0){
            res+=aux->number;
            count++;
        }
        next();
    }

    cout << res/count << endl;
}

int list::listSize() {
    aux = firstNode;
    int count = 0;
    while (aux!=nullptr){
        count++;
        next();
    }
    return count;
}

void list::printList() {
    aux = firstNode;
    while (aux!=nullptr){
        cout << aux->number << "->";
        next();
    }
}


void list::number2(int num1, int num2) {
    list list1;
    list list2;
    list list3;

    while (num1!=0){
        int x = num1%10;
        num1/=10;
        list1.appendAtStart(x);
    }
    while (num2!=0){
        int x = num2%10;
        num2/=10;
        list2.appendAtStart(x);
    }

    if(list1.listSize()==list2.listSize()){
        int index = list1.listSize()-1;
        while (index>=0){
            list3.appendAtStart(list1.dataInPosition(index)+list2.dataInPosition(index));
            index--;
        }
    }

    list3.printList();


}




void list::tareaOpcional(int num1, int num2) {
    list list1;
    list list2;
    list list3;

    if (numSize(num1)==numSize(num2)){
        while (num1!=0){
            list1.appendAtStart(num1%10);
            list2.appendAtStart(num2%10);
            num1/=10;
            num2/=10;
        }
    }
    int newNum = 0;
    list1.aux = list1.firstNode;
    list2.aux = list2.firstNode;
    while (list1.aux!= nullptr){
        if(list1.aux->number%2==0 && list2.aux->number%2==0){
            cout << "Two Evens" << endl;
            newNum =  (int)pow( (int)pow(list1.aux->number, 3) + (int)pow(list2.aux->number, 3), 2) + 4;
            list3.appendAtEnd(newNum);
        } else if (list1.aux->number%2==0 && list2.aux->number%2!=0) {
            cout << "Even, odd" << endl;
            newNum =  (int)pow( (int)pow(list1.aux->number, 2) + (int)pow(list2.aux->number, 3), 3);
            list3.appendAtEnd(newNum);
        } else if (list1.aux->number%2!=0 && list2.aux->number%2==0) {
            cout << "Odd Even" << endl;
            newNum =  (int)pow( (int)pow(list1.aux->number, 3) + (int)pow(list2.aux->number, 2), 2) + 1;
            list3.appendAtEnd(newNum);
        } else if (list1.aux->number%2!=0 && list2.aux->number%2!=0) {
            cout << "two odds" << endl;
            newNum =  (int)pow( (int)pow(list1.aux->number, 2) + (int)pow(list2.aux->number, 2), 3) + 3;
            list3.appendAtEnd(newNum);
        }
        list1.next();
        list2.next();
    }
    cout << "------------" << endl;
    list3.printList();
}

int list::numSize(int num) {
    int i = 0;
    if (num == 0){
        return 1;
    } else{
        while (num!=0){
            num=num/10;
            i++;
        }
        return i;
    }
}

bool list::findByElement(int num) {
    aux = firstNode;
    bool found = false;
    while (aux!= nullptr){
        if(aux->number==num){
            found = true;
            break;
        }
        next();
    }
    return found;
}

bool list::findByElAndPos(int index, int num) {
    bool found = false;

    int i = 0;
    aux = firstNode;
    while(i<index && aux != nullptr){
        i++;
        next();
    }
    if (aux == nullptr){
        cout << "Index out of bounds" << endl;
        return found;
    } else {
        if (aux->number == num){
            found = true;
        }
        return found;
    }

    return found;
}

void list::flipList() {
    node *temp = nullptr;
    while (firstNode != nullptr){
        firstNode = firstNode->nextNode;
        temp->nextNode = aux;
        aux = temp;
        temp = firstNode;
    }
    firstNode = aux;
}

bool list::isEmpty() {
    return firstNode == nullptr;
}

void list::deleteInPos(int pos) {
    if(listSize()==1 || pos==0){
        deleteAtStart();
    } else {
        int i = 0;
        aux = firstNode;
        while(i<pos-1 && aux != nullptr){
            i++;
            next();
        }
        if (aux == nullptr){
            throw std::out_of_range ("Index out of bounds");
        } else {
            node *temp = aux->nextNode;
            aux->nextNode=aux->nextNode->nextNode;
            delete(temp);
        }
    }



}

void list::deleteAtStart() {
    if(firstNode->nextNode== nullptr){
        delete(firstNode->nextNode);
        firstNode = nullptr;
    } else{
        aux = firstNode;
        node *temp = firstNode;
        firstNode = aux->nextNode;
        delete(temp);
    }
}

void list::appendAtStart(string op) {
    if(firstNode == nullptr){
        firstNode = new node(op);
    } else {
        firstNode = new node(op, firstNode);
    }
}

void list::numToList(int num) {
    while (num!=0){
        int add = num%10;
        appendAtStart(add);
        num/=10;
    }
}