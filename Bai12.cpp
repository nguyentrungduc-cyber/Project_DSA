#include <iostream>

struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pLeft = nullptr;
    p->pRight = nullptr;
    return p;
}

struct Tree
{
    Node *pRoot;
};

void initTree(Tree &t)
{
    t.pRoot = nullptr;
}

void addTree(Tree &t, Node *p)
{
    if (t.pRoot == nullptr)
    {
        t.pRoot = p;
        return;
    }
    else
    {
        Node *pGoto = t.pRoot;
        Node *pLocal = nullptr;
        while (pGoto != nullptr)
        {
            pLocal = pGoto;
            if (p->data < pGoto->data)
                pGoto = pGoto->pLeft;
            else if (p->data > pGoto->data)
                pGoto = pGoto->pRight;
        }
        if (p->data < pLocal->data)
            pLocal->pLeft = p;
        else if (p->data > pLocal->data)
            pLocal->pRight = p;
    }
}

int main()
{
    Tree t;
}
