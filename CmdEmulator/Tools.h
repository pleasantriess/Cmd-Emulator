#pragma once
#include <Windows.h>

class Tools
{
public:
	Tools();

	void CreateProc(LPCSTR CreateProcIn);

	void BootExec(); // Create and execute commands on cmd launch

	//void AddCommand(std::string str, int num);
	//void AddCommand();

	//void RemoveCommand();

	//void BootMessage();

	void InstallChocolatey(std::string sUserDir, int choice);

	void emulateCMD(std::string sCommand);

	~Tools();
};
