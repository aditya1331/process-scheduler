#pragma once
#include<iostream>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#include "structures.h"
using namespace std;

class Admin
{
private:
	vector<LoginDetails> loginDetailsList;
	int sizeOfLoginList;
	vector<Process> processList;
	int sizeofProcessList;
	
	int printAdminOptions();

	void createUser();
	void printsUsers();
	void deleteuser();
	void readUsers();
	void writeUsers();
	void clearAllUsers();
	
	void createProcess();
	void readProcess();
	void writeProcess();
	void showProcessList();
	void deleteProcess();
	void clearAllProcess();
public:
	void initiateAdminProcess();
	Admin();


};

