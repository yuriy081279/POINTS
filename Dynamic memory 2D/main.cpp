#include<iostream>
#include<conio.h>
using namespace std;

int nomer_stroki;
int nomer_stolba;

void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr, const int rows, const int cols);
void Allocate(int** arr, const int rows, const int cols);
void Clear(int** arr, const int rows, const int cols);

int** push_back(int** arr, int& rows, int& cols);
int** push_front(int** arr, int& rows, int& cols);
int** insert(int** arr, int& rows, int& cols, int nomer_stroki);

int** pop_back(int** arr, int& rows, int& cols);
int** pop_front(int** arr, int& rows, int& cols);
int** erase(int** arr, int& rows, int& cols, int nomer_stroki);

int** push_cols_back(int** arr, int& rows, int& cols);
int** push_cols_front(int** arr, int& rows, int& cols);
int** insert_cols(int** arr, int& rows, int& cols, int nomer_stolba);

int** pop_cols_back(int** arr, int& rows, int& cols);
int** pop_cols_front(int** arr, int& rows, int& cols);
int** erase_cols(int** arr, int& rows, int& cols, int nomer_stolba);

#define tab "\t"
#define Enter 13
void main()
{
	setlocale(LC_ALL, "");
	int rows, cols;

	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� �������: "; cin >> cols;

	int** arr = new int* [rows];

	Allocate(arr, rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	cout << "������� �����, ����� ��������� �������������� ������ ������� ����� ���������� �� ���������: " << endl;
	char key = 0;
	key = _getch();
	switch (key)
	{
	case Enter: arr = push_back(arr, rows, cols), Print(arr, rows, cols); break;
	default: cout << "�� ������ �� �� ������, ������ ���������� ��� ������� � ����������, ��� ������������� ���������. " << endl;
	}

	cout << endl;
	cout << "������� �����, ����� ��������� �������������� ������ ������� ������ ���������� �� ���������: " << endl;
	key = _getch();
	switch (key)
	{
	case Enter: arr = push_front(arr, rows, cols), Print(arr, rows, cols); break;
	default: cout << "�� ������ �� �� ������, ������ ���������� ��� ������� � ����������, ��� ������������� ���������. " << endl;
	}

	cout << endl;
	cout << "������� ����� �������������� ������ �������, ������� ����� �������� ���������� �� ���������: "; cin >> nomer_stroki;
	if (nomer_stroki > rows + 1)
	{
		cout << "��� ������ � ����� �������, ������������ �������� ������, ������� �� ������ ������ = " << rows + 1 << endl;
	}
	else
	{
		arr = insert(arr, rows, cols, nomer_stroki);
		Print(arr, rows, cols);
	}

	cout << endl;
	arr = pop_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	arr = pop_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	arr = erase(arr, rows, cols, nomer_stroki);
	Print(arr, rows, cols);


	cout << endl;
	arr = push_cols_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	arr = push_cols_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	cout << "������� ����� ��������������� ������ �������, ������� ����� �������� ���������� �� ���������: "; cin >> nomer_stolba;
	arr = insert_cols(arr, rows, cols, nomer_stolba);
	Print(arr, rows, cols);

	cout << endl;
	arr = pop_cols_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	arr = pop_cols_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl;
	cout << "������� ����� ��������������� ������ �������, ������� ���� �������: "; cin >> nomer_stolba;
	arr = erase_cols(arr, rows, cols, nomer_stolba);
	Print(arr, rows, cols);

	Clear(arr, rows, cols);

	/*int value;
	cout << "������� ���������� �������� � ����� �������: "; cin >> value;
	arr = push_back(arr, n, value);


	int value1;
	cout << "������� ���������� �������� � ������ �������: "; cin >> value1;
	arr = push_front(arr, n, value1);


	int value2;
	cout << "������� ����� �������� �� ����� �������� ���� �������� �������������� ��������: "; cin >> x;
	cout << "������� ���������� �������� � ������ �� ����� � ������� " << x << ": "; cin >> value2;
	arr = insert(arr, n, value2, x);


	cout << "������ ��� ���������� ��������" << endl;
	arr = pop_back(arr, n);

	cout << "������ ��� ������� (��������) ��������" << endl;
	arr = pop_front(arr, n);


	cout << "������ ��� ��������, ������� �� ����� �� ����� � �" << x << " � �������� ������� - ����������� � ��������� �������" << endl;
	arr = erase(arr, n, x);
	Print(arr, n);*/

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
int** push_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i] = new int[cols] {};

	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}
int** push_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i] = new int[cols] {};
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i + 1][j] = arr[i][j];
		}
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}
int** insert(int** arr, int& rows, int& cols, int nomer_stroki)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < rows + 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			if (i < (nomer_stroki - 1))
			{
				buffer[i][j] = arr[i][j];
			}
			else if (i > (nomer_stroki - 1))
			{
				buffer[i][j] = arr[i - 1][j];

			}
		}
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}

int** pop_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = new int[cols];
	}
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
int** pop_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = new int[cols];
	}
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i + 1][j];
		}
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
int** erase(int** arr, int& rows, int& cols, int nomer_stroki)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = new int[cols];
	}

	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i >= nomer_stroki - 2)
			{
				buffer[i][j] = arr[i + 1][j];
			}
			else if (i < nomer_stroki - 2)
			{
				buffer[i][j] = arr[i][j];
			}

		}
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
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
	int* buffer = new int[n - 1];
	for (int i = 1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int* erase(int* arr, int& n, int x)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		if (i >= (x - 2))
		{
			buffer[i] = arr[i + 1];
		}
		if (i < (x - 2))
		{
			buffer[i] = arr[i];
		}
	}

	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int** push_cols_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	delete[]arr;
	arr = buffer;
	cols++;
	return arr;
}
int** push_cols_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		{
			buffer[i] = new int[cols + 1]{};
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols + 1; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
	}
	delete[]arr;
	arr = buffer;
	cols++;
	return arr;
}
int** insert_cols(int** arr, int& rows, int& cols, int nomer_stolba)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		{
			buffer[i] = new int[cols + 1];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols + 1; j++)
		{
			if (j == nomer_stolba - 1)
			{
				buffer[i][j] = {};
			}
			else if (j > nomer_stolba - 1)
			{
				buffer[i][j] = arr[i][j - 1];
			}
			else if (j < nomer_stolba - 1)
			{
				buffer[i][j] = arr[i][j];
			}
		}
	}
	delete[]arr;
	arr = buffer;
	cols++;
	return arr;
}
int** pop_cols_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		{
			buffer[i] = new int[cols - 1];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	delete[]arr;
	arr = buffer;
	cols--;
	return arr;
}
int** pop_cols_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		{
			buffer[i] = new int[cols - 1];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
	}
	delete[]arr;
	arr = buffer;
	cols--;
	return arr;
}
int** erase_cols(int** arr, int& rows, int& cols, int nomer_stolba)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		{
			buffer[i] = new int[cols - 1];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{

			if (j >= nomer_stolba - 1)
			{
				buffer[i][j] = arr[i][j + 1];
			}
			else if (j < nomer_stolba - 1)
			{
				buffer[i][j] = arr[i][j];
			}
		}
	}
	delete[]arr;
	arr = buffer;
	cols--;
	return arr;
}
