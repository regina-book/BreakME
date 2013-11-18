	
	
	/**/
	//@SolutionCrackMex01
	//@Toufik Airane
	//@2013.10
	/**/
	#include <stdio.h>
	#include <stdlib.h>
	#include <windows.h>
	#include <TlHelp32.h>

	int GetProcessToPid(char *name) {
		PROCESSENTRY32 ProcessEntry = { 0 };
		ProcessEntry.dwSize = sizeof(PROCESSENTRY32);
		HANDLE Snapshot32Process = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		if(Snapshot32Process == INVALID_HANDLE_VALUE) {
		printf("Invalid Handle Value");
		exit(EXIT_FAILURE);
		}

		if(!Process32First(Snapshot32Process, &ProcessEntry)) {
		printf("Process First Failed");
		CloseHandle(Snapshot32Process);
		exit(EXIT_FAILURE);
		}

		do {
			char *ExeFile = ProcessEntry.szExeFile;
			if(strcmp(name, ExeFile)==0)
				return ProcessEntry.th32ProcessID;
		} while (Process32Next(Snapshot32Process, &ProcessEntry));
		CloseHandle(Snapshot32Process);
		return 0;
	}

	int main(int argc, char *argv[]) {
		if(argc!=2) exit(EXIT_FAILURE);
		int pid = GetProcessToPid(argv[1]);
		printf("[#] PID du CrackMe : %d\n", pid);
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
		if(hProcess==NULL) { printf("OpenProcess() : KO\n"); exit(EXIT_FAILURE); }

		DWORD buffer, taille;
		if(!(ReadProcessMemory(hProcess, (LPDWORD) 0x0028FF40, &buffer, sizeof(DWORD), &taille))) { // la seule difficultée est l'adresse du stack
				printf("ReadProcessMemory() : KO\n"); exit(EXIT_FAILURE);                           // que l'on récupère via le debugger
		}
		printf("[#] La key est : %d\n", buffer);
		close(hProcess);
		return 0;
	}

