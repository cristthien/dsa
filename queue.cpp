
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* pNext;
};
Node* initNode(int value){
    Node* p = new Node();
    p->data = value;
    p->pNext = NULL;
    return p;
}
struct Queue {
    Node* pFront;
    Node* pRear;

};
void initQueue(Queue& q) {
    q.pFront = q.pRear = NULL;
}
void enqueue(Queue &q, Node*p) {
    if (q.pFront == NULL) {
        q.pFront = q.pRear = p;
    }
    else {
        q.pRear->pNext = p;
        q.pRear = p;
    }

}
bool dequeue(Queue &q, int &value) {
    if (q.pFront == NULL) {
        return false;
    }else{
        Node* p = q.pFront;
        q.pFront = q.pFront->pNext;
        if (q.pFront == NULL) {
            q.pRear = NULL;
        }
        value = p->data;
        delete p;
        return true;
    }
}
bool CheckingEmpty(Queue q) {
    if (q.pFront == NULL) {
        return true;
    }
    return false;
}
void handleMenu(Queue& q) {
    cout << "Please enter the options: ";
    int option;
    cin >> option;
    switch (option)
    {
        int value;
    case 1:
        cout << "Enter the value for the node";
        cin >> value;
        enqueue(q, initNode(value));
        break;
    case 2:
        if (dequeue(q, value)) {
            cout << "The poped value" << value << endl;
        }
        else {
            cout << "Poping value does not work" << endl;
        }
        break;
    case 3:
        cout << "The value of front node is " << q.pFront->data << endl;
        cout << "The value of rear node is " << q.pRear->data << endl;
        break;
    case 4:
        if (CheckingEmpty(q)) {
            cout << "The stack is empty" << endl;
        }
        else {
            cout << "The stack is not empty" << endl;
        }
        break;
    case 5:
        Node * p = initNode(10);
        if (p == NULL) {
            cout << "The stack is full" << endl;
        }
        break;
    default:
        exit(0);
        break;
    }
};
void printQueue(Queue q) {
    Node* p = q.pFront;
    while (p != NULL) {
        cout << p-> data<<endl;
        p = p->pNext;
    }
}

void showMenu(Queue & q) {
    cout << endl;
    cout << "========Demo Stack==========" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Top" << endl;
    cout << "4. Checking Empty" << endl;
    cout << "5. Checking Full" << endl;
    cout << "============================" << endl;
    cout << "STACK = TOP < ";
    Node* p = q.pFront;
    while (p != NULL) {
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
    enqueue(q, initNode(10));
    enqueue(q, initNode(1));
    enqueue(q, initNode(4));
    enqueue(q, initNode(7));
    enqueue(q, initNode(9));
    int x;
    dequeue(q,x);
    cout << x << endl<< endl;

    printQueue(q);
}

