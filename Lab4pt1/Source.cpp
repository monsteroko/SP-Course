#include "7zipunp.h"
#define zip 1
#define unzip 2
int main()
{
	int i;

	for(;;)
	{
		printf_s("Choice an option:\n");
		printf_s("1 - Unpack file;\n");
		printf_s("2 - Pack files.\n");
		scanf_s("%i", &i);

		switch (i)
		{
		case zip:
		{
			LPSTR unpackFile = new CHAR[MAX_PATH];
			LPSTR resultFile = new CHAR[MAX_PATH];

			printf_s("Path to zip\n");
			scanf_s("%s", unpackFile);

			printf_s("Path to result\n");
			scanf_s("%s", resultFile);

			unpack_files(unpackFile, resultFile);
			break;
		}
		case unzip:
		{
			LPSTR packFile = new CHAR[MAX_PATH];
			LPSTR resultFile = new CHAR[MAX_PATH];

			printf_s("Path to File/Directory\n");
			scanf_s("%s", packFile);

			printf_s("Path to result (.zip)\n");
			scanf_s("%s", resultFile);
			pack_files(packFile, resultFile);
			break;
		}

		default: printf_s("Invalid input!\n"); break;
		}

		system("pause");
		system("cls");
	}


}
