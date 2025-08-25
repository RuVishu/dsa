#ifndef CD_H
#define CD_H

class lnode {
public:
    int data;
    lnode *prev;
    lnode *next;
    lnode(int el);
};

class cd {
    lnode *cdhead;
public:
    cd();
    ~cd();
    void hinsert(int el);
    void tinsert(int el);
    void delh();
    void delt();
    int cdsize();
    bool cdSearch(int el);
    void cdPrint();
};

#endif

