#include<stdio.h>
#include<stdlib.h>
void max_heapify(long int a[],long int index,long int n)
{
long int largest,temp,l,r;
l=2*index+1;
r=2*index+2;
if(l<n && a[l]>a[index])
largest=l;
else
largest=index;
if(r<n && a[r]>a[largest])
largest=r;
if(largest!=index)
{
temp=a[index];
a[index]=a[largest];
a[largest]=temp;
max_heapify(a,largest,n);
}
}
void main()
{
long int n,k,temp;
scanf("%ld",&n);
if(n<=0)
{
printf("size must be greater than 1");
exit(0);
}
long int a[n];
for(long int i=0;i<n;++i)
scanf("%ld",&a[i]);
scanf("%ld",&k);
if(k<=0)
{
printf("k must be greater than 1");
exit(0);
}
// for building the heap
for(long int i=(n-1)/2;i>=0;--i)
max_heapify(a,i,n);
for(long int i=n-1;i>=0;--i)
{
temp=a[i];
a[i]=a[0];
a[0]=temp;
--k;
if(k==0)
{
printf("%ld",a[i]);
exit(0);
}
else
max_heapify(a,0,i);
}
printf("k value exceeds the size of the array");
}
