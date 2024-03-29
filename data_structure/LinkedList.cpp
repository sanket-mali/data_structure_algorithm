/*
File: LinkedList.cpp
Author: Sanket Mali
Date: 01/03/2024
Description: Implementation of Linked List data structure
--------------------------------------------------------- */
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr){}
    // overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        os << node.data;
        return os;
    }
};

// LinkedList class
class LinkedList
{
    private:
        // keep track of the first node
        Node *head;
    public:
        LinkedList() : head(nullptr) {}
        LinkedList(int*, int);
        ~LinkedList();

        //-----------------------------
        void insert_back(int);
        void insert_front(int);
        void insert_after(Node*, int);
        void remove(int);
        void remove(Node*);
        void remove_back();
        void remove_front();
        Node* search(int);
        void print();
        // overload the << operator
        friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
            Node* itr = list.head;
            while(itr != nullptr) {
                os << *itr << " ";
                itr = itr->next;
            }
            return os;
        }
};

LinkedList::LinkedList(int* arr, int size)
{
    if(size>0) {
        this->head = new Node(arr[0]);
    }
    for(int i = 1; i<size; i++) {
        this->insert_back(arr[i]);
    }
}

LinkedList::~LinkedList()
{
}

// function to insert data at end
void LinkedList::insert_back(int data) {
    Node* newNode = new Node(data);
    if(this->head)
    {
        Node* itr = head;
        while(itr->next != nullptr) {
            itr = itr->next;
        }
        itr->next = newNode;
    }
    else {
        this->head = newNode;
    }
}

// function to insert data at the front
void LinkedList::insert_front(int data) {
    Node* newNode = new Node(data);
    if(this->head) {
        newNode->next = this->head;
        this->head = newNode;
    }
    else {
        this->head = newNode;
    }
}

// function to insert data after a specific node if exists
void LinkedList::insert_after(Node* key, int data) {
    Node* newNode = new Node(data);
    Node* itr = this->head;
    while(itr != key && itr != nullptr)
    {
        itr = itr->next;
    }
    if(itr == nullptr)
        cout<<"key not found"<<endl;
    else {
        Node* nextNode = itr->next;
        itr->next = newNode;
        newNode->next = nextNode;
    }
}

// function to search a integer value in the list
Node* LinkedList::search(int key) {
    Node* itr = this->head;
    while(itr != nullptr) {
        if(itr->data == key)
            return itr;
        itr = itr->next;
    }    
    return nullptr;
}

// function to print the linked list on console
void LinkedList::print() {
    Node* itr = this->head;
    while(itr != nullptr) {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<endl;
    cout<<"-----------------------------------"<<endl;
}

// function to delete a node
void LinkedList::remove(Node* dataNode) {
    Node* prevItr = nullptr;
    Node* itr = this->head;
    while(itr != dataNode && itr != nullptr) {
        prevItr = itr;
        itr = itr->next;
    }
    if(itr == nullptr)
        cout<<"Nothing in list to remove"<<endl;
    else {
        prevItr->next = itr->next;
        free(itr);
    }
}

// function to delete a node with a specific data
void LinkedList::remove(int data) {
    // search the node for the data
    Node* dataNode = this->search(data);
    // remove the node
    //check for nullptr if not found
    if(dataNode) {
        this->remove(dataNode);
    }
    else
        cout<<"Nothing to remove"<<endl;
}


// function to delete last node
void LinkedList::remove_back() {
    if(this->head) {
        Node* prevItr = nullptr;
        Node* itr = this->head;
        while(itr->next != nullptr) {
            prevItr = itr;
            itr = itr->next;
        }
        prevItr->next = nullptr;
        delete itr;
    }
}

// function to delete first node
void LinkedList::remove_front() {
    if(this->head) {
        Node* firstNode = this->head;
        head = head->next;
        delete firstNode;
    }
}

int main() {
    int arr[] = {5, 12, 3, 19};
    auto var = LinkedList(arr, 4);
    var.print();
    var.insert_front(21);
    var.print();
    var.insert_back(23);
    var.print();
    auto elm = var.search(23);
    var.insert_after(elm, 56);
    var.print();
    var.remove(3);
    var.print();
    cout<<*elm<<endl;
    cout<<var<<endl;
}