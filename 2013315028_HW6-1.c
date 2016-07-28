#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
//define floors max height , max riders, maxint
#define NFLOORS 110
#define MAX_RIDERS 50
#define MAXINT 110
#define MAX_STOP 50 //  max number of stoped elevator  

//define stops array for where riders go,number of riders,stops and double array for main data that calculate optimal jth stops
int stops[MAX_RIDERS];
	int nriders;
	int nstops;
	int elevator_place[MAX_STOP]; // stored where elevator is stop
	int people_place[MAX_RIDERS]; // the place which last people get off
	
	int m[NFLOORS+1][MAX_RIDERS];
	int p[NFLOORS+1][MAX_RIDERS];

//when people between two floor go down add all people' steps
int floors_walked(int previous, int current){
	int nsteps=0;
	int i;
	//  it is impossible to go up home after elevator  get off
	for (i = 1; i <= nriders; i++)
		if ((stops[i] > previous) && (stops[i]) <= current)
			nsteps += current - stops[i];
		
	return (nsteps);
}


//when found optimal solution with specific lastfloor print lastfloor in j:1~nstops case recursively
void reconstruct_path(int lastfloor,int stops_to_go){
	
	if(stops_to_go>1)
		reconstruct_path(p[lastfloor][stops_to_go],stops_to_go-1);
	
	
	elevator_place[stops_to_go] = lastfloor; // elevator is stored  stopping place  
	return ;
}

//optimze floor function is in main function
int main() {
	//gets nessesary data and define variables;
	scanf("%d",&nriders);
	scanf("%d",&nstops);    // must stop the elevator if lived high floor
	
	int x;
	for(x=1;x<=nriders;x++){
		scanf("%d",&stops[x]);
	}
	
	int i,j,k;
	int cost;
	int laststop;
	int maxfloor;

	// seach for max floor in disembarked people
	maxfloor = 0;
	for (i = 1; i <= nriders; i++)
		if (maxfloor < stops[i])
			maxfloor = stops[i];
	elevator_place[nstops] = maxfloor;
		nstops = nstops - 1;

	//calculate move when 0 stops
	for(i=1; i<=maxfloor; i++){
		m[i][0]=floors_walked(1,maxfloor);
		p[i][0]=-1;
	}
	// calculate optimal move when j stops is from 1 to nstops one by one. the idea is optimal j+1 stop case is solved by all j stop cases
	for(j=1; j<=nstops ; j++)
		for(i=1; i<=maxfloor; i++){
			m[i][j]=MAXINT; // make min
			for(k=1; k<=i; k++){
				cost = m[k][j-1] - floors_walked(k,maxfloor) + floors_walked(k,i) + floors_walked(i,maxfloor);
				if(cost<m[i][j]){
					m[i][j]=cost;
					p[i][j]=k;
				}
			}
	}
	//all floors in optimal solution is saved in p[i][1~j], i means lastfloor and m[i][j] has optimal cost so gets it
	laststop= 1;
	for (i = 1; i <= maxfloor;i++)
	{
		if (m[i][nstops] < m[laststop][nstops]) 
		{
			laststop = i;
		}
	}
		
	reconstruct_path(laststop,nstops);

	nstops = nstops + 1;
	// the place which people get off, elevator's location sum 
	for (i = 1; i <= nriders; i++)
	{
		
		for (j = 1; j <= nstops; j++)
		{
			if (stops[i] - elevator_place[j] <= 0)  // elevator stop if elevator arrive more high than arrived floor 
			{
				people_place[i] = elevator_place[j];   //pepole get off the place which elavator stoped 
				break;

			}
		}
	}

	for (i = 1; i <= nriders; i++) // print out where people get off
		printf("%d\n", people_place[i]);
	
	return 0;
}
