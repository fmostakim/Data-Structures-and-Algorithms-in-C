#include<stdio.h>
int main(){
    float times[] = {10.5, 9.8, 12.1, 11.3, 10.2};
    int n = sizeof(times)/sizeof(times[0]);

    for(int i = 0; i<n-1 ;i++){
        int minIn = i;
        for(int j = i+1; j<n; j++){
            if(times[minIn]>times[j]){
                minIn = j;
            }
            
        }
        float temp = times[minIn];
        times[minIn] = times[i];
        times[i] = temp;

    }

    

    printf("Enter which position do you want?");
    int k;
    scanf("%d",&k);
    printf("%.2f", times[k-1]);
}