#include<iostream>
using namespace std;

int x;// номер значения в массиве, куда мы будем вставлять число в функции Insert и будем убирать его в функции Erase

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value1);
int* insert(int* arr, int& n, int value2, int x);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n, int x);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	
	int value;
	cout << "Введите добавочное значение в конце массива: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	
	int value1;
	cout << "Введите добавочное значение в начале массива: "; cin >> value1;
	arr = push_front(arr, n, value1);
	Print(arr, n);

	int value2;	
	cout << "Введите номер значения на место которого надо вставить дополнительное значение: "; cin >> x;
	cout << "Введите добавочное значение в массив на место с номером "<< x<<": "; cin >> value2;
	arr = insert(arr, n, value2, x);
	Print(arr, n);

	cout << "Массив без последнего значения" << endl; 
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Массив без первого (нулевого) значения" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Массив без значения, которое мы ввели на место с №"<<x<<" в исходном массиве - возвращение к исходному массиву" << endl;
	arr = erase(arr, n, x);
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n+1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;	
	return arr;
}
int* push_front(int* arr, int& n, int value1)
{
	int* buffer = new int[n+1];
	for (int i = 1; i < n+1; i++)
	{
		buffer[i] = arr[i-1];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value1;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value2, int x)
{
	int* buffer = new int[n + 1];
	
	for (int i = 0; i < n+1; i++)
	{				
		if (i == x-1)
		{
			buffer[i] = value2;
		}
		else if (i < (x - 1))
		{
			buffer[i] = arr[i];
		}
		else if (i > (x - 1))
		{
			buffer[i] = arr[i-1];
		}
	}	
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int* arr, int& n)
{
	int* buffer=new int[n-1];
	for(int i=1; i<n; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int* erase(int* arr, int& n, int x)
{
	int* buffer = new int[n-1];
	for (int i = 0; i < n-1; i++)
	{		
		if (i >= (x-2))
		{
			buffer[i] = arr[i + 1];
		}
		if (i < (x-2))
		{
			buffer[i] = arr[i];
		}
	}

	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}