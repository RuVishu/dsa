// singly.h
#ifndef SINGLY_H    
#define SINGLY_H

class node
{
public:
    int data;
    node *next;
    node();           
    node(int el);     
};

class singly
{
    node *head;
public:
    singly();                        
    void insert_head(int el);        
    void print();                    
    void del_head();                 
    int size();                      
    void insert_last(int el);		
    void del_last();				
    bool search(int el); 		
    void insert_mid(int el);
};

#endif 

