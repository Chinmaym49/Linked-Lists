#include<iostream>
using namespace std;

class Node {
    int x;
    Node*next;
    friend class CLL;
public:
    Node() {
        x=0;
        next=NULL;
    }
};

class CLL {
    Node*rear;
public:
    CLL() {
        rear=NULL;
    }

    void append(int a) {
        Node*t=new Node();
        t->next=NULL;
        t->x=a;
        if(!rear) {
            rear=t;
            rear->next=rear;
        }
        else {
            t->next=rear->next;
            rear->next=t;
            rear=t;
        }
    }

    void addbeg(int a) {
        Node*t=new Node();
        t->x=a;
        t->next=NULL;
        if(!rear) {
            rear=t;
            rear->next=rear;
        }
        else {
            t->next=rear->next;
            rear->next=t;
        }
    }

    void display() {
        Node*t=rear->next;
        do {
            cout<<t->x<<" ";
            t=t->next;
        }while(t!=rear->next);
        cout<<endl;
    }

    void delbeg() {
        if(rear->next==rear)
            rear=NULL;
        else {   
            Node*t=rear->next;
            rear->next=t->next;
            t->next=NULL;
            delete t;
        }
    }

    void delend() {
        if(rear->next==rear)
            rear=NULL;
        else {
            Node*t=rear;
            Node*r=rear;
            do
                r=r->next;
            while(r->next!=t);
            rear=r;
            rear->next=t->next;
            t->next=NULL;
            delete t;
        }
    }

};

int main() {
    CLL *c=new CLL();
    c->append(1);
    c->append(2);
    c->append(3);
    c->append(4);
    c->addbeg(0);
    c->display();
    c->delbeg();
    c->delend();
    c->display();
    return 0;
}