#include<stdio.h>

int countAffordableHouse(int prices[], int n, int budget){
    int left = 0; 
    int right = n - 1;
    int last_affordabe_index = -1;

    while(left<=right){
        int mid = left + (right  - left)/2;

        if(prices[mid]<=budget){
            last_affordabe_index = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return last_affordabe_index + 1;
}

int main(){
    int prices[] = {150000, 200000, 250000, 300000, 350000, 400000};
    int n = 6;
    int budget = 275000;

    int result = countAffordableHouse(prices, n, budget);

    printf("Output: %d\n", result);

    printf("Affordable Houses: ");
    for(int i = 0; i<result; i++){
        printf("%d ", prices[i]);
    }

    return 0 ;
}