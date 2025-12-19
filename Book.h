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

    // Queue (Waiting List)
    struct QNode {
        int data;
        QNode* next;
    };
    QNode* qFront;
    QNode* qRear;

    // Stack (Undo System)
    struct SNode {
        string data;
        SNode* next;
    };
    SNode* top;

    // Helper methods for Queue
    void enqueue(int val);
    void dequeue();
    bool isQueueEmpty();

    // Helper methods for Stack
    void push(string val);
    void pop();
    bool isStackEmpty();

    // Internal Helpers
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
