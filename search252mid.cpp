#include<stdio.h>

int binarySearchOccurance(int arr[], int n, int terget, int searchFirst){

    int start = 0, end = n-1;
    int res = -1;

    while(start<=end){
        int mid = start + (end - start)/2;

        if(arr[mid] == terget){
            res = mid;

            if(searchFirst == 1){
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }else if(terget < arr[mid]){
            end = mid -1;
        }else{
            start = mid + 1;
        }

    }
    return res;

}

int main(){
    int arr[] = {2, 4, 4, 4, 6, 7};
    int terget = 4;
    int n = sizeof(arr)/sizeof(arr[0]);

    int first = binarySearchOccurance(arr, n, 4, 1);
    int last = binarySearchOccurance(arr, n, 4, 0);

    int count = (last - first + 1);

    printf("Count:  %d", count);
}