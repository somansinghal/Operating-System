// Optimal
#include <stdio.h>
int findOptimalFrame(int pages[], int frames[], int numPages, int currentIndex,
                     int numFrames) {
  int farthest = currentIndex;
  int replaceIndex = -1;
  for (int i = 0; i < numFrames; i++) {
    int j;
    for (j = currentIndex; j < numPages; j++) {
      if (frames[i] == pages[j]) {
        if (j > farthest) {
          farthest = j;
          replaceIndex = i;
        }
        break;
      }
    }
    if (j == numPages) {
      return i;
    }
  }
  return (replaceIndex == -1) ? 0 : replaceIndex;
}
int main() {
  int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
  int numPages = sizeof(pages) / sizeof(pages[0]);
  int numFrames = 3;
  int frames[numFrames];
  for (int i = 0; i < numFrames; i++) {
    frames[i] = -1;
  }
  int pageFaults = 0;
  for (int i = 0; i < numPages; i++) {
    int found = 0;
    for (int j = 0; j < numFrames; j++) {
      if (frames[j] == pages[i]) {
        found = 1;
        break;
      }
    }
    if (!found) {
      int emptyFound = 0;
      for (int j = 0; j < numFrames; j++) {
        if (frames[j] == -1) {
          frames[j] = pages[i];
          emptyFound = 1;
          break;
        }
      }
      if (!emptyFound) {
        int replaceIndex =
            findOptimalFrame(pages, frames, numPages, i + 1, numFrames);
        frames[replaceIndex] = pages[i];
      }
      pageFaults++;
    }
    printf("Page %d -> ", pages[i]);
    for (int j = 0; j < numFrames; j++) {
      if (frames[j] != -1)
        printf("%d ", frames[j]);
      else
        printf("- ");
    }
    printf(found ? "(Hit)\n" : "(Fault)\n");
  }
  printf("\nTotal Page Faults: %d\n", pageFaults);
  printf("Total Page Hits: %d\n", numPages - pageFaults);
  return 0;
}