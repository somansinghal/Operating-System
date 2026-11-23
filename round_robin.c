#include <stdio.h>

int main() {
  int n, i, bt[100], rt[100], wt[100], tat[100], tq;

  printf("Enter number of processes: ");
  if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
    printf("Invalid number of processes.\n");
    return 1;
  }

  for (i = 0; i < n; i++) {
    printf("P%d Burst Time: ", i + 1);
    if (scanf("%d", &bt[i]) != 1 || bt[i] < 0) {
      printf("Invalid Burst Time.\n");
      return 1;
    }
    rt[i] = bt[i];
    wt[i] = 0;
    tat[i] = 0;
  }

  printf("Enter Time Quantum: ");
  if (scanf("%d", &tq) != 1 || tq <= 0) {
    printf("Invalid Time quantum.\n");
    return 1;
  }

  int time = 0, done = 0, completion[100];
  while (done < n) {
    int progressed = 0;
    for (i = 0; i < n; i++) {
      if (rt[i] > 0) {
        progressed = 1;
        int slice = rt[i] < tq ? rt[i] : tq;
        time += slice;
        rt[i] -= slice;
        if (rt[i] == 0) {
          completion[i] = time;
          done++;
        }
      }
    }
    if (!progressed)
      break;
  }

  float avg_wt = 0.0f, avg_tat = 0.0f;
  for (i = 0; i < n; i++) {
    tat[i] = completion[i];
    wt[i] = tat[i] - bt[i];
    if (wt[i] < 0)
      wt[i] = 0;
    avg_wt += wt[i];
    avg_tat += tat[i];
  }

  printf("\nProcess\tBurst Time\tTime Quantum=%d\tWaiting Time\tTurn Around "
         "Time\n",
         tq);
  for (i = 0; i < n; i++) {
    printf("P%d\t\t%d\t\t\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
  }

  printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);
  printf("Average Turn Around Time: %.2f\n", avg_tat / n);

  return 0;
}