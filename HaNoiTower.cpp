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
 *  + ints
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

int pop(Stack &s)
{

  if (s.pTop != NULL)
  {
    Node *p = s.pTop;
    s.pTop = s.pTop->pNext;
    return p->data;
    delete p;
  }
  else
  {
    return 0;
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
 * Purpose: Pop the value from stack and add this to another stack
 * Input:
 *  + stack (ref)
 *  + stack (ref)
 * Output:
 *  + stack
 *  + stack
 */
void PopPush(Stack &sPop, Stack &sPush)
{
  if (sPop.pTop == NULL)
  {
    cout << "Can not pop";
    return;
  }
  int valuePop = sPop.pTop->data;
  int valuePush;
  if (sPush.pTop == NULL)
  {
    valuePush = 4;
  }
  else
  {
    valuePush = sPush.pTop->data;
  }
  if (valuePop < valuePush)
  {
    push(sPush, initNode(pop(sPop)));
  }
  else
  {
    cout << "Can not perform moving dish" << endl;
  }
}
/**
 * Purpose: Handle option that user give into
 * Input:
 *  + stack A
 *  + stack B
 *  + stack C
 * Output:
 *  + stack A
 *  + stack B
 *  + stack C
 */
void handleMenu(Stack &sA, Stack &sB, Stack &sC)
{
  cout << "Please enter the options: ";
  int option;
  cin >> option;
  switch (option)
  {
  case 0:
    push(sA, initNode(3));
    push(sA, initNode(2));
    push(sA, initNode(1));
    break;
  case 1:
    PopPush(sA, sB);
    break;
  case 2:
    PopPush(sB, sA);

    break;

  case 3:
    PopPush(sB, sC);

    break;

  case 4:
    PopPush(sC, sB);

    break;
  case 5:
    PopPush(sC, sA);

    break;
  case 6:
    PopPush(sA, sC);

    break;
  default:
    exit(0);
    break;
  }
};
/**
 * Purpose: Print out the option for user to choose
 * Input:

 *  + stack A
 *  + stack B
 *  + stack C
 * Output:
 *  + Print out the option for user to choose and show the current stacks
 */
void showMenu(Stack &sA, Stack &sB, Stack &sC)
{
  cout << endl;
  cout << "========Demo Stack==========" << endl;
  cout << "0. Creating a tower" << endl;
  cout << "1. A -> B" << endl;
  cout << "2. B -> A" << endl;
  cout << "3. B -> C" << endl;
  cout << "4. C -> B" << endl;
  cout << "5. C -> A" << endl;
  cout << "6. A -> C" << endl;
  cout << "============================" << endl;
  cout << "STACK A = TOP < ";
  print(sA);
  cout << ">" << endl;
  cout << "============================" << endl;
  cout << "============================" << endl;
  cout << "STACK B = TOP < ";
  print(sB);
  cout << ">" << endl;
  cout << "============================" << endl;
  cout << "============================" << endl;
  cout << "STACK C = TOP < ";
  print(sC);
  cout << ">" << endl;
  cout << "============================" << endl;

  handleMenu(sA, sB, sC);
}

int main()
{
  Stack sA;
  Stack sB;
  Stack sC;
  initStack(sA);
  initStack(sB);
  initStack(sC);

  while (1)
  {
    showMenu(sA, sB, sC);
  }
  return 0;
}
