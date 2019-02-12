#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void main()
{
	int ch,str_len,key,i=1;
	char *str;
        scanf("%d",&ch);
	if(ch!=1 && ch!=2)
	{
		printf("Error:either 1 or 2");
		exit(0);
	}
        scanf("%d",&str_len);
	char c=getchar();
	str=(char *) malloc(sizeof(char));
	while((c=getchar())!='\n')
	{
		str=(char *)realloc(str,(i+1)*sizeof(char));
		*(str + i)=c;
		++i;
	}
	if(i-1!=str_len)
	{
		printf("Incorrect string length");
		exit(0);
	}
        scanf("%d",&key);
	if(key<0)
	{
		printf("Error:key should be positive");
		exit(0);
	}
	switch (ch)
	{
		case 1:
			for(int i=0;i<=str_len;++i)
				if(isalpha(*(str + i )) && isalpha(*(str + i )+key))
					*(str + i )+=key;
				else if(isalpha(*(str + i )))
				{
				if(isupper(*(str + i )))
					*(str + i )='A'+key-1-('Z'-*(str + i ));
				else
				*(str + i )='a'+key-1-('z'-*(str + i ));
				}
			for(int i=0;i<=str_len;++i)
				printf("%c",*(str+i));
			break;
		case 2:
			for(int i=0;i<=str_len;++i)
				if(isalpha(*(str + i )) && isalpha(*(str + i )-key))
					*(str + i )=*(str + i )-key;
				else if(isalpha(*(str + i )))
				{
				if(isupper(*(str + i )))
					*(str + i )='Z'-(key-1-(*(str + i )-'A'));
				else
					*(str + i )='z'-(key-1-(*(str + i )-'a'));
				}
			for(int i=0;i<=str_len;++i)
				printf("%c",*(str+i));
			break;

	}
	free(str);
}


