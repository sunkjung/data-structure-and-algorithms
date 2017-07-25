#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAXSIZE 100
#define INFINITY 10000
#define NOT -1
#define False 0
#define True  1
FILE *fp;
FILE *fp1;
char m[100];
typedef int vertex;
typedef struct ArcNode
{
        int adjvex;
        int cost;
        struct ArcNode *nextadj;
}ArcNode;
typedef struct vexnode
{
        int vertexdata;
        struct ArcNode *first;
}vexnode;
typedef struct graph 
{
        vexnode vex[MAXSIZE];
        int vexnum,arcnum;
}*Graph;
typedef struct pathnode
{
        int pathvex;
        struct pathnode *next;
}pathnode,*ptrpath;
typedef struct TableNode
{
        int known;
        int dist;
        ptrpath path;
}Table[MAXSIZE]; 

void CreateGraph(Graph G)
{
     int i,k;
     ArcNode *p;
     for(i=0;i<G->vexnum;i++)
     {      
          G->vex[i].first = NULL;
     }
     for(k=0;k<G->arcnum;k++)
     {
          if(fgets(m,100,fp)!= NULL )
          {                                                        
             p=(ArcNode*)malloc(sizeof(ArcNode));              
             p->adjvex=m[2]-48;
             p->cost=m[4]-48;
             p->nextadj=G->vex[m[0]-48].first; 
             G->vex[m[0]-48].first=p;                         
          }                       
     }   
}                                                     
void InitTable(vertex begin, Graph G, Table T)
{
     int i;
     ptrpath p;   
     for(i=0;i<G->vexnum;i++)
     {
         p=(ptrpath)malloc(sizeof(pathnode));
         if(!p) exit(1);
         p->pathvex=NOT;
         p->next=NULL;
                             
         T[i].known = False;
         T[i].dist = INFINITY;
         T[i].path = p;
     }
     T[begin].dist = 0;
}             
void Dijkstra(Table T,Graph G) 
{
     int i,j,k,min;     
     vertex V;
     ArcNode *p;
     ptrpath q,temp=NULL,ptr;        
     for(j=0;j<G->vexnum;j++)
     {
     min = INFINITY;                              
     for(i=0;i<G->vexnum;i++)
     {                             
     if((!T[i].known) && (T[i].dist < min))
     {                                                      
     min = T[i].dist;
     V = i;
     }
     }                     
     if(V == NOT)
     break;     
     T[V].known = True;              
     for(p=G->vex[V].first;p;p=p->nextadj)
     { 
     if(!T[p->adjvex].known)
     {
     if(T[V].dist+p->cost == T[p->adjvex].dist)
     {
     q=(ptrpath)malloc(sizeof(pathnode));
     if(!q) exit(1);
     q->pathvex=V;
     q->next=NULL; 
     q->next=T[p->adjvex].path;
     T[p->adjvex].path=q; 
     }
     else 
     if(T[V].dist+p->cost < T[p->adjvex].dist)
     {
     T[p->adjvex].dist=T[V].dist+p->cost; 
     q=(ptrpath)malloc(sizeof(pathnode));
     if(!q) exit(1);
     q->pathvex=V;
     q->next=NULL;
     ptr=T[p->adjvex].path;
     while(ptr)
     {
     temp=ptr->next;
     free(ptr);
     ptr=temp;
     }
     T[p->adjvex].path=q;    
     }   
     }
     }
     }     
}
                                
int Prinfp1ath(int V,Table T)
{
    if(T[V].path->pathvex==NOT)
    {
     fprintf(fp1,"%d",V);
     printf("%d",V);
     return False;
    }
    else if(Prinfp1ath(T[V].path->pathvex,T)==1)
    {
     fprintf(fp1,"%d",V);
     printf("%d",V);
     return True;
    }
    else if(T[V].path->next==NULL)
    {
     fprintf(fp1,"%d",V);
     printf("%d",V);
     return False;
    } 
    else
    {
     fprintf(fp1,"%d",V);
     printf("%d",V);
     T[V].path=T[V].path->next;
     return True;
    }
}                                                                     
int main()
{
    vertex i,j;
    Graph G;
    Table T;
    int count=1;
    int OK=0;
    G=(Graph)malloc(sizeof(struct graph));
    G->vexnum = 8;
    G->arcnum = 17; 
    fp = fopen("input.txt","r");
    fp1 = fopen("output.txt","w");
    if(fp == NULL)     
    exit(1);
    CreateGraph(G); 
    while(OK==0)
    {              
    printf("please enter the begining£º\n");
    fflush(stdin);
    scanf("%d",&i);
    printf("please enter the end£º\n");
    fflush(stdin);
    scanf("%d",&j);
    if(i>=0&&i<=7&&j>=0&&j<=7)
    {
     OK=1;                      
    }
    if(OK==0)
    printf("wrong in put \n");
    }
    InitTable(i,G,T); 
    Dijkstra(T,G);
    fprintf(fp1,"The path from %d to %d:\n",i,j);
    printf("The path from%dto %d:\n",i,j); 
    fprintf(fp1,"path one is:");
    printf("path two is: "); 
    while(Prinfp1ath(j,T)==1)
    {
    count++;
    fprintf(fp1,"the path %d is: \n",count);
    printf("the path %d is: \n",count);                       
    }
    fprintf(fp1,"the shortest is:%d\n",T[j].dist); 
    printf("\nthe shortest is:%d\n",T[j].dist);   
    fclose(fp);
    fclose(fp1);
    system("pause");
    return 0;
}
