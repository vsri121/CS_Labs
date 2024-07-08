#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int mutex = 1;
int full = 0;
int x = 0;
int empty = MAX;

void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("Producer has produced item %d",x);
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("Consumer has consumed item %d",x);
	x--;
	++mutex;
}

int main()
{
	int n,i;
	printf("\nEnter 1 for Producer"
	       "\nEnter 2 for consumer"
	       "\nEnter 3 to exit");
	for(i=1;i>0;i++)
	{
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				if((mutex == 1) && (empty != 0))
				{
					producer();
				}
				else
				{
					printf("Buffer is full!, Producer cannot produce");
				}
				break;
			case 2:
				if((mutex == 1) && (full != 0))
				{
					consumer();
				}
				else
				{
					printf("Buffer is empty!, Consumer cannot consume");
				}
				break;
			case 3:
				exit(0);
				break;
		}
	}
	return 0;
}
