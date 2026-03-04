#include <stdio.h>

int main() {
    int n, i, time = 0, smallest, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   // Remaining time
    }

    while(completed < n) {
        smallest = -1;

        for(i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {

                if(smallest == -1)
                    smallest = i;

                else if(rt[i] < rt[smallest])
                    smallest = i;

                // 🔹 Tie case: same remaining time
                else if(rt[i] == rt[smallest]) {

                    // Choose earlier arrival
                    if(at[i] < at[smallest])
                        smallest = i;

                    // If arrival also same → smaller process number
                    else if(at[i] == at[smallest] && i < smallest)
                        smallest = i;
                }
            }
        }

        if(smallest == -1) {
            time++;  // CPU idle
        } else {
            rt[smallest]--;
            time++;

            if(rt[smallest] == 0) {
                completed++;
                ct[smallest] = time;
                tat[smallest] = ct[smallest] - at[smallest];
                wt[smallest] = tat[smallest] - bt[smallest];

                avg_wt += wt[smallest];
                avg_tat += tat[smallest];
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
