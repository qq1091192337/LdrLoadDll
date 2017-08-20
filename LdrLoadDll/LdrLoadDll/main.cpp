/*
DISCLAIMER! THIS IS FOR EDUCATIONAL PURPOSES ONLY. 

Bonjour! 

This is my project example on calling ntdll.dll!LdrLoadDll so you don't have to use kernel32.dll!LoadLibraryA/W. You can do extra work yourself to write a GetProcAddress replacement (walk the Export Address Table until you find what you need) and/or a GetModuleHandle replacement, but at least you don't have to figure out a LoadLibraryA/W replacement now

If you wish to block this method of DLL loading within your own program you can do a local hook on LdrLoadDll but it won't be perfect. LoadLibrary -> ends up at LdrLoadDll

Merci! - NtOpcode :)
*/

#include "header.h"
using namespace std;

BOOL bTestLoadDll()
{
	if (hLdrLoadDll(L"")) // pass the path of your DLL in the ""
	{
		return TRUE;
	}
	return FALSE;
}

int main()
{
	bTestLoadDll(); // call the function to test the DLL loading
	getchar();
	return 0;
}