#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, head, total_movement = 0, count = 0;
  int req[100];
  printf("Enter the number of requests: ");
  scanf("%d", &n);
  printf("Enter the request sequence: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &req[i]);
  }
  printf("Enter initial head position: ");
  scanf("%d", &head);
  printf("\nSeek Sequence: %d", head);
  while (count < n) {
    int min_distance = 9999;
    int index = -1;
    for (int i = 0; i < n; i++) {
      int distance = abs(req[i] - head);
      if (distance < min_distance) {
        min_distance = distance;
        index = i;
      }
    }
    total_movement += min_distance;
    head = req[index];
    printf(" -> %d", head);
    req[index] = 9999;
    count++;
  }
  printf("\nTotal Head Movement: %d\n", total_movement);
  return 0;
}