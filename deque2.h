#ifndef DEQUE2_H
#define DEQUE2_H

class node {
public:
    int data;
    node* prev;
    node* next;
    
    node(int el);
};

class deque2 {
private:
    node* frontNode;   
    node* rearNode;    

public:
    deque2();
    ~deque2();

    int getFront();     
    int getRear();      
    
    void insert_f(int el);
    void insert_r(int el);
    void del_f();
    void del_r();
    int size();
    void print_d();
};

#endif

