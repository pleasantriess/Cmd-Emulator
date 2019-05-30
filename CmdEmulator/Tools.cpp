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


	// cd to users folder and not the location of the exe
	// need to add some sort of hash to obfuscate the commands / info while exe is running
	// cls
}


void Tools::AddCommand() {
	std::ofstream out;

	out.open("asd.txt");

	out << "first number : " << 5 << std::endl;

	out.close();

}

void Tools::AddCommand(std::string str, int num) 
{
}

void Tools::RemoveCommand() {
	std::ifstream in;
	in.open("lst.txt");

	if (in.fail()) {
		std::cerr << "Error Opening File" << std::endl;
		exit(1);
	}

	int x, y;

	in >> x >> y;

	std::cout << x << " " << y;

	/*

	while(!in.eof())
	{
	in >> item; // item being a string
	}
	*/

}

//void Tools::BootMessage() { // add this to boot exec command eventually
//
//	TCHAR username[UNLEN + 1];
//	DWORD size = UNLEN + 1;
//	GetUserNameA((TCHAR*)username, &size);
//
//	std::cout << "Welcome to the cmd emulator, " << username << "! The terminal perfect for using at school or work!" << std::endl;
//	
//}


/*

char username[UNLEN+1];
DWORD username_len = UNLEN+1;
GetUserName(username, &username_len);

TCHAR username[UNLEN + 1];
DWORD size = UNLEN + 1;
GetUserName((TCHAR*)username, &size);

*/

void Tools::DownloadChoco(std::string sUserDir) // ask username (or get it) then ask what editor they want
{
	system("");


	
		SET INSTALLDIR = c:\Users\scottbanister\Desktop\chocoins
		setx ChocolateyInstall % INSTALLDIR %

		@powershell - NoProfile - ExecutionPolicy Bypass - Command "(iex ((new-object net.webclient).DownloadString('https://chocolatey.org/install.ps1'))) >$null 2>&1" && SET PATH = "%PATH%;%INSTALLDIR%\bin"

		CALL choco install puppet - agent.portable - y
		CALL choco install ruby.portable - y
		CALL choco install git.commandline - y

		::CALL choco install visualstudiocode.portable - y::Not available yet
		::CALL choco install notepadplusplus.commandline - y
		::CALL choco install nano - y
		::CALL choco install vim - tux.portable


}

void Tools::emulateCMD(std::string sCommand) {
	const char* command = sCommand.c_str(); // Converting the inputted string into a const char *

	system(command);
}

Tools::~Tools()
{
}

