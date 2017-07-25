#include<stdio.h>
#include<time.h> 
#include<stdlib.h>
void BUBBLESORT(int A[],int n)
{  int i,j,c;
   for(i=n-1;i>=1;i--)
   {  for(j=0;j<i;j++)
      {  if(A[j]>A[j+1])
         {  c=A[j];
            A[j]=A[j+1];
            A[j+1]=c;
         }
      }
   }
}

void INSERTSORT(int A[],int n)
{  int i,j,k,c; 
   for(i=1;i<n;i++)
   {  for(j=0;j<i;j++)
      {  if(A[i]<A[j])
         {  c=A[i];
            for(k=i;k>j;k--)
              A[k]=A[k-1];
            A[j]=c;
            break;
         }
      }
   }
}

void QUICKSORT(int A[],int p,int r)
{  int q;
   if(p<r)
   {  q=PARTITION(A,p,r);
      QUICKSORT(A,p,q-1);
      QUICKSORT(A,q+1,r);
   }
}
int PARTITION(int A[],int p,int r)
{  int m,x,i,j;
   x=A[r];
   i=p-1;
   for(j=p;j<=r-1;j++)
   {  if(A[j]<=x)
      {  i=i+1;
         m=A[i];
         A[i]=A[j];
         A[j]=m;
      }
   }
   m=A[i+1];
   A[i+1]=A[r];
   A[r]=m;
   return i+1;
}
int main()
{  int A[30000],B[30000],i,n,m,l;
   clock_t start, finish;
   double d1,d2;
   printf("input the arry you want to sort£º"); 
   scanf("%d",&m);
   for(l=1;l<=m;l++)
   {  printf("Nom.%d: ",l);
   printf("the length£º");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {  A[i]=(int)rand();
      B[i]=A[i];
   }

   if(n>20)
   {  start = clock();
      QUICKSORT(A,0,n-1);
   }
   else
   {  start=clock();
      INSERTSORT(A,n);
   }
   finish = clock();
   d1=(double)(finish - start)/ CLOCKS_PER_SEC;
   
   start = clock();
   BUBBLESORT(B,n);
   finish = clock();
   d2=(double)(finish - start)/ CLOCKS_PER_SEC;
   
   for(i=0;i<n;i++)
     printf("%d ",A[i]);
   printf("\n\nQuick_Sort spend%.8lfs\n",d1);
   printf("\nBubble_Sort spend%.8lfs\n",d2);
   printf("\n");
   }
   system("pause");
   return 0;
}
