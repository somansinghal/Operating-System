// fifo page replacement
#include <stdio.h>
int main() {
  int pages[] = {1, 3, 0, 3, 5, 6, 3};
  int n = sizeof(pages) / sizeof(pages[0]);
  int capacity = 3;
  int frames[capacity];
  for (int i = 0; i < capacity; i++) {
    frames[i] = -1;
  }
  int page_faults = 0;
  int index = 0;
  printf("Page\tFrames\n");
  for (int i = 0; i < n; i++) {
    int found = 0;
    for (int j = 0; j < capacity; j++) {
      if (frames[j] == pages[i]) {
        found = 1;
        break;
      }
    }
    if (!found) {
      frames[index] = pages[i];
      index = (index + 1) % capacity;
      page_faults++;
    }
    printf("%d\t", pages[i]);
    for (int j = 0; j < capacity; j++) {
      if (frames[j] != -1)
        printf("%d ", frames[j]);
      else
        printf("- ");
    }
    printf("\n");
  }
  printf("\nTotal Page Faults: %d\n", page_faults);
  printf("Total Page Hits: %d\n", n - page_faults);
  return 0;
}