#ifndef DOUBLY_H    // Include guard to prevent multiple inclusions
#define DOUBLY_H

class dnode
{
	public:
		int data;
		dnode *next;
		dnode *prev;
		dnode();
		dnode(int el);     // Parameterized constructor
};

class doubly
{
	public: 
    dnode *head;
    dnode *tail;  
	doubly();                        // Constructor
    ~doubly();
	void insert_dhead(int el);        // Insert at head
    void insert_dtail(int el); 		 // Insert at tail
	void dprint();                    // Print the linked list
    void del_dhead();                 // Delete the head node
    void del_dtail();                 // Delete the tail node
    int dsize();                      // Get the size of the list
    bool dsearch(int el);
    void insert_dmid(int el);
};

#endif  // End of include guard

