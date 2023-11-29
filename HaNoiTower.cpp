#include <iostream>
#include <string>
using namespace std;

struct Node
{
  int data;
  Node *pNext;
};
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

void initStack(Stack &s)
{
  s.pTop = NULL;
}
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

void print(Stack s)
{
  Node *p = s.pTop;
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->pNext;
  }
}
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
