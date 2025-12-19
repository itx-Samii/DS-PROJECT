#include "Book.h"

Books::Books() {
    head = NULL;
    root = NULL;
    qFront = NULL;
    qRear = NULL;
    top = NULL;
}

// ================= QUEUE (WAITING LIST) =================

void Books::enqueue(int val) {
    QNode* temp = new QNode;
    temp->data = val;
    temp->next = NULL;

    if (qRear == NULL) {
        qFront = qRear = temp;
    } else {
        qRear->next = temp;
        qRear = temp;
    }
}

void Books::dequeue() {
    if (qFront == NULL) {
        return;
    }

    QNode* temp = qFront;
    qFront = qFront->next;

    if (qFront == NULL) {
        qRear = NULL;
    }

    delete temp;
}

bool Books::isQueueEmpty() {
    return qFront == NULL;
}

// ================= STACK (UNDO SYSTEM) =================

void Books::push(string val) {
    SNode* temp = new SNode;
    temp->data = val;
    temp->next = top;
    top = temp;
}

void Books::pop() {
    if (top == NULL) {
        return;
    }

    SNode* temp = top;
    top = top->next;
    delete temp;
}

bool Books::isStackEmpty() {
    return top == NULL;
}

// ================= BOOK MANAGEMENT =================

bool Books::isBookListEmpty() {
    return head == NULL;
}

bool Books::isBookIdExists(int id) {
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void Books::insertBST(int id) {
    BSTNode* newNode = new BSTNode;
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        BSTNode* temp = root;
        BSTNode* parent = NULL;

        while (temp != NULL) {
            parent = temp;
            if (id < temp->id) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        if (id < parent->id) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}

bool Books::searchBST(int id) {
    BSTNode* temp = root;
    while (temp != NULL) {
        if (temp->id == id) {
            return true;
        }
        if (id < temp->id) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}

Book* Books::findBook(int id) {
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void Books::addBook() {
    int id;
    string name;

    while (true) {
        cout << "Enter Book ID: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Numbers only." << endl;
            continue;
        }

        if (isBookIdExists(id)) {
            cout << "Book ID already exists, try again" << endl;
        } else {
            break;
        }
    }

    cout << "Enter Book Name: ";
    cin.ignore();
    getline(cin, name);

    Book* book = new Book;
    book->id = id;
    book->name = name;
    book->issued = false;
    book->next = NULL;
    if (head == NULL) {
        head = book;
    } else {
        Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = book;
    }

    insertBST(id);

    cout << "Book Added Successfully" << endl;
}



void Books::showBooks() {
    if (isBookListEmpty()) {
        cout << "No books in list. Add book first." << endl;
        return;
    }

    Book* temp = head;
    while (temp != NULL) {
        cout << temp->id << " - " << temp->name;
        if (temp->issued) {
            cout << " (Issued)" << endl;
        } else {
            cout << " (Available)" << endl;
        }
        temp = temp->next;
    }
}

void Books::issueBook() {
    if (isBookListEmpty()) {
        cout << "No books in list. Add book first." << endl;
        return;
    }

    int id;
    cout << "Enter Book ID to Borrow: ";
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input." << endl;
        return;
    }

    Book* book = findBook(id);

    if (book != NULL) {
        if (!book->issued) {
            book->issued = true;
            push("ISSUE");
            cout << "Book Borrowed Successfully" << endl;
        } else {
            enqueue(id);
            cout << "Book Already Issued, Added to Waiting Queue" << endl;
        }
    } else {
        cout << "Book Not Found" << endl;
    }
}

void Books::returnBook() {
    if (isBookListEmpty()) {
        cout << "No books in list. Add book first." << endl;
        return;
    }

    int id;
    cout << "Enter Book ID to Return: ";
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input." << endl;
        return;
    }

    Book* book = findBook(id);

    if (book != NULL && book->issued) {
        book->issued = false;
        push("RETURN");
        cout << "Book Returned Successfully" << endl;

        if (!isQueueEmpty()) {
            dequeue();
            book->issued = true;
        }
    } else {
        cout << "Invalid Return" << endl;
    }
}

void Books::undoAction() {
    if (isStackEmpty()) {
        cout << "Nothing to Undo" << endl;
    } else {
        cout << "Undo Last Action: " << top->data << endl;
        pop();
    }
}
