#include <iostream>

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

void printStack(Stack a, Stack b, Stack c)
{
    std::cout << "Stack A: \n";
    for (Node *p = a.pTop; p != nullptr; p = p->pNext)
    {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;

    std::cout << "\nStack B: \n";
    for (Node *p = b.pTop; p != nullptr; p = p->pNext)
    {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;

    std::cout << "\nStack C: \n";
    for (Node *p = c.pTop; p != nullptr; p = p->pNext)
    {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}

void Pop(Stack &s, int &value)
{
    if (s.pTop == nullptr)
        return;
    Node *p = s.pTop;
    s.pTop = s.pTop->pNext;
    value = p->data;
    delete p;
}

void Pop(Stack &s)
{
    if (s.pTop == nullptr)
        return;
    Node *p = s.pTop;
    s.pTop = s.pTop->pNext;
    delete p;
}
// Hien tai chi kiem tra, khong chinh sua nhung sau nay thi sao
bool conditionGame(Stack &before, Stack &after) // Tang hieu suat vi lam truc tiep thay vi sao chep
{
    // Kiem tra Stack ban dau co gia tri de Pop
    if (before.pTop == nullptr)
        return false; // Tra ve false neu Stack rong

    // Kiem tra Stack sau co rong khong, vi so sanh gia tri pTop, neu khong se crash
    if (after.pTop == nullptr)
        return true; // Du Stack rong nhung la noi de Push, khong nhat thiet phai co Node

    // Neu STack ban dau va sau deu co Node thi so sanh GIA TRI pTop
    return (before.pTop->data < after.pTop->data);
}

void defaultGame(Stack &s)
{
    Push(s, initNode(3));
    Push(s, initNode(2));
    Push(s, initNode(1));
}

bool endGame(Stack c)
{
    int checkPoint = 1;
    for (Node *pCurrent = c.pTop; pCurrent != nullptr; pCurrent = pCurrent->pNext)
    {
        if (pCurrent->data != checkPoint)
            return false; // sai la dung luon, khong tang checkPoint
        checkPoint++;
    }
    return (checkPoint == 4);
}

void changeTop(Stack &before, Stack &after)
{
    int value;
    Pop(before, value);
    Push(after, initNode(value));
}

void gameStart(Stack &a, Stack &b, Stack &c)
{
    defaultGame(a);
    printStack(a, b, c);
    while ((endGame(c) == false))
    {
        int optionGame;
        std::cout << "Nhap su lua chon cua ban: ";
        std::cin >> optionGame;
        switch (optionGame)
        {
        case 0:
        {
            // a -> b
            if (conditionGame(a, b))
            {
                changeTop(a, b);
                printStack(a, b, c);
                break;
            }
            else
            {
                std::cout << "Vi pham dieu khien!\n";
                break;
            }
        }
        case 1:
        {
            // b -> a
            if (conditionGame(b, a))
            {
                changeTop(b, a);
                printStack(a, b, c);
                break;
            }
            else
            {
                std::cout << "Vi pham dieu khien!\n";
                break;
            }
        }
        case 2:
        {
            // b -> c
            if (conditionGame(b, c))
            {
                changeTop(b, c);
                printStack(a, b, c);
                break;
            }
            else
            {
                std::cout << "Vi pham dieu khien!\n";
                break;
            }
        }
        case 3:
        {
            // c -> b
            if (conditionGame(c, b))
            {
                changeTop(c, b);
                printStack(a, b, c);
                break;
            }
            else
            {
                std::cout << "Vi pham dieu khien!\n";
                break;
            }
        }
        case 4:
        {
            // a -> c
            if (conditionGame(a, c))
            {
                changeTop(a, c);
                printStack(a, b, c);
                break;
            }
            else
            {
                std::cout << "Vi pham dieu khien!\n";
                break;
            }
        }
        case 5:
        {
            // c -> a
            if (conditionGame(c, a))
            {
                changeTop(c, a);
                printStack(a, b, c);
                break;
            }
            else
            {
                std::cout << "Vi pham dieu khien!\n";
                break;
            }
        }
        default:
        {
            std::cout << "Ban da nhap sai lua chon! Moi nhap lai (0 - 5)\n";
        }
        }
        if (endGame(c))
            std::cout << "Chuc mung ban da pha dao game!";
    }
}

int main()
{
    Stack a;
    initStack(a);

    Stack b;
    initStack(b);

    Stack c;
    initStack(c);

    gameStart(a, b, c);

    return 0;
}