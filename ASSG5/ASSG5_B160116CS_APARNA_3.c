#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int n,prior_len;

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
printf("%d(%d) ",x->key,x->wt);
x=x->ptr;
}
printf("\n");
}

///////////////////////////////
struct vertice_node
{
int node_val;
int d;
int wt;
struct vertice_node *p;
};

struct vertice
{
struct vertice_node *ptr;
}*prior_q;

struct vertice_node * createVertice(int val)
{
struct vertice_node *newptr=(struct vertice_node *)malloc(sizeof(struct vertice_node));
newptr->node_val=val;
return newptr;
}

void create_prior_q()
{
prior_q=(struct vertice*)calloc(n,sizeof(struct vertice));
for(int i=0;i<n;++i)
{
prior_q[i].ptr=createVertice(i);
}
}
///////////////////////////////
void initialize_single_source(int s)
{
for(int i=0;i<n;++i)
{
prior_q[i].ptr->d=INT_MAX;
prior_q[i].ptr->p=NULL;
}
prior_q[s].ptr->d=0;     //taking my source vertex as 0
}

void min_heapify(int ind)
{
int l=2*ind+1;
int r=2*ind+2;
int min;
if(l<prior_len && (prior_q[l].ptr)->d < (prior_q[ind].ptr)->d)
min=l;
else
min=ind;
if(r<prior_len && (prior_q[r].ptr)->d < (prior_q[min].ptr)->d)
min =r;
if(min!=ind)
{
struct vertice_node*temp=prior_q[ind].ptr;
prior_q[ind].ptr=prior_q[min].ptr;
prior_q[min].ptr=temp;
min_heapify(min);
}
}

void build_heap()
{
for(int i=prior_len/2;i>=0;--i)
min_heapify(i);
}

struct vertice_node*extract_min()
{
build_heap();  //the min node is now at index 0;
struct vertice_node*temp=prior_q[0].ptr;
prior_q[0].ptr=prior_q[prior_len-1].ptr;
prior_q[prior_len-1].ptr=temp;
--prior_len;
return prior_q[prior_len].ptr;
}

void relax(struct vertice_node* u,struct vertice_node *v,int wt)
{
if(v->d > u->d + wt)
{
v->d = u->d + wt;
v->p=u;
}
}

int pos_in_q(int val)
{
for(int i=0;i<n;++i)
if((prior_q[i].ptr)->node_val == val)
{
//printf("&%d %d&\n",(prior_q[val].ptr)->node_val,val);
return i;}
}

void dijkstra(int s)
{
int pos;
prior_len=n;
create_prior_q();
initialize_single_source(s);

struct vertice_node*u;
//struct adj_node*ptr;
struct adj_node*x;
for(int i=0;i<n;++i)
{
u=extract_min();
x=adj_list[u->node_val].start;
while(x!=NULL)
{
pos=pos_in_q(x->key);
if(pos<prior_len)
relax(u,prior_q[pos].ptr,x->wt);
x=x->ptr;
}
}
}

int main()
{
int val,nw,s,d;
char ch,str[5];
scanf("%d",&n);
adj_list=(struct adj_list_elem*)calloc(n,sizeof(struct adj_list_elem));
create_adj_list();
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

struct adj_node*x;
for(int i=0;i<n;++i)
{                       //basically the adj_list has been created
x=adj_list[i].start;     //and the corresponding wts has been stored
while(x!=NULL)
{
scanf("%d",&val);
x->wt=val;
x=x->ptr;
}
}

/******************************************/
/*
printf("\n");
printf("\n");
for (int i=0;i<n;++i)
{
printf("%d ",i);
print_linked_list(adj_list[i].start);
}
*/
/******************************************/


int pos;
scanf("%s",str);
while(strcmp(str,"stop"))
{
if(!strcmp(str,"apsp"))
{
scanf("%d",&s);
dijkstra(s);
for(int i=0;i<n;++i)
{
pos=pos_in_q(i);
if(prior_q[pos].ptr->d==INT_MAX)
printf("INF ");
else
printf("%d ",prior_q[pos].ptr->d);
}
printf("\n");
}
else if(!strcmp(str,"sssp"))
{
scanf("%d %d",&s,&d);
dijkstra(s);
pos=pos_in_q(d);
if(prior_q[pos].ptr->d==INT_MAX)
printf("UNREACHABLE\n");
else
printf("%d\n",prior_q[pos].ptr->d);
}
scanf("%s",str);
}
return 0;
}

