// process scheduler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Admin.h"
#include "User.h"
using namespace std;

int main()
{
    Admin* admin = new Admin;
    User* user = new User;
    admin->initiateAdminProcess();
    bool flag = true;
    /*while (flag)
    {
        cout << "Press 1 to login as Admin" << endl;
        cout << "Press 2 to login as User" << endl;
        cout << "Press 0 to quit" << endl;
        int input;
        cin >> input;
        switch (input)
        {
        case 1:
        case 2:user->authenticateUser();break;
        case 3:flag = false; break;
        }
    }*/

}
