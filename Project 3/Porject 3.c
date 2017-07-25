#include<stdio.h>  
#include<malloc.h>  
#include<string.h> 
#define Max 30
 
typedef struct node  
{  
  char data;  
  struct node *lchild,*rchild;  
}node;  
                 // 定义节点的结构   
node * creat(char *pre,char *in,int len);  
void postorder(node *head); //先序遍历的函数 
void findpath(node *T);//找出节点路径的函数 
void levelorder(node *t);//层序遍历函数 

int main()  
{  
  int len;  
  char pre[Max],in[Max];    // 存储先序和中序遍历的序列   
  node *head;  
  head=(node*)malloc(sizeof(node));  
  
  puts("please in put the preorder and inorder please：");
  scanf("%s%s",pre,in);fflush(stdin);  
  len=strlen(pre);  
  head=creat(pre,in,len); 
  puts("it's postorder is："); 
  postorder(head);  
  printf("\n"); 
  
  findpath(head);
  printf("\n"); 
  
  puts("it's levelorder traversal is：");
  levelorder(head);
  printf("\n"); 
  
  system("pause");
  
  return 0;  
} 
 
node * creat(char *pre,char *in,int len)  // 创建后序遍历的函数   
{  int k;  
   if(len<=0) return NULL;  
   node *head=(node*)malloc(sizeof(node));  
   head->data=*pre;  
   char *p;  
   for(p=in;p!=NULL;p++)   
      if(*p==*pre) break;                 // 在中序遍历的序列中得到与先序相同的节点   
   k=p-in;  
   head->lchild=creat(pre+1,in,k);          //递归调用得到左子树   
   head->rchild=creat(pre+k+1,p+1,len-k-1);//得到右子树   
   return head;  
}  
void postorder(node *head)  // 打印后序遍历序列   
{  
  if(head==NULL) return ;  
  postorder(head->lchild);  
  postorder(head->rchild);  
  printf("%c",head->data);  
}  
void findpath(node *T)
{
    typedef struct node2//Stack的定义 
    {
        node *tree;
        int flag;
    }node2;
    
    char X; 
    printf("tell me which you want to find:");
    scanf("%c",&X);fflush(stdin);
    int top=0;
    node2 stack[Max];//建立用数组实现的栈 
    if(X==T->data)
    printf("\nit is the root\n");
    else
    {
        do
        {
          while(T!=NULL&&X!=T->data)
          {
                top++;
                stack[top].tree=T;
                stack[top].flag=0;//当前所查找的结点入栈，并标记其右子树尚未查找过 
                T=T->lchild;
          }
          if(T!=NULL)
          //在左子树中找到了该结点，从栈底到栈顶打印（因为要求的路径是从根结点到该结点） 
          {
             printf("\nits path is：");                                                                             
             int j;
             for(j=1;j<=top;j++)
                 printf("%c->",stack[j].tree->data); 
             printf("%c",T->data);
             printf("\n");
             break;
          }
          else if((stack[top].tree->rchild!=NULL)&&(stack[top].flag==0))
               //在栈顶结点的左子树中未找到，找栈顶结点的右子树 
               {
                  T=stack[top].tree->rchild;
                  stack[top].flag=1;
               }
               else
               //当前结点没有右子树，为叶子节点。回溯至上一个结点 
               {
                    top--; 
                    if(stack[top].flag==0) 
                    //上一个结点的右子树没有被访问 
                    {
                        T=stack[top].tree->rchild;
                        stack[top].flag=1;
                    } 
                    else
                    //上一个结点的右子树被访问了 ，再次回溯 
                        top--;
               }
        }while(top!=-1);
    if (top<=0)
       printf("sorry we cant find\n");
    }
} 
void levelorder(node *t)
{
     node *queue[Max];
     int front=0,rear=0,i=0,k,p=0;
     int hang=1;
     queue[rear++]=t;
     while(front!=rear)
     {
        if (queue[front]!=NULL)
        printf("%c",queue[front]->data);
        else
        {
        printf("_");
        queue[front]=(node *)malloc(sizeof(struct node));
        queue[front]->lchild=NULL;
        queue[front]->rchild=NULL;
        } 
        i++; 
        queue[rear++]=queue[front]->lchild;
        queue[rear++]=queue[front]->rchild;
        front++;
        if (i==hang)
        {
                 printf("\n");
                 hang=hang*2;
                 i=0;
                 for (k=front;k<rear;k++)
                 if (queue[k]==NULL)
                 p++;
                 if (p==hang)
                 break;
                 else
                 p=0;
        }
     }
     
}
