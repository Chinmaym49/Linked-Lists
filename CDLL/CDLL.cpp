#include<iostream>
using namespace std;

class Node {
    Node*next,*prev;
    int x;
    friend class CDLL;
public:
    Node() {
        x=0;
        next=NULL;
        prev=NULL;
    }
};

class CDLL {
    Node*rear;
public:
    CDLL() {
        rear=NULL;
    }

    void append(int a) {
        Node*t=new Node();
        t->x=a;
        t->next=t;
        t->prev=t;
        if(!rear)
            rear=t;
        else {
            t->next=rear->next;
            rear->next->prev=t;
            t->prev=rear;
            rear->next=t;
            rear=rear->next;
        }
    }

    void display() {
        Node*t=rear;
        do {
            t=t->next;
            cout<<t->x<<" ";
        }while(t!=rear);
        cout<<"\n";
    }

};

int main() {
    CDLL c;
    c.append(1);
    c.append(2);
    c.append(3);
    c.append(4);
    c.display();
    return 0;
}