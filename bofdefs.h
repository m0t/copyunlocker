#pragma once

#include <windows.h>

#ifdef BOF
#define intAlloc(size) 				KERNEL32$HeapAlloc(KERNEL32$GetProcessHeap(), HEAP_ZERO_MEMORY, size)
#define intRealloc(ptr, size) 		KERNEL32$HeapReAlloc(KERNEL32$GetProcessHeap(), HEAP_ZERO_MEMORY, ptr, size) 
#define intFree(addr) 				KERNEL32$HeapFree(KERNEL32$GetProcessHeap(), 0, addr)
//#define intZeroMemory(addr,size) 	MSVCRT$memset((addr),0,size)
#define GetModuleHandleA 		 	KERNEL32$GetModuleHandleA
#define GetProcAddress 				KERNEL32$GetProcAddress
#define CreateToolhelp32Snapshot	KERNEL32$CreateToolhelp32Snapshot
#define Process32First 			 	KERNEL32$Process32First
#define Process32Next 			 	KERNEL32$Process32Next
#define OpenProcess 				KERNEL32$OpenProcess
#define GetFileType 				KERNEL32$GetFileType
#define DuplicateHandle 			KERNEL32$DuplicateHandle
#define CloseHandle 				KERNEL32$CloseHandle
#define QueryDosDevice 				KERNEL32$QueryDosDevice
#define GetVolumePathName 			KERNEL32$GetVolumePathName
#define GetFileSizeEx 				KERNEL32$GetFileSizeEx
#define CreateFileMapping 			KERNEL32$CreateFileMapping
#define MapViewOfFile 				KERNEL32$MapViewOfFile
#define CreateFile 					KERNEL32$CreateFile
#define WriteFile 					KERNEL32$WriteFile
#define UnmapViewOfFile				KERNEL32$UnmapViewOfFile
//strlen

#define NtQuerySystemInformation 	NTDLL$NtQuerySystemInformation
//#define 							NtDuplicateObject NTDLL$NtDuplicateObject
#define NtQueryObject 				NTDLL$NtQueryObject

#define msg(fmt, ...) BeaconPrintf(CALLBACK_OUTPUT, fmt, ##__VA_ARGS__ )
#define err(fmt, ...) BeaconPrintf(CALLBACK_ERROR, fmt, ##__VA_ARGS__ )

#else

#include <stdio.h>

#define intAlloc(size) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size)
#define intRealloc(ptr, size) HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, ptr, size) 
#define intFree(addr) HeapFree(GetProcessHeap(), 0, addr)

#define msg(fmt, ...) printf(fmt, ##__VA_ARGS__ )
#define err(fmt, ...) printf(fmt, ##__VA_ARGS__ )
#endif