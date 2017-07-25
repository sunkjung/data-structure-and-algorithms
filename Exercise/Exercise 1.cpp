int exitIntegerI(const int A[ ],int N)
{
     int i,exit=0;
     
     for(i=0;(i<N)&&(exit=0);i++)
     {
          if(i==A[i])
              exit = 1;
     }
     
     return exit;
}
