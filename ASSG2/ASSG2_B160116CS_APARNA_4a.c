#include<stdio.h>
#include<stdlib.h>
void main()
{
long int m,n,ele;
long int *a = malloc(sizeof(long int));
scanf("%ld %ld",&m,&n);
if(n<=0)
{
printf("size must be greater than 1");
exit(0);
}
if(m<=0)
{
printf("size must be greater than 1");
exit(0);
}
long int size=1;
for (long int i=0;i<m;++i)
for (long int j=0;j<n;++j)
{
scanf("%ld",&ele);
a=(long int *) realloc(a,size*(sizeof(long int)));
*(a+i*n+j)=ele;
++size;
}
scanf("%ld",&ele);
long int r=m-1,c=0;
for (long int i=0;i<m+n;++i)
if(ele==*(a+r*n+c))
{
printf("1");
break;
}
else if (ele<*(a+r*n+c)&&r>0)
--r;
else if(ele>*(a+r*n+c)&&c<n)
++c;
else
{
printf("-1");
break;
}
}
