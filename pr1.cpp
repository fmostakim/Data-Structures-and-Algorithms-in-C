#include<stdio.h>


int searchaffordable(int arr[], int n, int x){
    int low = 0; 
    int high = n-1;
    int res = -1;
    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid] >= x){
            res = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return res;
}

int main(){
    int n = 7;
    int arr[n] = {35, 50, 55, 60, 65, 70, 85};
    int x = 60;

    int result = searchaffordable(arr, n, x);

    
    for(int i = result; i<n; i++){
        printf("%d ", arr[i]);
    }
}