#include<stdio.h>

int binSearch(int scores[], int n, int x){
    int left = 0; 
    int right = n-1;

    int first_valid_index = n;

    while(left<=right){
        int mid = left +(right - left)/2;

        if(scores[mid] >= x){
            first_valid_index = mid;
            right = mid -1;
        }else{
            left = mid + 1;
        }
    }

    return n - first_valid_index;

}

int main(){
    int n = 7;
    int scores[n] = {35, 50, 60, 65, 65, 70, 85};
    int x = 60;
    
    int result = binSearch(scores, n, x);

    for(int i = 0; i<n; i++){
        printf("%d ", scores[i]);
    }
    printf("\n");
    printf("Output: %d", result);
}