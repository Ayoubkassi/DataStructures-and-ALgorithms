#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void print(int arr[],int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}

int main()
{
    int arr[] = { 80 , 90 ,60 ,30 ,50 ,70 ,40 };
    int n = 7;

    insertionSort(arr, n);
    print(arr, n);
    return 0;
}
