#include <stdio.h>

int main() {
  int n, m, i, j, k, f = 0;
  scanf("%d%d", &n, &m);

  int a[n][m], max[n][m], need[n][m], avail[m];
  int finish[n], safe[n], work[m];

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &a[i][j]);

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &max[i][j]);

  for (j = 0; j < m; j++)
    scanf("%d", &avail[j]);

  for (i = 0; i < n; i++) {
    finish[i] = 0;
    for (j = 0; j < m; j++)
      need[i][j] = max[i][j] - a[i][j];
  }

  for (j = 0; j < m; j++)
    work[j] = avail[j];

  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      if (!finish[i]) {
        for (j = 0; j < m && need[i][j] <= work[j]; j++)
          ;
        if (j == m) {
          for (j = 0; j < m; j++)
            work[j] += a[i][j];
          safe[f++] = i;
          finish[i] = 1;
        }
      }

  if (f == n) {
    printf("Safe sequence: ");
    for (i = 0; i < n; i++)
      printf("P%d ", safe[i]);
  } else
    printf("Unsafe state");

  return 0;
}
