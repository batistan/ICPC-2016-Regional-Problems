#include <stdio.h>
#include <stdlib.h>

int p (int n);
int q (int n);

int main() {

  int numlines;
  scanf("%d", &numlines);

  // allocate memory for all data
  int *values = malloc(numlines*sizeof(int));
  int junk, i;

  // get data
  for (i = 0; i < numlines; i++) {
    // first integer is just the line number, which we don't care about
    // second integer is the actual value, which we put into values[i]
    scanf("%d %d", &junk, values+i);
  }

  for (i = 0; i < numlines; i++) {
    printf("%d %d/%d\n", i+1, p(values[i]), q(values[i]));
  }

  exit(EXIT_SUCCESS);
}

int p (int n) {
  if (n==1) { 
    return 1;
  }

  else {
    if (n%2==0) {
      return p(n/2);
    }
    else {
      return p((n-1)/2) + q((n-1)/2);
    }
  }
}

int q (int n) {
  if (n==1) {
    return 1;
  }

  else {
    if (n%2==0) {
      return p(n/2) + q(n/2);
    }

    else {
      return q((n-1)/2);
    }
  }
}
