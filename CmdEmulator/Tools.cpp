#pragma once
#include "includes.h"


Tools::Tools()
{

}

void Tools::CreateProc(LPCSTR CreateProcIn) { // Use for "start" command

	HANDLE hProcess; // Handling hProcess
	HANDLE hThread;  // Handling hThread

	PROCESS_INFORMATION procinfo;

	STARTUPINFO startup;

	DWORD dwProcessId;
	DWORD dwThreadID;

	ZeroMemory(&procinfo, sizeof(procinfo)); // Setting the memory location of procinfo to NULL
	ZeroMemory(&startup, sizeof(startup));  // Setting the memory location of startup  to NULL

	BOOL bCreateProcess = false;

	// Chances are, we will not need to modify the below (all of the NULLs), but if we do, we can just overload :)
	bCreateProcess = CreateProcess(CreateProcIn, nullptr, nullptr, nullptr, NULL, NULL, nullptr, nullptr, &startup, &procinfo);


	if (bCreateProcess) {
		std::cout << "Create Process suceeded" << std::endl;

		std::cout << "Proc ID      : " << procinfo.dwThreadId << std::endl;
		std::cout << "Thread Id    : " << procinfo.dwProcessId << std::endl;

		std::cout << "GetProcessID : " << GetProcessId(procinfo.hProcess) << std::endl;
		std::cout << "GetThreadID  : " << GetProcessId(procinfo.hThread) << std::endl;

	}
	else {
		std::cout << "Create Proc Failed " << GetLastError() << std::endl;
	}

	//WaitForSingleObject(procinfo.hProcess, INFINITE);

	CloseHandle(procinfo.hProcess);
	CloseHandle(procinfo.hThread);

}

void Tools::BootExec()
{
	// Mandatory boot cmds

	system("cd C:\\Users");
	system("cls");

	//---------------------
}


void Tools::InstallChocolatey(std::string sUserDir, int choice) // ask username (or get it) then ask what editor they want
{
	int iErrorCheck = 0;

	system("SET INSTALLDIR = c:\\Users\\scottbanister\\Desktop\\chocoins");
	system("setx ChocolateyInstall % INSTALLDIR %");
	system("@powershell - NoProfile - ExecutionPolicy Bypass - Command \"(iex((new - object net.webclient).DownloadString('https://chocolatey.org/install.ps1'))) > $null 2 > & 1\" && SET PATH = \" % PATH%; % INSTALLDIR % \bin\"");
	system("CALL choco install puppet - agent.portable - y");
	system("CALL choco install ruby.portable - y");
	system("CALL choco install git.commandline - y");
	system("CALL choco install notepadplusplus.commandline - y");

	do {
		if (iErrorCheck < 0) {
			std::cout << "please enter an integer\n\n" << std::endl;
		}

		std::cout << "What text editor would you like to install? \n" << std::endl;
		std::cout << "1: nano" << std::endl;
		std::cout << "2: vim " << std::endl;
		//std::cout << "3: vs code " << std::endl;
		std::cout << "3	: all of them" << std::endl;

		std::cin >> choice; // need to error check

		iErrorCheck++;
	} while (isalpha(choice));

	iErrorCheck = 0;

do {
	switch (choice)
	{
		case 1:
			system("CALL choco install nano - y");
			break;
		case 2:
			system("CALL choco install vim - tux.portable");
			break;
		case 3:
			system("CALL choco install visualstudiocode.portable - y");
			system("CALL choco install vim - tux.portable");
			system("CALL choco install nano - y");
			break;
		default:
			std::cout << "You literally failed to enter a number within the range. smh.\n I guess I'll just install all of them for you :P" << std::endl;
			system("CALL choco install visualstudiocode.portable - y");
			system("CALL choco install vim - tux.portable");
			system("CALL choco install nano - y");
			break;
	}
} while(iErrorCheck >= 0);


		//::CALL choco install visualstudiocode.portable - y


}

void Tools::emulateCMD(std::string sCommand) {
	const char* command = sCommand.c_str(); // Converting the inputted string into a const char *

	system(command);
}

TCHAR GetUsername()
{
	TCHAR username[UNLEN + 1];
	DWORD size = UNLEN + 1; // Getting size of the username + 1 (for esc character)

	GetUserNameA((TCHAR*)username, &size); // Getting logged in user

	return username;
}

Tools::~Tools()
{
}
