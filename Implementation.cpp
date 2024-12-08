#include "List.h"
#include <iostream>
using namespace std;

void List::insert_at_head(int value)
{
    Node* temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        head->setNext(head);
        head->setPrev(head);
    }
    else
    {
        temp->setNext(head);
        temp->setPrev(tail);
        head->setPrev(temp);
        tail->setNext(temp);
        head = temp;
    }
}

void List::insert_at_tail(int value)
{
    Node* temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        head->setNext(head);
        head->setPrev(head);
    }
    else
    {
        temp->setPrev(tail);
        temp->setNext(head);
        tail->setNext(temp);
        head->setPrev(temp);
        tail = temp;
    }
}

void List::insert_at_target(int value, int target)
{
    Node* temp = head;
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    do
    {
        if (temp->getData() == target)
        {
            Node* newNode = new Node(value);
            newNode->setNext(temp->getNext());
            newNode->setPrev(temp);
            temp->getNext()->setPrev(newNode);
            temp->setNext(newNode);

            if (temp == tail)
            {
                tail = newNode;
            }
            return;
        }
        temp = temp->getNext();
    } while (temp != head);

    cout << "Target value not found!" << endl;
}

void List::search_target(int target)
{
    Node* temp = head;
    if (head == NULL)
    {
        cout << "Not Found" << endl;
        return;
    }

    do
    {
        if (temp->getData() == target)
        {
            cout << "Found" << endl;
            return;
        }
        temp = temp->getNext();
    } while (temp != head);

    cout << "Not Found" << endl;
}

void List::print()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    } while (temp != head);

    cout << endl;
}

void List::prev_print()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = tail;
    do
    {
        cout << temp->getData() << " ";
        temp = temp->getPrev();
    } while (temp != tail);

    cout << endl;
}

void List::remove(int target)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do
    {
        if (temp->getData() == target)
        {
            if (temp == head && temp == tail)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                temp->getPrev()->setNext(temp->getNext());
                temp->getNext()->setPrev(temp->getPrev());
                if (temp == head)
                {
                    head = temp->getNext();
                }
                if (temp == tail)
                {
                    tail = temp->getPrev();
                }
            }

            delete temp;
            return;
        }
        temp = temp->getNext();
    } while (temp != head);

    cout << "Value not found!" << endl;
}
