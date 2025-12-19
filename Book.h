#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

struct Book {
    int id;
    string name;
    bool issued;
    Book* next;
};

struct BSTNode {
    int id;
    BSTNode* left;
    BSTNode* right;
};

class Books {
private:
    Book* head;
    BSTNode* root;

    struct QNode {
        int data;
        QNode* next;
    };
    QNode* qFront;
    QNode* qRear;

    struct SNode {
        string data;
        SNode* next;
    };
    SNode* top;

    void enqueue(int val);
    void dequeue();
    bool isQueueEmpty();

    void push(string val);
    void pop();
    bool isStackEmpty();

    bool isBookIdExists(int id);
    void insertBST(int id);
    bool searchBST(int id);
    Book* findBook(int id);

public:
    Books();
    bool isBookListEmpty();
    void addBook();
    void showBooks();
    void issueBook();
    void returnBook();
    void undoAction();
};

#endif
