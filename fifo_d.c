// fcfs disk scheduling
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, head, total_movement = 0;

  printf("Enter the number of disk requests: ");
  scanf("%d", &n);

  int requests[n];
  printf("Enter the request queue: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &requests[i]);
  }

  printf("Enter initial head position: ");
  scanf("%d", &head);

  printf("\nSeek Sequence: %d", head);
  for (int i = 0; i < n; i++) {
    total_movement += abs(requests[i] - head);
    head = requests[i];
    printf(" -> %d", head);
  }

  printf("\nTotal Head Movement = %d\n", total_movement);
  printf("Average Seek Length = %.2f\n", (float)total_movement / n);

  return 0;
}