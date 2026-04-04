#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0, shortest;
    int at[20], bt[20], rt[20], ct[20];
    int wt[20], tat[20];
    int min, finish_time;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i]; // remaining time
    }

    while (count != n) {
        min = 9999;
        shortest = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] < min && rt[i] > 0) {
                min = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;

        if (rt[shortest] == 0) {
            count++;
            finish_time = time + 1;

            ct[shortest] = finish_time;
            tat[shortest] = finish_time - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            total_wt += wt[shortest];
            total_tat += tat[shortest];
        }

        time++;
    }

    // Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}