#pragma once
#include <Windows.h>
#include <winternl.h>
#include <iostream>

// lets make this function accessible to other source files
HMODULE hLdrLoadDll(LPWSTR DllName);