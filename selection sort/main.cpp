#include <iostream>

using namespace std;

void swapo(int&x,int&y){
    int temp=x;
    x=y;
    y=temp;
}

void selectionSort(int arr[], int n)
{
	int minIdx;
	                               //0  1  2  3  4  5
	for (int i = 0; i < n - 1; i++)//60 40 50 30 10 20
	{
		minIdx = i;//4

		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIdx])
				minIdx = j;
	            swapo(arr[minIdx], arr[i]);

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
    int arr[]={60,40,50,-10,35};
    int n = 5;
    selectionSort(arr,n);
    print(arr,n);
    return 0;
}
