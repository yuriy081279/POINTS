#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;
	int x;//���������� - "������" �������� � ���������� ��� ������
	int c = 0;//���������� ��� ����������� ������� ������� Even � ������������ � ����������� ���������, ������� � ���� ������
	int d = 0;//���������� ��� ����������� ������� ������� Odd � ������������ � ����������� ���������, ������� � ���� ������
	
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	int* even = new int[c];
	int* odd = new int[d];
    for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 8;				
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
	//delete[] arr;
	cout << endl;
	cout << "����� �������� ��������� � ��������� ������ \"���\"";
	cout << endl;
	for (int i = 0; i < d; i++)
	{
		cout << odd[i] << "\t";
	}
	//delete[] odd;
	cout << endl;
	cout << "����� ������ ��������� � ��������� ������ \"����\"";
	cout << endl;
	for (int i = 0; i < c; i++)
	{
		cout << even[i] << "\t";
	}
	//delete[] even;
}


