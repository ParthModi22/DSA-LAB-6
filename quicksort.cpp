#include<iostream>
using namespace std;

int partition(int arr[],int f,int l){
    int pivot = arr[l];
    int i = f-1;
    for(int j = f;j<l;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[l]);
    return i+1;
}

void quicksort(int arr[],int f,int l){
    if(f>=l){
        return;
    }
    int pi = partition(arr,f,l);
    quicksort(arr,f,pi-1);
    quicksort(arr,pi+1,l);
}
int main()
{
    int arr[] = {22,12,-34,111,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
   return 0;
}