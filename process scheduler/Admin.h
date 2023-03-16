#pragma once
#include<iostream>
#include "User.h"
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#include "structures.h"
using namespace std;

class Admin:private User{
private:	 

	void adminAutheniticate();
	int printAdminOptions();


	void createUser();
	void printsUsers();
	void deleteuser();
	void writeUsers();
	void clearAllUsers();
	
	void createProcess();

	void writeProcess();
	
	void deleteProcess();
	void clearAllProcess();
public:
	void initiateAdminProcess();
	Admin();


};

