#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;  
    return p;
}

Node *insertNode(Node *p, int x) {
    if (p == NULL) {
        Node *temp = createNode(x);
        return temp;
    }
    else {
        if (x < p->data)
            p->left = insertNode(p->left,x);
        else 
            p->right = insertNode(p->right,x);
    }
    return t;
} 

/* 1. Tạo cây nhị phân tìm kiếm từ tập tin data.txt */

void readData(Node *&p) {
    int n,x;
    ifstream data;
    data.open("data.txt");
    data >> n;
    for (int i=0; i<n; i++) {
        data >> x;
        p = insertNode(p,x);
    }
    data.close();
}

/* 2.Đếm số node có giá trị khoá > x và < y trong cây đã tạo. */
int countNode(Node *p, int x, int y) {
    if (p == NULL)
        return 0;
    if (p->data > x && p->data < y)
        return 1 + countNode(p->left,x,y) + countNode(p->right,x,y);
    else 
        return 0 + countNode(p->left,x,y) + countNode(p->right,x,y);
}

/* 3.Tìm phần tử trái nhất của phần tử chứa node t trong cây. */

Node *searchNode(Node *p, int t) {
    if (p->data == t || p == NULL)
        return p;
    if (t < p->data)
        return searchNode(p->left,t);
    else 
        return searchNode(p->right,t);
}
  
Node *searchLeft(Node *p) {
    if (p->left == NULL)
        return p;
    else return searchLeft(p->left);
}

/* 4.Tìm số nguyên tố nhỏ nhất trên cây. */
bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int i=2; i*i<=x; i++)
        if (x%i==0)
            return false;
    return true;
}

void findPrime(Node *p, int a[]) {
    if (p == NULL)
        return ;
    if (isPrime(p->data) == 1) {
        a[p->data] ++;
    }
    findPrime(p->left,a);
    findPrime(p->right,a);
}

/* 5. Viết hàm Tìm z xem có trong cây hay không? (trả về 1 nếu tìm thấy, 0 nếu không tìm thấy) */
bool isFound(Node *p, int z) {
    if (p == NULL) 
        return false;
    if (p->data == z)
        return true;
    else if (z < p->data)
        return isFound(p->left,z);
    else 
        return isFound(p->right,z);
}

/* 6. In cây sao cho nhận được một mảng giảm dần */
void printTree(Node *p,ofstream &output) {
    if (p!=NULL) {
        printTree(p->right,output);
        output << p->data << " ";
        printTree(p->left,output);
    }
}
