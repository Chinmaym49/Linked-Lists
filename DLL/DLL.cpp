#include<iostream>
using namespace std;

class Node {
    int x;
    Node *next,*prev;
    friend class DLL;
public:
    Node() {
        x=0;
        next=NULL;
        prev=NULL;
    }
};

class DLL {
    Node*head;
public:
    DLL() {
        head=NULL;
    }

    void append(int a) {
        Node*t=new Node();
        t->x=a;
        t->prev=NULL;
        t->next=NULL;
        if(!head)
            head=t;
        else {
            Node*r=head;
            while(r->next)
                r=r->next;
            r->next=t;
            t->prev=r;
        }
    }

    void addbeg(int a) {
        Node*t=new Node();
        t->x=a;
        t->prev=NULL;
        t->next=NULL;
        if(!head)
            head=t;
        else {
            t->next=head;
            head->prev=t;
            head=t;
        }
    }

    void display() {
        Node*t=head;
        while(t) {
            cout<<t->x<<" ";
            t=t->next;
        }
        cout<<"\n";
    }

    void delend() {
        if(!head->next)
            head=NULL;
        else {
            Node*t=head;
            Node*r=head;
            while(t->next) {
                r=t;
                t=t->next;
            }
            t->prev=NULL;
            r->next=NULL;
            delete t;
        }
    }

    void delbeg() {
        if(!head->next)
            head=NULL;
        else {
            Node*t=head;
            head=head->next;
            head->prev=NULL;
            t->next=NULL;
            delete t;
        }
    }

    void delmid(int a) {
        Node*r=head;
        Node*t=head;
        while(t->x!=a) {
            r=t;
            t=t->next;
        }
        r->next=t->next;
        t->next->prev=r;
        t->next=NULL;
        t->prev=NULL;
        delete t;
    }

};

int main() {
    DLL d;
    d.append(1);
    d.append(2);
    d.append(3);
    d.append(4);
    d.addbeg(0);
    d.display();
    d.delmid(2);
    // d.delbeg();
    // d.delend();
    d.display();
}