#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h> 
#include <conio.h>
#include <clocale>
#include <windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	int n, x, indxMAX, e = 0;
	ofstream f("C:\\Users\\nikit\\source\\repos\\vadim9_1\\vadim9_1\\text.txt");
	cout << "Введите число элементов в файле: ";
	cin >> n;
	srand(time(0));
	for (int i = 0; i < n; i++) { // Заполняеем файл случаными числами от 0 до 20
		x = rand() % 20;
		f << x << ' ';
	}
	f.close();
	ifstream file("C:\\Users\\nikit\\source\\repos\\vadim9_1\\vadim9_1\\text.txt");
	int* arr = new int[n]; // Объявлеяем массив размером n
	int ma = INT_MIN;
	for (int i = 0; i < n; i++) { // Переписываем из файла в ранее объявленный массив все числа 
		file >> arr[i];
	}
	cout << "Изначальный массив: " << "\n" << "[";
	for (int i = 0; i < n; i++) { // Выводим второй элемент массива
		cout << arr[i];
		if (i < n - 1) { // Ставим пробел и запятую до последнего элемента 
			cout << ", ";
		}
	}
	cout << "]" << "\n";
	for (int i = 0; i < n; i++) { // Ищем максимум в массиве путем перебора каждого числа и сравнивания их друг с другом поочередно
		if (arr[i] > ma) {
			ma = arr[i];
		}
	}
	for (int i = 0; i < n; i++) { // Находим индекс максимального элемента 
		if (arr[i] == ma) {
			indxMAX = i;
			break; // Прерываем цикл, когда индекс первого максимального элемента найден
		}
	}
	int* arr1 = new int[n - indxMAX]; // Обявляем массив размером [Размер изначального массива - индекс максимального элемента]
	for (int i = indxMAX+1; i < n; i++) { // Проходим по первому массиву, начиная с максимального элемента, если элемент первого массива не равен нулю, записываем его во второй
		if (arr[i] > 0) {
			arr1[e] = arr[i];
			e++;
		}
	}
	cout << "Массив, в котором только ненулевые элементы, которые идут по порядку после максимального: ";
	cout << "\n" << "[";
	for (int i = 0; i < e; i++) { // Выводим второй элемент массива
		cout << arr1[i];
		if (i < e - 1) { // Ставим пробел и запятую до последнего элемента 
			cout << ", ";
		}
	}
	cout << "]";
}