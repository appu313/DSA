#include<stdio.h>
#include<stdlib.h>
int hcf(int a,int b)
{
	int rem;
	if(a<0)
		a=-a;
	if(a<b)
	{
		int temp=a;
		a=b;
		b=temp;
	}

	while(b!=0)
	{
		rem=a%b;
		a=b;
		b=rem;
	}

	return a;
}

int lcm(int a,int b)
{
	int fac=hcf(a,b);
	int res=fac*(a/fac)*(b/fac);
} 

struct rat
{
	int num;
	int den;
};

void print_simplest_form(struct rat r)
{
	struct rat res;
	int factor=hcf(r.num,r.den);
	res.num=r.num/factor;
	res.den=r.den/factor;
	printf("%d/%d",res.num,res.den);
}

void main()
{
	int ch;
	scanf("%d",&ch);
	int factor;
	struct rat r,r1,r2,res;
	switch(ch)
	{
		case (1):
		{
			scanf("%d %d",&r.num,&r.den);
			if(r.den==0)
			{
				printf("Error:Division by 0");
				exit(0);
			}
			if(r.den<0)
			{
				r.num=-r.num;
				r.den=-r.den;
			}
			print_simplest_form(r);

			break;
		}

		case (2):
		{

			scanf("%d %d",&r1.num,&r1.den);
			if(r1.den==0)
			{
				printf("Error:Division by 0");
				exit(0);
			}

			if(r1.den<0)
			{
				r1.num=-r1.num;
				r1.den=-r1.den;
			}

			scanf("%d %d",&r2.num,&r2.den);
			if(r2.den==0)
			{
				printf("Error:Division by 0");
				exit(0);
			}

			if(r2.den<0)
			{
				r2.num=-r2.num;
				r2.den=-r2.den;
			}
			res.den=lcm(r1.den,r2.den);
			if(r1.den!=res.den)
				res.num=(res.den/r1.den)*r1.num;
			else
				res.num=r1.num;

			if(r2.den!=res.den)
				res.num+=(res.den/r2.den)*r2.num;
			else
				res.num+=r2.num;


			print_simplest_form(res);
			break;
		}

		case (3):
		{

			scanf("%d %d",&r1.num,&r1.den);
			if(r1.den==0)
			{
				printf("Error:Division by 0");
				exit(0);
			}

			if(r1.den<0)
			{
				r1.num=-r1.num;
				r1.den=-r1.den;
			}

			scanf("%d %d",&r2.num,&r2.den);
			if(r2.den==0)
			{
				printf("Error:Division by 0");
				exit(0);
			}

			if(r2.den<0)
			{
				r2.num=-r2.num;
				r2.den=-r2.den;
			}
			res.num=r1.num*r2.num;
			res.den=r1.den*r2.den;

			print_simplest_form(res);
			break;
		}

		case (4):
		{
			int n,arr_lcm=1;

			scanf("%d",&n);
			if(n<1)
			{
				printf("There should be atleast 1 element");
				exit(0);
			}

			struct rat key;
			struct rat * arr_rat=(struct rat *)malloc(n*sizeof(struct rat));

			for(int i=0;i<n;++i)
			{
				scanf("%d %d",&(arr_rat+i)->num,&(arr_rat+i)->den);
				if((arr_rat+i)->den==0)
				{
					printf("Error:Division by 0");
					exit(0);
				}
				if((arr_rat+i)->den<0)
				{
					(arr_rat+i)->num=-(arr_rat+i)->num;
					(arr_rat+i)->den=-(arr_rat+i)->den;
				}
			}
			for(int i=0;i<n;++i)
				arr_lcm=lcm((arr_rat+i)->den,arr_lcm);


			for(int j=1;j<n;++j)
			{
				key=*(arr_rat +j);
				int i=j-1;
				for(;i>=0;--i)
				if(((arr_rat+i)->num*(arr_lcm/ (arr_rat+i)->den))>(key.num*(arr_lcm/key.den)))
				*(arr_rat+i+1)=*(arr_rat+i);
				else
				break;
				*(arr_rat+i+1)=key;
			}
			for(int i=0;i<n;++i)
				printf("%d/%d ",(arr_rat+i)->num,(arr_rat+i)->den);
			free(arr_rat);
			break;
		}

		case (5):
		{

			scanf("%d %d",&r.num,&r.den);
			if(r.den==0)
			{
				printf("Error:Division by 0");
				exit(0);
			}
			if(r.den<0)
			{
				r.num=-r.num;
				r.den=-r.den;
			}

			print_simplest_form(r);
			break;
		}

		default:
			printf("Error");

	}
}

