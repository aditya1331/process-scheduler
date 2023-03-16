
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string.h> 
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