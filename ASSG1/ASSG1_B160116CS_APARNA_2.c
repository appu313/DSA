#include<stdio.h>
int main()
{
	FILE * fin;
	FILE *fout;
	int flag =0;
	char ch;
	fin = fopen("in.txt","r");
	fout = fopen("out.txt","w");
	if(fin==NULL)
	{
		printf("Error");
		return 0;
	}
	ch=fgetc(fin);
	while(ch!=EOF)
	{
		if(ch=='\t')
			ch=' ';
		if(ch!=' ')
		{
			flag=0;
			fprintf(fout,"%c",ch);
		}
		else if(ch==' '&& flag  == 0)
		{
			fprintf(fout,"%c",ch);
			++flag;
		}
		ch=fgetc(fin);
	}
	fclose(fin);
	return 0;
}
