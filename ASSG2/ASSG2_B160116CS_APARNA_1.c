
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

long int ceiling(float num)
{
if(num==(long int)num)
return (long int)num;
else
return ((long int)num+1);
}

void merge(long int a[],long int start,long int mid1,long int mid2,long int end)
{
long int i,j,k,cnt,size=end-start+1;
long int n1=(mid1-start+1)+1,n2=mid2-mid1+1,n3=end-mid2+1;
long int l[n1],m[n2],u[n3];
for(i=0;i<n1-1;++i)
{
l[i]=a[start+i];}
l[i]=LONG_MAX;

for(i=0;i<n2-1;++i)
{
m[i]=a[mid1+1+i];}
m[i]=LONG_MAX;

for(i=0;i<n3-1;++i)
{
u[i]=a[mid2+1+i];}
u[i]=LONG_MAX;

i=j=k=cnt=0;
while(cnt<size)
{
if(l[i]<m[j])
if(l[i]<u[k])
{
a[start+cnt]=l[i];
++i;
}
else
{
a[start+cnt]=u[k];
++k;
}
else
if(m[j]<u[k])
{
a[start+cnt]=m[j];
++j;
}
else
{
a[start+cnt]=u[k];
++k;
}
++cnt;
}

}
void merge_sort(long int a[],long int start,long int end)
{
long int size=end-start+1;
if(start<end)
{
long int mid1=start+ceiling(size/3.0)-1;
long int mid2=end-ceiling(size/3.0);
merge_sort(a,start,mid1);
merge_sort(a,mid1+1,mid2);
merge_sort(a,mid2+1,end);
merge(a,start,mid1,mid2,end);
}
}
void main()
{
long int num,size=0;
long int*a=(long int *)malloc(sizeof(long int));
FILE*fin =fopen("in","rb");
if(fin==NULL)
{
printf("Error");
exit(0);
}
while(fscanf(fin,"%ld",&num)!=EOF)
{
a=(long int*)realloc(a,(size+1)*sizeof(long int));
a[size]=num;
++size;
}
fclose(fin);
merge_sort(a,0,size-1);
FILE*fout=fopen("out","wb");
if(fout==NULL)
{
printf("Error");
exit(0);
}
for (int i=0;i<size;++i)
fprintf(fout,"%ld ",a[i]);
fclose(fout);
free(a);
}
