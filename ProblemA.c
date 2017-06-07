#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hextodec (int n, int count);
int octtodec (int n, int count);

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
    printf("%d %d %d %d\n", i+1, octtodec(values[i],0), values[i], hextodec(values[i],0));
  }

  exit(EXIT_SUCCESS);
}

int hextodec (int n, int count) {
  if (n < 10) {
    return n*pow(16,count);
  }

  else {
    // tail recursion!
    return hextodec(n/10, count+1) + ((n%10)*pow(16,count));
  }
}

int octtodec (int n, int count) {
  // first check if it's a valid octal number
  if (count == 0) {
    int i = n;
    // make sure each digit is a valid octal digit i.e. less than 8
    while (i >= 10) {
      if (i%10>=8) {
        return 0;
      }

      i /= 10;
    }
  }

  // we haven't returned yet, so it's valid
  // proceed with conversion
  if (n < 10) {
    return n*pow(8,count);
  }

  else {
    return octtodec(n/10, count+1) + ((n%10)*pow(8,count));
  }
}
