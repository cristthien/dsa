#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node* pNext;
};
Node* initNode(string value)
{
    Node* p = new Node();
    p->data = value;
    p->pNext = NULL;
    return p;
}
struct Stack
{
    Node* pTop;
};

void initStack(Stack& s)
{
    s.pTop = NULL;
}
void push(Stack& s, Node* p)
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

bool pop(Stack& s, string& x)
{

    if (s.pTop != NULL)
    {
        Node* p = s.pTop;
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

void print(Stack s)
{
    Node* p = s.pTop;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
}
void SplitIntoStack(string str, Stack& s) {
    int i = 0;
    while (str[str.length() - 1] == ' ') {
        str.pop_back();
    } 
    string temp= "";
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            temp += str[i];
        }
        else {
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
