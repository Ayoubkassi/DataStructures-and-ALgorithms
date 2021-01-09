#include <iostream>

using namespace std;

void bubbleSortint(int arr[],int n){
    int c=0;
    for(int i=0;i<n-1;i++){
            bool flag = true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
                flag= false;
            }
            c++;
        }
        if(flag == true)
            break;
    }
    cout<<"Number of rounds :"<<c<<endl;
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
     int arr[]={6,0,40,30,35};
    int n = 5;
    bubbleSortint(arr,n);
    print(arr,n);


    return 0;
}
