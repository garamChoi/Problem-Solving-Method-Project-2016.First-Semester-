//2013315028 choi garam

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* You can modify from here */
int move(int p, int len, int swap1[], int swap2[], int n){  // function of move is changing back p's letter from forword p's letter         
	int i;
	
	for(i=p-1; i>=0; i--)      //  in the string, designate letter for swapping 
	{
		swap1[n] = len-p+i;  //  backword someting of exchainging two strings          
		swap2[n] = i;                 // forword someting of exchainging two strings  
		n++;                           //   n++ need to calculate the number of swapping 
	}
	return n;
}
int cal_S(int p, char s[], int swap1[], int swap2[]){            
	int n=0;             
	int remain_length=strlen(s);              //  saved remaing letters
	
	
	
	while(p<remain_length)
	{
		n = move(p, remain_length, swap1, swap2, n); // function of move is changing back p's letter from forword p's letter
		remain_length = remain_length-p;            // in remaining letters, remaining letters after fineshing the  fuction of move
	}
	
	if(remain_length == p)           // if p is same the remaing letters
	{
		return n;                   // return number of swapping 
	}
	else                          //  if nevertheless swapping, not come out the normal numbers
		return n;               // return numbers of swapping   
	
	/*
	swap1[0]=0;
	swap2[0]=2;
	swap1[1]=1;
	swap2[1]=3;
	n=2;
	*/

	return n;
}

/* You can modify to here */

int main(void) {
	char s[1000], temp;
	int swap1[10000],swap2[10000],p,y,n,i,j;
	
	printf("What is p?");
	scanf("%d",&p);
	printf("What is String?");
	scanf("%s",s);
	
	
	
	n = cal_S(p,s,swap1,swap2);
	for (i=0; i<n; i++) {
		printf("SWAP %d and %d\n",swap1[i],swap2[i]);
		temp=s[swap1[i]];
		s[swap1[i]] = s[swap2[i]];
		s[swap2[i]]= temp;
		printf("Current String: %s\n",s);
	}
	printf("n=%d\n",n);
	return 0;
}
