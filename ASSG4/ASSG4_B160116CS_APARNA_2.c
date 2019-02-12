#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bst_elem
{
int key;
struct bst_elem*p;
struct bst_elem*left;
struct bst_elem*right;
};

struct bst_data_struct
{
struct bst_elem* root;
}bst;

struct bst_elem* CreateNewNode(int val)
{
struct bst_elem *newptr=(struct bst_elem*)malloc(sizeof(struct bst_elem));
if(newptr==NULL)
{
printf("Error");
exit(0);
}
newptr->key=val;
newptr->p=newptr->left=newptr->right=NULL;
}

void CreateBst()
{
bst.root=NULL;
}

struct bst_elem* search_aux(struct bst_data_struct bst,int val)  //returns the parent of the node which is searched.
{
struct bst_elem *x=bst.root,*prev;
while(x!=NULL&&x->key!=val)
{
prev=x;
if(val < x->key)
x=x->left;
else
x=x->right;
}
return prev;
}

int search(struct bst_data_struct bst,int val)
{
if(bst.root==NULL)
return -1;
else if(bst.root->key==val)
return 1;
else
{
struct bst_elem*prev=search_aux(bst,val);
if(prev->left!=NULL&&(prev->left)->key==val)
return 1;
else if(prev->right!=NULL&&(prev->right)->key==val)
return 1;
else
return -1;
//printf("NOT FOUND\n");
}
}



void predecessor(struct bst_data_struct bst,int val)
{
if(search(bst,val)==-1)
printf("NOT FOUND\n");
else
{
	if(val==bst.root->key&&bst.root->left==NULL&&bst.root->right==NULL)
	printf("NIL\n");
	else
	{
		struct bst_elem *p_req,*req,*x,*par;
		if(val==(bst.root)->key)
			req=bst.root;
		else
		{
			p_req=search_aux(bst,val);
			if(p_req->left!=NULL&&(p_req->left)->key==val)
				req=p_req->left;
			else if(p_req->right!=NULL&&(p_req->right)->key==val)
				req=p_req->right;
		}
		
		
		if(req->left!=NULL)
		{
			x=req->left;
			while(x->right!=NULL)
			x=x->right;
			printf("%d\n",x->key);
			return;
		}
		else
		{
			x=req;
			//printf("%d\n",x->key);
			while(x->p!=NULL&&x!=(x->p)->right)
			x=x->p;
			if(x->p==NULL&& x->key > val)
			printf("NIL\n");
			else
			printf("%d\n",(x->p)->key);
		}


	}
}
}

void successor(struct bst_data_struct bst,int val)
{
if(search(bst,val)==-1)
printf("NOT FOUND\n");
else
{
	if(bst.root->key==val && bst.root->left==NULL&& bst.root->right==NULL)
		printf("NIL\n");
	else
	{
		struct bst_elem *p_req,*req,*x,*par;
		if(bst.root->key==val)
		req=bst.root;
		else
		{
			p_req=search_aux(bst,val);
			if(p_req->left!=NULL&&(p_req->left)->key==val)
				req=p_req->left;
			else if(p_req->right!=NULL&&(p_req->right)->key==val)
				req=p_req->right;
		}
		
		if(req->right!=NULL)
		{
			x=req->right;
			while(x->left!=NULL)
			x=x->left;
			printf("%d\n",x->key);
			return;
		}
		else
		{
			x=req;
			//printf("%d\n",x->key);
			while(x->p!=NULL&&x!=(x->p)->left)
			x=x->p;
			if(x->p==NULL&& x->key < val)
			printf("NIL\n");
			else
			printf("%d\n",(x->p)->key);
		}

	}
	
}
}

void print_search_res(int x)
{
if(x==-1)
printf("NOT FOUND\n");
else
printf("FOUND\n");
}

void insert(struct bst_data_struct* bst,int val)
{
struct bst_elem *ptr=CreateNewNode(val);
if((*bst).root==NULL)
(*bst).root=ptr;
else
{
struct bst_elem*prev=search_aux(*bst,val);
ptr->p=prev;
if(val<prev->key)
prev->left=ptr;
else
prev->right=ptr;
}
}

void transplant(struct bst_data_struct* bst,struct bst_elem *u,struct bst_elem *v)
{
if(u->p==NULL)
(*bst).root=v;
else if(u==(u->p)->left)
(u->p)->left=v;
else
(u->p)->right=v;
if(v!=NULL)
v->p=u->p;
}

void delete(struct bst_data_struct *bst,int val)
{
struct bst_elem *p_req,*req,*x,*temp;
if((*bst).root->key==val&&&(*bst).root->left==NULL&&(*bst).root->right==NULL)
{
temp=(*bst).root;
(*bst).root==NULL;
free(temp);
}
else
{
	if(val==((*bst).root)->key)
		req=(*bst).root;
	else
	{
		p_req=search_aux((*bst),val);
		if(p_req->left!=NULL&&(p_req->left)->key==val)
			req=p_req->left;
		else if(p_req->right!=NULL&&(p_req->right)->key==val)
			req=p_req->right;
	}
	x=req;
	
	if(x->left==NULL)
		transplant(bst,x,x->right);
	else if(x->right==NULL)
		transplant(bst,x,x->left);
	else//replacing with the successor
	{
		x=req->right;
		while(x->left!=NULL)
			x=x->left;	
		if(x->p!=req)
		{
			transplant(bst,x,x->right);
			
			x->right=req->right;
			(req->right)->p=x;
		}
		transplant(bst,req,x);
		x->left=req->left;
		(req->left)->p=x;
		
	}
	free(req);
}
}

void findMin(struct bst_data_struct bst)
{
struct bst_elem *x=bst.root;
if(bst.root==NULL)
printf("NIL\n");
else{
while(x->left!=NULL)
x=x->left;
printf("%d\n",x->key);
}
}

void findMax(struct bst_data_struct bst)
{
struct bst_elem *x=bst.root;
if(bst.root==NULL)
printf("NIL\n");
else{
while(x->right!=NULL)
x=x->right;
printf("%d\n",x->key);
}
}


void inorder_aux(struct bst_elem* x)
{
if(x->left!=NULL)
inorder_aux(x->left);
printf("%d ",x->key);
if(x->right!=NULL)
inorder_aux(x->right);
}

void inorder(struct bst_data_struct bst)
{
if(bst.root==NULL)
return;
inorder_aux(bst.root);
printf("\n");
}


void preorder_aux(struct bst_elem* x)
{
printf("%d ",x->key);
if(x->left!=NULL)
preorder_aux(x->left);
if(x->right!=NULL)
preorder_aux(x->right);
}

void preorder(struct bst_data_struct bst)
{
if(bst.root==NULL)
return;

preorder_aux(bst.root);
printf("\n");
}

void postorder_aux(struct bst_elem* x)
{
if(x->left!=NULL)
postorder_aux(x->left);
if(x->right!=NULL)
postorder_aux(x->right);
printf("%d ",x->key);
}

void postorder(struct bst_data_struct bst)
{
if(bst.root==NULL)
return;

postorder_aux(bst.root);
printf("\n");
}


int main()
{
CreateBst();
char ch[10];
int val;
scanf("%s",ch);
while(strcmp(ch,"stop"))
{
if(!strcmp(ch,"insr"))
{
scanf("%d",&val);
insert(&bst,val);
}
else if(!strcmp(ch,"srch"))
{
scanf("%d",&val);
print_search_res(search(bst,val));
}
else if(!strcmp(ch,"minm"))
findMin(bst);
else if(!strcmp(ch,"maxm"))
findMax(bst);
else if(!strcmp(ch,"pred"))
{
scanf("%d",&val);
predecessor(bst,val);
}
else if(!strcmp(ch,"succ"))
{
scanf("%d",&val);
successor(bst,val);
}
else if(!strcmp(ch,"delt"))
{
scanf("%d",&val);
delete(&bst,val);
}
else if(!strcmp(ch,"inor"))
{
inorder(bst);
}
else if(!strcmp(ch,"prer"))
{
preorder(bst);
}
else if(!strcmp(ch,"post"))
{
postorder(bst);
}

scanf("%s",ch);
}

return 0;
}
