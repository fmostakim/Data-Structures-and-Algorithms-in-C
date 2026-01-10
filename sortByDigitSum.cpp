#include<stdio.h>

int getDigitSum(int n){
    int sum = 0;
    while(n>0){
        sum  += n % 10;
        n /=10;
    }
    return sum;
}

int main(){
    int arr[] = {34, 23, 45, 12, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 1; i<n; i++){
        int j = i -1;
        int key = arr[i];

        while(j>=0 && getDigitSum(arr[j])>getDigitSum(key)){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
}