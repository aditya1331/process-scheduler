
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <conio.h>
#include <string.h> 
#include <list>
#include <Windows.h>
#include "User.h"

using namespace std;

User::User()
{
	CPUcount = 0;
}

void User::authenticateUser()
{
	readUsers();
	readProcess();
	char username[30],password[30];
	cout << "Enter your username" << endl;
	cin >> username;
	cout << "Enter your password" << endl;
	cin >> password;
	bool flag = true;
	while (flag) {
		for (auto i : loginDetailsList)
		{
			if (!strcmp(i.username, username) && !strcmp(i.password, password))
			{
				initiateUser();
				break;
			}			
		}
		cout << "Invalid username or password!!!" << endl << "Renter the password" << endl;
		
		cin >> username;
		cin >> password;

	}

}

void User::initiateUser()
{
	readUsers();
	readProcess();  //To be removed after testing
	cout << "Enter the number of processor" << endl;
	cin >> CPUcount;
	cout << "Enter the number of process" << endl;
	cin >> processCount;
	addProcessByUser();
	bool flag = true;
	while (flag)
	{
		int readytoRuncount = CPUcount;
		for (int i = 0; i < processCount && readytoRuncount; i++)
		{
			cout << readyToRun[i].name << " " << readyToRun[i].status << endl;
			if (!strcmp(readyToRun[i].status, yetToRun))
			{
				cout << endl<<readyToRun[i].name<<endl<<endl;
				strcpy(readyToRun[i].status, running);
				readyToRun[i].completionCycles--;
				if (readyToRun[i].completionCycles == 0)
				{
					strcpy(readyToRun[i].status, completed);
					cout << readyToRun[i].name << " completed" << endl;
				}
				readytoRuncount--;
			}
		}
		Sleep(1000);
		waitingTimeReduction();
		randomStatusAssignment();
		if (_kbhit()) {
			char ch[1];
			cin >> ch;
			if (!strcmp(ch,"s"))
				restartProcess();
		}
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
	cout << "Process selected are :" << endl;
	for (auto i : readyToRun)
		cout << i.name << endl;
	cout << endl;
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
		randInt = 1 + (rand() % 10);
		if (!strcmp(readyToRun[i].status,yetToRun) || !strcmp(readyToRun[i].status, running))		
			switch (randInt)
			{
			case 1: strcpy(readyToRun[i].status, stopped);cout << randInt << " " << readyToRun[i].name << endl; break;
			case 2: strcpy(readyToRun[i].status, waiting);break;
			default: strcpy(readyToRun[i].status, yetToRun);break;
			}	
	}
}

void User::restartProcess()
{
	cout << "Press 1 to start the process and 0 to skip for now" << endl;
	for(int i =0;i<processCount;i++)
		if (!strcmp(readyToRun[i].status, stopped))
		{
			cout << readyToRun[i].name << " stopped "<< readyToRun[i].completionCycles << endl;
			int input;
			cin >> input;
			if (input)
				strcpy(readyToRun[i].status, yetToRun);
			cout << readyToRun[i].name<< " Status changed to " << readyToRun[i].status << endl;
			
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
	fp = fopen("UserDetail.txt", "r");
	//fread(&login, sizeof(LoginDetails), 1, fp);
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