#define AmountOfBytesToRead 2048
#include "windows.h"
#include "stdio.h"
#include "string.h"
#include "locale.h"

void FromUnicodeToAscii(char*);
void FromAsciiToUnicode(char*);
bool CreateResultAndOpenSourceFiles(char*, HANDLE*, HANDLE*);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf_s("Incorrect input!");
    }
    else
    {
        if (strcmp(argv[1], "-a") == 0)
        {
			HANDLE readFile;
			HANDLE writeFile;			
			bool Result = true;
			readFile = CreateFileA(argv[2], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			writeFile = CreateFileA("output.txt", GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (readFile != INVALID_HANDLE_VALUE && writeFile != INVALID_HANDLE_VALUE){
				BYTE buff[AmountOfBytesToRead];
				DWORD dwBytes;
				while (ReadFile(readFile, buff, AmountOfBytesToRead, (LPDWORD)&dwBytes, NULL))
				{
					if (dwBytes == 0) break;
					int uLength = MultiByteToWideChar(CP_UTF8, 0, (LPCCH)buff, dwBytes, NULL, 0);
					wchar_t* uStr = new wchar_t[uLength];
					MultiByteToWideChar(CP_UTF8, 0, (LPCCH)buff, dwBytes, uStr, uLength);
					if (!WriteFile(writeFile, uStr, uLength * sizeof(wchar_t), (LPDWORD)&dwBytes, NULL)) {
						printf("Save error!");
						break;
					}
				}
				CloseHandle(readFile);
				CloseHandle(writeFile);
			}
        }
        else if (strcmp(argv[1], "-u") == 0)
        {
			HANDLE readFile;
			HANDLE writeFile;
			bool Result = true;
			readFile = CreateFileA(argv[2], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			writeFile = CreateFileA("output.txt", GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (readFile != INVALID_HANDLE_VALUE && writeFile != INVALID_HANDLE_VALUE){
				BYTE buff[AmountOfBytesToRead];
				DWORD dwBytes;
				while (ReadFile(readFile, buff, AmountOfBytesToRead, (LPDWORD)&dwBytes, NULL))
				{
					if (dwBytes == 0) break;
					int uLength = MultiByteToWideChar(CP_UTF8, 0, (LPCCH)buff, dwBytes, NULL, 0);
					wchar_t* uStr = new wchar_t[uLength];
					MultiByteToWideChar(CP_UTF8, 0, (LPCCH)buff, dwBytes, uStr, uLength);
					int aLength = WideCharToMultiByte(CP_ACP, 0, uStr, uLength, NULL, 0, NULL, NULL);
					char* aStr = new char[aLength];
					WideCharToMultiByte(CP_ACP, 0, uStr, uLength, aStr, aLength, NULL, NULL);
					if (!WriteFile(writeFile, aStr, aLength * sizeof(char), &dwBytes, NULL)) {
						printf("Save error!");
						break;
					}
				}
				CloseHandle(readFile);
				CloseHandle(writeFile);
			}
        }
        else
        {
            printf_s("Incorrect key!");
        }
    }
    return 0;
}