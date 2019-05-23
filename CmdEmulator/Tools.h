#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <fstream>

class Tools
{
public:
	Tools();

	void CreateProc(const char* CreateProcIn);

	~Tools();
};

