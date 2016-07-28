// 2013305028 garam choi
#include <stdio.h>
/* You can modify from here */
char Max(int a, int b, int c)   //  after take three cards, printg max number  
{
   if(a>b && a>c)
      return a;
   
   else if(b>a && b>c)
      return b;
      
   else
      return c;
}
char Min(int a, int b, int c) //  after take three cards, printg min number
{
   if(a<b && a<c)
      return a;
   
   else if(b<a && b<c)
      return b;
      
   else
      return c;
}
char Mid(int a, int b, int c)  // after take three cards, printg mid number
{
   if(b>a && b<c)
      return b;
      
   else if(a>b && a<c)
      return a;
      
   else
      return c;
}

int straight_flush(char BN1, char BS1, char BN2, char BS2, char BN3, char BS3){
   int max, mid, min;                             
   
   max = Max(BN1, BN2, BN3);
   mid = Mid(BN1, BN2, BN3);
   min = Min(BN1, BN2, BN3);
   
   if(BS1==BS2 && BS3==BS1)              // first card, second card and third card are same 
    {
      if(max-mid==1 && mid-min==1)       // condition operation execute . if below conditional statement satisfied, executed choiced statement,
      									//	the better conditional statements proceed .and calculate total sum
         return 50+max+1;
                                          // straight number dicide to 50 score
      if(min==7 && mid==8 && max==9)
         return 50+max;
      
      if(max-mid==1)
         return 50+max+1;
      
      if(max==9 && mid==8)
         return 50+max;
      
      if(max-mid==2)
         return 50+max;
      
      if(mid-min==1)
         return 50+mid+1;
         
      if(max==9 && mid==8)
         return 50+max;   
         
      if(mid-min==2)
         return 50+max;
         
      if(mid-min==1)
         return 50+mid;
      
      if(mid-min==2)
         return 50+mid;


   }   

   return 0; 
}
int flush(char BN1, char BS1, char BN2, char BS2, char BN3, char BS3){
   int max, mid, min;
   
   max = Max(BN1, BN2, BN3);
   mid = Mid(BN1, BN2, BN3);
   min = Min(BN1, BN2, BN3);
   
   if(BS1==BS2 && BS3==BS1)             // flush have same suit. if below conditional statement satisfied, executed choiced statement,
      									// the better conditional statements proceed and calculate total sum 
      									// flush number dicide to 30 score
      if(max-mid==1 && mid-min==1)             
         return 30+max+1;
      {
         if(min==7 && mid==8 && max==9)
         return 30+max;
      
         if(max-mid==1)
         return 30+max+1;
      
         if(max==9 && mid==8)
         return 30+max;
      }
      if(max-mid==2)
         return 30+max;
      
      {   
         if(mid-min==1)
         return 30+mid+1;
         
         if(max==9 && mid==8)
         return 30+max;   
         
         if(mid-min==2)
         return 30+max;
         
         if(mid-min==1)
         return 30+mid;
      }
      if(mid-min==2)
         return 30+mid;
   else 
      return 0;
}
int straight(char BN1, char BS1, char BN2, char BS2, char BN3, char BS3){
   int max, mid, min;
   
   max = Max(BN1, BN2, BN3);
   mid = Mid(BN1, BN2, BN3);
   min = Min(BN1, BN2, BN3);
   
      if(max-mid==1 && mid-min==1)      // if satisfied the consecutive order from numbers, executed statements below. 
	  									// straight number is decided to 40 score  
         return 40+max+1;
      if(min==7 && mid==8 && max==9)
         return 40+max;
      
      if(max-mid==1)
         return 40+max+1;
      
      if(max==9 && mid==8)
         return 40+max;
      if(max-mid==2)
         return 40+max;

      if(mid-min==1)
         return 40+mid+1;
         
      if(max==9 && mid==8)
         return 40+max;   
         
      if(mid-min==2)
         return 40+max;
         
      if(mid-min==1)
         return 40+mid;
      if(mid-min==2)
         return 40+mid;
         
   else
      return 0;
}
int threeofkind(char BN1, char BS1, char BN2, char BS2, char BN3, char BS3){
   int max, mid, min;
                                  
   max = Max(BN1, BN2, BN3);
   mid = Mid(BN1, BN2, BN3);
   min = Min(BN1, BN2, BN3);
   
   if(BN1==BN2 && BN3==BN1)           // if satisfied the 3 same numbers of cards, executed statements below. 
	  									// straight number is decided to 20 score
    {
    
      if(max-mid==1 && mid-min==1)
         return 20+max+1;
      
         if(min==7 && mid==8 && max==9)
         return 20+max;
      
         if(max-mid==1)
         return 20+max+1;
      
         if(max==9 && mid==8)
         return 20+max;
      
      if(max-mid==2)
         return 20+max;
      
         
         if(mid-min==1)
         return 20+mid+1;
         
         if(max==9 && mid==8)
         return 20+max;   
         
         if(mid-min==2)
         return 20+max;
         
         if(mid-min==1)
         return 20+mid;
      
      if(mid-min==2)
         return 20+mid;
   }
   return max+10;                  //if this statemens not satisfied with upword, Pair rule executed . rule of High card is discard because impossible make
   								//    this rule. 4 rules not contained. automatic sequence follws the Pair rule
}
int score(char N1, char S1, char N2, char S2, char N3, char S3){
      
   int score1;
   
      score1=straight_flush(N1, S1, N2, S2, N3, S3);              // calculate straight_flush score, afterward send total sum to  black or white
      if(score1!=0){
         return score1;
      }
      score1=flush(N1, S1, N2, S2, N3, S3);                // calculate fulsh score, atgerward send total sum to black or white
      if(score1!=0){
         return score1;
      }
      score1=straight(N1, S1, N2, S2, N3, S3);              // calculate straight score, afterward send total sum to black or white
      if(score1!=0){                                       
         return score1;
      }
      score1=threeofkind(N1, S1, N2, S2, N3, S3);              // calculate threeofkind score, afterward send total sum to black or white
      if(score1!=0){                                       
         return score1;
     }
      else
         return Max(N1, N2, N3)+10;                     //  the rule of upward not satisfied, afterward apply to Pair rule, calulate score 
      
}
int Foker_hands(char BN1, char BS1, char BN2, char BS2, char BN3, char BS3,char WN1, char WS1, char WN2, char WS2, char WN3, char WS3){
   
   int black_score=0;               // score of black is maked to 0 number
   int white_score=0;				// score of white is maked to 0 number
   
   black_score = score(BN1, BS1, BN2, BS2, BN3, BS3);        // black score calulated from score function taking 6 parameter 
   white_score = score(WN1, WS1, WN2, WS2, WN3, WS3);		// white score calulated from score function taking 6 parameter 
   
   if(white_score > black_score)                        //if white score win black score, print out Black wins your monitor
      return 1;
   else if (white_score < black_score)					//if white score win white score, print out White wins your monitor
      return -1;
   else return 0;										// if white and block is draw, print out Tie your monitor 
   

   
}

/* You can modify to here */

int main(void) {
   // your code goes here
   int result;
   char BN1, BS1, BN2, BS2, BN3, BS3, WN1, WS1, WN2, WS2, WN3, WS3;
   
   
   scanf("%c%c %c%c %c%c %c%c %c%c %c%c", &BN1, &BS1, &BN2, &BS2, &BN3, &BS3, &WN1, &WS1, &WN2, &WS2, &WN3, &WS3);

   result = Foker_hands(BN1, BS1, BN2, BS2, BN3, BS3,WN1, WS1, WN2, WS2, WN3, WS3);
   if (result==1) printf("White wins.\n");
   else if (result==-1) printf("Black wins.\n");
   else printf("Tie.\n");
   return 0;
}
