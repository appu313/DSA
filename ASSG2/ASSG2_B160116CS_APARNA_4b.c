#include<stdio.h>
#include<stdlib.h>
void main()
{
long int size,ele,start=0;
scanf("%ld",&size);
if(size<=0)
{
printf("size must be greater than 1");
exit(0);
}

long int *a=(long int *)malloc(sizeof(long int));
for(long int i=0;i<size;++i)
{
a=(long int *)realloc(a,(i+1)*sizeof(long int));
scanf("%ld",&a[i]);
if(i!=0)
if(a[i-1]>a[i])
{start=i;
}
}
scanf("%ld",&ele);
long int mid,new_mid,new_start=0,new_end=size-1;
while(new_start<=new_end)
{
new_mid=(new_start+new_end)/2;
if(new_mid+start<size)
mid=new_mid+start;
else
mid=new_mid+start-size;
if(a[mid]==ele)
{
printf("%ld",mid);
exit(0);
}
else if(ele<a[mid])
new_end=new_mid-1;
else
new_start=new_mid+1;
}
printf("-1");
}
