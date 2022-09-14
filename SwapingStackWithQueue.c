#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define QUEUE_SIZE 10
#define STACK_SIZE 10

struct array{
	int data;
	char array[QUEUE_SIZE];
	int front;
	int rear;
	int counter;
};


struct arrayForStack{
	
	int top;
	char array[STACK_SIZE];
};

typedef struct array queue;
typedef struct arrayForStack stack;

char engueue(queue*,char);
char dequeue(queue*);
void initialize(queue*);
int isFull(queue *q);
int isEmpty(queue *q);
char push(stack*,char);
char pop(stack*);
void initilazeStack(stack*stk);

int main(int argc, char *argv[]) {
	
	
	queue queue1;
	stack stack1;
	
	char swap[QUEUE_SIZE];
	int i=0;

	initialize(&queue1);
	initilazeStack(&stack1);

	//putting "Muharrem" in stack
	push(&stack1,'M');
	push(&stack1,'u');
	push(&stack1,'h');
	push(&stack1,'a');
	push(&stack1,'r');
	push(&stack1,'r');
	push(&stack1,'e');
	push(&stack1,'m');

	//putting "Aslan" in queue
	engueue(&queue1,'A');
	engueue(&queue1,'s');
	engueue(&queue1,'l');
	engueue(&queue1,'a');
	engueue(&queue1,'n');

	
	//assigning the value from stack to an array
	char control=pop(&stack1);
	while(control!='X')
	{
		swap[i]=control;
		i++;
		
		control=pop(&stack1);
	}
	
	initilazeStack(&stack1);
	
	//assigning the value in queue to stack
	control=dequeue(&queue1);
	while(control!='X')
	{
		push(&stack1,control);
		control=dequeue(&queue1);
	}
	
	initialize(&queue1);
	
	
	//REPLAYED FOR NOT PRINTING REVERSLY LAST NAME
		control=pop(&stack1);
		while(control!='X')
		{
			engueue(&queue1,control);	
			control=pop(&stack1);
		}
		

		
		control=dequeue(&queue1);
		while(control!='X')
		{
			push(&stack1,control);	
			control=dequeue(&queue1);
		}
	//	
	
	initialize(&queue1);
	
	for(i-=1;i!=-1;i--)
	{
		
		engueue(&queue1,swap[i]);
	}
	
	
	//printing "Muharrem" in queue
	
	printf("%c\n",dequeue(&queue1));
	printf("%c\n",dequeue(&queue1));
	printf("%c\n",dequeue(&queue1));
	printf("%c\n",dequeue(&queue1));
	printf("%c\n",dequeue(&queue1));
	printf("%c\n",dequeue(&queue1));
	printf("%c\n",dequeue(&queue1));
	printf("%c\n",dequeue(&queue1));
	
	printf("---\n");
	
	//printing "Aslan" in stack;
	
	printf("%c\n",pop(&stack1));
	printf("%c\n",pop(&stack1));
	printf("%c\n",pop(&stack1));
	printf("%c\n",pop(&stack1));
	printf("%c\n",pop(&stack1));
	
	// if  it is empty, prints 'X'
	printf("%c\n",pop(&stack1));
	
	
	return 0;
}
char engueue(queue *q,char x){
	
	if(isFull(q))
	return 'X';
	
	else if(!(isEmpty(q))&& q->rear==QUEUE_SIZE-1){
		q->rear=0;
	}
	
	q->array[q->rear++]=x;
	q->counter++;
	
}
char dequeue(queue *q){
	
	if(isEmpty(q))
		return 'X';
	
	else if(q->front==QUEUE_SIZE){
		q->front=0;
	}
	
	q->counter--;
	return q->array[q->front++];
	
}
void initialize(queue *q){
	q->front=0;
	q->rear=0;
	q->counter=0;
}
int isFull(queue *q){
	if(q->counter==QUEUE_SIZE)
	return 1;
	
	return 0; 
}
int isEmpty(queue *q){
	if(q->counter==0)
	return 1;
	
	return 0; 
}
void initilazeStack(stack*stk){
	stk->top=-1; 
}
char pop(stack* stk)
{
	if(stk->top==-1)
		return 'X';
	
	else{
		return stk->array[stk->top--];
	}
	
	
}
char push(stack *stk,char x){
	
	if(stk->top==STACK_SIZE)
			return 'X';
	else{
		
		stk->array[++(stk->top)]=x;
		
	}
}
