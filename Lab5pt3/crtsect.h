#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define ARRAY_MAX_SIZE 60000000
#define THREAD_ACTION_FIND_MIN 0
#define THREAD_ACTION_FIND_MAX 1
#define THREAD_ACTION_FIND_AVG 2
#define THREAD_ACTION_TYPE 0
#define THREAD_CRITICAL_SECTION_FLAG 1

CRITICAL_SECTION section;
int* array;

int random_integer(int min, int max)
{
	return min + rand() % (max + 1 - min);
}

void fill_array(int* array)
{
	for (int i = 0; i < ARRAY_MAX_SIZE; i++)
	{
		array[i] = random_integer(0, 1000);
	}
}

DWORD WINAPI thread_function(LPVOID param)
{
	int* params = (int*)param;
	if ((bool)params[THREAD_CRITICAL_SECTION_FLAG])
	{
		while (!TryEnterCriticalSection(&section)){}
	}
	int min = array[0];
	int max = array[0];
	float avg = 0;
	switch (params[THREAD_ACTION_TYPE])
	{
	case THREAD_ACTION_FIND_MIN:
		for (int i = 0; i < ARRAY_MAX_SIZE; i++)
		{
			if (min > array[i])
				min = array[i];
		}
		printf("Min: %i\n", min);
		break;
	case THREAD_ACTION_FIND_MAX:

		for (int i = 0; i < ARRAY_MAX_SIZE; i++)
		{
			if (max < array[i])
				max = array[i];
		}
		printf("Max: %i\n", max);
		break;
	case THREAD_ACTION_FIND_AVG:

		for (int i = 0; i < ARRAY_MAX_SIZE; i++)
		{
			avg += array[i];
		}
		printf("Avg: %f\n", avg / ARRAY_MAX_SIZE);
		break;
	}
	if ((bool)params[THREAD_CRITICAL_SECTION_FLAG])
	{
		LeaveCriticalSection(&section);
	}
	return 0;
}

HANDLE* launch_threads(LPVOID use_critical_section)
{
	HANDLE* threads = new HANDLE[3];
	for (int i = 0; i < 3; i++)
	{
		int* params = new int[2];
		params[THREAD_ACTION_TYPE] = i;
		params[THREAD_CRITICAL_SECTION_FLAG] = (int)use_critical_section;
		threads[i] = CreateThread(NULL,0,thread_function,(LPVOID)params,NULL,NULL);
	}
	return threads;
}