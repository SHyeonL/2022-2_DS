#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;

typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[(s->top)--];
}

void queue_pop(StackType *s)
{
    StackType tmp;
    int s_top = s->top;
    init_stack(&tmp);
    for (int i = s_top; i > 0; i--) {
        tmp.data[++(tmp.top)] = pop(s);
    }
    for (int i = 0; i < tmp.top; i++) {
        printf("%d | ", tmp.data[i]);
    }
}

int return_size(StackType *s) {
    return s->top + 1;
}

int main() {
    StackType stack;

    init_stack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    pop(&stack);
    printf("스택에 저장된 요소의 수 : %d", return_size(&stack));
}