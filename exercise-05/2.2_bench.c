#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define ROUNDS 10
#define LOOP 100

int main() {
  void *init = sbrk(0);
  void *current;

  printf("The initial top of the heap is at %.p\n", init);

  for (int j = 0; j < ROUNDS; j++) {
    for (int i = 0; i < LOOP; i++) {
      size_t size = (rand() % 4000) + sizeof(int);

      int *memory;
      memory = malloc(size);

      if (memory == NULL) {
        fprintf(stderr, "ERROR: malloc failed!\n");
        return 1;
      }

      // *memory = 123; // write to memory so we know it exists
      free(memory);
    }

    current = sbrk(0);
    int allocated = (int) ((current - init) / 1024);

    printf("\n|-- %d --|\n", j);
    printf("The current top of the heap is at %.p\n", current);
    printf("Increased by %d Kbyte\n", allocated);
  }

  return 0;
}