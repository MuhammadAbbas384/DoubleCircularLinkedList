#pragma once
#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    Node* prev;

public:
    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }

    int getData()
    {
        return data;
    }

    Node* getNext()
    {
        return next;
    }

    Node* getPrev()
    {
        return prev;
    }

    void setNext(Node* nextNode)
    {
        next = nextNode;
    }

    void setPrev(Node* prevNode)
    {
        prev = prevNode;
    }
};
