
#include <iostream>
using namespace std;
/*
Define a node to store data and the pointer of adjacent
*/
struct Node
{
    int data;
    Node *pNext;
};
/**
 * Purpose: Initialize the node of stack
 * Input:
 *  + int
 * Output:
 *  + Node*
 */
Node *initNode(int value)
{
    Node *p = new Node();
    p->data = value;
    p->pNext = NULL;
    return p;
}
/**
 * Purpose: Initialize the queue
 * Input:
 *  + queue
 * Output:
 *  + queue
 */

struct Queue
{
    Node *pFront;
    Node *pRear;
};

void initQueue(Queue &q)
{
    q.pFront = q.pRear = NULL;
}
/**
 * Purpose:  enqueue a node to the queue
 * Input:
 *  + queue
 *  + Node*
 * Output:
 *  + queue
 */
void enqueue(Queue &q, Node *p)
{
    if (q.pFront == NULL)
    {
        q.pFront = q.pRear = p;
    }
    else
    {
        q.pRear->pNext = p;
        q.pRear = p;
    }
}
/**
 * Purpose:  dequeue a node to the queue
 * Input:
 *  + queue
 *  + int
 * Output:
 *  + bool
 */
bool dequeue(Queue &q, int &value)
{
    if (q.pFront == NULL)
    {
        return false;
    }
    else
    {
        Node *p = q.pFront;
        q.pFront = q.pFront->pNext;
        if (q.pFront == NULL)
        {
            q.pRear = NULL;
        }
        value = p->data;
        delete p;
        return true;
    }
}
/**
 * Purpose: Check whether a queue is empty or not
 * Input:
 *  + queue
 * Output:
 *  + bool
 */
bool CheckingEmpty(Queue q)
{
    if (q.pFront == NULL)
    {
        return true;
    }
    return false;
}
/**
 * Purpose: Handle option that user give into
 * Input:
 *  + queue
 * Output:
 *  + queue
 */
void handleMenu(Queue &q)
{
    cout << "Please enter the options: ";
    int option;
    cin >> option;
    Node *p;
    switch (option)
    {
        int value;
    case 1:
        cout << "Enter the value for the node";
        cin >> value;
        enqueue(q, initNode(value));
        break;
    case 2:
        if (dequeue(q, value))
        {
            cout << "The poped value" << value << endl;
        }
        else
        {
            cout << "Poping value does not work" << endl;
        }
        break;
    case 3:
        cout << "The value of front node is " << q.pFront->data << endl;
        cout << "The value of rear node is " << q.pRear->data << endl;
        break;
    case 4:
        if (CheckingEmpty(q))
        {
            cout << "The stack is empty" << endl;
        }
        else
        {
            cout << "The stack is not empty" << endl;
        }
        break;
    case 5:
        p = initNode(10);
        if (p == NULL)
        {
            cout << "The stack is full" << endl;
        }
        break;
    default:
        exit(0);
        break;
    }
};
void printQueue(Queue q)
{
    Node *p = q.pFront;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->pNext;
    }
}
/**
 * Purpose: Print a list of value of queue to the terminal
 * Input:
 *  + queue
 * Output:
 *  + Print a list of value of queue to the terminal
 */
void showMenu(Queue &q)
{
    cout << endl;
    cout << "========Demo Stack==========" << endl;
    cout << "1. enqueue" << endl;
    cout << "2. dequeue" << endl;
    cout << "3. Front and Rear" << endl;
    cout << "4. Checking Empty" << endl;
    cout << "5. Checking Full" << endl;
    cout << "============================" << endl;
    cout << "STACK = TOP < ";
    Node *p = q.pFront;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << ">" << endl;
    cout << "============================" << endl;

    handleMenu(q);
}

int main()
{
    Queue q;
    initQueue(q);

    while (1)
    {
        showMenu(q);
    }
}
