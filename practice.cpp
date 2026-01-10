#include<stdio.h>
#include<string.h>

typedef struct{
    char name[50];
    int id;
    float physics, chemistry, math;
    float total;
}Student;

void add_student(Student s[], int *count){
    int i = *count;

    printf("\n---Add New Student---\n");
    printf("Enter id: ");
    scanf("%d",&s[i].id);
    printf("Enter Name: ");
    scanf(" %[^\n]",s[i].name);
    printf("Enter marks(Phy Chem Math): ");
    scanf("%f %f %f", &s[i].physics, &s[i].chemistry, &s[i].math);
    s[i].total = s[i].physics + s[i].chemistry + s[i].math;
    (*count)++;
}

void printStudent(Student s){
    printf("ID: %d|Name: %s|Total: %.2f(phy: %.2f, chem: %.2f, math: %.2f)\n", s.id, s.name, s.total, s.physics, s.chemistry, s.math);

}

void insertionSort(int n, Student s[]){
    for(int i = 1; i<n; i++){
        Student key = s[i];
        int j = i-1;
        while(j>=0 && s[j].total<key.total){
            s[j+1] = s[j];
            j= j-1;
        }
        s[j+1] = key;
    }
}

void showKthPosition(int n, Student s[]){
    insertionSort(n, s);
    int k;
    printf("Enter position(K): ");
    scanf("%d",&k);

    if(k>0 && k<=n){
        printf("The student position %d is : \n");
        printStudent(s[k-1]);
    }else{
        printf("Invalid position!\n");
    }
}

void showStanding(int n, Student s[]){
    insertionSort(n, s);

    printf("\n---Class Standing---\n");
    printf("Rank\tId\tName\tTotal Marks\n");
    for(int i = 0; i<n; i++){
        printf("%d\t%d\t%s\t%.2f\n",i+1, s[i].id,s[i].name, s[i].total);
    }
}

void showInfoByID(int n, Student s[]){
    int searchId;
    printf("Enter Student Id to search: ");
    scanf("%d",&searchId);
    int found = 0;
    for(int i = 0; i<n; i++){
        if(s[i].id == searchId){
            printStudent(s[i]);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Student with ID %d not found\n",searchId);
    }
}

int main(){
    int m;
    
    
    Student student[10];
    int n;
    int count = 0;
    printf("Enter the maximum number of Student(N): ");
    scanf("%d",&n);
   
    
    int choice;
    while(1){
        printf("\n=====Action List=====\n");
        printf("1. Add new Student information\n");
        printf("2. Show the information of the students(by id)\n");
        printf("3. Kt-positioned student\n");
        printf("4. Show the standings of all the students\n ");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice == 1){
            add_student(student, &count);
        }else if(choice == 2){
            showInfoByID(count,student);
        }else if(choice == 3){
            showKthPosition(count, student);
        }else if(choice == 4){
            showStanding(count, student);
        }else if(choice == 5){
            break;
        }else{
            printf("Invalid Input!\n");
        }
    }
    return 0;

}