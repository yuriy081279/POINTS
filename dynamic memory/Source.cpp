#include<iostream>
#include<conio.h>
using namespace std;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define tab "\t"
#define Enter 13

int x;// номер значения в одномерном массиве, куда мы будем вставлять число в функции Insert и будем убирать его в функции Erase

int nomer_stroki;
int nomer_stolba;

//Здесь собраны функции для одномерного массива
void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value1);
int* insert(int* arr, int& n, int value2, int x);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n, int x);

//Здесь собраны функции для двухмерного массива
void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr, const int rows, const int cols);
void Allocate(int** arr, const int rows, const int cols);
void Clear(int** arr, const int rows, const int cols);

int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int& cols);
int** row_insert(int** arr, int& rows, int& cols, int nomer_stroki);

int** pop_row_back(int** arr, int& rows, int& cols);
int** pop_row_front(int** arr, int& rows, int& cols);
int** erase_row(int** arr, int& rows, int& cols, int nomer_stroki);

void push_cols_back(int** arr, const int rows, int& cols);
int** push_cols_front(int** arr, int rows, int& cols);
int** insert_cols(int** arr, int rows, int& cols, int nomer_stolba);

int** pop_cols_back(int** arr, int rows, int& cols);
int** pop_cols_front(int** arr, int rows, int& cols);
int** erase_cols(int** arr, int rows, int& cols, int nomer_stolba);

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	
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
	cout << "Введите добавочное значение в массив на место с номером " << x << ": "; cin >> value2;
	arr = insert(arr, n, value2, x);
	Print(arr, n);

	cout << "Массив без последнего значения" << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Массив без первого (нулевого) значения" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Массив без значения, которое мы ввели на место с №" << x << " в исходном массиве - возвращение к исходному массиву" << endl;
	arr = erase(arr, n, x);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;

	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество столбов: "; cin >> cols;

	int** arr = new int* [rows];

	Allocate(arr, rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	cout << "Нажмите Энтер, чтобы заполнить дополнительную строку массива снизу значениями по умолчанию: " << endl;
	char key = 0;
	key = _getch();
	switch (key)
	{
	case Enter: arr = push_row_back(arr, rows, cols), Print(arr, rows, cols); break;
	default: cout << "Вы нажали не ту кнопку, можете пропустить это задание и продолжить, или перезапустите программу. " << endl;
	}

	cout << endl;
	cout << "Нажмите Энтер, чтобы заполнить дополнительную строку массива сверху значениями по умолчанию: " << endl;
	key = _getch();
	switch (key)
	{
	case Enter: arr = push_row_front(arr, rows, cols), Print(arr, rows, cols); break;
	default: cout << "Вы нажали не ту кнопку, можете пропустить это задание и продолжить, или перезапустите программу. " << endl;
	}

	cout << endl;
	cout << "Введите номер дополнительной строки массива, который будет заполнен элементами по умолчанию: "; cin >> nomer_stroki;
	if (nomer_stroki > rows + 1)
	{
		cout << "Нет строки с таким номером, максимальное значение строки, которое Вы можете ввести = " << rows + 1 << endl;
	}
	else
	{
		arr = row_insert(arr, rows, cols, nomer_stroki);
		Print(arr, rows, cols);
	}

	cout << endl;
	cout << "Нажмите Энтер, чтобы удалить дополнительную строку массива снизу: " << endl;
	key = _getch();
	switch (key)
	{
	case Enter: arr = pop_row_back(arr, rows, cols), Print(arr, rows, cols); break;
	default: cout << "Вы нажали не ту кнопку, можете пропустить это задание и продолжить, или перезапустите программу. " << endl;
	}
	
	cout << endl;
	cout << "Нажмите Энтер, чтобы удалить дополнительную строку массива сверху: " << endl;
	key = _getch();
	switch (key)
	{
	case Enter: arr = pop_row_front(arr, rows, cols), Print(arr, rows, cols); break;
	default: cout << "Вы нажали не ту кнопку, можете пропустить это задание и продолжить, или перезапустите программу. " << endl;
	}
	
	cout << endl;
	cout << "Нажмите Энтер, чтобы удалить дополнительную строку массива под номером: "<< nomer_stroki-1 << endl;
	key = _getch();
	switch (key)
	{
	case Enter: arr = erase_row(arr, rows, cols, nomer_stroki), Print(arr, rows, cols); break;
	default: cout << "Вы нажали не ту кнопку, можете пропустить это задание и продолжить, или перезапустите программу. " << endl;
	}
	
	
	cout << endl;
	push_cols_back (arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	arr = push_cols_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	cout << "Введите номер дополнительного столба массива, который будет заполнен элементами по умолчанию: "; cin >> nomer_stolba;
	arr = insert_cols(arr, rows, cols, nomer_stolba);
	Print(arr, rows, cols);

	cout << endl;
	arr = pop_cols_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	arr = pop_cols_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	cout << "Введите номер дополнительного столба массива, который надо удалить: "; cin >> nomer_stolba;
	arr = erase_cols(arr, rows, cols, nomer_stolba);
	Print(arr, rows, cols);

	Clear(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
void Allocate(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
}
void Clear(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
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
	n-- ;
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
int** push_row_back(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows+1];
	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i] = arr[i];
	}
   
	delete[] arr;	
	buffer[rows] = new int[cols]{};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i+1] = arr[i];
	}
	
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** row_insert(int** arr, int& rows, int& cols, int nomer_stroki)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
	{
		if (i < (nomer_stroki - 1))
		{
			buffer[i] = arr[i];
		}
		else if (i > (nomer_stroki - 1))
		{
			buffer[i] = arr[i - 1];

		}
	}	
	delete[] arr;
	buffer[nomer_stroki-1] = new int[cols] {};
	rows++;
	return buffer;
}

int** pop_row_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	
	delete[] arr;	
	rows--;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	rows--;
	return buffer;	
}
int** erase_row(int** arr, int& rows, int& cols, int nomer_stroki)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		if (i >= nomer_stroki - 2)
		{
			buffer[i] = arr[i + 1];
		}
		else if (i < nomer_stroki - 2)
		{
			buffer[i] = arr[i];
		}
	}
	delete[] arr;
	rows--;
	return buffer;	
}

void push_cols_back(int** arr, const int rows, int& cols)
{		
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols+1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}	
		delete[] arr[i];
		arr[i] = buffer;
	}		
	cols++;	
}
int** push_cols_front(int** arr, int rows, int& cols)
{	
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}	
	cols++;
	return arr;
}
int** insert_cols(int** arr, int rows, int& cols, int nomer_stolba)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			if (j > nomer_stolba - 1)
			{
				buffer[j] = arr[i][j-1];
			}
			else if (j < nomer_stolba - 1)
			{
				buffer[j] = arr[i][j];
			}	
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}
int** pop_cols_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];		
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
int** pop_cols_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
int** erase_cols(int** arr, int rows, int& cols, int nomer_stolba)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols; j++)
		{
			if (j < nomer_stolba-1)
			{
				buffer[j] = arr[i][j];
			}
			if (j >= nomer_stolba-1)
			{
				buffer[j] = arr[i][j+1];
			}
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}



