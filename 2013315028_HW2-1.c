//2013315028 Garam choi
#include <stdio.h>
#include <stdlib.h>

/* You can modify from here */

int test_cases(int X, int Y, int n, int *D, int **matrix) {
   int *check = (int *)malloc((Y+1)*sizeof(int));
   int i, j;
   int insert;
   
   for (j=0; j<=Y; j++) // array initialization for checking repetition
      check[j] = 0;

   for(i=0; i<n; i++)  // insert diagonal number
   {
      for(j=0; j<n; j++ )
      {
         if(j==n-1-i)  // if diagonal, insert numbers
         {
            matrix[i][j]=D[j];
            check[D[j]] = 1;
         }
      }
   }
   
   for(j=n-2; j>=0; j--)  // insert number at upword triangle of maxrix
   {
      for(i=n-2-j; i>=0; i--)
      {
         if (matrix[i+1][j] > matrix[i][j+1]) // calculate inserted value 
         {
            insert = matrix[i][j+1]-1;
         }
         else
         {
            insert = matrix[i+1][j]-1;
         }
         
         if (check[insert] == 1) // checking repetition
         {
            while (1)
            {
               insert = insert - 1;
               
               if (check[insert] == 0)  // insert value if not repetition 
               {
                  matrix[i][j] = insert;
              check[insert] = 1;
                  break;
               }
            }
         }
       else
       {
          matrix[i][j] = insert;
          check[insert] = 1;
       }
      }
   }
   
   if (matrix[0][0] < X)  // Are upword triangle satisfied the condition?
      return 0;  // infeasible
      
    
   for(j=1; j<n; j++)  // insert number at downword triangle of maxrix
   {
      for(i=n-j; i<n; i++)
      {
         if (matrix[i-1][j] > matrix[i][j-1]) // calulate inserted value
         {
            insert = matrix[i-1][j]+1;
         }
         else
         {
            insert = matrix[i][j-1]+1;
         }
         
         if (check[insert] == 1)  // checking repitition
         {
            while (1)
            {
               insert = insert + 1;
               
               if (check[insert] == 0)  // insert value if not repetition 
               {
                  matrix[i][j] = insert;
              	  check[insert] = 1;
                  break;
               }
            }
         }   
       else
       {
          matrix[i][j] = insert;
          check[insert] = 1;
       }
      }
   }
   
   if (matrix[n-1][n-1] > Y)  // are downside triangle right at the condition?
      return 0;  // infeasible
   
   return 1;
}

/* You can modify to here */

int main(void) {
   // your code goes here
   int X,Y,n;
   int *D, **matrix,i,j;
   
   
   printf("What is X and Y?");
   scanf("%d %d",&X, &Y);
   printf("What is n?");
   scanf("%d",&n);
   D=(int*)calloc(n,sizeof(int));
   printf("What are Ds?");
   for (i=0; i<n; i++) {
      scanf("%d",&D[i]);   
   }
   
   
   
   matrix=(int**)calloc(n,sizeof(int*));
   for (i=0; i<n; i++) {
      matrix[i]=(int*)calloc(n,sizeof(int));
   }
   
   printf("\n");
   if (test_cases(X,Y,n,D,matrix)==0) {
      printf("Infeasible!\n");
   } else {
      for (i=0; i<n; i++) {
         for (j=0; j<n; j++) {   
            printf("%d ", matrix[i][j]);   
         }
         printf("\n");
      }
   }
   
   
   
   
   for (i=0; i<n; i++) {
      free(matrix[i]);
   }
   free(matrix);
   free(D);
   
   
   return 0;
}
