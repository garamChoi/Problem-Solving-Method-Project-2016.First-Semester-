//2013315028 choigaram
#include <stdio.h>
#define SIZE 10

int main(void) {
   int arr[SIZE] = { 1, -2, 3, -4, 5, -3, 2, 1 };
   int N = 8;
   int i,j;
   int cum[SIZE+1]; // 값을 새로 저장할 곳 

   cum[0] = 0;
   for (i = 0; i < N; i++) {
      cum[i + 1] = cum[i] + arr[i];
   }

   for (i = 1; i <= N+1; i++) {
      printf("%3d", i);
   }
   printf("\n");
   printf("=================================================\n");
   for (i = 0; i < N; i++) {
      printf("%3d", arr[i]);
   }
   printf("\n");
   for (i = 0; i <= N; i++) {
      printf("%3d", cum[i]);
   }
   printf("\n");

   for (i = 0; i < N; i++) {
      for (j = i + 1; j <= N; j++) {
         if (cum[i] == cum[j]) {
            printf("(%d, %d) is zero-sum\n", i+1, j);
         }
      }
   }


   return 0;
}
