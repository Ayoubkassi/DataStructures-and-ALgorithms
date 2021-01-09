#include <iostream>

using namespace std;


int partition1(int arr[], int l, int h)
{
	int p = arr[l];
	int i = l;
	int j = h;
	while (i < j)
	{
		do
		{
			i++;
		} while (arr[i] <= p);
		do
		{
			j--;
		} while (arr[j] > p);

		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[j]);
	return j;
}

void quickSort1(int arr[], int l, int h)
{

	if (l < h) {
		int piv = partition1(arr, l, h);
		quickSort1(arr, l, piv);
		quickSort1(arr, piv + 1, h);
	}

}


int main()
{
    int arr[] = { 2,-1,4,7,0};
	int n = sizeof(arr) / sizeof(arr[0]);

	quickSort1(arr, 0, n );
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

    return 0;
}
