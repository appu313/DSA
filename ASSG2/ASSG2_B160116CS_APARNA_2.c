#include<stdio.h>
#include<stdlib.h>
long int cnt=3;
long int ceiling(float num)
{
if(num==(long int)num)
return (long int)num;
else
return ((long int)num+1);
}
void insertion_sort(long int a[],long int s,long int e)
{
long int key,j;
for(long int i=s;i<=e;++i)
{
key=a[i];
j=i-1;
while(j>=s && a[j]>key)
{
a[j+1]=a[j];
--j;
}
a[j+1]=key;
}
}

long int select_med(long int a[],long int s,long int e)
{
long int temp,new_s,med_ind,new_e,size=e-s+1;
if(size<=5)
{
insertion_sort(a,s,e);
if(size%2==0)
return (s+size/2-1);
else
return (s+size/2);
}

for(long int i=0;i<ceiling(size/5.0);++i)
{
new_s=i*5;
new_e=i*5+4;

if(s+new_e>e)
med_ind=select_med(a,s+new_s,e);
else
med_ind=select_med(a,s+new_s,s+new_e);

temp=a[med_ind];
a[med_ind]=a[s+i];
a[s+i]=temp;


//making the median come to front

}
long int res=select_med(a,s,s+ceiling(size/5.0)-1);
return(res);
}

long int partition(long int a[],long int p,long int r)
{
long int ind_med=select_med(a,p,r);
// the sorted aray from which the median is obtained
if(cnt!=0)
{
printf("%ld\n",a[ind_med]);
--cnt;
}
long int temp=a[ind_med];
a[ind_med]=a[r];
a[r]=temp;
long int i=p-1;
for(long int j=p;j<r;++j)
if(a[j]<=a[r])
{i+=1;
temp=a[i];
a[i]=a[j];
a[j]=temp;
}

temp=a[i+1];
a[i+1]=a[r];
a[r]=temp;
return (i+1);
}

void quick_sort(long int a[],long int p,long int r)
{
if(p<r)
{
long int q=partition(a,p,r);
quick_sort(a,p,q-1);
quick_sort(a,q+1,r);
}
}
void main()
{
long int n;
scanf("%ld",&n);
long int *a=(long int*)malloc(sizeof(long int));
if(n<=0)
{
printf("size must be greater than 1");
exit(0);
}
for(long int i=0;i<n;++i)
{
a=(long int*)realloc(a,(i+1)*sizeof(long int));
scanf("%ld",&a[i]);
}
if(n==1)
{
printf("%ld\n",a[0]);
}
quick_sort(a,0,n-1);
for(long int i=0;i<n;++i)
printf("%ld ",a[i]);
}
