/**
* 2021. 07. 13
* Creater : Gunhee Choi
* Problem Number : 18258
* Title : 큐2

* Problem :
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

	push X: 정수 X를 큐에 넣는 연산이다.
	pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 큐에 들어있는 정수의 개수를 출력한다.
	empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
	front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

* Input :
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

	15
	push 1
	push 2
	front
	back
	size
	empty
	pop
	pop
	pop
	size
	empty
	pop
	push 3
	empty
	front

* Output :
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

	1
	2
	2
	0
	1
	2
	-1
	0
	1
	-1
	0
	3

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 2000000
#define MAX_STRING 100

typedef struct {
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
	int size;
} QueueType;

void init_queue(QueueType * queue) {
	queue->rear = -1;
	queue->front = -1;
	queue->size = 0;
}

int is_full(QueueType * queue) {
	if(queue->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	
	return 0;
}

int is_empty(QueueType * queue) {
	if(queue->front == queue->rear)
		return 1;
	
	return 0;
}

int enqueue(QueueType * queue, int data) {
	if( is_full(queue) ) {
		printf("Queue is Full\n");
		return -1;
	}
	
	queue->size++;
	queue->data[++(queue->rear)] = data;
	return 0;
}

int dequeue(QueueType * queue) {
	int data;
	
	if( is_empty(queue) ) {
		return -1;
	}
	
	queue->size--;
	data = queue->data[++(queue->front)];
	return data;
}

void print_queue(QueueType * queue) {
	int i;
	
	for(i=0; i<MAX_QUEUE_SIZE; i++) {
		if(i <= queue->front || i> queue->rear)
			printf("  |  ");
		else
			printf("%d | ", queue->data[i]);
	}
	printf("\n");
}

int get_size(QueueType * queue) {
	return queue->size;
}

int get_front(QueueType * queue) {
	return queue->data[queue->front];
}

int get_back(QueueType * queue) {
	return queue->data[queue->rear];
}

int main(void) {
	int data;
	QueueType q;
	
	init_queue(&q);
	
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	print_queue(&q);
	
	printf("%d\n", get_front(&q));
	printf("%d\n", get_back(&q));
	
	data = dequeue(&q);
	data = dequeue(&q);
	print_queue(&q);
	
	return 0;
}