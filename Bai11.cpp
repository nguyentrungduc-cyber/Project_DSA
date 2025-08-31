#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define SIZE 5

struct Node
{
    float data;
    Node *pNext;
};

Node *initNode(float value)
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

struct HashTable
{
    Busket busket[SIZE];
};

void initHash(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        initBusket(h.busket[i]);
    }
}

void addTail(Busket &bk, Node *p)
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

int hashFunction(float value)
{
    return (int)(abs(value)) % SIZE;
}

void addHash(HashTable &h, float value)
{
    int indexBusket = hashFunction(value);
    addTail(h.busket[indexBusket], initNode(value));
}
void printHash(HashTable h)
{
    std::cout << "HaskTable\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Busket[" << i << "] = ";
        printBusket(h.busket[i]);
    }
}

float createValue()
{
    // 856 - 988
    return 856.0f + static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * (988.0f - 856.0f);
}

int sizeOfHash()
{
    // 45 - 95
    return (45 + std::rand() % (95 - 45 + 1));
}

void cau1(HashTable &h)
{
    srand(time(0));
    int Size = sizeOfHash();
    std::cout << Size << "\n";
    for (int i = 0; i < Size; i++)
    {
        addHash(h, createValue());
    }
}

void cau2(HashTable &h, float array[], int soLuong)
{
    for (int i = 0; i < soLuong; i++)
    {
        addHash(h, array[i]);
    }
}

int main()
{
    HashTable h;
    initHash(h);

    cau1(h);

    float array[] = {5.5, 6.5, 7.8, 8.8, 9.9};
    int soLuong = 5;
    // cau2(h, array, soLuong);
    printHash(h);

    return 0;
}
