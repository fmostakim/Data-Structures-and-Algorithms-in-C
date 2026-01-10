#include<stdio.h>

void insertionSort(float arr[], int n){

    for(int i = 1; i<n;i++){
        float key = arr[i];
        int j = i-1;
        while(j>= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}



int main(){
    int n = 5;
    float arr[n] = {10.5, 9.8, 12.1, 11.3, 10.2};

    insertionSort(arr, n);

    printf("%f",arr[2]);
    
}