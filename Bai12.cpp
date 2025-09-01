#include <iostream>
#include <stack>
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

void printTree(Tree t)
{
    std::stack<Node *> s;
    Node *p = t.pRoot;
    while ((p != nullptr) || (s.empty() == false))
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        std::cout << p->data << " ";
        p = p->pRight;
    }
}

bool findValue(Tree t, int x)
{
    Node *p = t.pRoot;
    while (p != nullptr)
    {
        if (p->data == x)
            return true;
        else if (p->data > x)
            p = p->pLeft;
        else
            p = p->pRight;
    }
    return false;
}

int main()
{
    Tree t;
    initTree(t);
    addTree(t, initNode(10));
    addTree(t, initNode(9));
    addTree(t, initNode(11));
    addTree(t, initNode(13));
    // printTree(t);
    std::cout << findValue(t, 9);
    std::cout << findValue(t, 20);
    return 0;
}
