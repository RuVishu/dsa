#include "cd.h"
#include <iostream>

using namespace std;

lnode::lnode(int el) {
    data = el;
    prev = next = NULL;
}

cd::cd() {
    cdhead = NULL;
}


cd::~cd() {
    if (cdhead == NULL) return;
    lnode* temp = cdhead;
    do {
        lnode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != cdhead); 
}

void cd::hinsert(int el) {
    lnode *newnode = new lnode(el);
    if (cdhead == NULL) {
    	cdhead=newnode;
    	cdhead->next=cdhead;
    	cdhead->prev=cdhead;
    	return;
	}
	newnode->next=cdhead;
	newnode->prev=cdhead->prev;
	cdhead->prev->next=newnode;
	cdhead->prev=newnode;
	cdhead=newnode;
	
}

void cd::tinsert(int el){
	lnode *newnode=new lnode(el);
	if(cdhead==NULL){
		cdhead=newnode;
    	cdhead->next=cdhead;
    	cdhead->prev=cdhead;
		return;		
	}
	newnode->prev=cdhead->prev;
	newnode->next=cdhead;
	cdhead->prev->next=newnode;
	cdhead->prev=newnode;
}
void cd::cdPrint() {
    if (cdhead == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    lnode *temp = cdhead;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != cdhead);
    cout << endl;
}
void cd::delh() {
    if (cdhead == NULL) { 
        cout << "List is Empty\n"; 
        return; 
    }

    lnode *temp = cdhead; 
    if (cdhead->next == cdhead) {
        cdhead = NULL;  
    } 
    else {
        cdhead->prev->next = cdhead->next;  
        cdhead->next->prev = cdhead->prev;  
        cdhead = cdhead->next; 
    }
    delete temp; 
}
void cd::delt() {
    if (cdhead == NULL) {
        cout << "List is Empty\n";
        return;
    }

    lnode *temp = cdhead->prev;  
    if (temp == cdhead) {  
        cdhead = NULL;
    } 
    else {
        cdhead->prev = temp->prev;      
        temp->prev->next = cdhead;     
    }
    delete temp; 
}
int cd::cdsize(){
	if (cdhead == NULL) return 0;
	int count=0;
    lnode* temp = cdhead;
    do {
        count++;
        temp = temp->next;
    } while (temp != cdhead);
	return count; 
}
bool cd::cdSearch(int el) {
    if (cdhead == NULL) {
        cout << "List is Empty\n";
        return false;
    }  
    lnode* temp = cdhead;
    do {
        if (temp->data == el) {
            return true;
        }
        temp = temp->next;
    } while (temp != cdhead);
    return false;
}

