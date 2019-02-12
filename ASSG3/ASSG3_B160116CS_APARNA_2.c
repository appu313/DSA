#include<stdio.h>
#include<stdlib.h>

int borrow=0;
struct Node
{
	int info;
	struct Node* next;
}*start1,*rear1,*start2,*rear2,*start,*rear,*newptr,*prev,*succ,*ptr,*temp;

struct Node* CreateNewNode(int n)
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
	temp=start;
	start=rear;
	rear=temp;
}

void Display(struct Node* np)
{
	while(np!=NULL)
	{
		printf("%d",np->info);
		np =np->next;
	}
	printf("\n");
}

void FindLarger(struct Node*np1,struct Node*np2)
{
	int flag=1;
while(np1!=NULL)
{
if(np1->info>np2->info)
return;
if(np1->info<np2->info)
{
flag=2;
break;
}
np1=np1->next;
np2=np2->next;
}

if (flag==2)
{
temp=start1;
start1=start2;
start2=temp;

temp=rear1;
rear1=rear2;
rear2=temp;
}
}

void difference_of_digit(struct Node *np1,struct Node *np2)
{
if(np1!=NULL)
if((np1->info-borrow)>=np2->info)
{
np1->info=np1->info-borrow-np2->info;
borrow=0;
difference_of_digit(np1->next,np2->next);
}
else
{
np1->info=10+np1->info-borrow-np2->info;
borrow=1;
difference_of_digit(np1->next,np2->next);
}
return;
}
void DisplayRes(struct Node*np)
{
int inner_zero=0;
while(np!=NULL)
	{
if(np->info!=0)
{
		printf("%d",np->info);
inner_zero=1;
}
else if(inner_zero==1)
		printf("%d",np->info);
		np =np->next;
	}
	
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
void main()
{
	start1 =rear1=NULL;
	char c;
	c=getchar();
   start=start1;
   rear=rear1;	
	while(c!='\n')
	{
		c-='0';
		ptr=CreateNewNode(c);
		Insert(ptr);
		c=getchar();
	}
   start1=start;
   rear1=rear;
//	Display(start1);


	start2 =rear2=NULL;
   start=start2;
   rear=rear2;
	c=getchar();
   while(c!='\n')
   {
c-='0';
   ptr=CreateNewNode(c);
   Insert(ptr);
   c=getchar();
   }
   start2=start;
   rear2=rear;

//   Display(start2);

FindLarger(start1,start2);
//Display(start1);

start=start1;
   rear=rear1;

Reverse(start1);
start1=start;
	rear1=rear;

//Display(start1);

start=start2;
   rear=rear2;
Reverse(start2);
start2=start;
	rear2=rear;
//Display(start2);

difference_of_digit(start1,start2);

//Display(start1);

start=start1;
   rear=rear1;

Reverse(start1);
start1=start;
	rear1=rear;

DisplayRes(start1);
free_mem(start1);
free_mem(start2);
   }
