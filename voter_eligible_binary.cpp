#include<stdio.h>

void insertionSort(int arr[],int n){
    for(int i = 0; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}

void binarySearch(int arr[], int n, int key){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid  =  low + (high - low)/2;

        if(arr[mid]>= key){
            printf("%d ",arr[mid]);
            high = mid -1;
        }else {
            low = mid + 1;
        }
    }
}



int main(){
    int arr[5] = {15, 18, 20, 39, 17};
    insertionSort(arr,5);

    

    binarySearch(arr, 5, 18);
    
}