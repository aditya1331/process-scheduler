#pragma once
#include<iostream>
#include <list>
#include<vector>
#include "structures.h"

using namespace std;


class User
{protected:
	list<processQueue> readyToRun;
	list<processQueue> runningProcesses;
	list<processQueue> waitingProcesses;
	list<processQueue> completedProcesses;
	list<processQueue> stoppedProcesses;
		
	vector<LoginDetails> loginDetailsList;
	int sizeOfLoginList;
	vector<Process> processList;
	int sizeofProcessList;

	void addProcessByUser(int);
	void readUsers();
	void showProcessList();
	void readProcess();
	

public:	
	User();
	void authenticateUser();
	void initiateUser();

};

