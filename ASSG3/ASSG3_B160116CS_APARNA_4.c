#include<stdio.h>
#include<stdlib.h>
int n=0;   ////size of the queue
struct pq_elem
{
int info;
int prior;
};         //change size
void min_heapify(struct pq_elem *pq,int i,int n)
{
int l =2*i+1;
int r =2*i+2,min;
if(l<n && pq[l].prior<pq[i].prior)
min =l;
else
min =i;
if(r<n && pq[r].prior<pq[min].prior)
min =r;
if(min!=i)
{
struct pq_elem temp=pq[i];
pq[i]=pq[min];
pq[min]=temp;
min_heapify(pq,min,n);
}
}

void build_min_heap(struct pq_elem *pq,int n)
{
for(int i=n/2;i>=0;--i)
min_heapify(pq,i,n);
}

void insert(struct pq_elem *pq,int elem,int pr)
{
long int size=sizeof(pq)/sizeof(struct pq_elem);
pq=realloc(pq,(size+1)*sizeof(struct pq_elem));
struct pq_elem pq_one_elem;
pq_one_elem.info=elem;
pq_one_elem.prior=pr;
pq[n]=pq_one_elem;
++n;

build_min_heap(pq,n);
}

void extract_min(struct pq_elem *pq)
{
if(n==0)
printf("EMPTY\n");
else
{
printf("%d (%d)\n",pq[0].info,pq[0].prior);
struct pq_elem temp=pq[n-1];
pq[n-1]=pq[0];
pq[0]=temp;
--n;
min_heapify(pq,0,n);
}
}

void get_min(struct pq_elem *pq)
{
if(n==0)
printf("EMPTY\n");
else
printf("%d (%d)\n",pq[0].info,pq[0].prior);

}

void decrease_priority(struct pq_elem *pq,int elem,int newpr)
{
int res;
int i;
for( i=0;i<n;++i)
if (elem==pq[i].info)
{
res=i;
pq[i].prior=newpr;
break;}
int parent=(i-1)/2;
while(parent>=0 && pq[parent].prior>newpr)
{
//printf("hi\n");
struct pq_elem temp=pq[parent];
pq[parent]=pq[res];
pq[res]=temp;
parent=(i-1)/2;
//printf("hi\n");
}
}
int main()
{
int elem,pr;
struct pq_elem *pq=malloc(sizeof(struct pq_elem));
char ch;
scanf("%c",&ch);
do
{
if(ch=='a')
{
scanf("%d %d",&elem,&pr);
insert(pq,elem,pr);
}
else if(ch=='e')
extract_min(pq);
else if(ch=='g')
get_min(pq);
else if(ch=='d')
{
scanf("%d %d",&elem,&pr);
decrease_priority(pq,elem,pr);
}
scanf("%c",&ch);
}while(ch!='s');
free(pq);
return 0;
}
