#include <cstdio>
#include <iostream>

using namespace std;
int num[100000];

void swap(int &a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void selectPivotMid(int arr[], int low, int high)
{
	int mid = low + ((high - low) >> 1);//���������м��Ԫ�ص��±�  

										//ʹ������ȡ�з�ѡ������  
	if (arr[mid] > arr[high])//Ŀ��: arr[mid] <= arr[high]  
	{
		swap(arr[mid], arr[high]);
	}
	if (arr[low] > arr[high])//Ŀ��: arr[low] <= arr[high]  
	{
		swap(arr[low], arr[high]);
	}
	if (arr[mid] > arr[low]) //Ŀ��: arr[low] >= arr[mid]  
	{
		swap(arr[mid], arr[low]);
	}
	//��ʱ��arr[mid] <= arr[low] <= arr[high]  
	//return arr[low];  
	//low��λ���ϱ���������λ���м��ֵ  
	//�ָ�ʱ����ֱ��ʹ��lowλ�õ�Ԫ����Ϊ���ᣬ�����øı�ָ����  
}


void sort2(int a[], int left, int right)
{
	if (left < right)
	{
		selectPivotMid(a, left, right);
		int pivot = a[left];
		int i = left, j = right;
		while (i < j)
		{
			while (i < j && a[j] > pivot)
			{
				j--;
			}
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			while (i < j && a[i] < pivot)
			{
				i++;
			}
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}
		}
		a[i] = pivot;

		sort2(a, left, i - 1);
		sort2(a, i + 1, right);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	sort2(num, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}