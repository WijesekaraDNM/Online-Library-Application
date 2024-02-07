#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

void moveCursorFunc(int row, int col)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int x_pos = col, y_pos = row;
    COORD screen;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    screen.X = x_pos;
    screen.Y = y_pos;
    SetConsoleCursorPosition(hOutput, screen);
}

void bubbleSort(int arr[], int size)
{
	for (int step = 1; step < size; step++)
	{
		for (int j = 0; j < size - step; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}