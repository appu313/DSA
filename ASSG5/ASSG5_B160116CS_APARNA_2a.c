#include<stdio.h>
#include<stdlib.h>
int n,sum=0,no_of_edges;

struct adj_node
{
int key;
int wt;
struct adj_node*ptr;
};

struct adj_list_elem
{
struct adj_node *start,*rear;
}*adj_list;

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

void create_adj_list()
{
for (int i=0;i<n;++i)
adj_list[i].start=adj_list[i].rear=NULL;
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

/******************/
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
/*********************/

struct disj_node
{
int key;
struct disj_node*p;
};

struct disj_list_elem
{
struct disj_node *ptr;
}*disj_list;

void create_disj_list()
{
for(int i=0;i<n;++i)
disj_list[i].ptr=NULL;
}

struct disj_node* CreateDisjNode(int val)
{
struct disj_node* newptr=(struct disj_node*)malloc(sizeof(struct disj_node));
if (newptr==NULL)
{
printf("Error");
exit(0);
}
newptr->key=val;
newptr->p=newptr;
return newptr;
}

struct edge
{
int u,v;
int wt;
}*edge_set;


void make_set(int val)
{
if(disj_list[val].ptr==NULL)
{
struct disj_node*newptr=CreateDisjNode(val);
disj_list[val].ptr=newptr;
}
}

int find_set(int val)
{
struct disj_node*x=disj_list[val].ptr;
while(x->p!=x)
x=x->p;
return x->key;
}

void union_set(int x,int y)
{
int x_rep=find_set(x);
int y_rep=find_set(y);
disj_list[y_rep].ptr->p=disj_list[x_rep].ptr;
}

void sort_wt()
{
int min;
struct edge temp;
for(int i=0;i<no_of_edges;++i)
{
min =i;
for(int j=i+1;j<no_of_edges;++j)
if(edge_set[j].wt<edge_set[min].wt)
min=j;
temp=edge_set[i];
edge_set[i]=edge_set[min];
edge_set[min]=temp;
}
}
void kruskal_mst()
{
for(int i=0;i<n;++i)
make_set(i);
sort_wt();
for(int i=0;i<no_of_edges;++i)
if(find_set(edge_set[i].u)!=find_set(edge_set[i].v))
{
sum+=edge_set[i].wt;
//printf("---%d--- ",edge_set[i].wt);
union_set(edge_set[i].u,edge_set[i].v);
}
}

int main()
{
char ch;
int nw,val;
scanf("%d",&n);

adj_list=(struct adj_list_elem*)calloc(n,sizeof(struct adj_list_elem));

create_adj_list();

disj_list=(struct disj_list_elem*)calloc(n,sizeof(struct disj_list_elem));

create_disj_list();

edge_set=(struct edge*)calloc(n*n,sizeof(struct edge));
getchar();
no_of_edges=0;
for(int i=0;i<n;++i)
{
val=0,nw=1;
while((ch=getchar())!='\n')
{
nw=0;
if(ch==' ')
{
insert_linked_list(&adj_list[i].start,&adj_list[i].rear,val);
edge_set[no_of_edges].u=i;
edge_set[no_of_edges].v=val;
++no_of_edges;
val =0;
}
else
val=val*10+ch-'0';
}
if(!nw)
{
insert_linked_list(&adj_list[i].start,&adj_list[i].rear,val);
edge_set[no_of_edges].u=i;
edge_set[no_of_edges].v=val;
++no_of_edges;
}
}
struct adj_node*x;
no_of_edges=0;
for(int i=0;i<n;++i)
{
x=adj_list[i].start;
while(x!=NULL)
{
scanf("%d",&val);
x->wt=val;
edge_set[no_of_edges++].wt=val;
x=x->ptr;
}
}
kruskal_mst();
printf("%d",sum);
return 0;
}
