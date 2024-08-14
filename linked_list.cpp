#include <iostream>
#include "linked_list.h"


LinkedList::Node::Node(int val) 
    :value {val}
    ,next {nullptr}
{}

LinkedList::LinkedList()
    :head {nullptr}
{}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::clear()
{
    Node* current = head;
    Node* nextNode = nullptr;
    while(current != nullptr){
        nextNode = current -> next; 
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList& other)
    :head {nullptr}
{
    Node* otherNode = other.head;
    Node* thisPro = nullptr;
    while(otherNode != nullptr){
        Node* newNode = new Node(otherNode -> value);
        if (thisPro == nullptr){
            head = newNode;
        } else {
            thisPro -> next = newNode;
        }
        thisPro = newNode;
        otherNode = otherNode -> next;
    }
}

LinkedList::LinkedList(LinkedList&& other)
    :head {other.head}
{
    other.head = nullptr;
}

const LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if (this != &other){
        clear();

        Node* otherNext = other.head;
        Node* thisPro = nullptr;
        while(otherNext != nullptr){
            Node* newNode = new Node(otherNext -> value);
            if (thisPro == nullptr){
            head = newNode;
        } else {
            thisPro -> next = newNode;
        }
        thisPro = newNode;
        otherNext = otherNext -> next;
        }
    }
    return *this;
}

const LinkedList& LinkedList::operator=(LinkedList&& other)
{
    if (this != &other){
        clear();

        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

bool LinkedList::empty()
{
    if (head){
        return false;
    }
    return true;
}

void LinkedList::push_back(int value)
{
    Node* tmp = new Node(value);
    if (head == nullptr){
        head = tmp;
    } else {
        Node* nextNode = head;
        while(nextNode -> next){
            nextNode = nextNode -> next;
        }
        nextNode -> next = tmp;
    }
    tmp = nullptr;
}

void LinkedList::push_front(int value)
{
    Node* newNode = new Node(value);
    newNode -> next = head;
    head = newNode;
}

void LinkedList::display()
{
    Node* nextNode = head;
    while(nextNode){
        std::cout << nextNode -> value << "  ";
        nextNode = nextNode -> next;
    }
    std::cout << std::endl;
}


void LinkedList::pop_back()
{
    if (head == nullptr){
        return;
    }
    if (head -> next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* nextNode = head;
    while(nextNode -> next -> next != nullptr){
        nextNode = nextNode -> next;
    }
    delete nextNode -> next;
    nextNode -> next = nullptr;
}

void LinkedList::pop_front()
{
    if (head == nullptr){
        return;
    }
    Node* tmp = head -> next;
    delete head;
    head = tmp;
    tmp = nullptr;
}

size_t LinkedList::size()
{
    if(head == nullptr){
        return 0;
    }
    size_t s = 1;
    Node* nextNode = head;
    while(nextNode -> next != nullptr){
        nextNode = nextNode -> next;
        ++s;
    }
    return s;
}

void LinkedList::insert(size_t index, int value)
{
    size_t s = size();
    if (index > s){
        throw std::invalid_argument("Renge of out!");
    }
    Node* newNode = new Node(value);
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* nextNode = head;
    for (size_t i = 0; i < index - 1; ++i) {
        nextNode = nextNode->next;
    }

    newNode->next = nextNode->next;
    nextNode->next = newNode;
}

int LinkedList::get(size_t index)
{
    size_t s = size();
    if (index > s){
        throw std::invalid_argument("Index out of renge!");
    }
    Node* nextNode = head;
    for(size_t i = 0; i < index; ++i){
        nextNode = nextNode -> next;
    }
    return nextNode -> value;
}

void LinkedList::remove(int value)
{
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->value == value) {
            if (previous == nullptr) {
                head = current->next;
                delete current;
                return; 
            } else {
                previous->next = current->next;
                delete current;
                return; 
            }
        } else {

            previous = current;
            current = current->next;
        }
    }
}






























