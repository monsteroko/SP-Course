#include "windows.h"
#include "stdio.h"
#include "string.h"
#include "locale.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    if (argc != 2)
    {
        printf_s("Incorrect input!");
    }
    else
    {
        if (strcmp(argv[1], "-e") == 0)
        {
            MEMORYSTATUS ms;
            GlobalMemoryStatus(&ms);
            HLOCAL memory = LocalAlloc(LPTR, ms.dwTotalPhys * (3));
            if (memory == NULL) {
                LPVOID message;
                DWORD code = GetLastError();
                FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&message, 0, NULL);
                wprintf(L"\nError code: 0x%x\n", code);
                wprintf(L"Сообщение об ошибке: %s\n", (char*)message);
            }

        }
        else if (strcmp(argv[1], "-s") == 0)
        {
            MEMORYSTATUSEX ms;
            SYSTEM_INFO proc;
            GlobalMemoryStatusEx(&ms);
            GetSystemInfo(&proc);
            printf_s("\nCPU Info:");
            printf_s("Number of processors: %u\n", proc.dwNumberOfProcessors);
            printf_s("Processor architectire: %u\n", proc.wProcessorArchitecture);
            printf_s("Processor level: %u\n", proc.wProcessorLevel);
            printf_s("Processor revision: %u\n", proc.wProcessorRevision);
            printf_s("Active processor mask: %u\n", proc.dwActiveProcessorMask);
            printf_s("Page size: %u\n", proc.dwPageSize);
            printf_s("Minimum application address: %lx\n", proc.lpMinimumApplicationAddress);
            printf_s("Maximum application address: %lx\n", proc.lpMaximumApplicationAddress);
            printf_s("Information about memory:\n");
            printf_s("Availble memory: %d bytes;\n", ms.ullAvailPhys);
            printf_s("Total memory: %d bytes;\n", ms.ullTotalPhys);
        }
        else
        {
            printf_s("Incorrect key!");
        }
    }
    return 0;
}