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

struct Stack
{
    Node *pTop;
};
/**
 * Purpose: Initialize the stack
 * Input:
 *  + stack
 * Output:
 *  + stack
 */

void initStack(Stack &s)
{
    s.pTop = NULL;
}
/**
 * Purpose: push a node to the stack
 * Input:
 *  + stack
 *  + Node*
 * Output:
 *  + stack
 */
void push(Stack &s, Node *p)
{
    if (s.pTop == NULL)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}
/**
 * Purpose: Pop the node out the stack
 * Input:
 *  + stack
 *  + int
 * Output:
 *  + bool
 */

bool pop(Stack &s, int &x)
{

    if (s.pTop != NULL)
    {
        Node *p = s.pTop;
        s.pTop = s.pTop->pNext;
        x = p->data;
        delete p;
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * Purpose: Check whether a stack is empty or not
 * Input:
 *  + stack
 * Output:
 *  + bool
 */
bool CheckingEmpty(Stack s)
{
    if (s.pTop == NULL)
    {
        return true;
    }
    return false;
}
/**
 * Purpose: Handle option that user give into
 * Input:
 *  + stack
 * Output:
 *  + stack
 */
void handleMenu(Stack &s)
{
    cout << "Please enter the options: ";
    int option;
    cin >> option;
    Node *p;
    switch (option)
    {
        int value;
    case 1:
        cout << "Enter the  value for the node";
        cin >> value;
        push(s, initNode(value));
        break;
    case 2:
        if (pop(s, value))
        {
            cout << "The poped value" << value << endl;
        }
        else
        {
            cout << "Poping value does not work" << endl;
        }
        break;
    case 3:
        cout << "The value of top node is " << s.pTop->data << endl;
        break;
    case 4:
        if (CheckingEmpty(s))
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
/**
 * Purpose: Print out the option for user to choose
 * Input:
 *  + stack (ref)
 * Output:
 *  + Print out the option for user to choose and show the current stack
 */
void showMenu(Stack &s)
{
    cout << endl;
    cout << "========Demo Stack==========" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Top" << endl;
    cout << "4. Checking Empty" << endl;
    cout << "5. Checking Full" << endl;
    cout << "============================" << endl;
    cout << "STACK = TOP < ";
    Node *p = s.pTop;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << ">" << endl;
    cout << "============================" << endl;

    handleMenu(s);
}
/**
 * Purpose: Print a list of value of stack to the terminal
 * Input:
 *  + stack
 * Output:
 *  + Print a list of value of stack to the terminal
 */
void print(Stack s)
{
    Node *p = s.pTop;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->pNext;
    }
}

int main()
{
    Stack s;
    initStack(s);
    while (1)
    {
        showMenu(s);
    }

    return 0;
}
