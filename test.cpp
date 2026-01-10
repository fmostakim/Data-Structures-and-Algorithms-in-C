#include<stdio.h>
int sumOfDigits(int num){
    int sum = 0;
    while(num>0){
        sum += num%10;
        num = num /10;
    }
    return sum;
}

void nsort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i -1;
        while(j>=0 && sumOfDigits(arr[j])>sumOfDigits(key)){
            arr[j+1]= arr[j];
            j = j-1;
        }
        arr[j+1] = key;

    }
}


int main(){
    int n = 5;
    int arr[] = {34, 23, 45, 12, 9};

    nsort(arr, n);

    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
}