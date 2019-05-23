#include "Tools.h"



Tools::Tools()
{

}

void Tools::CreateProc(const char* CreateProcIn)
{
	// Not using the below in func params because it would be so hecking long.

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


	if (bCreateProcess)
	{
		std::cout << "Create Process suceeded" << std::endl;

		std::cout << "Proc ID      : " << procinfo.dwThreadId << std::endl;
		std::cout << "Thread Id    : " << procinfo.dwProcessId << std::endl;

		std::cout << "GetProcessID : " << GetProcessId(procinfo.hProcess) << std::endl;
		std::cout << "GetThreadID  : " << GetProcessId(procinfo.hThread) << std::endl;

	}

	else
	{
		std::cout << "Create Proc Failed " << GetLastError() << std::endl;
	}

	//WaitForSingleObject(procinfo.hProcess, INFINITE);

	CloseHandle(procinfo.hProcess);
	CloseHandle(procinfo.hThread);

}


Tools::~Tools()
{
}
