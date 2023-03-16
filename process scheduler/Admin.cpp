
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Admin.h"
#include <vector>
#include "structures.h"

using namespace std;

Admin::Admin()
{
	readUsers();
	readProcess();
	
}

void Admin::initiateAdminProcess()
{
	bool flag = true;
	while (flag)
	{		
		switch (printAdminOptions())
		{
		case 1: createUser(); break;
		case 2: deleteuser(); break;
		case 3: createProcess(); break;
		case 4: deleteProcess(); break;
		default : flag = false; break;
		}
	}
}

int Admin::printAdminOptions()
{
	int adminInput;
	cout << "Press 1 to create the user" << endl;
	cout << "Press 2 to delete the user" << endl;
	cout << "Press 3 to create a process" << endl;
	cout << "Press 4 to delete a process" << endl;
	cout << "Press 5 to clear all process" << endl;
	cout << "Press 0 to exit" << endl;
	cin >> adminInput;
	return adminInput;

}

void Admin::createUser()
{
	FILE* fp;
	fp = fopen("UserDetail.txt", "a");
	cout << "Enter the user name of the user\n";
	LoginDetails LD ;
	cin >> LD.username;
	cout << "Enter the password of the user\n";
	cin >> LD.password;	
	fwrite(&LD, sizeof(LoginDetails), 1, fp);
	fclose(fp);

}

void Admin::printsUsers()
{
	int n = loginDetailsList.size();
	for (int i =0 ;i<n;i++)
		cout <<i+1<<"\t"<< loginDetailsList[i].username  << endl;	
}

void Admin::writeUsers() {
	FILE* fp = fopen("UserDetail.txt", "wt");
	for (auto i : loginDetailsList)
		fwrite(&i, sizeof(LoginDetails), 1, fp);
	printsUsers();

}

void Admin::deleteuser()
{
	int n;
	cout << "Enter the use ID to delete the user\n";
	while (true)
	{
		printsUsers();		
		cin >> n;
		if (n <= sizeOfLoginList)
			break;		
		cout << "User Id not in the list!! Renter the ID properly\n";
	}
	cout << "User " << n << " deleted successfully\n";
	loginDetailsList.erase(loginDetailsList.begin() + n - 1);
	writeUsers();
}

void Admin::clearAllUsers()
{
	FILE* fp = fopen("UserDetail.txt", "wt");
	fclose(fp);
	loginDetailsList.clear();
	sizeOfLoginList = 0;

}

void Admin::createProcess()
{
	Process process;	
	cout << "Enter the name of the process\n";
	cin >> process.name;
	char ch = getchar();
	cout << "Enter the time cycles required to complete the process" << endl;
	cin >> process.completionCycles;
	cout << "Enter the waiting cycles of the process" << endl;
	cin >> process.waitingCycles;
	processList.push_back(process);
	sizeofProcessList = processList.size();
	writeProcess();

}



void Admin::writeProcess()
{
	FILE* fp;
	fp = fopen("ProcessList.txt", "wt");
	for (auto i : processList)
		fwrite(&i, sizeof(Process), 1, fp);
	fclose(fp);
}



void Admin::deleteProcess()
{
	int input;
	cout << "Enter the process Id to be deleted" << endl;
	while (true)
	{
		showProcessList();
		cin >> input;
		if (input <= sizeofProcessList)
			break;
		cout << "Process Id not in the list!! Renter the ID properly"<<endl;
	}
	processList.erase(processList.begin() + input - 1);
	sizeofProcessList = processList.size();

}

void Admin::clearAllProcess()
{
	FILE* fp;
	fp = fopen("ProcessList.txt", "wt");
	fclose(fp);
	processList.clear();
}