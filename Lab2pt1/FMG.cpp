#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include "fmlib.h"
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Russian");
	char path[MAX_PATH];
	strcpy(path, "C://");
	while (true)
	{
		system("cls");
		if (GetCurrentDirectoryA(MAX_PATH, path) != 0)
		{
			printf("Current dir: %s\n", path);
		}
		else
		{
			printf("Error occured!\n");
			exit(1);
		}

		printf("1 - Change directory;\n");
		printf("2 - Print directory;\n");
		printf("3 - Copy file;\n");
		printf("4 - Create directory;\n");
		printf("5 - Delete file;\n");
		printf("6 - Delete directory;\n");
		printf("7 - File info.\n");
		printf(">> ");
		int action;
		scanf_s("%i", &action);
		switch (action)
		{
		case 1: change_dir(); break;
		case 2: print_dir(); break;
		case 3: copy_file(); break;
		case 4: create_dir(); break;
		case 5: remove_file(); break;
		case 6: remove_dir(); break;
		case 7: print_file(); break;
		default: printf("Input error!\n");
		}
	}
}