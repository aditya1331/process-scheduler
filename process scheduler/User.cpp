
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
	readUsers();
	readProcess();
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
	int CPUcount,processCount;
	cout << "Enter the number of processor" << endl;
	cin >> CPUcount;
	cout << "Enter the number of process" << endl;
	cin >> processCount;
	addProcessByUser(processCount);
	while (!readyToRun.empty() && !stoppedProcesses.empty())
	{

	}
	

}

void User::addProcessByUser(int processCount)
{
	processQueue temp;
	temp.waitingCount = 0;
	temp.cyclesCount = 0;

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
	FILE* fp = fopen("ProcessList.txt", "rt");
	Process process;
	fread(&process, sizeof(Process), 1, fp);
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