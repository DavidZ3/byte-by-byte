<<<<<<< Updated upstream
#include <stdio.h>
#define EXIT_SUCCESS 0;

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    return EXIT_SUCCESS;
=======
#include "quickSort.h"

/*
 If the range has fewer than two elements, return immediately as there is
nothing to do. Possibly for other very short lengths a special-purpose sorting
method is applied and the remainder of these steps skipped. Otherwise pick a
value, called a pivot, that occurs in the range (the precise manner of choosing
depends on the partition routine, and can involve randomness). Partition the
range: reorder its elements, while determining a point of division, so that all
elements with values less than the pivot come before the division, while all
elements with values greater than the pivot come after it; elements that are
equal to the pivot can go either way. Since at least one instance of the pivot
is present, most partition routines ensure that the value that ends up at the
point of division is equal to the pivot, and is now in its final position (but
termination of quicksort does not depend on this, as long as sub-ranges strictly
smaller than the original are produced). Recursively apply quicksort to the
sub-range up to the point of division and to the sub-range after it, possibly
excluding from both ranges the element equal to the pivot at the point of
division. (If the partition produces a possibly larger sub-range near the
boundary where all elements are known to be equal to the pivot, these can be
excluded as well.)
*/

int partition(int* arr, int lo, int hi){
    int pivot = arr[hi];
    int idx = lo;

    for (int i; condition; inc-expression) {
    
    }



    return -1;

}

void quickSort(int* arr, int lo, int hi)
{
    if ((lo >= hi) || (lo < 0))
        return;
    
    int p = partition(arr, lo, hi);
    quickSort(arr, lo, p-1);
    quickSort(arr, p, hi);
>>>>>>> Stashed changes
}
