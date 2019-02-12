#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void push(int *a,int *start,int ele)
{
//a=(char *)realloc(a,(*start+2)*(sizeof(char)));
*start+=1;
a[*start]=ele;
}
int pop(int *a,int*start)
{
int res=a[*start];
*start-=1;
return res;
}
int main()
{
char str[1000],sub_str[1000];/////change size
int op1,op2,num,sum_len=0,out_len=0;
int start_sum=-1,val,start_out=-1;
scanf(" %[^\n]s",str);
//str[sum_len]=' ';
int sum_arr[1000];/////change size
char out_sub[1000],s1[1000],s2[1000],s_res[1000],out_arr[1000][1000];

for (int i=0;str[i]!='\0';++i)
{
if(!isalnum(str[i]))
{

if(str[i]==' ')        //when the value is a space
{
if(sum_len==1)                       //when the prev value is a single character
{
val=sub_str[0]-'0';              
push(sum_arr,&start_sum,val);
}
else if(sum_len>1)                    //when the prev values are not a single character
{
num=0;
for(int i=0;i<sum_len;++i)
num=num*10+sub_str[i]-'0';
push(sum_arr,&start_sum,num);
}
sum_len=0;
//push(*out_arr,&start_out,out_sub);


if((strcmp(out_sub,"\0")))
{start_out+=1;
strcpy(out_arr[start_out],out_sub);}
out_len=0;

}
else
{
strcpy(s2,out_arr[start_out]);
strcpy(s1,out_arr[start_out-1]);
op2=pop(sum_arr,&start_sum);
op1=pop(sum_arr,&start_sum);        //when it is an operator
if(str[i]=='+')
{
strcat(s1,"+");
val=op1+op2;}
else if(str[i]=='-')
{strcat(s1,"-");
val=op1-op2;}
else if(str[i]=='*')
{
strcat(s1,"*");
val=op1*op2;}
else if(str[i]=='/')
{strcat(s1,"/");
val=op1/op2;}
push(sum_arr,&start_sum,val);

strcat(s1,s2);
start_out-=1;
strcpy(out_arr[start_out],s1);
strcpy(out_sub,"\0");
}
}
else          //if it is a digit add it to sub_str
{

out_sub[out_len]=str[i];
out_sub[out_len+1]='\0';
sub_str[sum_len]=str[i];
++sum_len;
++out_len;
//for(int i=0;i<out_len;++i)

}
}
printf("%s\n",out_arr[0]);
printf("%d",sum_arr[0]);

return 0;
}
