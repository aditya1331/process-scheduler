#pragma once
#include<iostream>
#include<vector>
#include "structures.h"
using namespace std;
class User
{private:

	
protected:
	vector<LoginDetails> loginDetailsList;
	int sizeOfLoginList;
	vector<Process> processList;
	int sizeofProcessList;

	void readUsers();
	void showProcessList();
	void readProcess();
	

public:	
	User();
	void authenticateUser();
	void initiateUser();

};

