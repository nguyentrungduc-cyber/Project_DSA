#include <iostream>
#include <iomanip>

struct SinhVien
{
    std::string maSV, hoTen, xepLoai;
    float diemTB;

    void NhapSV();
    void XuatSV();
};

void SinhVien::NhapSV()
{
    std::cout << "Nhap mssv: ";
    getline(std::cin, maSV);

    std::cout << "Nhap ho ten: ";
    getline(std::cin, hoTen);

    std::cout << "Nhap diem trung binh: ";
    std::cin >> diemTB;
    std::cin.ignore();

    std::cout << "Nhap xep loai: ";
    getline(std::cin, xepLoai);
}

void SinhVien::XuatSV()
{
    std::cout << "|" << std::setw(5) << maSV
              << "," << std::setw(25) << hoTen
              << "," << std::fixed << std::setprecision(1) << std::setw(7) << diemTB
              << "," << std::setw(10) << xepLoai << "|";
}

struct Node
{
    SinhVien data;
    Node *pNext;
};

Node *initNode(SinhVien sv)
{
    Node *p = new Node;
    p->data = sv;
    p->pNext = nullptr;
    return p;
}

struct List
{
    Node *pHead;
    Node *pTail;
};

void initList(List &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}

void addHead(List &l, Node *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addTail(List &l, Node *p)
{
    if (l.pTail == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void printList(List l)
{
    Node *p = l.pHead;
    while (p != nullptr)
    {
        p->data.XuatSV();
        std::cout << std::endl;
        p = p->pNext;
    }
}

void updateMark(List &l)
{
    for (Node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        if ((p->data.diemTB >= 9) && (p->data.diemTB <= 10))
        {
            p->data.xepLoai = "Xuat Sac";
        }
        else if ((p->data.diemTB >= 8) && (p->data.diemTB < 9))
        {
            p->data.xepLoai = "Gioi";
        }
        else if (((p->data.diemTB >= 7) && (p->data.diemTB < 8)))
        {
            p->data.xepLoai = "Kha";
        }
        else
        {
            p->data.xepLoai = "Ngu";
        }
    }
}

float printMaxMark(List l)
{
    float maxMark = l.pHead->data.diemTB;
    Node *p = l.pHead->pNext;
    while (p != nullptr)
    {
        if (maxMark < p->data.diemTB)
            maxMark = p->data.diemTB;
        p = p->pNext;
    }
    return maxMark;
}

void printStudent(List l)
{
    std::string maSVCanTim;
    std::cout << "Nhap mssv can tim: ";
    std::cin >> maSVCanTim;
    std::cin.ignore();
    Node *p = l.pHead;
    while (p != nullptr)
    {
        if (p->data.maSV == maSVCanTim)
        {
            p->data.XuatSV();
        }
        p = p->pNext;
    }
}

int main()
{
    SinhVien sv1 = {"01", "Nguyen Trung Duc", "NULL", 9.1};
    // sv1.NhapSV();

    SinhVien sv2 = {"02", "To Thi Anh Thi", "NULL", 10};
    // sv2.NhapSV();

    List l;
    initList(l);

    addHead(l, initNode(sv2));
    addHead(l, initNode(sv1));
    addTail(l, initNode({"03", "Luu Vo Tra My", "NULL", 8.5}));
    addTail(l, initNode({"04", "Nguyen Thi Thanh Nhan", "NULL", 7.3}));

    updateMark(l);

    // printList(l);
    std::cout<< "Diem TB cao nhat: " << printMaxMark(l);
    //printStudent(l);

    return 0;
}