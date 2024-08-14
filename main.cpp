#include <iostream>
#include "linked_list.h"

int main(){
    LinkedList myList;

    // Insert elements at the back
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Display the elements of the linked list
    std::cout << "Linked List: ";
    myList.display();

    // Insert an element at the front
    myList.push_front(5);

    // Display the modified linked list
    std::cout << "Linked List after push_front(5): ";
    myList.display();

    // Insert an element at a specific index
    myList.insert(2, 15);

    // Display the modified linked list
    std::cout << "Linked List after insert(2, 15): ";
    myList.display();

    // Remove an element with the specified value
    myList.remove(20);

    // Display the modified linked list
    std::cout << "Linked List after remove(20): ";
    myList.display();

    // Pop elements from the back and front
    myList.pop_back();
    myList.pop_front();

    // Display the modified linked list
    std::cout << "Linked List after pop_back() and pop_front(): ";
    myList.display();

    // Check if the linked list is empty
    std::cout << "Is the linked list empty? " << (myList.empty() ? "Yes" : "No") << std::endl;

    // Get the size of the linked list
    std::cout << "Size of the linked list: " << myList.size() << std::endl;

    return 0;
}

