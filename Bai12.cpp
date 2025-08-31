#include <iostream>

struct Node
{
    int data;
    Node* pLeft;
    Node* pRight;
};

Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pLeft = nullptr;
    p->pRight = nullptr;
    return p; 
}

struct Tree
{
    Node* pRoot;
};

void initTree(Tree &t)
{
    t.pRoot = nullptr;
}

void addTree(Tree &t, Node* p)
{
    if (t.pRoot == nullptr)
    {
        t.pRoot = p;
    }
}


int main()
{
    Tree t;

}

