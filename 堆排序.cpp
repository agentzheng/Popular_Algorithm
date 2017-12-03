#include<iostream>
using namespace std;

void heapadjust(int * arr,int parent,int length)
{
	int temp = arr[parent];
	int child = 2 * parent + 1;//×óº¢×Ó
	while (child<length)
	{
		if (child + 1 < length&&arr[child + 1] > arr[child])
		{
			child++;
		}
		if (temp >= arr[child])
			break;
		arr[parent] = arr[child];

		parent = child;
		child = 2 * parent + 1;
	}
	arr[parent] = temp;
}

void heapsort(int * arr,int length)
{
	for (int i = length / 2; i >= 0; i--)
	{
		heapadjust(arr, i, length);
	}

	for (int i=length-1;i>0;i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;

		heapadjust(arr, 0, i);
	}


}

int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	heapsort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]<<' ';
	}
	cout << endl;

	system("pause");
}