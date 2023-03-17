#pragma once
#include<iostream>
#include <list>
#include<vector>
#include "structures.h"

using namespace std;


class User
{protected:
	vector<processQueue> readyToRun;
	vector<LoginDetails> loginDetailsList;
	int sizeOfLoginList;
	vector<Process> processList;
	int CPUcount;
	int processCount;
	int sizeofProcessList;
	const char* yetToRun = "Ready to Run";
	const char* stopped = "Stopped";
	const char* waiting = "Waiting";
	const char* running  = "Running";
	const char* completed = "Completed";

	void addProcessByUser();
	void readUsers();
	void waitingTimeReduction();
	void randomStatusAssignment();
	void restartProcess();
	bool processCompletionCheck();
	void showProcessList();
	void readProcess();
	

public:	
	User();
	void authenticateUser();
	void initiateUser();

};

