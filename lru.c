// LRU
#include <stdio.h>
int main() {
  int pages[50], frames[10], time[10];
  int n, f, counter = 0, faults = 0;
  printf("Enter number of pages: ");
  scanf("%d", &n);
  printf("Enter reference string: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &pages[i]);
  }
  printf("Enter number of frames: ");
  scanf("%d", &f);
  for (int i = 0; i < f; i++) {
    frames[i] = -1;
    time[i] = 0;
  }
  printf("\nFrame States:\n");
  for (int i = 0; i < n; i++) {
    int found = 0;
    for (int j = 0; j < f; j++) {
      if (frames[j] == pages[i]) {
        counter++;
        time[j] = counter;
        found = 1;
        break;
      }
    }
    if (!found) {
      int pos = -1;
      for (int j = 0; j < f; j++) {
        if (frames[j] == -1) {
          pos = j;
          break;
        }
      }
      if (pos == -1) {
        int min = time[0];
        pos = 0;
        for (int j = 1; j < f; j++) {
          if (time[j] < min) {
            min = time[j];
            pos = j;
          }
        }
      }
      counter++;
      frames[pos] = pages[i];
      time[pos] = counter;
      faults++;
    }
    for (int j = 0; j < f; j++) {
      if (frames[j] != -1)
        printf("%d\t", frames[j]);
      else
        printf("-\t");
    }
    printf("\n");
  }
  printf("\nTotal Page Faults: %d\n", faults);
  return 0;
}