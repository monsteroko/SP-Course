#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <locale.h>
void change_dir()
{
	printf("Enter path: \n");
	printf(">> ");
	char path[MAX_PATH];
	scanf_s("%s", path, MAX_PATH);
	if (SetCurrentDirectoryA((LPCSTR)path))
	{
		if (GetCurrentDirectoryA(MAX_PATH, path) != 0)
		{
			printf("Directory changed!\n");
			system("pause");
		}
		else
		{
			printf("Error! \n");
			system("pause");
			exit(1);
		}
	}
	else
	{
		printf("Error! \n");
		system("pause");
	}
}

void print_dir()
{
	WIN32_FIND_DATAA file;
	HANDLE hf;
	char path[MAX_PATH];

	if (GetCurrentDirectoryA(MAX_PATH, path) != 0)
	{
		system("cls");
		strcat(path, "//*");
		hf = FindFirstFileA(path, &file);
		if (hf == INVALID_HANDLE_VALUE)
		{
			printf("Error!\n");
			system("Pause");
			return;
		}
		else {
			do
			{

				if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
					printf("[DIR] ");
				else
					printf("[FILE] ");

				printf("%s\n", file.cFileName);

				SYSTEMTIME time;
				FileTimeToSystemTime(&file.ftCreationTime, &time);
				printf("Created: %02d-%02d-%d %02d:%02d:%02d", time.wMonth, time.wDay, time.wYear, time.wHour, time.wMinute, time.wSecond);
				printf("Size: %dB\n", file.nFileSizeLow);

			} while (FindNextFileA(hf, &file));
			system("Pause");
			FindClose(hf);
		}
	}
	else
	{
		printf("Error! \n");
		system("pause");
		exit(1);
	}


}

void copy_file()
{
	char oldPath[MAX_PATH];
	char newPath[MAX_PATH];
	system("cls");
	printf("Enter path:\n");
	printf(">>");
	scanf_s("%s", oldPath, MAX_PATH);
	printf("Enter new path and name.\n");
	printf(">>");
	scanf_s("%s", newPath, MAX_PATH);
	if (CopyFileA((LPCSTR)oldPath, (LPCSTR)newPath, FALSE))
	{
		printf("File copied!\n");
	}
	else
	{
		printf("Failed to copy file!\n");
	}
	system("Pause");
}

void create_dir()
{
	char path[MAX_PATH];
	system("cls");
	printf("Enter the path of the directory to be created.\n");
	printf(">>");
	scanf_s("%s", path, MAX_PATH);
	if (CreateDirectoryA((LPCSTR)path, NULL))
	{
		printf("Directory created!\n");
	}
	else
	{
		printf("Failed to create directory!\n");
	}
	system("pause");
}

void remove_file()
{
	char path[MAX_PATH];
	system("cls");
	printf("Enter path and name of file.\n");
	printf(">>");
	scanf_s("%s", path, MAX_PATH);
	if (DeleteFileA(path))
	{
		printf("File deleted!\n");
	}
	else
	{
		printf("Failed to delete file!\n");
	}
	system("pause");
}

void remove_dir()
{
	char path[MAX_PATH];
	system("cls");
	printf("Enter directory path.\n");
	printf(">>");
	scanf_s("%s", path, MAX_PATH);
	if (RemoveDirectoryA(path))
	{
		printf("Directory deleted!\n");
	}
	else
	{
		printf("Failed to delete directory!\n");
	}
	system("pause");
}

void print_file()
{
	char path[MAX_PATH];
	system("cls");
	printf("Enter new path and name of file.\n");
	printf(">>");
	scanf_s("%s", path, MAX_PATH);

	BY_HANDLE_FILE_INFORMATION fileInfo;
	SYSTEMTIME time;
	HANDLE file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (GetFileInformationByHandle(file, &fileInfo))
	{
		SYSTEMTIME time;
		FileTimeToSystemTime(&fileInfo.ftCreationTime, &time);
		printf("Size: %dB\n", fileInfo.nFileSizeLow);
		FileTimeToSystemTime(&(fileInfo.ftCreationTime), &time);
		printf("Created: %02d-%02d-%d %02d:%02d:%02d\n", time.wMonth, time.wDay, time.wYear, time.wHour, time.wMinute, time.wSecond);
		FileTimeToSystemTime(&(fileInfo.ftLastAccessTime), &time);
		wprintf(L"Last usage: %02d-%02d-%d %02d:%02d:%02d\n",
			time.wMonth, time.wDay, time.wYear,
			time.wHour, time.wMinute, time.wSecond);
		FileTimeToSystemTime(&(fileInfo.ftLastWriteTime), &time);
		wprintf(L"Last change: %02d-%02d-%d %02d:%02d:%02d\n",
			time.wMonth, time.wDay, time.wYear,
			time.wHour, time.wMinute, time.wSecond);
		wprintf(L"¹ of links: %d\n", fileInfo.nNumberOfLinks);
	}
	else
	{
		printf("Failed to get detailed information!\n");
	}
	system("pause");
	CloseHandle(file);
}