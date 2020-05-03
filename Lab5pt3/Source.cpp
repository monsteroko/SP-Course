#include "crtsect.h"
int main()
{
	HANDLE* threads;
	clock_t start;
	float elapsed_time;
	srand(time(NULL));
	InitializeCriticalSection(&section);
	array = new int[ARRAY_MAX_SIZE];
	fill_array(array);
	start = clock();
	threads = launch_threads((LPVOID)TRUE);
	WaitForMultipleObjects(3, threads, TRUE, INFINITE);
	for (int i = 0; i < 3; i++)
		CloseHandle(threads[i]);
	elapsed_time = ((float)(clock() - start)) / CLK_TCK;
	printf("Time with critical section: %f sec.\n\n", elapsed_time);
	start = clock();
	threads = launch_threads((LPVOID)FALSE);
	WaitForMultipleObjects(3, threads, TRUE, INFINITE);
	for (int i = 0; i < 3; i++)
		CloseHandle(threads[i]);
	elapsed_time = ((float)(clock() - start)) / CLK_TCK;
	printf("Time without critical section: %f sec.\n\n", elapsed_time);
	DeleteCriticalSection(&section);
	system("pause");
}