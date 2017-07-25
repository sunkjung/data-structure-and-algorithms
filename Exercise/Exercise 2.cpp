int  MinSubsequenceSum(const int A[ ],int N) 
{ 
	int  Thissum,Minsum,i,j; 
 	Minsum=0;
 	
 	for(i=0;i<N;i++)
 	{
         Thissum=0; 
         for(j=i;j<N;j++)
 		 {
              Thissum+=A[j];
 		      if(Thissum<Minsum) 
 		           Minsum=Thissum;
         }
	}
	
 	return  Minsum; 
} 
