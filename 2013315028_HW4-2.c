//2013315028 choigaram
#include <stdio.h>
#include <stdlib.h>

int is_a_solution(int a[], int k, int day[], int fine[], int num_task) {
   /* You can modify from here */
   if (k == num_task)    // if depth is same numbers of shows,  return 1 if not 0
      return 1;
   else
      return 0;
   /* You can modify to here */
}

void process_solution(int a[], int day[], int fine[], int num_task, int order[], int *min) {
   /* You can modify from here */
   int Totaltime = 0;
   int Totalfine = 0;
   int i;
   
   for (i=0; i<num_task; i++)                 // this for statement calculates total fine
   {
      Totalfine += Totaltime * fine[a[i]];
      Totaltime += day[a[i]];
   }
   
   if (Totalfine < *min)          // if total fine is min, be changed min of totalfine 
   {
      *min = Totalfine;
      for (i=0; i<num_task; i++)  // insert order frst processed work
         order[i] = a[i];
   }
   else
      ;
   /* You can modify to here */
}


void construct_candidates(int a[], int k,  int day[], int fine[], int num_task, int c[], int *ncandidates) {
   /* You can modify from here */
   int *flags;   // prvious numbers exist ot not
   int i;
   int idx = 0;

   flags = (int *)malloc(num_task * sizeof(int));
   
   for (i=0; i<num_task; i++)  //every flag do 0 
      flags[i] = 0;
   
   for (i=0; i<k; i++)
      flags[a[i]] = 1;      // previous existed nuber makes 1
      
   for (i=0; i<num_task; i++)  // insert numberss prvious not exising 
      if (flags[i] == 0)
      {
         c[idx] = i;
         idx += 1;
      }
   
   *ncandidates = idx;   // numbers of candidates
   /* You can modify to here */
}


void backtrack(int a[], int k, int num_task, int day[], int fine[], int order[], int *min) {
   /* You can modify from here */
   int *c;
   int ncandidates;
   int i;

   c = (int *)malloc(num_task * sizeof(int));
   
   if(is_a_solution(a,k,day,fine,num_task))
      process_solution(a,day,fine,num_task,order,min); // 원하는 답이 맞으면 하고 싶은 일을 한다.  
   else{
      construct_candidates(a,k,day,fine,num_task,c,&ncandidates);
      for(i=0; i<ncandidates; i++){
         a[k] =c[i];
         backtrack(a,k+1,num_task,day,fine,order,min);
      }
   }

   /* You can modify to here */
}


int calculate_fine(int day[], int fine[], int num_task, int order[] ) {
   /* You can modify from here */
   int Totaltime = 0;
   int Totalfine = 0;
   int i;
   
   for (i=0; i<num_task; i++)     // this for statement calculates total fine
   {
      Totalfine += Totaltime * fine[i];
      Totaltime += day[i];
   }

   return Totalfine;
   /* You can modify to here */

}

int main(void) {
   
   int num_case;
   int num_task;
   int *day;
   int *a;
   int *fine;
   int *order;
   int i,j;
   int min;

   scanf("%d",&num_case);

   for(i=0;i<num_case;i++) {
      scanf("%d",&num_task);
      day = (int*)calloc(num_task,sizeof(int));
      fine = (int*)calloc(num_task,sizeof(int));
      order = (int*)calloc(num_task,sizeof(int));
      a = (int*)calloc(num_task,sizeof(int));
      for(j=0;j<num_task;j++) {
         scanf("%d %d",&day[j],&fine[j]);
         order[j]=j;
      }
      min=calculate_fine(day,fine,num_task,order);
      backtrack(a, 0, num_task, day, fine, order, &min);
      if (i>0) printf("\n");
      for(j=0;j<num_task;j++) {
         printf("%d",order[j]+1);
         if (j<num_task-1) printf(" ");
      }
      printf("\n");
      free(day);
      free(fine);
      free(order);
   } 
   return 0;
}
