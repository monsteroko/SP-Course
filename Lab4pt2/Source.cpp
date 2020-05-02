#include "thrds.h"

int main()
{
	int count;
	printf("Enter quantity of threads:\n");
	scanf("%i", &count);

	threads = new HANDLE[count];
	srand(time(0));
	InitializeCriticalSection(&criticalSection);
	launch_threads(count);
	WaitForMultipleObjects(count, threads, TRUE, INFINITE);
	DeleteCriticalSection(&criticalSection);
	system("pause");
	return 0;
}
