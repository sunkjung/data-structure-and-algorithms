#include<stdio.h>  
#include<malloc.h>  
#include<string.h> 
#define Max 30
 
typedef struct node  
{  
  char data;  
  struct node *lchild,*rchild;  
}node;  
                 // ����ڵ�Ľṹ   
node * creat(char *pre,char *in,int len);  
void postorder(node *head); //��������ĺ��� 
void findpath(node *T);//�ҳ��ڵ�·���ĺ��� 
void levelorder(node *t);//����������� 

int main()  
{  
  int len;  
  char pre[Max],in[Max];    // �洢������������������   
  node *head;  
  head=(node*)malloc(sizeof(node));  
  
  puts("please in put the preorder and inorder please��");
  scanf("%s%s",pre,in);fflush(stdin);  
  len=strlen(pre);  
  head=creat(pre,in,len); 
  puts("it's postorder is��"); 
  postorder(head);  
  printf("\n"); 
  
  findpath(head);
  printf("\n"); 
  
  puts("it's levelorder traversal is��");
  levelorder(head);
  printf("\n"); 
  
  system("pause");
  
  return 0;  
} 
 
node * creat(char *pre,char *in,int len)  // ������������ĺ���   
{  int k;  
   if(len<=0) return NULL;  
   node *head=(node*)malloc(sizeof(node));  
   head->data=*pre;  
   char *p;  
   for(p=in;p!=NULL;p++)   
      if(*p==*pre) break;                 // ����������������еõ���������ͬ�Ľڵ�   
   k=p-in;  
   head->lchild=creat(pre+1,in,k);          //�ݹ���õõ�������   
   head->rchild=creat(pre+k+1,p+1,len-k-1);//�õ�������   
   return head;  
}  
void postorder(node *head)  // ��ӡ�����������   
{  
  if(head==NULL) return ;  
  postorder(head->lchild);  
  postorder(head->rchild);  
  printf("%c",head->data);  
}  
void findpath(node *T)
{
    typedef struct node2//Stack�Ķ��� 
    {
        node *tree;
        int flag;
    }node2;
    
    char X; 
    printf("tell me which you want to find:");
    scanf("%c",&X);fflush(stdin);
    int top=0;
    node2 stack[Max];//����������ʵ�ֵ�ջ 
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
                stack[top].flag=0;//��ǰ�����ҵĽ����ջ�����������������δ���ҹ� 
                T=T->lchild;
          }
          if(T!=NULL)
          //�����������ҵ��˸ý�㣬��ջ�׵�ջ����ӡ����ΪҪ���·���ǴӸ���㵽�ý�㣩 
          {
             printf("\nits path is��");                                                                             
             int j;
             for(j=1;j<=top;j++)
                 printf("%c->",stack[j].tree->data); 
             printf("%c",T->data);
             printf("\n");
             break;
          }
          else if((stack[top].tree->rchild!=NULL)&&(stack[top].flag==0))
               //��ջ��������������δ�ҵ�����ջ������������ 
               {
                  T=stack[top].tree->rchild;
                  stack[top].flag=1;
               }
               else
               //��ǰ���û����������ΪҶ�ӽڵ㡣��������һ����� 
               {
                    top--; 
                    if(stack[top].flag==0) 
                    //��һ������������û�б����� 
                    {
                        T=stack[top].tree->rchild;
                        stack[top].flag=1;
                    } 
                    else
                    //��һ�������������������� ���ٴλ��� 
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
