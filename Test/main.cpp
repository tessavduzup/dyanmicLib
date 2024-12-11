#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
	HINSTANCE load;
	load = LoadLibrary(L"D:\\PROJECTS\\DSTU\\DynamicLab\\DynamicLab\\x64\\Debug\\DynamicLab.dll");

    if (load == NULL) {
        std::cerr << "Failed to load the library." << std::endl;
        return 1;
    }

	typedef void (*sort) (int*, int);
	sort Sort;
	Sort = (sort)GetProcAddress(load, "sort");

    typedef int (*searchElement) (int*, int, int);
    searchElement SearchElement;
    SearchElement = (searchElement)GetProcAddress(load, "searchElement");

    typedef double (*average) (int*, int);
    average Average;
    Average = (average)GetProcAddress(load, "average");

	int arr[] = { 5, 3, 8, 1, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Sort(arr, size);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int element;
    cout << "Введите элемент для поиска: ";
    cin >> element;
    int result = SearchElement(arr, size, element);
    cout << "Полученный элемент: " << result << endl;

    double avg = Average(arr, size);
    cout << "Среднее значение элементов массива: " << avg << endl;

	FreeLibrary(load);

    return 0;
}