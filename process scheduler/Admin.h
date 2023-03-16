#pragma once
#include<iostream>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#include "structures.h"
using namespace std;

class Admin
{
	void createUser();
	void printsUsers();
	void deleteuser();
	void readUsers();
	void writeUsers();
	vector<LoginDetails> loginDetailsList;
	int sizeOfLoginList;
public:
	void initiateAdminProcess();
	Admin();


};

