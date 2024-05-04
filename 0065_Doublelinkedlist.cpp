#include <iostream>
using namespace std;

struct Node {
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode() {
    Node* newNode = new Node(); // step 1: create a new node
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs; // Assign value to the data field of the new node
    cout << "\nEnter the name of the student : ";
    cin >> newNode->name; // Assign velue to the data field of the new node

    if (START == NULL || newNode->noMhs <= START->noMhs)
    { 
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers allowed\033[0m" << endl;
            return;
        }
        newNode->next = START; 
        if (START != NULL)
        {
            START->prev = newNode; 
        }
        newNode->prev = NULL; 
        START = newNode; 
    }
    else
    {
        Node* current = START; 
        Node* previous = NULL; 
        while (current != NULL && current->noMhs < newNode->noMhs)
        { 
            previous = current; 
            current = current->next; 
        }

        newNode->next = current; 
        newNode->prev = previous; 

        if (current != NULL)
        {
            current->prev = newNode;
        }
        if (previous != NULL)
        {
            previous->next = newNode; 
        }
        else
        {
            START = newNode;
        }
    }
}

bool search(int rollNo, Node** previous, Node** current) {
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode(){
    Node* previous, * current;
    int rollno;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollno;

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    current = START;
    previous = NULL;
    
while (current != NULL && current->noMhs != rollno)
    {
        previous = current;
        current = current->next;
    }
    if (current == START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
      else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }

 delete current;
    cout << "\x1b[32mRecord with roll number" << rollno << "deleted\x1b[0m" << endl;

}

bool listEmpty()
{
    return (START == NULL);
}

void traverse(){
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in ascending order of roll number are:" << endl;
        Node* currentNode = START;
        while (currentNode != NULL) 
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->next;

        }
    }
}
