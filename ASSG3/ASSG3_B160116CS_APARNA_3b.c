#include<stdio.h>
#include<stdlib.h>
struct Node
{
long int info;
struct Node*next;
}*start,*rear,*ptr,*newptr;

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

void print_queue()
{
struct Node* np=start;
if(np==NULL)
printf("-1");
	while(np!=NULL)
	{
		printf("%ld ",np->info);
		np =np->next;
	}
	printf("\n");
}

void enqueue(long int val)
{
//printf("hi\n");
ptr=CreateNewNode(val);
Insert(ptr);
//Display(start);
//printf("hi\n");
}

long int dequeue()
{
if(start==NULL)
return -1;
ptr=start;
long int res=start->info;

if(start==rear)
start=rear=NULL;
else
start=start->next;
free(ptr);
return res;
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

int main()
{
char ch;
long int ele;
//while(getchar()!='\n');
scanf("%c",&ch);
start=rear=NULL;
do 
{
if(ch=='e')
{
scanf("%ld",&ele);
enqueue(ele);

}
else if(ch=='d')
{
ele=dequeue();
printf("%ld\n",ele);
//Display(start);
}
else if(ch=='p')
print_queue();
else if(ch=='s')
break;

while(getchar()!='\n');
scanf("%c",&ch);
}while(ch!='s');
free_mem(start);
return 0;
}
