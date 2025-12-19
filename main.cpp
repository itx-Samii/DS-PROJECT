#include <iostream>
#include "Book.h"
#include "Member.h"

using namespace std;

int main() {
    Books books;
    Members members;

    int choice;

    do {
        cout << "Main Menu" <<endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Member Login" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Numbers only." << endl;
            continue;
        }

        if (choice == 1) {
            string user, pass;
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;

            if (user == "admin" && pass == "123") {
                int adminChoice;

                do {
                    cout << "Admin Menu" <<endl;
                    cout << "1. Show Books" << endl;
                    cout << "2. Add Book" << endl;
                    cout << "3. Issue Book" << endl;
                    cout << "4. Return Book" << endl;
                    cout << "5. Undo Action" << endl;
                    cout << "6. Add Member" << endl;
                    cout << "0. Logout" << endl;
                    cout << "Choice: ";
                    cin >> adminChoice;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input." << endl;
                        continue;
                    }

                    if (adminChoice == 1) books.showBooks();
                    else if (adminChoice == 2) books.addBook();
                    else if (adminChoice == 3) books.issueBook();
                    else if (adminChoice == 4) books.returnBook();
                    else if (adminChoice == 5) books.undoAction();
                    else if (adminChoice == 6) members.addMember();
                    else if (adminChoice != 0) cout << "Invalid choice" << endl;

                } while (adminChoice != 0);
            } else {
                cout << "Invalid Admin Credentials" << endl;
            }
        }
        else if (choice == 2) {
            if (members.login()) {
                int memberChoice;
                do {
                    cout << "Member Menu"<<endl;
                    cout << "1. Show Books" << endl;
                    cout << "2. Borrow Book" << endl;
                    cout << "3. Return Book" << endl;
                    cout << "0. Logout" << endl;
                    cout << "Choice: ";
                    cin >> memberChoice;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input." << endl;
                        continue;
                    }

                    if (memberChoice == 1) books.showBooks();
                    else if (memberChoice == 2) books.issueBook();
                    else if (memberChoice == 3) books.returnBook();
                    else if (memberChoice != 0) cout << "Invalid choice" << endl;

                } while (memberChoice != 0);
            } else {
                cout << "Invalid Member Login" << endl;
            }
        }
        else if (choice != 0) {
            cout << "Invalid choice" << endl;
        }

    } while (choice != 0);

    cout << "Goodbye" << endl;
    return 0;
}

