#include<stdio.h>
void insertionSort(int arr[] , int n){
    
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j>=0 && arr[j]<key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n = 5;
    int arr[5]={120, 340, 290, 450, 210};

    insertionSort(arr, n);

    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
}