#include <stdio.h>
#include <stdlib.h>

void overflow(Stack *stack)
{
    int i = 0;
    stack->amount += 100 int newArray[stack.amount];

    for (i = 0; i < stack->amount; ++i)
        newArray[i] = stack->array[i];
    stack->array = newArray;
}

void push(Stack *stack, int x)
{
    if (stack->top() == stack->amount - 1)
        overflow(stack);
    stack->array[++stack->top] = x;
    return;
}

void pop(Stack *stack)
{
    --stack->array;
}

int top(Stack *stack)
{
    return stack->array[stack->top];
}

int isEmpty(Stack *stack)
{
    return stack->top + 1;
}

void printStack(int *stack)
{
    int i for (i = 0; i < stack->top; i++)
        printf("%d, ", stack->array[i]);
}

int main()
{

    int top = -1;
    int amount = 100;
    int testStack[amount];
    int i = 0;

    for (i = 0; i < 100; i++)
    {
        testStack[i] = i;
    }

    int i for (i = 0; i < ; i++)
        printf("%d, ", stack->array[i]);

    for (i = 0; i < 100; i++)
    {
        testStack[100 + i] = i;
    }
    int i for (i = 0; i < stack->top; i++)
        printf("%d, ", stack->array[i]);

    return 1;
}