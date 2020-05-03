#include <stdio.h>
#include <Windows.h>

int main()
{
	HANDLE myMutex = CreateMutex(0,0,TEXT("MutexSP"));
	DWORD result = WaitForSingleObject(myMutex, 0);
	if (result != WAIT_OBJECT_0) {
		printf("Program already works!\n");
		system("pause");
		return 0;
	}
	else {
		printf("Program works...");
		while (1) {}
	}
	return 0;
}