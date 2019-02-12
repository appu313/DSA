#include<stdio.h>
#include<stdlib.h>
int data_acc_a=0,data_acc_b=0,data_acc_c=0,data_acc_d=0;
struct regNode
{
int key;
struct regNode* p;
};

struct regTree_data_struct_a
{
struct regNode*root;
}reg_disj_set_a[10000];

struct regTree_data_struct_b
{
struct regNode*root;
int rank;
}reg_disj_set_b[10000];

struct regTree_data_struct_c
{
struct regNode*root;
}reg_disj_set_c[10000];

struct regTree_data_struct_d
{
struct regNode*root;
int rank;
}reg_disj_set_d[10000];


void CreateRegDisjSet_a()
{
for (int i=0;i<10000;++i)
{
reg_disj_set_a[i].root=NULL;
}
}

void CreateRegDisjSet_b()
{
for (int i=0;i<10000;++i)
{
reg_disj_set_b[i].root=NULL;
reg_disj_set_b[i].rank=0;
}
}

void CreateRegDisjSet_c()
{
for (int i=0;i<10000;++i)
{
reg_disj_set_c[i].root=NULL;
}
}

void CreateRegDisjSet_d()
{
for (int i=0;i<10000;++i)
{
reg_disj_set_d[i].root=NULL;
reg_disj_set_d[i].rank=0;
}
}

struct regNode * CreateRegNode(int val)
{
struct regNode* newptr=(struct regNode*)malloc(sizeof(struct regNode));
if(newptr==NULL)
{
printf("ERROR\n");
exit(0);
}
newptr->key=val;
newptr->p=NULL;
return newptr;
}


void makeset_a(int val)
{
if(reg_disj_set_a[val].root==NULL)
{
struct regNode* ptr=CreateRegNode(val);
reg_disj_set_a[val].root=ptr;
ptr->p=ptr;
printf("%d\n",val);
}
else
printf("PRESENT\n");
}

void makeset_b(int val)
{
if(reg_disj_set_b[val].root==NULL)
{
struct regNode* ptr=CreateRegNode(val);
reg_disj_set_b[val].root=ptr;
ptr->p=ptr;
}
}

void makeset_c(int val)
{
if(reg_disj_set_c[val].root==NULL)
{
struct regNode* ptr=CreateRegNode(val);
reg_disj_set_c[val].root=ptr;
ptr->p=ptr;
}
}

void makeset_d(int val)
{
if(reg_disj_set_d[val].root==NULL)
{
struct regNode* ptr=CreateRegNode(val);
reg_disj_set_d[val].root=ptr;
ptr->p=ptr;
}
}

struct regNode* find_a(int val)
{

struct regNode* x=reg_disj_set_a[val].root;
if(x!=NULL)
while(x->p!=x)
{
x=x->p;
++data_acc_a;
}
++data_acc_a;
return x;
}

struct regNode* find_b(int val)
{

struct regNode* x=reg_disj_set_b[val].root;
if(x!=NULL)
while(x->p!=x)
{
x=x->p;
++data_acc_b;
}
++data_acc_b;
return x;
}

struct regNode* find_c(int val)
{

struct regNode* x=reg_disj_set_c[val].root;
if(x==NULL)
return x;

if(x->p!=x)
{
x->p=find_c((x->p)->key);
++data_acc_c;
return x->p;
}
++data_acc_c;
return x;
}

struct regNode* find_d(int val)
{

struct regNode* x=reg_disj_set_d[val].root;
if(x==NULL)
return x;

if(x->p!=x)
{
x->p=find_d((x->p)->key);
++data_acc_d;
return x->p;
}
++data_acc_d;
return x;
}

void union_without_rank_a(int x,int y)
{
struct regNode* x_rep=find_a(x);
struct regNode* y_rep=find_a(y);
if(x_rep==NULL||y_rep==NULL)
{
printf("ERROR ");
return;
}
else if(x_rep!=y_rep)
y_rep->p=x_rep;
printf("%d ",x_rep->key);
}

void union_with_rank_b(int x,int y)
{

struct regNode* x_rep=find_b(x);
struct regNode* y_rep=find_b(y);
if(x_rep==NULL||y_rep==NULL)
{
printf("ERROR ");
return;
}
if(reg_disj_set_b[x_rep->key].rank>reg_disj_set_b[y_rep->key].rank)
//////y is smaller
{
y_rep->p=x_rep;
printf("%d ",x_rep->key);
}
else if(reg_disj_set_b[x_rep->key].rank==reg_disj_set_b[y_rep->key].rank)
///////both are equal
{
y_rep->p=x_rep;
reg_disj_set_b[x_rep->key].rank++;
printf("%d ",x_rep->key);
}
else
{

x_rep->p=y_rep;
printf("%d ",y_rep->key);
}
}

void union_without_rank_c(int x,int y)
{
struct regNode* x_rep=find_c(x);
struct regNode* y_rep=find_c(y);
if(x_rep==NULL||y_rep==NULL)
{
printf("ERROR ");
return;
}
else if(x_rep!=y_rep)
y_rep->p=x_rep;
printf("%d ",x_rep->key);
}

void union_with_rank_d(int x,int y)
{

struct regNode* x_rep=find_d(x);
struct regNode* y_rep=find_d(y);
if(x_rep==NULL||y_rep==NULL)
{
printf("ERROR\n");
return;
}
if(reg_disj_set_d[x_rep->key].rank>reg_disj_set_d[y_rep->key].rank)
//////y is smaller
{
y_rep->p=x_rep;
printf("%d\n",x_rep->key);
}
else if(reg_disj_set_d[x_rep->key].rank==reg_disj_set_d[y_rep->key].rank)
///////both are equal
{
y_rep->p=x_rep;
reg_disj_set_d[x_rep->key].rank++;
printf("%d\n",x_rep->key);
}
else
{

x_rep->p=y_rep;
printf("%d\n",y_rep->key);
}
}

int main()
{
int x,y;
struct regNode* temp;
CreateRegDisjSet_a();
CreateRegDisjSet_b();
CreateRegDisjSet_c();
CreateRegDisjSet_d();
char ch;
scanf("%c",&ch);
while(ch!='s')
{
if(ch=='m')
{
scanf("%d",&x);
makeset_a(x);
makeset_b(x);
makeset_c(x);
makeset_d(x);
}
else if(ch=='u')
{
scanf("%d",&x);
scanf("%d",&y);
union_without_rank_a(x,y);
union_with_rank_b(x,y);
union_without_rank_c(x,y);
union_with_rank_d(x,y);
}
else if(ch=='f')
{
scanf("%d",&x);
temp=find_a(x);
if(temp==NULL)
printf("NOT FOUND ");
else
printf("%d ",temp->key);

temp=find_b(x);
if(temp==NULL)
printf("NOT FOUND");
else
printf("%d ",temp->key);

temp=find_c(x);
if(temp==NULL)
printf("NOT FOUND");
else
printf("%d ",temp->key);

temp=find_d(x);
if(temp==NULL)
printf("NOT FOUND");
else
printf("%d\n",temp->key);

}
scanf("%c",&ch);
}
printf("%d %d %d %d\n",data_acc_a,data_acc_b,data_acc_c,data_acc_d);
return 0;
}
