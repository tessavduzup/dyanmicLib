#pragma once
#ifndef MYLIB_H
#define MYLIB_H

extern "C" namespace ArrayUtils
{
	extern "C" class ArrayProcessor {
		void sort(int*, int);

		int searchElement(int*, int, int);

		double average(int*, int);

		void displayArray(int* arr, int size);
	};
}

#endif