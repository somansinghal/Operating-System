#include <stdio.h>

int main() {
  int n, i, j, temp, p[20], bt[20], pr[20], wt[20], tat[20];
  float avg_wt = 0, avg_tat = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  printf("Enter Burst time & Priority for each process:\n");
  for (i = 0; i < n; i++) {
    p[i] = i + 1;
    printf("P%d Burst Time: ", i + 1);
    scanf("%d", &bt[i]);
    printf("P%d Priority: ", i + 1);
    scanf("%d", &pr[i]);
  }

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (pr[i] > pr[j]) {
        temp = pr[i];
        pr[i] = pr[j];
        pr[j] = temp;

        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }

  wt[0] = 0;
  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
  }

  printf("\nProcess\tBurst Time\t\tPriority\tWaiting time\tTurn Around Time\n");
  for (i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i];
    avg_tat += tat[i];
    avg_wt += wt[i];
    printf("P%d\t\t%d\t\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pr[i], wt[i],
           tat[i]);
  }

  printf("\nAverage Waiting Time: %.2f", avg_wt / n);
  printf("\nAverage Turn Around Time: %.2f\n", avg_tat / n);

  return 0;
}
