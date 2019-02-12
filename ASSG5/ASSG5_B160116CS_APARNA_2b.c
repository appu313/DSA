#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n,prior_len;
struct adj_node           //creates adjacent list nodes with elements
{                         //node_val={0,n-1},wt,pointer to next node
	int node_val;
	int wt;
	struct adj_node*ptr;
};

struct adj_list_elem
{
struct adj_node *start,*rear;
}*adj_list;               //adjacency list with start and rear

void create_adj_list()          //initialises start and rear to NULL
{
for (int i=0;i<n;++i)
adj_list[i].start=adj_list[i].rear=NULL;
}


struct adj_node* CreateNewAdjNode(int val)
{
struct adj_node * newptr=(struct adj_node*)malloc(sizeof(struct adj_node));
if (newptr==NULL)             //sets the value of node_val and ptr
{                         // the wt is set later on
printf("Error");
exit(0);
}
newptr->node_val=val;
newptr->ptr=NULL;
return newptr;
}

void insert_linked_list(struct adj_node **start,struct adj_node **rear,int val)
{             //inserts the node at the rear of the adj list
struct adj_node *newptr=CreateNewAdjNode(val);
if(*start==NULL)
*start=*rear=newptr;
else
{
(*rear)->ptr=newptr;
*rear=newptr;
}
}

/*******************************************/
void print_linked_list(struct adj_node *start)
{
struct adj_node *x=start;
while(x!=NULL)
{
printf("%d(%d) ",x->node_val,x->wt);
x=x->ptr;
}
printf("\n");
}
/***********************************************/

struct prior_node
{             //creates a priority node with attributes
int key;        //key(least dist from source),node_val(val of node)
int node_val;   //and the p pointer that points to the parent
struct prior_node*p;
};

struct prior_q_elem
{
struct prior_node*ptr;      //an array of pointers that points to
}*prior_q;                  //a priority_node

struct prior_node* CreatePriorNode(int val)
{
struct prior_node*newptr=(struct prior_node*)malloc(sizeof(struct prior_node));
if (newptr==NULL)
{
printf("Error");
exit(0);
}
if(val==0)
newptr->key=0;
else                   //initialises the node with node_val 0 as 0
newptr->key=INT_MAX;    // and the rest to inf
newptr->node_val=val;
newptr->p=NULL;
}

void create_prior_q()
{
for(int i=0;i<n;++i)           //makes the ith element of the prior
prior_q[i].ptr=CreatePriorNode(i);  //q pont to node_val i
}

void min_heapify(int ind)
{
int l=2*ind+1;
int r=2*ind+2;
int min;
if(l<prior_len && (prior_q[l].ptr)->key < (prior_q[ind].ptr)->key)
min=l;
else
min=ind;
if(r<prior_len && (prior_q[r].ptr)->key < (prior_q[min].ptr)->key)
min =r;
if(min!=ind)
{
struct prior_node*temp=prior_q[ind].ptr;
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

struct prior_node*extract_min()
{
build_heap();  //the min node is now at index 0;
struct prior_node*temp=prior_q[0].ptr;
prior_q[0].ptr=prior_q[prior_len-1].ptr;
prior_q[prior_len-1].ptr=temp;
--prior_len;
return prior_q[prior_len].ptr;
}

int pos_in_q(int val)
{
for(int i=0;i<n;++i)
if((prior_q[i].ptr)->node_val == val)
{
//printf("&%d %d&\n",(prior_q[val].ptr)->node_val,val);
return i;}
}

void print_prior_q()
{
for(int i=0;i<n;++i)
printf("(%d)%d ",(prior_q[i].ptr)->node_val,(prior_q[i].ptr)->key);
printf("\n");
}

void prim_mst()
{
prior_len=n;

prior_q=(struct prior_q_elem*)calloc(n,sizeof(struct prior_q_elem));
create_prior_q();

//print_prior_q();
int pos;
struct prior_node*u;
struct adj_node *v;
for(int i=0;i<n;++i)   //till the q is non empty
{
u=extract_min();        //extracts the node with the min key
//printf("After extracting the min:\n");
//print_prior_q();
v=adj_list[u->node_val].start;  //traversing the adjacency list of 
while(v!=NULL)              //the extracted node
{
pos=pos_in_q(v->node_val);          //checks if the adjacent node 
if(pos<prior_len && v->wt < (prior_q[pos].ptr)->key)      //is in q
{
//printf("*%d %d*\n",v->node_val,pos);
(prior_q[pos].ptr)->p=u;
(prior_q[pos].ptr)->key=v->wt;
//print_prior_q();
}
v=v->ptr;
}
}
//print_prior_q();
int sum=0;
for(int i=0;i<n;++i)
sum+=prior_q[i].ptr->key;
printf("%d",sum);
//printf("exit\n");
}


int main()
{
int val,nw;
char ch;
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

prim_mst();



return 0;
}


