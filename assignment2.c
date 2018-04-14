#include<stdio.h>


void calc_wt();
int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
   
int main()
{
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter burst time for the processes: \n");
    for(i=0;i<n;i++)
    {
        printf("\nP%d => ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;          	 //contains process number
    }
   
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

void sort(){

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
}
