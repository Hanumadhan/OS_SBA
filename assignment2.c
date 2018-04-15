#include <stdio.h>

struct process{
	int P[100];
	int at[100];
	int bt[100];
	int ct[100];
	int pr[100];
	int tat[100];
	int wt[100];
}p,t;	

int i, j, n, total=0, pos, temp, avg_wt, avg_tat, AT[100];;

void calc_wt();
   
int main()
{
	printf("Enter Total Number of Process: ");
	scanf("%d", &n);
 
	printf("\nEnter arrival time and burst time for the processes: \n");
	for(i=0; i<n; i++)
    	{
        	printf("\nP%d:\nArrival time => ",i+1);
        	scanf("%d", &p.at[i]);
        	printf("Burst time => ",i+1);
        	scanf("%d", &p.bt[i]);
        	p.P[i]=i + 1;     		     	 //contains process number
    	}
	
	t = p;

  	for(i=0; i<n; i++){
		printf("\tP%d\t%d\t%d\t%d\n", t.P[i], t.at[i], t.bt[i], t.pr[i]);
	}
  	for(i=0; i<n; i++){
		printf("\n\tP%d\t%d\t%d\t%d\n", p.P[i], p.at[i], p.bt[i], p.pr[i]);
	}
}/*   
    sort();
    calc_wt();

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
    return 0;
}

void calc_wt(){
    wt[0]=0;    //waiting time for first process is zero 
    for(i=1;i<n;i++)			//calculate waiting time
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }
    avg_wt=total/n;      //average waiting time
    total=0;
}

void sort_pr(){
	for(i=0; i<( n - 1 ); i++){
		pos = i; 
      		for(j=i+1; j<n; j++){
         		if(t.bt[pos]>t.bt[j])
            		pos = j;
      		}
      		if(pos != i){
         		temp = t.bt[i];
         		t.bt[i] = t.bt[pos];
         		t.bt[pos] = temp;

			temp = t.P[i];
			t.P[i] = t.P[pos];
			t.P[pos] = temp;
			
			temp = t.at[i];
			t.at[i] = t.at[pos];
			t.at[pos] = temp;
      		}
		t.pr[i] = n-i;
		t.pr[n-1] = 1;
	}
	sort_at();
}

void sort_at(){
   	for(i=0; i<( n - 1 ); i++){
		AT[i] = t.at[i];
		AT[n-1] = t.at[n-1];
		pos = i; 
      		for(j=i+1; j<n; j++){
         		if(AT[pos]>AT[j])
            		pos = j;
      		}
      		if(pos != i){
         		temp = AT[i];
         		AT[i] = AT[pos];
         		AT[pos] = temp;
		}
	}
}

void calc_ct(){
	int tym = 0;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(AT[i] == t.at[j]){
				pos = j;
				if(t.at[pos]<AT[i+1]){
					t.bt[pos] -= (AT[i+1] - t.at[pos]);		//updating burst time
					ct[pos] = AT[i+1];
					tym += ct[pos];
				}
			}
}
