#include<stdio.h>
#include<stdlib.h>
char mode;
int *ht_open;
int m;

struct Node
{
int info;
struct Node* ptr;
};

struct ht_elem
{
struct Node*start;
struct Node*rear;
}*ht_chain;

struct Node* CreateNewNode(int val)
{
struct Node* new_ptr=(struct Node*)malloc(sizeof(struct Node));
if(new_ptr==NULL)
{
printf("Error");
exit(0);
}
new_ptr->info=val;
new_ptr->ptr=NULL;
return new_ptr;
}

void insert_linked_list(struct Node**start,struct Node**rear,struct Node*np)
{
if(*start==NULL)
*start=*rear=np;
else
{
(*rear)->ptr=np;
(*rear)=np;
}
}

void print_linked_list(struct Node*np)
{
printf("(");
while(np!=NULL)
{
if(np->ptr==NULL)
printf("%d",np->info);
else
printf("%d ",np->info);
np=np->ptr;
}
printf(")");
}

void search_linked_list(struct Node *np,int key)
{
while(np!=NULL&&np->info!=key)
np=np->ptr;
if(np==NULL)
printf("-1\n");
else
printf("1\n");
}

void del_linked_list(struct Node**start,int key)
{
struct Node*prev,*temp,*np=*start;
while(np!=NULL&&np->info!=key)
{
prev=np;
np=np->ptr;
}
if (np==NULL)
return;
else if (*start==np)
{*start=np->ptr;
free(np);
}
else
{
temp=np;
prev->ptr=np->ptr;
free(temp);
}
}

//////////////////////////////////

void hashTable_chain(int m)
{
ht_chain =calloc(m,sizeof(struct ht_elem));
for(int i=0;i<m;++i)
{
ht_chain[i].start=NULL;
ht_chain[i].rear=NULL;
}
}

void insert_chain(int key)
{
int index=key%m;
struct Node*ptr=CreateNewNode(key);
insert_linked_list(&(ht_chain[index].start),&(ht_chain[index].rear),ptr);
}

void print_chain()
{
for(int i=0;i<m;++i)
{
printf("%d ",i);
print_linked_list(ht_chain[i].start);
printf("\n");
}
}

void search_chain(int key)
{
int index=key%m;
search_linked_list(ht_chain[index].start,key);
}

void del_chain(int key)
{
int index=key%m;
del_linked_list(&(ht_chain[index].start),key);
}

//////////////////////////////////
void hashTable_open(int m)
{

ht_open =calloc(m,sizeof(int));
for(int i=0;i<m;++i)
ht_open[i]=0;

}

void print_open()
{
for(int i=0;i<m;++i)
{
if(ht_open[i]==0||ht_open[i]==-1)
printf("%d ()\n",i);
else
printf("%d (%d)\n",i,ht_open[i]);
}
}
//////////////////////////////////
void insert_linear(int key)
{
int index=key%m;
while(ht_open[index]!=0 && ht_open[index]!=-1)
index=(index+1)%m;
ht_open[index]=key;
}

void search_linear(int key)
{
int index=key%m;
int cnt=0;
while(ht_open[index]!=key)
{
if(ht_open[index]==0)
{
cnt=m;
break;
}
else if(cnt==m)
break;
else
index=(index+1)%m;
cnt++;
}
if (cnt==m)
printf("-1\n");
else
printf("1\n");

}

void del_linear(int key)
{
int index=key%m;
int cnt=0;
while(ht_open[index]!=key)
{
if(ht_open[index]==0)
{
cnt=m;
break;
}
else if(cnt==m)
break;
else
index=(index+1)%m;
}

if (cnt==m)
printf("-1\n");
else
{
ht_open[index]=-1;
}


}
//////////////////////////////////
void insert_quad(int key)
{
int index=key%m,i=1;
int init_index=index;
while(ht_open[index]!=0&&ht_open[index]!=-1)
{
index=(init_index+i*i)%m;
++i;
}

ht_open[index]=key;
}

void search_quad(int key)
{
int index=key%m;
int cnt=0,i=1;
while(ht_open[index]!=key)
{
if(ht_open[index]==0)
{
cnt=m;
break;
}
else if(cnt==m)
break;
else
{
index=(key%m+i*i)%m;
i++;
}
cnt++;
}
if (cnt==m)
printf("-1\n");
else
printf("1\n");

}

void del_quad(int key)
{
int index=key%m;
int cnt=0,i=1;
while(ht_open[index]!=key)
{
if(ht_open[index]==0)
{
cnt=m;
break;
}
else if(cnt==m)
break;
else
{
index=(key%m+i*i)%m;
i++;
}
}

if (cnt==m)
printf("-1\n");
else
{
ht_open[index]=-1;
}
}

//////////////////////////////////
void insert_double(int key)
{
int r=2,j;
for(int i=2;i<m;++i)
{
for(j=2;j<i;++j)
if(i%j==0)
break;
if(j==i)
r=i;
}
int index=key%m,i=1;
int init_index=index;
while(ht_open[index]!=0&&ht_open[index]!=-1)
{
index=(init_index+i*(r-key%r))%m;
++i;
}
ht_open[index]=key;
}

void search_double(int key)
{
int r=2,j;
for(int i=2;i<m;++i)
{
for(j=2;j<i;++j)
if(i%j==0)
break;
if(j==i)
r=i;
}

int index=key%m;
int cnt=0,i=1;
while(ht_open[index]!=key)
{
if(ht_open[index]==0)
{
cnt=m;
break;
}
else if(cnt==m)
break;
else
{
index=(key%m+i*(r-key%r))%m;
i++;
}
cnt++;
}
if (cnt==m)
printf("-1\n");
else
printf("1\n");

}

void del_double(int key)
{
int r=2,j;
for(int i=2;i<m;++i)
{
for(j=2;j<i;++j)
if(i%j==0)
break;
if(j==i)
r=i;
}

int index=key%m;
int cnt=0,i=1;
while(ht_open[index]!=key)
{
if(ht_open[index]==0)
{
cnt=m;
break;
}
else if(cnt==m)
break;
index=(key%m+i*(r-key%r))%m;
i++;
cnt++;
}

if (cnt==m)
printf("-1\n");
else
{
ht_open[index]=-1;
}
}
//////////////////////////////////
void hashTable(int m)
{
if(mode=='a'||mode=='b'||mode=='c')
hashTable_open(m);
else
hashTable_chain(m);
}

void insert(int key)
{
if(mode=='a')
insert_linear(key);
else if(mode=='b')
insert_quad(key);
else if(mode=='c')
insert_double(key);
else if(mode=='d')
insert_chain(key);
}

void print()
{
if(mode=='a'||mode=='b'||mode=='c')
print_open(m);
else
print_chain(m);
}

void search(int key)
{
if(mode=='a')
search_linear(key);
else if(mode=='b')
search_quad(key);
else if(mode=='c')
search_double(key);
else if(mode=='d')
search_chain(key);
}

void delete(int key)
{
if(mode=='a')
del_linear(key);
else if(mode=='b')
del_quad(key);
else if(mode=='c')
del_double(key);
else if(mode=='d')
del_chain(key);

}
//////////////////////////////////
int main()
{
char ch;
int key;
scanf("%c",&mode);
scanf("%d",&m);
while(getchar()!='\n');
scanf("%c",&ch);
hashTable(m);
do
{
if(ch=='i')
{
scanf("%d",&key);
insert(key);
}
else if(ch=='s')
{
scanf("%d",&key);
search(key);
}
else if(ch=='d')
{
scanf("%d",&key);
delete(key);
}
else if(ch=='p')
print();
else if(ch=='t')
exit(0);
while(getchar()!='\n');
scanf("%c",&ch);
}while(ch!='t');

return 0;
}
