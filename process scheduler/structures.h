#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef struct LoginDetail {
public:
	char username[30];
	char password[30];
}LoginDetails;

typedef struct process {
	char name[30];
	int waitingCycles;
	int completionCycles;
}Process;

class structures
{
};

