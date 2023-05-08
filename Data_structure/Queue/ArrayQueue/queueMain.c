#include <stdio.h>
#include <stdlib.h>

#define LEN_MAX 10

/*head를 데이터를 넣고 rear로 데이터를 뺀다.*/
int test_queue[LEN_MAX];
// 0도 사용할려고 가능하다.
int head = -1;
int rear = -1;

int IsEmpty()
{
    // 큐의 마지막 원소가 나가면 enqueue에서 초기화 해줄거임
    if (rear == -1)
        return 1;
    return 0;

    // 이것도 되긴 하다.
    // 이러면 rear가 가르키는게 deq된 상태를 의미
    if (head == rear)
        return 1;
    return 0;
}

int IsFull()
{
    if (rear == LEN_MAX - 1)
        return 1;
    return 0;
}

void enqueue(int inputNum)
{
    if (IsFull())
    {
        printf("큐가 다 차있습니다.\n");
        return;
    }
    else if (IsEmpty())
    {
        head = 0;
        rear = 0;
    }
    else
    {
        rear += 1;
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
    else if (head == rear)
    // 큐에 남은 유일한 데이터를 뺏기 때문에 초기화
    {
        head = -1;
        rear = -1;
    }
    else
    {
        head += 1;
    }
}

void print_queue()
{
    int i;

    for (i = head; i <= rear; ++i)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    for (int i = 0; i < LEN_MAX / 2; ++i)
    {
        enqueue(i);
    }

    print_queue();

    for (int i = 0; i < LEN_MAX / 2; ++i)
    {
        dequeue();
    }

    printf("head = %d, rear = %d\n", head, rear);

    for (int i = 0; i < LEN_MAX; ++i)
    {
        enqueue(i * 10);
    }

    print_queue();

    return 0;
}