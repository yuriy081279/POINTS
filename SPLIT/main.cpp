#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;
	int x;//Переменная - "Флажок" четности и нечетности для ифэлса
	int c = 0;//Переменная для ограничения размера массива Even в соответствии с количеством элементов, которые в него войдут
	int d = 0;//Переменная для ограничения размера массива Odd в соответствии с количеством элементов, которые в него войдут
	
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];	
	int* even = new int[c];
	int* odd = new int[d];
    for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;				
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;	
	for (int i = 0; i < n; i++)
	{
		x = arr[i] % 2;
		if (x == 0)
		{			
			*(even + c) = arr[i];
			c++;
		}
		else
		{			
			*(odd + d) = arr[i];
			d++;
		}
	}
	
	delete[] arr;
	cout << endl;
	cout << "Вывод нечетных элементов в отдельный массив \"ОДД\"";
	cout << endl;
	for (int i = 0; i < d; i++)
	{
		cout << odd[i] << "\t";
	}
	
	cout << endl;
	cout << "Вывод четных элементов в отдельный массив \"ИВЭН\"";
	cout << endl;
	for (int i = 0; i < c; i++)
	{
		cout << even[i] << "\t";
	}	
	
}


