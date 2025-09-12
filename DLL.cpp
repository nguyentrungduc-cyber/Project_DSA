#include <iostream>

struct Node
{
    int data;
    Node *pNext;
    Node *pPre;
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = nullptr;
    p->pPre = nullptr;
    return p;
}

struct List
{
    Node *pHead;
    Node *pTail;
};

void initList(List &l)
{
    l.pHead = l.pTail = nullptr;
}

void addHead(List &l, Node *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pHead->pPre = p;
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addTail(List &l, Node *p)
{
    if (l.pTail == nullptr)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pPre = l.pTail;
        l.pTail = p;
    }
}

void printList(List l)
{
    std::cout << "pNext: \n";
    for (Node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;

    std::cout << "pPre: \n";
    for (Node *p = l.pTail; p != nullptr; p = p->pPre)
    {
        std::cout << p->data << " ";
    }
}

void removeHead(List &l)
{
    if (l.pHead == nullptr)
        return;
    Node *pCurrent = l.pHead;
    l.pHead = l.pHead->pNext;
    if (l.pHead == nullptr)
        l.pTail = nullptr;
    delete pCurrent;
    l.pHead->pPre = nullptr;
}

void removeTail(List &l)
{
    if (l.pHead == nullptr)
        return;
    if (l.pHead == l.pTail)
    {
        delete l.pHead;
        l.pHead = l.pTail = nullptr;
        return;
    }
    Node *pCurrent = l.pTail;
    l.pTail = l.pTail->pPre;
    delete pCurrent;
    l.pTail->pNext = nullptr;
}

int main()
{
    List l;
    initList(l);

    addHead(l, initNode(7));
    addHead(l, initNode(6));
    addTail(l, initNode(8));
    // 6 7 8
    removeHead(l);
    removeTail(l);
    printList(l);

    return 0;
}