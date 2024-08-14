#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList(LinkedList&& other);

    const LinkedList& operator=(const LinkedList& other);
    const LinkedList& operator=(LinkedList&& other);

public:
    void clear();
    bool empty();
    void push_back(int);
    void push_front(int);
    void display();
    
    void pop_back();
    void pop_front();
    size_t size();
    void insert(size_t, int);
    int get(size_t);
    void remove(int);

private:
    struct Node
    {
        int value;
        Node* next;
        Node(int);
    };
    Node* head;
};

#endif
