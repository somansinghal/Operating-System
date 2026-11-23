#include <stdio.h>

int main() {
  int n = 4;
  int pid[] = {1, 2, 3, 4};
  int at[] = {2, 0, 4, 1};
  int bt[] = {3, 5, 2, 4};
  int ct[n], tat[n], wt[n];
  int total_tat = 0, total_wt = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (at[i] > at[j]) {
        int temp = at[i];
        at[i] = at[j];
        at[j] = temp;

        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = pid[i];
        pid[i] = pid[j];
        pid[j] = temp;
      }
    }
  }

  ct[0] = at[0] + bt[0];
  for (int i = 1; i < n; i++) {
    if (ct[i - 1] < at[i]) {
      ct[i] = at[i] + bt[i];
    } else {
      ct[i] = ct[i - 1] + bt[i];
    }
  }

  for (int i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    total_tat += tat[i];
    total_wt += wt[i];
  }

  printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i],
           wt[i]);
  }

  printf("\nAverage TAT = %.2f", (float)total_tat / n);
  printf("\nAverage WT = %.2f\n", (float)total_wt / n);

  return 0;
}
