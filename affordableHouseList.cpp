#include<stdio.h>
int main(){
    int prices[] = {150000, 200000, 250000, 300000, 350000, 400000};
    int n = sizeof(prices)/sizeof(prices[0]);
    int terget = 275000;

    int low = 0; 
    int high = n - 1; 
    int firstIndex = -1;
    while(low<=high){
        int mid = low + (high - low);

        if(prices[mid]>=terget){
            firstIndex = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }

    for(int i = 0; i<firstIndex; i++){
        printf("%d ",prices[i]);
    }
}