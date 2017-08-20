#include "header.h"

// definition for LdrLoadDll
typedef NTSTATUS(NTAPI *pLdrLoadDll)(PWSTR SearchPath OPTIONAL, PULONG LoadFlags OPTIONAL, PUNICODE_STRING ModuleName, HMODULE *pvBaseAddress OPTIONAL);

// This function will be responsible for loading the DLL via LdrLoadDll and will return the HMODULE if it is successful. If the return value is (HMODULE)0 then the loading failed and if it is != 0 then it was a success. You pass the file path of the DLL you wish to load, that is all you need to do
HMODULE hLdrLoadDll(LPWSTR DllName)
{
	// get the address of LdrLoadDll from ntdll.dll
	LPVOID lpLdrLoadDll = (LPVOID)GetProcAddress(GetModuleHandle("ntdll.dll"), "LdrLoadDll");
	if (lpLdrLoadDll) // if the address is obtained
	{
		HMODULE hModule = (HMODULE)0; // we will store our HMODULE here later on
		UNICODE_STRING LdrDllInfo; // we will use this to hold the information for the LdrLoadDll call
		LdrDllInfo.Buffer = DllName; // the dll path must be the .Buffer -> you can always just do = L"path" instead of passing a param for it
		LdrDllInfo.Length = (wcslen(DllName) * 2); // calc the length
		LdrDllInfo.MaximumLength = (LdrDllInfo.Length + 2); // max length calc
		pLdrLoadDll LdrLoadDll = (pLdrLoadDll)lpLdrLoadDll; // setup memory for the call
		if (NT_SUCCESS(LdrLoadDll(NULL, NULL, &LdrDllInfo, &hModule))) // call LdrLoadDll
		{
			return hModule; // if success then we return our HMODULE
		}
	}
	return (HMODULE)0; // failure! return nothing
}