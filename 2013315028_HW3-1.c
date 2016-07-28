//2013315028 choi garam

#include <stdio.h>
#include <stdlib.h>

/* You can modify from here */

void copy(int *x, int *y, int n) // at x, copy  y 
{
	int i;
	for (i=0; i<n; i++)
	{
		x[i]=y[i];
	}
}

int minimize(int x[], int y, int idx) // this fuction minimizes the total lengths
{
   int i, j, cur;
   int n2;
   int n1;
   int p1, p2;
   int temp[10000];

   cur=idx;
   n1=cur+3;
   n2=cur;
   
   copy(temp, x, idx+1);

   for (i=cur-1; i >= 1; i--){
      for (j=cur-3; j >= 0; j--){
         p1=i, p2=j;

         while (1){
            temp[cur]=temp[p1]+temp[p2];

            if (temp[cur]>y)
               p2--;
            else if (temp[cur]<y){
               n2 = ++cur;
               p1 = cur-1, p2 = cur-2;
            }
            else{
               n2 = ++cur;
               break;
            }
         }

         if (n2>=n1)
            cur=idx;
         else{
         	copy(x, temp, n2);
            return n2;
         }
      }
   }

   if (i==0 && j==0)
      return n1;

   return n1;
}

int cal_x(int x[], int y){

	int n=0; // the total number made in the index
	
	int i, j, flag=0;
	int temp;
	for(i=3; i<10000; i++){    // i will start  form 3 because of making fix numbers  
		x[i] = x[i-1] + x[i-2]; // add the number there
		if(x[i]==y){            // if i insert y is same i
			n=i+1;             // contain the total numbers with making the numbers
			break;
		}
		else if(x[i]>y){                   //  if inserting numbers is higher than y 
			for(j=0; j<i-1; j++){         //   not add privious numbers, but adds a initial number    
				if(x[i-1]+x[j]==y){      //    execute the calculation 
					x[i]=y;
					n=i+1;
					flag=1;             //  makes y if flag become 1     
					break;
				}
			}
			if(flag==0){                   // makes y if flag become 0    
				for(j=0; j<i-1; j++){      //  
					if(x[j]+x[i-1]>y)	
					break;
				}
				x[i]=x[i-1]+x[j-1];           // adding i of before valuey and j's value is not higher than y 
				temp=x[i];
				
				while(temp<y){               // to inserting the i's value to temp, this is smaller than y, and execute         
					i++;
					x[i]=x[i-1]+1;
					temp++;
				}
				n=i+1;
				break;  
			}
			else break;
		}
		else if (y-x[i] == 2)
		{
			x[i+1]=x[i]+1;
			x[i+2]=x[i]+2;
			n=minimize(x, y, i);
			return n;
		}
	}
	
	return n;
}

/* You can modify to here */

int main(void) {
	int x[10000],y,n,i;  
	
	x[0]=1, x[1]=1, x[2]=3;
	
	
	printf("What is y? ");
	scanf("%d",&y);
	
	
	n = cal_x(x,y);

	for (i=0; i<n; i++) {
		printf("%d ",x[i]);
	}
	printf("\n");
	
	

	return 0;
}
