#include "Member.h"

Members::Members() {
    head = NULL;
}

bool Members::isMemberIdExists(int id) {
    Member* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void Members::addMember() {
    int id;
    string password;

    while (true) {
        cout << "Enter Member ID: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Numbers only." << endl;
            continue;
        }

        if (isMemberIdExists(id)) {
            cout << "Member ID already exists, try again" << endl;
        } else {
            break;
        }
    }

    cout << "Enter Password: ";
    cin >> password;

    Member* member = new Member;
    member->id = id;
    member->password = password;
    member->next = head;
    head = member;

    cout << "Member Added Successfully" << endl;
}

bool Members::login() {
    int id;
    string pass;

    cout << "Enter Member ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> pass;

    Member* temp = head;
    while (temp != NULL) {
        if (temp->id == id && temp->password == pass) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
