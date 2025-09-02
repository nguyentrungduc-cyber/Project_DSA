#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
    Node *pList;
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pLeft = nullptr;
    p->pRight = nullptr;
    p->pList = nullptr;
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
            else
                pGoto = pGoto->pList;
        }
        if (p->data < pLocal->data)
            pLocal->pLeft = p;
        else if (p->data > pLocal->data)
            pLocal->pRight = p;
        else
            pLocal->pList = p;
    }
}

void printTree(const Tree &t)
{
    std::stack<Node *> s;
    Node *p = t.pRoot;

    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }

        p = s.top();
        s.pop();

        std::cout << p->data << " ";

        // Traverse linked list attached to node
        Node *listNode = p->pList; // nên gán trước để tránh nullptr và ko bị crack khi truy xuất data
        while (listNode != nullptr)
        {
            std::cout << listNode->data << " ";
            listNode = listNode->pList;
        }
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

int sumTree(Tree t)
{
    int sum = 0;
    std::stack<Node *> s;
    Node *p = t.pRoot;
    while (p != nullptr || s.empty() == false)
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        sum += p->data;
        p = p->pRight;
    }
    return sum;
}

int accountLeaves(Tree t)
{
    int account = 0;
    std::stack<Node *> s;
    Node *p = t.pRoot;
    while (p != nullptr || s.empty() == false)
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        if (((p->pLeft == nullptr) && (p->pRight == nullptr)))
            account++;
        p = p->pRight;
    }
    return account;
}

int numberNode()
{
    // [10; 20]
    return 10 + std::rand() % 11;
}

int valueNode()
{
    // [-36; 68]
    return -36 + std::rand() % 105;
}

void addTreeRandom(Tree &t)
{
    int numberNodes = numberNode();
    std::cout << numberNodes << std::endl;
    for (int i = 0; i < numberNodes; i++)
    {
        addTree(t, initNode(valueNode()));
    }
}

int main()
{
    Tree t;
    initTree(t);
    // addTree(t, initNode(30));
    // addTree(t, initNode(20));
    // addTree(t, initNode(10));
    // addTree(t, initNode(19));
    // addTree(t, initNode(21));
    // addTree(t, initNode(9));
    // addTree(t, initNode(11));
    srand(time(0));
    addTreeRandom(t);
    printTree(t);
    std::cout << std::endl;
    // std::cout << findValue(t, 9);
    // std::cout << findValue(t, 20);
    // std::cout << sumTree(t);
    // std::cout << accountLeaves(t);
    return 0;
}
