#include <iostream>
#include <string>
using namespace std;
/*
Define a node to store data and the pointer of adjacent
*/
struct Node
{
    string data;
    Node *pNext;
};
/**
 * Purpose: Initialize the node of stack
 * Input:
 *  + string
 * Output:
 *  + Node*
 */
Node *initNode(string value)
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
 *  + string
 * Output:
 *  + bool
 */
bool pop(Stack &s, string &x)
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
        cout << p->data << " ";
        p = p->pNext;
    }
}
/**
 * Purpose: Split the string into a list of  words whose delimeter is space.
 * Input:
 *  + string
 *  + stack
 * Output:
 *  + stack
 */
void SplitIntoStack(string str, Stack &s)
{
    int i = 0;
    while (str[str.length() - 1] == ' ')
    {
        str.pop_back();
    }
    string temp = "";
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            temp += str[i];
        }
        else
        {
            push(s, initNode(temp));
            temp.clear();
        }
        i++;
    }
    push(s, initNode(temp));
}
int main()
{
    Stack s;
    initStack(s);
    string str;
    cout << "Nguoi dung nhap: ";
    getline(cin, str);
    cout << endl;
    SplitIntoStack(str, s);
    cout << "Ket qua dao chuoi: ";
    print(s);
    return 0;
}
