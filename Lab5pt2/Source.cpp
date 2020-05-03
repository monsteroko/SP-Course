#include "Semap.h"
int main()
{
    int max_handles;
    int max_threads;
    srand(time(NULL));
    printf("Input max number of handles:\n");
    scanf("%i", &max_handles);
    printf("Input max number of threads:\n");
    scanf("%i", &max_threads);
    HANDLE* threads = new HANDLE[max_threads];
    semaphore = CreateSemaphoreA(NULL, max_handles, max_handles, "SemaphSP");
    if (semaphore == NULL)
        return 1;
    HANDLE file = CreateFileA("result.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE)
    {
        CloseHandle(file);
        return 1;
    }
    CloseHandle(file);
    for (int i = 0; i < max_threads; i++)
    {
        int* params = new int[2];
        params[0] = i; 
        params[1] = random_int(1, 5);
        threads[i] = CreateThread(NULL, 0, thread_function, (LPVOID)params, NULL, NULL);
    }
    WaitForMultipleObjects(max_threads, threads, TRUE, INFINITE);
    return 0;
}