#include<stdio.h>


void bmiSort(float arr[], int n){

    for(int i = 1; i<n; i++){
        float key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(){
    int N;
    scanf("%d",&N);

    float Weight[N];
    float Height[N];

    printf("Enter Weight: ");
    for(int i = 0; i<N; i++){
        scanf("%f",& Weight[i]);
    }

    printf("Enter Height: ");

    for(int i = 0; i<N; i++){
        scanf("%f",& Height[i]);
    }

    float BMI[N];

    for(int i = 0; i<N; i++){
        BMI[i] = Weight[i]/Height[i];
    }

    bmiSort(BMI, N);

    printf("Sorted BMI: ");

    for(int i = 0; i<N; i++){
        printf("%f ",BMI[i]);
    }

    
}