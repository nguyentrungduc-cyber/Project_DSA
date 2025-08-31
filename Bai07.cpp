#include <iostream>

struct Node {
    int data;
    Node* pNext;
};

Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = nullptr;
    return p;
}

struct Stack {
    Node* pTop;
};

void initStack(Stack& s)
{
    s.pTop = nullptr;
}

void Push(Stack& s, Node* p)
{
    if (s.pTop == nullptr)
        s.pTop = p;
    else {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

void printStack(Stack s)
{
    for (Node* p = s.pTop; p != nullptr; p = p->pNext) {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}

void Pop(Stack& s, int& value)
{
    if (s.pTop == nullptr)
        return;
    Node* p = s.pTop;
    s.pTop = s.pTop->pNext;
    value = p->data;
    delete p;
}

int getTop(Stack s)
{
    if (s.pTop == nullptr)
        return 0;
    else {
        return s.pTop->data;
    }
}

void convertDecToBin(Stack& s)
{
    int Decimal;
    std::cout << "Decimal: ";
    std::cin >> Decimal;
    while (Decimal != 0) {
        Push(s, initNode(Decimal % 2));
        Decimal /= 2;
    }
}

int main()
{
    Stack s;
    initStack(s);
    // Push(s, initNode(7));
    // Push(s, initNode(6));
    // Push(s, initNode(5));

    // int value = 0;
    // Pop(s, value);
    // std::cout << value << std::endl;

    // std::cout << getTop(s);

    // convertDecToBin(s);
    // printStack(s);
    return 0;
}