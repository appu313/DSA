//the final code
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int n,*queue,*stack,start_q=-1,rear_q=-1,time,found,top;

struct srch_node
{
int key;
int d;
int f;
char colour;
struct srch_node*p;
};

struct srch_list_elem
{
struct srch_node*ptr;
}*srch_list;

struct srch_node* CreateNewSrchNode(int val)  //returns a node whose colour is white dist is inf and predecessor is NULL
{
struct srch_node *newptr=(struct srch_node*)malloc(sizeof(struct srch_node));
if (newptr==NULL)
{
printf("Error");
exit(0);
}
newptr->colour='w';
newptr->key=val;
newptr->p=NULL;
newptr->d=newptr->f=INT_MAX;
return newptr;
}

void create_srch_list()
{
struct srch_node* new_ptr;
for (int i=0;i<n;++i)
{
new_ptr=CreateNewSrchNode(i);
srch_list[i].ptr=new_ptr;
}
}

struct adj_node
{
int key;
struct adj_node*ptr;
};

struct adj_list_elem
{
struct adj_node *start,*rear;
}*adj_list;

void create_adj_list()
{
for (int i=0;i<n;++i)
adj_list[i].start=adj_list[i].rear=NULL;
}





struct adj_node* CreateNewAdjNode(int val)
{
struct adj_node * newptr=(struct adj_node*)malloc(sizeof(struct adj_node));
if (newptr==NULL)
{
printf("Error");
exit(0);
}
newptr->key=val;
newptr->ptr=NULL;
return newptr;
}



void insert_linked_list(struct adj_node **start,struct adj_node **rear,int val)
{
struct adj_node *newptr=CreateNewAdjNode(val);
if(*start==NULL)
*start=*rear=newptr;
else
{
(*rear)->ptr=newptr;
*rear=newptr;
}
}

void print_linked_list(struct adj_node *start)
{
struct adj_node *x=start;
while(x!=NULL)
{
printf("%d ",x->key);
x=x->ptr;
}
printf("\n");
}

void enqueue(int val)
{
if(start_q==-1)
start_q=rear_q=0;
else
++rear_q;
queue[rear_q]=val;
}

int dequeue()
{
if(start_q==-1)
return -1;
int val=queue[start_q];
if(start_q==rear_q)
start_q=rear_q=-1;
else
++start_q;
return val;
}

void print_q()
{
for(int i=start_q;i<=rear_q;++i)
printf("%d ",queue[i]);
printf("\n");
}

void bfs(int s,int x)
{

//printf("hi 1\n");
int u_val,v_val;
for(int i=0;i<n;++i)
{
if(i!=s)
{
//printf("hi 2\n");
//new_ptr=CreateNewSrchNode(i);
//srch_list[i].ptr=new_ptr;
srch_list[i].ptr->colour='w';
srch_list[i].ptr->p=NULL;
srch_list[i].ptr->d=INT_MAX;
//printf("hi 3\n");
}
}
//new_ptr=CreateNewSrchNode(s);
//new_ptr->colour='g';
//new_ptr->d=0;
//srch_list[s].ptr=new_ptr;
srch_list[s].ptr->colour='g';
srch_list[s].ptr->d=0;
srch_list[s].ptr->p=NULL;
start_q=rear_q=-1;
enqueue(s);
//print_q();
while(start_q!=-1)
{
u_val=dequeue();
printf("%d ",u_val); 
if(u_val==x)
break;
struct adj_node * v=adj_list[u_val].start;
while(v!=NULL)               //traversing the adj list of u
{
v_val=v->key;
if(srch_list[v_val].ptr->colour=='w')
{
srch_list[v_val].ptr->colour='g';
srch_list[v_val].ptr->d=srch_list[u_val].ptr->d+1;
srch_list[v_val].ptr->p=srch_list[u_val].ptr;
enqueue(v_val);
//print_q();
}
v=v->ptr;
}
srch_list[u_val].ptr->colour='b';
}
}

void print_path_bfs(int s,int x)
{
if(s==x)
{
printf("%d ",s);
return;
}
else if(srch_list[x].ptr->p==NULL)
printf("No path exists!!\n");
else
{
print_path_bfs(s,(srch_list[x].ptr->p)->key);
printf("%d ",x);
}
}


void push(int val)
{
top++;
stack[top]=val;
}

int pop()
{
top--;
return stack[top+1];
}

void dfs_stack(int s,int x)
{
int u_val,v_val;
for(int i=0;i<n;++i)
{
if(i!=s)
{
srch_list[i].ptr->colour='w';
srch_list[i].ptr->p=NULL;
}
}
srch_list[s].ptr->colour='g';
srch_list[s].ptr->p=NULL;
time=0;
top=-1;
push(s);
while(top!=-1)
{
u_val=pop();
printf("%d ",u_val); 
if(u_val==x)
break;
struct adj_node * v=adj_list[u_val].start;
while(v!=NULL)               //traversing the adj list of u
{
v_val=v->key;
if(srch_list[v_val].ptr->colour=='w')
{
srch_list[v_val].ptr->colour='g';
srch_list[v_val].ptr->d=srch_list[u_val].ptr->d+1;
srch_list[v_val].ptr->p=srch_list[u_val].ptr;
push(v_val);
}
v=v->ptr;
}
srch_list[u_val].ptr->colour='b';
}

}


int main()
{
int val,nw,s,x;
char ch,str[5];
scanf("%d",&n);
adj_list=(struct adj_list_elem*)calloc(n,sizeof(struct adj_list_elem));
srch_list=(struct srch_list_elem*)calloc(n,sizeof(struct srch_list_elem));
create_adj_list();
create_srch_list();
getchar();
for (int i=0;i<n;++i)
{
val=0,nw=1;
while((ch=getchar())!='\n')
{
nw=0;
if(ch==' ')
{
insert_linked_list(&adj_list[i].start,&adj_list[i].rear,val);
val =0;
}
else
val=val*10+ch-'0';
}
if(!nw)
insert_linked_list(&adj_list[i].start,&adj_list[i].rear,val);

}
/*********************/
/*
printf("\n");
printf("\n");
for (int i=0;i<n;++i)
{
printf("%d ",i);
print_linked_list(adj_list[i].start);
}
*/
/*********************/
queue=(int *)calloc(n,sizeof(int));
stack=(int *)calloc(n,sizeof(int));
scanf("%s",str);
while(strcmp(str,"stp"))
{
scanf("%d",&s);
scanf("%d",&x);
if(!strcmp(str,"bfs"))
{
bfs(s,x);
printf("\n");
}
else if(!strcmp(str,"dfs"))
{
found=0;
dfs_stack(s,x);
printf("\n");
}
scanf("%s",str);
}
return 0;
}

void dfs_visit(int u_val,int x)
{
//printf("hi 1\n");
printf("%d ",u_val);
if(u_val==x)
{
//printf("hi 2\n");
found=1;
return;}
int v_val;
time=time+1;
srch_list[u_val].ptr->d=time;
srch_list[u_val].ptr->colour='g';
struct adj_node*v=adj_list[u_val].start;
while(v!=NULL)
{
v_val=v->key;
if(srch_list[v_val].ptr->colour=='w')
{
//printf("hi 3\n");
srch_list[v_val].ptr->p=srch_list[u_val].ptr;
dfs_visit(v_val,x);
}
if(found==1)
{
//printf("hi 4\n");
break;
}
v=v->ptr;
}
srch_list[u_val].ptr->colour='b';
time=time+1;
srch_list[u_val].ptr->f=time;
//printf("hi 5\n");
}

void dfs(int s,int x)
{
for(int i=0;i<n;++i)
{
srch_list[i].ptr->colour='w';
srch_list[i].ptr->p=NULL;
}
time=0;

if(srch_list[s].ptr->colour=='w')
dfs_visit(s,x);
if(found==0)
for (int i=0;i<n;++i)
{
if(srch_list[i].ptr->colour=='w')
dfs_visit(i,x);
if(found==1)
break;
}
}

