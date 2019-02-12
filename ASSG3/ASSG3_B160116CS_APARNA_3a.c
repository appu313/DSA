#include<stdio.h>
#include<stdlib.h>
long int start,rear,n;
long int *a;
void enqueue(long int val)
{
if((start==0 && (rear==(n-1)))||(start==(rear+1)))
{
printf("-2\n");
return;
}
if(start==-1)
start=rear=0;
else if(rear==n-1)
rear=0;
else
rear=rear+1;
//printf("Start and rear:%ld %ld %ld\n",start,rear,n);
a[rear]=val;
}

void print_queue()
{
if(start==-1)
printf("-1");
else if(rear>=start)
for (long int i=start;i<=rear;++i)
printf("%ld ",a[i]);
else
{
for (long int i=start;i<n;++i)
printf("%ld ",a[i]);
for(long int i=0;i<=rear;++i)
printf("%ld ",a[i]);
}
printf("\n");
}

long int dequeue()
{
if(start==-1)
return -1;
long int res=a[start];
if(start==rear)
start=rear=-1;
else if(start==n-1)
start=0;
else
start++;
//printf("Start and rear:%ld %ld %ld\n",start,rear,n);
return res;

}
int main()
{
char ch;
long int ele;
scanf("%ld", &n);
//printf("%ld\n",n);
a=(long int *)malloc(n*sizeof(long int));;
while(getchar()!='\n');
scanf("%c",&ch);
start=rear=-1;
do
{
if(ch=='e')
{
scanf("%ld",&ele);
//printf("%ld %ld\n",ele,n);
enqueue(ele);
//print_queue();
}
else if(ch=='d')
{
ele=dequeue();
printf("%ld\n",ele);
}
else if(ch=='p')
print_queue();
else if(ch=='s')
break;
while(getchar()!='\n');
scanf("%c",&ch);
}while(ch!='s');
free(a);
return 0;
}
