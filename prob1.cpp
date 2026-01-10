#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int n, int terget){
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end -start)/2;

        if(arr[mid] == terget){
            return mid;
        }else if(terget<arr[mid]){
            end = mid -1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}


void insertionSort(int arr[], int n){

    for(int i = 0; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    char *strNumber[] = {"45", "12", "7", "100", "23", "5"};
    int n = 6;
    int number[n];

    for(int i=0;i<n; i++){
        number[i] = atoi(strNumber[i]);
    }


    insertionSort(number, n);

    


    int terget1 =23;
    

    int result1 =  binarySearch(number, n, terget1);
        if(result1 != -1){
            printf("Terget %d found at index: %d \n", terget1, result1);
        }else{
            printf("Target %d Not Found\n", terget1);
        }
    

    return 0;
    
}