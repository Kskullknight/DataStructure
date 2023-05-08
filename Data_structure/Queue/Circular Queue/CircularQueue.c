#include <stdio.h>
#include <stdlib.h>

#define LEN_MAX 10

int test_queue[LEN_MAX];
// 원형큐는 0에서 시작 => 순환하면서 초기화 안하면서 사용 할 예정
// -1부터 시작해도 되기는 함
int head = 0;
int rear = 0;

int IsEmpty()
{
    if (head == rear)
        return 1;
    return 0;
}

int IsFull() // rear의 다음이 head일 경우
{
    if ((rear + 1) % LEN_MAX == head)
        return 1;
    return 0;
}

void enqueue(int inputNum)
{
    if (IsFull())
    {
        printf("%d 큐가 다 차있습니다.\n", inputNum);
        return;
    }
    // 원형큐는 굳이 초기화 할 필요 없을 듯
    // else if (IsEmpty())
    // {
    //     head = 0;
    //     rear = 0;
    // }
    else
    {
        rear = (rear + 1) % LEN_MAX;
    }
    test_queue[rear] = inputNum;
}

void dequeue()
{
    if (IsEmpty())
    {
        printf("큐가 비어있습니다. \n");
        return;
    }
    // 원형큐는 굳이 초기화 할 필요 없어 보인다.
    // else if (head == rear)
    // {
    //     head = -1;
    //     rear = -1;
    // }
    else
    {
        head = (head + 1) % LEN_MAX;
    }
}

void print_queue()
{
    int i;

    for (i = (head + 1) % LEN_MAX; i != rear; i = (i + 1) % LEN_MAX)
    {
        printf("%d -> ", test_queue[i]);
    }
    printf("%d\n", test_queue[rear]);
}

int main()
{
    for (int i = 0; i < LEN_MAX; ++i)
    {
        enqueue((i + 1) * 10);
    }

    print_queue();

    for (int i = 0; i < LEN_MAX / 2; ++i)
    {
        dequeue();
    }

    for (int i = 0; i <= LEN_MAX / 2; ++i)
    {
        enqueue((i + 1) * 100);
    }

    print_queue();

    return 0;
}