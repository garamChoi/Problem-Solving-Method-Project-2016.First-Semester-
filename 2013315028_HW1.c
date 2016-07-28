#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10 //Input can be changed

int count=0;
int access_value(int x, int y) {
	int **input,i;
	input=(int**)calloc(LENGTH,sizeof(int*));
	for (i=0; i<LENGTH; i++) {
		input[i]=(int*)calloc(LENGTH,sizeof(int));
	}
	
	count++;
	
	//Input can be changed
   input[0][0]= 2;
   input[0][1]= 6;
   input[0][2]= 7;
   input[0][3]= 8;
   input[0][4]= 13;
   input[0][5]= 15;
   input[0][6]= 19;
   input[0][7]= 27;
   input[0][8]= 28;
   input[0][9]= 30;
   input[1][0]= 4;
   input[1][1]= 7;
   input[1][2]= 10;
   input[1][3]= 15;
   input[1][4]= 19;
   input[1][5]= 24;
   input[1][6]= 27;
   input[1][7]= 36;
   input[1][8]= 52;
   input[1][9]= 53;
   input[2][0]= 6;
   input[2][1]= 11;
   input[2][2]= 12;
   input[2][3]= 18;
   input[2][4]= 26;
   input[2][5]= 28;
   input[2][6]= 45;
   input[2][7]= 46;
   input[2][8]= 65;
   input[2][9]= 67;
   input[3][0]= 7;
   input[3][1]= 16;
   input[3][2]= 20;
   input[3][3]= 24;
   input[3][4]= 32;
   input[3][5]= 37;
   input[3][6]= 45;
   input[3][7]= 48;
   input[3][8]= 72;
   input[3][9]= 81;
   input[4][0]= 15;
   input[4][1]= 17;
   input[4][2]= 24;
   input[4][3]= 28;
   input[4][4]= 43;
   input[4][5]= 52;
   input[4][6]= 61;
   input[4][7]= 65;
   input[4][8]= 79;
   input[4][9]= 84;
   input[5][0]= 26;
   input[5][1]= 30;
   input[5][2]= 33;
   input[5][3]= 44;
   input[5][4]= 57;
   input[5][5]= 61;
   input[5][6]= 65;
   input[5][7]= 76;
   input[5][8]= 80;
   input[5][9]= 87;
   input[6][0]= 27;
   input[6][1]= 35;
   input[6][2]= 42;
   input[6][3]= 59;
   input[6][4]= 61;
   input[6][5]= 62;
   input[6][6]= 69;
   input[6][7]= 81;
   input[6][8]= 86;
   input[6][9]= 92;
   input[7][0]= 34;
   input[7][1]= 39;
   input[7][2]= 50;
   input[7][3]= 60;
   input[7][4]= 64;
   input[7][5]= 71;
   input[7][6]= 81;
   input[7][7]= 87;
   input[7][8]= 92;
   input[7][9]= 94;
   input[8][0]= 47;
   input[8][1]= 59;
   input[8][2]= 61;
   input[8][3]= 66;
   input[8][4]= 75;
   input[8][5]= 80;
   input[8][6]= 90;
   input[8][7]= 92;
   input[8][8]= 94;
   input[8][9]= 97;
   input[9][0]= 59;
   input[9][1]= 61;
   input[9][2]= 75;
   input[9][3]= 83;
   input[9][4]= 88;
   input[9][5]= 91;
   input[9][6]= 91;
   input[9][7]= 92;
   input[9][8]= 96;
   input[9][9]= 98;
	
	/*
	The input array is
  2   6   7   8  13  15  19  27  28  30 
  4   7  10  15  19  24  27  36  52  53 
  6  11  12  18  26  28  45  46  65  67
  7  16  20  24  32  37  45  48  72  81
 15  17  24  28  43  52  61  65  79  84
 26  30  33  44  57  61  65  76  80  87
 27  35  42  59  61  62  69  81  86  92
 34  39  50  60  64  71  81  87  92  94
 47  59  61  66  75  80  90  92  94  97
 59  61  75  83  88  91  91  92  96  98  
	
	*/
	
	return input[x][y];
	
}

void cal_single(int k) {
	int i, j, now;                          //  make  variables
	
	for(i=0; i<LENGTH; i++)                 // double "for" statements execute
	{
		for(j=0; j<LENGTH; j++)                
		{
			now = access_value(i, j);     //  assigne row and column of matrix to now
			if(k<now)                    // if i find wanted row and column, immediatly out
				break;
			if(k==now)            // if k statements match access_value, immediatly copy out 
			{                                    // execpt other maching numbers
				printf("(%d, %d)\n", i, j);            // print out only one element in maxtrix row and column in searching sequence
				return;
			}
		}
	}
	return;
}

void cal_all(int k) {
	int i, j, now;                      // make variables
	
	for(i=0; i<LENGTH; i++)               
	{                                           // double "for" statement execute
		for(j=0; j<LENGTH; j++)
		{
			now = access_value(i, j);        //  assigne row and column of matrix to now
			if(k<now)                       // if i find wanted row and column, another elements dismiss afterward next string move and 
				break;                      // start seaching
			if(k==now)           //if k statements match accss_value, immediatly copy out  
			{                                   // including other matching numbers
				printf("(%d, %d)\n", i, j);     // printf out all elements in maxrix row and column in searching sequence 
				
			}
		}
	}
	

	return;
}


int main(void) {
	int i,j,k;

	k=7;
	printf("k is %d.\n",k);

	count=0;
	printf("\nFinding any single k\n");
	cal_single(k);
	printf("\nCount=%d\n",count);

	count=0;
	printf("\nFinding all k\n");
	cal_all(k);
	printf("\nCount=%d\n",count);

}

		
		







