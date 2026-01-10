#include<stdio.h>
int main(){
    int sales[] = {120, 340, 290, 450, 210};
    int n = sizeof(sales)/sizeof(sales[0]);
    

    for(int i = 0; i<n-1; i++){
        int maxindex = i;
        for(int j = i+1; j<n; j++){
            if(sales[maxindex]<sales[j]){
                maxindex = j;
            }
        }
        int temp = sales[maxindex];
        sales[maxindex] = sales[i];
        sales[i] = temp;
    }


    for(int i = 0; i<n; i++){
        printf("%d ",sales[i]);
    }
}