#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

struct Stack
{
    int data[MAX];
    int top;
};

typedef struct Stack Stack;

void init(Stack *s){
    s->top = -1;
}

int is_empty(Stack *s){
    return s->top;
}

void push(Stack* s, int value){
    if(s->top < MAX - 1){
        s->data
    }
}
