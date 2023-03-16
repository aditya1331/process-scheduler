
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Admin.h"
#include <vector>
#include "structures.h"

using namespace std;

Admin::Admin()
{
	readUsers();
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

void Admin::readUsers()
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

void Admin::printsUsers()
{
	int n = loginDetailsList.size();
	for (int i =0 ;i<n;i++)
		cout <<i+1<<"\t"<< loginDetailsList[i].username  << endl;	
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

void Admin::writeUsers() {
	FILE* fp = fopen("UserDetail.txt","wt");
	for (auto i : loginDetailsList)
		fwrite(&i, sizeof(LoginDetails), 1, fp);
	printsUsers();

}

void Admin::initiateAdminProcess()
{
	deleteuser();
}