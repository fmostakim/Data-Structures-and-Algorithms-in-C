#include<stdio.h>

int findFirst(int arr[], int n, int terget){
    int low = 0; 
    int high = n-1;

   
    int result = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(arr[mid] == 4){
            result = mid;
            high = mid  - 1;
        }else if(arr[mid] > terget){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return result;
}

int findLast(int arr[], int n, int terget){
    int low = 0; 
    int high = n-1;

   
    int result = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(arr[mid] == 4){
            result = mid;
            low = mid  + 1;
        }else if(arr[mid] > terget){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return result;
}

int main(){
    int arr[] = {2, 4, 4, 4, 6, 7};

    int n = sizeof(arr)/sizeof(arr[0]);

    int low = 0; 
    int high = n-1;

    int terget = 4;
    int count = 0; 

    int firstIndex = findFirst(arr, n, terget);
    int lastIndex = findLast(arr, n, terget);

    count = lastIndex - firstIndex + 1;


    printf("%d ",count);
}