#include "stack.h"

/*
Name: Alex Woods NetID: ajw817
Date: 4/11/24 Due Date: 4/12/24
Description: defines the functions of node.h
*/

Stack::Stack()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

Stack::~Stack()
{
    if (size > 0)
    {
        Node* temp;

        while (head != nullptr)
        {
            temp = head->next;

            delete head;

            head = temp;
        }
    }
}

void Stack::add(char item)
{
    Node* temp = new Node(item,nullptr);
    
    if (size == 0) {
        
        head = temp;
        tail = head;

        
    }
    else {
        tail->next = temp;
        tail = temp;
        
    }
    size++;
}

char Stack::remove()
{
    char returned;
    Node* temp = head;
    if (size == 1) {
        
        returned = temp->data;
        head, tail = nullptr, nullptr;

        delete temp;

    }
    else {
        while (temp->next->next != nullptr) {
            temp = temp->next;
       }
        returned = temp->next->data;
        delete temp->next;
        tail = temp;
        tail->next = nullptr;

    }
    size--;
    return returned;
    /*
    if (size == 1)
    {
        // store current head
        Node* temp = head;

        // sanity check clear head and tail
        head = nullptr;
        tail = nullptr;

        // delete node
        delete temp;
    }

    // otherwise, if it won't
    else
    {
        // start a temporary node at the head
        Node* temp = head;

        // loop to one before the tail
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // delete the current tail
        delete tail;

        // sanity check clear the next pointer
        // and assign the new tail
        tail = temp;
        tail->next = nullptr;
    }*/
    
}
