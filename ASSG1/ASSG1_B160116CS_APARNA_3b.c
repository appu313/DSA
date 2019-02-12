#include<stdio.h>
#include<stdlib.h>
void transpose(int n,int * a,int i,int j)
{
	if(i==n)
		return;

	else if(j==i)
	t	ranspose(n,a,i+1,0);

	else
	{
		*(a+i*n+j)+=*(a+j*n+i);
		*(a+j*n+i)=*(a+i*n+j)-*(a+j*n+i);
		*(a+i*n+j)-=*(a+j*n+i);

		transpose(n,a,i,j+1);
	}
}

void main()
{
	int m,n,size;

	scanf("%d",&n);
	if(n<1)
	{
		printf("The order of a matix should be greater than 0");
		exit(0);
	}
	int * a=(int *) malloc(n* m* sizeof(int));
	for (int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",(a+i*n+j));

	transpose(n,a,0,0);

	size=m=n;

	int i=0,j=0;
	while(i<m)
	{
		for(int k=j;k<n;++k)
			printf("%d ",*(a+i*size+k));
		++i;
		for(int k=i;k<m;++k)
			printf("%d ",*(a+k*size+n-1));
		--n;
		if(i<m)
		{
			for(int k=n-1;k>=j;--k)
				printf("%d ",*(a+(m-1)*size+k));
			--m;
		}
		if(j<n)
		{
			for(int k=m-1;k>=i;--k)
				printf("%d ",*(a+k*size+j));
			j++;
		}
	}

}
