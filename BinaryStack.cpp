#include <iostream>
using namespace std;

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
        cout << p->data;
        p = p->pNext;
    }
}
/**
 * Purpose: Convert a decimal number to a binary
 * Input:
 *  + stack
 *  + int
 * Output:
 *  + stack
 */
void ConvertToBinary(Stack &s, int value)
{
    while (value != 0)
    {
        push(s, initNode(value % 2));
        value = value / 2;
    }
}
int main()
{
    Stack s;
    initStack(s);
    int n;
    cout << "Enter the number you want to convert to binary" << endl;
    cin >> n;
    ConvertToBinary(s, n);
    cout << "The result is: ";
    print(s);
    return 0;
}
