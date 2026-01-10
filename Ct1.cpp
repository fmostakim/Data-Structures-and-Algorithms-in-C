#include<stdio.h>
#include<string.h>

#define MAX_STUDENTS 100

typedef struct{
    char name[50];
    int id;
    float physics;
    float chemistry;
    float math;
    float total;
}Student;

void insertionSortStudents(Student s[], int n){
    
    for(int i = 1; i<n; i++){
        int key = s[i];
        int j = i-1;

        while(j>=0 && arr[j]<key){
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }
}

int main(){
    Student students[MAX_STUDENTS];
    int count = 0;
    int n, choice;

    printf("Enter the initial number of student: ");
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        printf("\nEnter details for student %d",i+1);
        printf("Name: ");
        scanf("%s", &students[i].name);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Marks(Phy Chem Math): ");
        scanf("%f %f %f",&students[i].physics, &students[i].chemistry, &students[i].math);

        students[i].total = students[i].physics + students[i].chemistry + students[i].math;

        count ++;

    }

    while(1){
        printf("\n----------------------------\n");
        printf("         ACTION LIST         \n");
        printf("1. Add new student Information\n");
        printf("2. Show the information\n");
        printf("3. kth-postioned student\n");
        printf("4. Show the standing of all the student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 5){
            printf("Exiting program...\n");
            break;
        }

        switch(choice){
            case 1:
                if(count<MAX_STUDENTS){
                    printf("\nEnter details for new Student: \n");
                    printf("Name: ");
                    scanf("%s", students[count].name);
                    printf("ID: ");
                    scanf("%d",&students[count].id);
                    printf("Marks (Phy Chem Math): ");
                    scanf("%f %f %f",&students[count].physics, &students[count].chemistry, &students[count].math);
                    students[count].total = students[count].physics + students[count].chemistry + students[count].math;
                    count ++;
                    printf("Student added successfully!\n");

                }else{
                    printf("Memory full! Cannot add more students.\n");
                }
                break;
            case 2:
                {
                    int searchID, found = 0;
                    printf("Enter Student ID to search: ");
                    scanf("%d",&searchID);

                    for(int i = 0; i<count; i++){
                        if(students[i].id == searchID){
                            printf("\n---Student Found---\n");
                            printf("Name: %s\n", students[i].name);
                            printf("Physics: %.2f, Chemistry: %.2f, Math: %.2f\n", students[i].physics, students[i].chemistry, students[i].math);
                            printf("Total Marks: %.2f\n", students[i].total);
                            found = 1;
                            break;
                        }
                    }
                    if(found == 0){
                        printf("Student with ID %d not found\n", searchID);
                    }
                    break;
                }
            case 3:
                {
                    insertionSortStudents(students, count);

                    int k; 
                    printf("Enter position(k): ");
                    scanf("%d",&k);

                    if(k>0 && k<=count){
                        Student s = students[k-1];
                        printf("\nThe %d-th positioned student is: \n",k);
                        printf("Name: %s (ID: %d) - Total Marks: %.2f\n",s.name, s.id, s.total);

                    }else{
                        printf("Invalid positioned!\n");
                    }
                }
                break;  
            case 4:
                {
                    insertionSortStudents(students, count);

                    printf("\n--- Student Standings (Sorted by Marks) ---\n");
                    printf("Rank\tID\tName\tTotal Marks\n");
                    for(int i = 0; i<count;i++){
                        printf("%d\t%d\t%s\t%.2f\n", i+1, students[i].id, students[i].name, students[i].total);
                    }
                }
                break;

            default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}