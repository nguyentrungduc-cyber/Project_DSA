#include <iostream>
#include <string.h>

struct Node
{
    char *data;
    Node *pNext;
};

Node *initNode(char *value)
{
    Node *p = new Node;
    p->data = new char[strlen(value) + 1];
    strcpy(p->data, value);
    p->pNext = nullptr;
    return p;
}

struct Stack
{
    Node *pTop;
};

void initStack(Stack &s)
{
    s.pTop = nullptr;
}

void Push(Stack &s, Node *p)
{
    if (s.pTop == nullptr)
        s.pTop = p;
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

void printStack(Stack s)
{
    for (Node *p = s.pTop; p != nullptr; p = p->pNext)
    {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}

// void Pop(Stack &s, int &value)
// {
//     if (s.pTop == nullptr)
//         return;
//     Node *p = s.pTop;
//     s.pTop = s.pTop->pNext;
//     value = p->data;
//     delete p;
// }

void reverseStack(Stack &s, char str[])
{
    char *token = strtok(str, " ");

    while (token != NULL)
    {
        Push(s, initNode(token));
        token = strtok(NULL, " ");
    }
}

int main()
{
    Stack s;
    initStack(s);

    char str[] = "Banana Apple Coconut";

    reverseStack(s, str);
    printStack(s);

    return 0;
}
