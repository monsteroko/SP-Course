#include "notebk.h"

int main()
{
	int choice;
	for (;;) {
		printf("Choice a item:\n");
		printf("1 - View all records;\n");
		printf("2 - Add record;\n");
		printf("3 - Change record;\n");
		printf("4 - Delete record;\n");
		scanf("%i", &choice);
		system("cls");
		switch (choice) {
		case 1: PrintRecords(); break;
		case 2: AddRecord(); break;
		case 3: ChangeRecord(); break;
		case 4:	DeleteRecord(); break;
		default:printf("Choice error!\n");
		}
		system("pause");
		system("cls");
	}
}