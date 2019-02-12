#include<stdio.h>
#include<stdlib.h>

struct Node
{
	long int info;
	struct Node* next;
}*start,*rear,*newptr,*prev,*succ,*ptr;

         struct Node* CreateNewNode(long int n)
{
	newptr=(struct Node *)malloc(sizeof(struct Node *));
	if(newptr==NULL)
	{
		printf("Error");
		exit(0);
	}
	newptr->info=n;
	newptr->next=NULL;
	return newptr;
}

void Insert(struct Node *np)
{
	if(start==NULL)
		start=rear=np;
	else
	{
		rear->next=np;
		rear=np;
	}
}

void Reverse(struct Node *np)
{
	prev=np;
	ptr=np->next;
	np->next=NULL;
	while(ptr!=NULL)
	{
		succ=ptr->next;
		ptr->next=prev;
		prev=ptr;
		ptr=succ;
	}
	start=rear;
}
void free_mem(struct Node *np)
{
while(np!=NULL)
{
struct Node *temp;
temp=np;
np=np->next;
free(temp);
}
}
void Display(struct Node* np)
{
	while(np!=NULL)
	{
		printf("%ld ",np->info);
		np =np->next;
	}
	//printf("\n");
}

void main()
{
	start =rear=NULL;
	long int val;
	char c='a';
	while(c!='\n')
	{
		scanf("%ld",&val);
		c=getchar();
		ptr=CreateNewNode(val);
		Insert(ptr);
	}
	Reverse(start);
	Display(start);
free_mem(start);
}
