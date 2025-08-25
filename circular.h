
#ifndef CIRCULAR_H    // Include guard to prevent multiple inclusions
#define CIRCULAR_H

class cnode
{
public:
    int data;
    cnode *next;

    cnode();           // Default constructor
    cnode(int el);     // Parameterized constructor
};

class circular
{
    cnode *cursor;
public:
    circular();                        // Constructor
    int front();
    int back();
    void insert_back(int el);
	void insert_front(int el);        // Insert at head
    void cprint();                    // Print the linked list
    void del_back();
	void del_front();                 // Delete the head node
    bool csearch(int el);
	int csize();                      // Get the size of the list
};

#endif  // End of include guard

