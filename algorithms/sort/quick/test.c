#include "quickSort.h"

static void printArray(const int *arr, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {
  int arr1[] = {42};
  int arr2[] = {-3, 7, 0, -131, 23, 2, 9};
  int arr3[] = {1, 2, 3, 4, 5, 6};
  int arr4[] = {6, 5, 4, 3, 2, 1};
  int arr5[] = {5, 5, 5, 5, 5};
  int arr6[] = {3, 1, 2, 3, 2, 1, 0, 0, -1, -1};

  struct {
    const char *name;
    int *arr;
    int n;
  } tests[] = {
      {"single", arr1, sizeof arr1 / sizeof arr1[0]},
      {"mixed", arr2, sizeof arr2 / sizeof arr2[0]},
      {"alreadySorted", arr3, sizeof arr3 / sizeof arr3[0]},
      {"reverseSorted", arr4, sizeof arr4 / sizeof arr4[0]},
      {"allEqual", arr5, sizeof arr5 / sizeof arr5[0]},
      {"duplicates", arr6, sizeof arr6 / sizeof arr6[0]},
  };

  for (size_t t = 0; t < sizeof tests / sizeof tests[0]; ++t) {
    printf("Test %s\n", tests[t].name);
    printf("  Input:  ");
    printArray(tests[t].arr, tests[t].n);

    quickSort(tests[t].arr, 0, tests[t].n - 1);

    printf("  Sorted: ");
    printArray(tests[t].arr, tests[t].n);
    printf("\n");
  }

  return 0;
}
