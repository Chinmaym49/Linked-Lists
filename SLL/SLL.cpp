#include<iostream>
using namespace std;

class Node {
    Node*next;
    int x;
    friend class SLL;
public:
    Node() {
        x=0;
        next=NULL;
    }
};

class SLL {
    Node*head;
public:
    SLL() {
        head=NULL;
    }

    void append(int a) {
        if(!head) {
            head=new Node();
            head->x=a;
            head->next=NULL;
        }
        else {
            Node*t=head;
            Node*r=new Node();
            r->next=NULL;
            r->x=a;
            while(t->next)
                t=t->next;
            t->next=r;
        }
    }

    void addbeg(int a) {
        if(!head) {
            head=new Node();
            head->x=a;
            head->next=NULL;
        }
        else {
            Node*t=new Node();
            t->x=a;
            t->next=head;
            head=t;
        }
    }

    int count() {
        int c=0;
        Node*t=head;
        while(t) {
            t=t->next;
            c++;
        }
        return c;
    }

    void display() {
        Node*t=head;
        while(t) {
            cout<<t->x<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    void del(int l) {
        if(l==0) {
            Node*t=head;
            head=head->next;
            t->next=NULL;
            delete t;
        }
        else if(l>=count())
            cout<<"Invalid index\n";
        else if(l==count()-1) {
            Node*t=head;
            while(t->next->next)
                t=t->next;
            t->next=NULL;
        }
        else {
            Node*t=head;
            Node*r=head;
            for(int i=0;i<l;i++) {
                r=t;
                t=t->next;
            }
            r->next=t->next;
            t->next=NULL;
            delete t;
        }
        display();
    }

    void disprev() {
        disprev(head);
        cout<<endl;
    }

    void disprev(Node*t) {
        if(t) {
            disprev(t->next);
            cout<<t->x<<" ";
        }
    }

    void reverse() {
        Node*p=NULL;
        Node*q=head;
        Node*r=q->next;
        while(q) {
            q->next=p;
            p=q;
            q=r;
            r=r->next;
        }
        head=p;
        display();
    }

};

int main() {
    SLL *s=new SLL();
    s->append(1);
    s->append(2);
    s->addbeg(0);
    s->append(3);
    s->append(4);
    s->append(5);
    cout<<s->count()<<endl;
    s->display();
    // s->del(10);
    // s->del(3);
    // s->del(0);
    // s->del(3);
    s->disprev();
    s->reverse();
    return 0;
}