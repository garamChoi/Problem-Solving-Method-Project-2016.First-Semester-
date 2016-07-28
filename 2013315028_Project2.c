// 2013315028 CHoi-Garam
#include <stdio.h>

void fillT(int start,int end,char* a);
void fillWL(int start,int end,char* a,int flagT,int flagWL);
void fillX(char *a);
void fillres(char *a);

int main(void)
{
	int a,b,c,d,e;
	char arr[20][20];
	int i, j;

	// input W(a),T(b),L(c),m(d),E(e) //
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);

	// case1: minimum and W>=L //
	if(e==0 && a>=c){
		
		// fill W on upper triangle //
		for(i=0;i<d-1;i++){
			for(j=d-1;j<20;j++){
				arr[i][j]='W';
			}
		}
		
		// T middle, W+L<2T //
		if(((a>=b&&b>=c) || (a<=b&&b<=c)) && a+c<2*b){
			fillT(0,d-1,&arr[0][0]);
			fillWL(d-1,20,&arr[0][0],0,0);
		}
		
		// T middle, W+L>=2T //
		else if(((a>=b&&b>=c) || (a<=b&&b<=c)) && a+c>=2*b){
			fillT(0,d-1,&arr[0][0]);
			fillT(d-1,20,&arr[0][0]);
		}

		// T highest //
		else if(b>=a&&b>=c){
			fillT(0,d-1,&arr[0][0]);
			fillWL(d-1,20,&arr[0][0],1,0);
		}

		// T lowest //
		else if(b<=a&&b<=c){
			fillT(0,20,&arr[0][0]);
		}

		fillX(&arr[0][0]);
		fillres(&arr[0][0]);
	}

	// case2: minimum and W<L //
	if(e==0 && a<c){
		
		// fill L on upper triangle //
		for(i=0;i<d-1;i++){
			for(j=d-1;j<20;j++){
				arr[i][j]='L';
			}
		}
		
		// T middle, W+L<2T //
		if(((a>=b&&b>=c) || (a<=b&&b<=c)) && a+c<2*b){
			fillT(0,d-1,&arr[0][0]);
			fillWL(d-1,20,&arr[0][0],0,1);
		}
		
		// T middle, W+L>=2T //
		else if(((a>=b&&b>=c) || (a<=b&&b<=c)) && a+c>=2*b){
			fillT(0,d-1,&arr[0][0]);
			fillT(d-1,20,&arr[0][0]);
		}

		// T highest //
		else if(b>=a&&b>=c){
			fillT(0,d-1,&arr[0][0]);
			fillWL(d-1,20,&arr[0][0],1,1);
		}

		// T lowest //
		else if(b<=a&&b<=c){
			fillT(0,20,&arr[0][0]);
		}

		fillX(&arr[0][0]);
		fillres(&arr[0][0]);
	}
	
	// case3: maximum and W>=L //
	if(e==1 && a>=c){

		// fill W on upper triangle //
		for(i=0;i<d;i++){
			for(j=d;j<20;j++){
				arr[i][j]='W';
			}
		}
		
		// T middle, W+L<2T //
		if(((a>=b&&b>=c) || (a<=b&&b<=c)) && a+c<2*b){
			fillT(0,d,&arr[0][0]);
			fillT(d,20,&arr[0][0]);
		}
		
		// T middle, W+L>=2T //
		else if(((a>=b&&b>=c) || (a<=b&&b<=c)) && a+c>=2*b){
			fillWL(0,d,&arr[0][0],0,0);
			fillT(d,20,&arr[0][0]);
		}

		// T highest //
		else if(b>=a&&b>=c){
			fillT(0,20,&arr[0][0]);
		}

		// T lowest //
		else if(b<=a&&b<=c){
			fillWL(0,d,&arr[0][0],1,0);
			fillT(d,20,&arr[0][0]);
		}

		fillX(&arr[0][0]);
		fillres(&arr[0][0]);
	}

	// case4: maximum and W<L //
	if(e==1 && a<c){

		// fill L on upper triangle //
		for(i=0;i<d;i++){
			for(j=d;j<20;j++){
				arr[i][j]='L';
			}
		}
		
		// T middle, W+L<2T //
		if(((a>=b&&b>=c) || (a<=b&&b<=c)) && a+c<2*b){
			fillT(0,d,&arr[0][0]);
			fillT(d,20,&arr[0][0]);
		}
		
		// T middle, W+L>=2T //
		else if(((a>=b&&b>=c) || (a<=b&&b<=c)) && a+c>=2*b){
			fillWL(0,d,&arr[0][0],0,1);
			fillT(d,20,&arr[0][0]);
		}

		// T highest //
		else if(b>=a&&b>=c){
			fillT(0,20,&arr[0][0]);
		}

		// T lowest //
		else if(b<=a&&b<=c){
			fillWL(0,d,&arr[0][0],1,1);
			fillT(d,20,&arr[0][0]);
		}
			
		fillX(&arr[0][0]);
		fillres(&arr[0][0]);
	}

	// print the match //
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",arr[i][j]);
		}printf("\n");
	}

	return 0;
}

//fills all element in half of the given gird with T
void fillT(int start,int end,char* a){
	int i,j;
	for(i=start;i<end;i++){
		for(j=i+1;j<end;j++)
		*(a+i*20+j)='T';
	}
	return;
}

// Fill W and L considering m and E //
// flagT : determine whether T or W/L for left diagonal //
// flagWL : determine whether W and L changed //
void fillWL(int start,int end,char* a,int flagT,int flagWL){

	int i,j;

	// fill given square with L or W //
	for(i=start;i<end;i++){
		for(j=i+1;j<end;j++){
			if(flagWL==0)
				*(a+i*20+j)='L';
			else
				*(a+i*20+j)='W';
		}
	}

	// if one side of given square is even //
	if((end-start)%2==0){
		
		// fill the square with T or W/L //
		if(flagT==0){
			for(i=start;i<=start-1+(end-start)/2;i++)
			*(a+i*20+i+(end-start)/2)='T';
		}
		else{
			for(i=start;i<=start-1+(end-start)/2;i++)
				if(flagWL==0)
					*(a+i*20+i+(end-start)/2)='W';
				else
					*(a+i*20+i+(end-start)/2)='L';
		}
			
		// fill the rest of square //
		for(i=start;i<start-1+(end-start)/2;i++){
			for(j=i+1+(end-start)/2;j<end;j++){
				if(flagWL==0)
					*(a+i*20+j)='W';
				else
					*(a+i*20+j)='L';
			}
		}	
	}
	// if one side of given square is odd //
	else{
		for(i=start;i<start+(end-start)/2;i++){
			for(j=i+1+(end-start)/2;j<end;j++){
				if(flagWL==0)
					*(a+i*20+j)='W';
				else
					*(a+i*20+j)='L';
				
			}
		}
	}
	
	return;
}

// fill the diagonal with X //
void fillX(char* a){
	int i;
	for(i=0;i<20;i++)
	*(a+i*20+i)='X';
	
	return;
}

// fill lower triangle from upper triangle //
void fillres(char* a){
	int i,j;
	for(i=0;i<20;i++){
		for(j=i+1;j<20;j++){
			if(*(a+20*i+j)=='W')
			*(a+j*20+i)='L';
			if(*(a+i*20+j)=='T')
			*(a+j*20+i)='T';
			if(*(a+i*20+j)=='L')
			*(a+j*20+i)='W';
		}
	}
	return;
}
