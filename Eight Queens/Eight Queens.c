#include <stdio.h>
#include <stdlib.h>
#define N 8
void Output(int bc[][N],int *count)
{
	int i,j; 
	*count=*count+1;
	printf("第%d种:\n",*count);
	for(i=0;i<N;i++)
	{   
		for(j=0;j<N;j++)
		{   
			if(bc[i][j])
				printf("Q");
			else   
				printf("■"); 
		}   
		printf("\n\r");   
	}
}
void   Queen(int   board[][N],int   row,int *count)
{   
	int OK,i,j; 
	if(row==N)
	{   
		Output(board,count); 
		return;   
	}   
	for(j=0;j<N;j++)
	{   
		OK=1;   
		for(i=0;i<row;i++)
		{   
			if((board[i][j])||(j-row+i>=0&&board[i][j-row+i])||(j-i+row<N&&board[i][j-i+row]))   
			{   
				OK=0;   
				break;   
			}   
		}   
		if(OK)
		{  
			board[row][j]=1;   
			Queen(board,row+1,count);
			board[row][j]=0;   
		}   
	}   
}   


void   main()
{   
	int pad[N][N];   
	int i,j,count=0;
	for(i=0;i<N;i++)
	{   
		for(j=0;j<N;j++)
		{   
			pad[i][j]=0;
		}   
	}   
	Queen(pad,0,&count);
	printf("共有%d种方案",count); 
    system("pause");  
}   
