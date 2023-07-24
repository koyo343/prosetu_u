#include <stdio.h>

int main(void)
{
  double x, x1, x2, eps, v;

  eps = 2e-3;

  x1 = 0.0;
  x2 = 1.0;

  while (x2 - x1 > eps) {
    x = (x1 + x2) / 2.0;
    v = x * x * x + x - 1.0;

    printf("x1 = %f, x2 = %f, x = %f, v = %f\n", x1, x2, x, v);

    if (v > 0)
      x2 = x;
    else
      x1 = x;
  }

  x = (x1 + x2) / 2.0;
  printf("answer = %f\n", x);

  return 0;
}
