
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string.h> 
#include <list>
#include <Windows.h>
#include "User.h"

using namespace std;

User::User()
{
	
}

void User::authenticateUser()
{
	char username[30],password[30];
	cout << "Enter your username" << endl;
	cin >> username;
	cout << "Enter your password" << endl;
	cin >> password;
	for (auto i : loginDetailsList)
	{
		if (!strcmp(i.username, username) && !strcmp(i.password, password))
		{
			initiateUser();
			break;
		}
		cout << "Invalid username or password!!!" << endl << "Renter the password" << endl;
		cin >> username >> password;
	}

}

void User::initiateUser()
{
	readUsers();
	readProcess();
	cout << "Enter the number of processor" << endl;
	cin >> CPUcount;
	cout << "Enter the number of process" << endl;
	cin >> processCount;
	CPUcount = min(CPUcount, processCount);
	addProcessByUser();
	bool flag = true;
	while (flag)
	{
		int readytoRuncount = CPUcount;
		for (int i = 0; i < processCount && readytoRuncount; i++)
		{
			if (!strcmp(readyToRun[i].status, yetToRun))
			{
				strcpy(readyToRun[i].status, running);
				readyToRun[i].completionCycles--;
				if (readyToRun[i].completionCycles == 0)
					strcpy(readyToRun[i].status, completed);
				readytoRuncount--;
			}
		}
		Sleep(1000);
		waitingTimeReduction();
		randomStatusAssignment();
		flag = processCompletionCheck();
	}


}

void User::addProcessByUser()
{
	processQueue temp;
	temp.waitingCount = 0;
	temp.cyclesCount = 0;
	strcpy(temp.status, yetToRun);

	for (int i = 0; i < processCount; i++)
	{
		showProcessList();
		int selection;
		cout << "Enter the process ID to be done" << endl;
		cin >> selection;
		if (selection > sizeofProcessList)
		{
			i--;
			cout << "Process ID does not exist" << endl;
			continue;
		}
		strcpy(temp.name, processList[selection - 1].name);
		temp.waitingCycles = processList[selection - 1].waitingCycles;
		temp.completionCycles = processList[selection - 1].completionCycles;
		readyToRun.push_back(temp);

	}
}

void User::waitingTimeReduction()
{
	for (int i = 0; i < processCount; i++)
		if (!strcmp(readyToRun[i].status, waiting))
			readyToRun[i].waitingCount--;
}

void User::randomStatusAssignment()
{
	int randInt;
	for (int i = 0; i < processCount; i++)
	{
		randInt = 1 + (rand() % 5);
		if (!strcmp(readyToRun[i].status,yetToRun) || !strcmp(readyToRun[i].status, running))
		{
			if (randInt == 1)
				strcpy(readyToRun[i].status, stopped);
			else if(randInt==2)
				strcpy(readyToRun[i].status, waiting);
			else
				strcpy(readyToRun[i].status, yetToRun);
		}
	}
}

bool User::processCompletionCheck()
{
	for (auto i : readyToRun)
		if (strcmp(i.status, completed))
			return true;
	return false;
}

void User::readUsers()
{
	LoginDetails login;
	FILE* fp;
	fp = fopen("UserDetail.txt", "rt");
	fread(&login, sizeof(LoginDetails), 1, fp);
	while (!feof(fp))
	{
		fread(&login, sizeof(LoginDetails), 1, fp);
		loginDetailsList.push_back(login);
	}
	sizeOfLoginList = loginDetailsList.size();
	fclose(fp);
}

void User::readProcess()
{
	FILE* fp = fopen("ProcessList.txt", "r");
	Process process;
	//fread(&process, sizeof(Process), 1, fp);
	//processList.push_back(process);
	while (!feof(fp))
	{
		
		fread(&process, sizeof(Process), 1, fp);
		processList.push_back(process);
	}
	fclose(fp);
	processList.erase(processList.begin() + 1);
	sizeofProcessList = processList.size();
}

void User::showProcessList()
{
	for (int i = 0; i < sizeofProcessList; i++)
		cout << i + 1 << "\t" << processList[i].name << endl;

}