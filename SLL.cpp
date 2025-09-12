#include <iostream>
#include <vector>

// Step 1: Create a Node: data(int), pNext - next pointer with asterisk Node datatype (Node*)
struct Node
{
    int data;
    Node *pNext;
};

// step 2: Initialize a Node with value
Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    // the "->" operator is used instead of "." because p is a pointer to Node structure,
    // equivalent to dereferencint with (*p).data
    p->pNext = nullptr;
    return p;
}

// step 3: Create a List
struct List
{
    Node *pHead;
    Node *pTail;
};

// step 4: Initialize an empty List by setting pHead and pTail to nullptr
void initList(List &l)
{
    l.pHead = nullptr;
    // use "." operator because l is reference to a object
    l.pTail = nullptr;
}

// step 5.1: Add a new node to the head of linked list
void addHead(List &l, Node *p)
{
    // At the begin, pHead and pTail are nullptr so wherever adding is same
    if (l.pTail == nullptr)
    {
        // Labeling p to both pHead and pTail because of first node
        l.pHead = p;
        l.pTail = p;
    }
    else // if the list is not empty, insert a new node at the head
    {
        p->pNext = l.pHead; // link the new node to the current head
        l.pHead = p;        // update pHead to the new node
    }
}

// step 5.2: Add a new node to the tail of linked list
void addTail(List &l, Node *p)
{
    // it is the same as if clause of addHead function
    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        // Set pNext of current pTail is address of new node
        l.pTail->pNext = p;
        l.pTail = p; // update pTail to a new node
    }
}

// step 6.1: Print linked list to screen with for statement
void printList_For(List l)
{
    // Start: pHead
    // Step: p = p->pNext
    // Stop: p == nullptr
    for (Node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        //std::cout << p->data << " "; // warning: "std::"
        std::cout << p << " "; // warning: "std::"
    }
    std::cout << std::endl;
}

// step 6.2: Print linked list to screen with while statement
void printList_Wh(List l)
{
    // Start: pHead
    // Step: p = p->pNext
    // Stop: p == nullptr
    Node *p = l.pHead;
    while (p != nullptr)
    {
        std::cout << p->data << " ";
        p = p->pNext;
    }
    std::cout << std::endl;
}

// Task 1: Find second-last Node
void secondLastNode(List l)
{
    // Check an empty or have 1 Node
    if ((l.pHead == nullptr) || (l.pHead->pNext == nullptr))
    {
        std::cout << "Danh sach khong co Node ke cuoi";
    }
    // Find second-last node data
    else
    {
        for (Node *p = l.pHead; p != nullptr; p = p->pNext)
        {
            if (p->pNext == l.pTail)
            {
                std::cout << p->data;
            }
        }
        std::cout << std::endl;
    }
}

// Task 2: Find minium value Node
void minNode(List l)
{
    Node *minNode = l.pHead;
    for (Node *p = l.pHead->pNext; p != nullptr; p = p->pNext)
    {
        if (p->data < minNode->data)
            minNode = p;
    }
    std::cout << minNode->data << std::endl;
}

// Task 3: Add array to list
void addArrayToList(List &l, int *array, int soLuong)
{
    for (int i = 0; i < soLuong; i++)
    {
        addTail(l, initNode(*(array + i)));
    }
}

// Task 4: Remove pHead Node from the singly linked List
void removeHead(List &l)
{
    if (l.pHead == nullptr)
        return;         // if the list is empty, do nothing
    Node *p = l.pHead;  // store current pHead
    l.pHead = p->pNext; // update the pHead to second Node
    if (l.pHead == nullptr)
        l.pTail = nullptr; // if pHead become nullptr after deleting, update nullptr to pTail
    delete p;              // deallocate the old pHead
}

// Task 5: Remove pTail from the singly linked list
void removeTail(List &l)
{
    // if the list is empty, do nothing
    if (l.pHead == nullptr)
        return;
    // if the list have one Node
    if (l.pHead == l.pTail)
    {
        delete l.pHead; // delete both pTail and pHead
        l.pTail = l.pHead = nullptr;
        return;
    }
    Node *pCurrent = l.pHead;
    // if there are two Node more
    while (pCurrent->pNext != l.pTail)
    {
        pCurrent = pCurrent->pNext; // find second-last Node
    }
    delete l.pTail;
    l.pTail = pCurrent;
    l.pTail->pNext = nullptr;
}

// Task 6: Return a vector of pointers to all nodes in the singly linked list
std::vector<Node*> initNodeVT(List &l) // use reference to increase performance
{
    std::vector<Node *> dsNode; // initialize an empty vector to store Node Node* pointer
    Node* p = l.pHead; // start from head Node
    while (p != nullptr) // traverse the list
    {
        dsNode.push_back(p); // dsNode is Node* datatype so push_back (p) not p->data
        p = p->pNext;
    }
    return dsNode;
}


int main()
{
    List l;
    initList(l);
    addHead(l, initNode(8));
    addHead(l, initNode(7));
    addTail(l, initNode(9));
    addTail(l, initNode(10));
    // 7 8 9 10
    // removeHead(l);
    // removeTail(l);
    // printList_For(l);
    // printList_Wh(l);
    // secondLastNode(l);
    // minNode(l);
    // int Array[] = {1, 2, 3, 4, 5}, soLuong = 5;
    // addArrayToList(l, Array, soLuong);
    // printList_For(l);

    std::vector<Node *> dsNode = initNodeVT(l);
    int nodeNumber;
    std::cout << "Nhap so node can tim: ";
    std::cin >> nodeNumber;
    std::cout << dsNode[nodeNumber]->data;


    

    return 0;
}