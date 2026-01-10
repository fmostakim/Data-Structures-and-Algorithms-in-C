#include<stdio.h>
void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]<key){
            arr[j+1] = arr[j];

            j--;


        }
        arr[j+1] = key;
    }
}

int main(){
    int n = 6;
    int arr[n] ={10, 20, 50, 70 , 100, 150};

    insertionSort(arr, n);

    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
}