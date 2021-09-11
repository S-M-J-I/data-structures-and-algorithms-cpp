#include<bits/stdc++.h>

using namespace std;

class Person{
private:
    string name;
    int id;

public:
    Person(string name, int id)
    {
        this->name = name;
        this->id = id;
    }

    string getName(){
        return this->name;
    }

    int getID(){
        return this->id;
    }

    void printInfo(){
        cout << "{Name : " << this->name << " | ID : " << this->id << "}";
    }

};

struct Node{
    Person data;
    struct Node *next;
};

Node *front = NULL, *back = NULL;

void queuePerson(Person person){
    struct Node *n;
    n->data = person;
    n->next = NULL;

    if(front = NULL){
        front = back = n;
        return;
    }

    back->next = n;
    back = n;
}


void printQueue(){
    Node *p = front;
    while(p){
        p->data.printInfo();
        cout << " -> ";
        p = p->next;
    }
    cout << "\n";
}

int main()
{
    queuePerson(Person("Jishan", 1000));
    queuePerson(Person("Jishan", 1000));
    queuePerson(Person("Jishan", 1000));
    queuePerson(Person("Jishan", 1000));

    printQueue();
}