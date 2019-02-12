#include<stdio.h>
#include<stdlib.h>

int *pre_order,*in_order,n,i=0;
struct Node
{
int key;
struct Node *p,*left,*right;
};

struct Node *bt_root;

struct Node*CreateNewNode(int val)
{
struct Node *newptr=(struct Node*)malloc(sizeof(struct Node));
if(newptr==NULL)
{
printf("Error");
exit(0);
}
newptr->key=val;
newptr->p=newptr->left=newptr->right=NULL;
return newptr;
}



int Search_in_order(int sta_ind,int end_ind,int val)
{
for(int j=sta_ind;j<=end_ind;++j)
if(in_order[j]==val)
return j;
}

struct Node *build_tree(int sta_ind,int end_ind)
{
if(sta_ind>end_ind)
return NULL;
int val=pre_order[i];
++i;
struct Node *ptr=CreateNewNode(val);
if(i==1)
bt_root=ptr;
if(sta_ind==end_ind)
return ptr;

int new_ind=Search_in_order(sta_ind,end_ind,val);
struct Node *right_sub,*left_sub;
left_sub=build_tree(sta_ind,new_ind-1);
ptr->left=left_sub;
if(left_sub!=NULL)
left_sub->p=ptr;
right_sub=build_tree(new_ind+1,end_ind);
ptr->right=right_sub;
if(right_sub!=NULL)
right_sub->p=ptr;
return ptr;
}

void print_res(struct Node*x)
{
if(bt_root==x)
printf("( %d",x->key);
else
printf(" ( %d",x->key);
if(x->left!=NULL)
print_res(x->left);
else
printf(" ( )");
if(x->right!=NULL)
print_res(x->right);
else
printf(" ( )");
printf(" )");
}

int main()
{
scanf("%d",&n);
pre_order=(int *)calloc(n,sizeof(int));
in_order=(int *)calloc(n,sizeof(int));
for (int i=0;i<n;++i)
scanf("%d",&pre_order[i]);
for (int i=0;i<n;++i)
scanf("%d",&in_order[i]);
build_tree(0,n-1);
print_res(bt_root);
return 0;
}
