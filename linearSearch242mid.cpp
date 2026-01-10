#include<stdio.h>

int linearSearch(int arr[] , int n, int terget){

    for(int i = 0; i<n; i++){
        if(arr[i] == terget){
            return terget;
        }
       
    }
     return -1;
}

void SearchPair(int arr[], int n, int x, int y){
    int s1 = linearSearch(arr,n,x);
    int s2 = linearSearch(arr,n,y);

    if(s1 != -1 && s2 != -1){
        printf("PAIR MATCHED");
    }else if(s1 == -1 && s2 == -1){
        printf("BETTER LUCK NEXT TIME");
    }else{
        if(s1 != -1){
            printf("ONLY ME (%d)", s1);
        }else{
            printf("ONLY ME (%d)", s2);
        }   
    }


}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    printf("Enter array: ");
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter terget: ");
    int x, y;
    scanf("%d",&x);
    scanf("%d",&y);
    
    SearchPair(arr, n, x, y);

    return 0;


}