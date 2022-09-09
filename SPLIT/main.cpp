#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;
	int x;

	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	int* even = new int[x];
	int* odd = new int[x];

	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "   ";
		}
		x = *(arr + i);
		if (x % 2 == 0)
		{
			*(even + i) = x;
		}
		
	}
	cout << endl;
	
}


