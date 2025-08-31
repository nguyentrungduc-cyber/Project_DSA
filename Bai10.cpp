#include <iostream>

#define Size 5

struct Node
{
    int data;
    Node *pNext;
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = nullptr;
    return p;
}

struct Busket
{
    Node *pHead;
    Node *pTail;
};

void initBusket(Busket &bk)
{
    bk.pHead = bk.pTail = nullptr;
}

void addBusket(Busket &bk, Node *p)
{
    if (bk.pHead == nullptr)
    {
        bk.pHead = bk.pTail = p;
    }
    else
    {
        bk.pTail->pNext = p;
        bk.pTail = p;
    }
}

void printBusket(Busket bk)
{
    for (Node *p = bk.pHead; p != nullptr; p = p->pNext)
    {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}

struct HashTable
{
    Busket busket[Size];
};

void initHash(HashTable &h)
{
    for (int i = 0; i < Size; i++)
    {
        initBusket(h.busket[i]);
    }
}

int hashFunction(int value)
{
    return value % Size;
}

void addHash(HashTable &h, int value)
{
    int indexBusket = hashFunction(value);
    // for (int i = 0; i < Size; i++)
    // {
    //     addBusket(h.busket[indexBusket], initNode(value));
    // }
    addBusket(h.busket[indexBusket], initNode(value));
}

void printHash(HashTable h)
{
    std::cout << "HaskTable\n";
    for (int i = 0; i < Size; i++)
    {
        std::cout << "Busket[" << i << "] = ";
        printBusket(h.busket[i]);
    }
}

int main()
{
    HashTable h;
    initHash(h);

    addHash(h, 50);
    addHash(h, 73);
    addHash(h, 35);
    addHash(h, 36);
    addHash(h, 64);
    addHash(h, 28);
    addHash(h, 90);
    addHash(h, 21);
    addHash(h, 53);
    addHash(h, 13);

    printHash(h);

    return 0;
}
