#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

using namespace std;

struct Member {
    int id;
    string password;
    Member* next;
};

class Members {
private:
    Member* head;

    bool isMemberIdExists(int id);

public:
    Members();
    void addMember();
    bool login();
};

#endif
