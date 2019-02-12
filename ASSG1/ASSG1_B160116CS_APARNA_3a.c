#include<stdio.h>
#include<stdlib.h>
void reverse(char *str,int size,int index)
{
	if(size==0)
		return;
	*(str+index)=*(str+index)+*(str+size-index);
	*(str+size-index)=*(str+index)-*(str+size-index);
	*(str+index)=*(str+index)-*(str+size-index);
	if(size%2!=0&&index==(size-1)/2)
		return;
	else if(size%2==0&&index==size/2-1)
		return;
	else
		reverse(str,size,index+1);
}
void main()
{
	char*str;;
	char c=getchar();
	str=(char *) malloc(sizeof(char));
	*str =c;
	int size=1;
	while((c=getchar())!='\n')
	{
		str=(char *)realloc(str,(size+1)*sizeof(char));
		*(str + size)=c;
		++size;
	}

	reverse(str,size-1,0);

	for(int i=0;i<size;++i)
		printf("%c",*(str+i));
	free(str);

}
