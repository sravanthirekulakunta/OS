#include <stdio.h>

int main() {
    int n,i,time=0,count=0,pos;
    int at[20],bt[20],pr[20],rt[20];
    int ct[20],wt[20],tat[20],p[20];
    int done[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i]=i+1;

        printf("\nProcess %d\n",p[i]);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        rt[i]=bt[i];   // remaining time
        done[i]=0;
    }

    while(count<n){
        pos=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                if(pos==-1 || pr[i] < pr[pos]){
                    pos=i;
                }
            }
        }

        if(pos==-1){
            time++;
        }
        else{
            rt[pos]--;   // execute for 1 unit
            time++;

            if(rt[pos]==0){
                ct[pos]=time;
                tat[pos]=ct[pos]-at[pos];
                wt[pos]=tat[pos]-bt[pos];

                done[pos]=1;
                count++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i],at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);
    }

    return 0;
}