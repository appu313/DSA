#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int e,v;
struct vertice_node
{
int node_val;
int d;
struct vertice_node *p;
};

struct vertice
{
struct vertice_node *ptr;
}*vertice_set;

struct vertice_node * createVertice(int val)
{
struct vertice_node *newptr=(struct vertice_node *)malloc(sizeof(struct vertice_node));
newptr->node_val=val;
return newptr;
}

void create_vertice_set()
{
vertice_set=(struct vertice*)calloc(v,sizeof(struct vertice));
for(int i=0;i<v;++i)
{
vertice_set[i].ptr=createVertice(i);
}
}

struct edge_node
{
struct vertice_node *u;
struct vertice_node *v;
int wt;
};

struct edge
{
struct edge_node *ptr;
}*edge_set;

struct edge_node * createEdge()
{
struct edge_node *newptr=(struct edge_node *)malloc(sizeof(struct edge_node));
newptr->u=NULL;
newptr->v=NULL;
newptr->wt=0;
return newptr;
}


void create_edge_set()
{
edge_set=(struct edge*)calloc(e,sizeof(struct edge));
for(int i=0;i<e;++i)
{
edge_set[i].ptr=createEdge();
}

}

void initialize_single_source()
{
for(int i=0;i<v;++i)
{
vertice_set[i].ptr->d=INT_MAX;
vertice_set[i].ptr->p=NULL;
}
vertice_set[0].ptr->d=0;     //taking my source vertex as 0
}

void relax(struct vertice_node* u,struct vertice_node *v,int wt)
{
if(v->d > u->d + wt)
{
v->d = u->d + wt;
v->p=u;
}
}

int bellman_ford()
{
initialize_single_source();

for(int i=0;i<v-1;++i)
for(int j=0;j<e;++j)
{
relax(edge_set[j].ptr->u,edge_set[j].ptr->v,edge_set[j].ptr->wt);
}
for(int i=0;i<e;++i)
{
if(edge_set[i].ptr->v->d > edge_set[i].ptr->u->d + edge_set[i].ptr->wt)
return 1;   // there is a negative cycle
}
return -1;  // there is no negative cycle
}

int main()
{
int u_val,v_val,wt_val;
scanf("%d %d",&v,&e);
create_vertice_set();
create_edge_set();
for(int i=0;i<e;++i)
{
scanf("%d %d %d",&u_val,&v_val,&wt_val);
edge_set[i].ptr->u=vertice_set[u_val].ptr;
edge_set[i].ptr->v=vertice_set[v_val].ptr;
edge_set[i].ptr->wt=wt_val;
}
/*****************************/
/*
printf("\n");
for(int i=0;i<e;++i)
{
printf("%d %d %d\n",edge_set[i].ptr->u->node_val,edge_set[i].ptr->v->node_val,edge_set[i].ptr->wt);
}
printf("\n");
*/
/*****************************/

printf("%d",bellman_ford());
return 0;
}
