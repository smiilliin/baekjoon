#include <stdio.h>
#include <math.h>

#define bool int
#define false 0
#define true (!false)

double distance(int x1, int y1, int x2, int y2)
{
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
bool in(int cx, int cy, int r, int x, int y)
{
  if (distance(cx, cy, x, y) <= r)
  {
    return true;
  }
  return false;
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; i++)
  {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int result = 0;
    int n;
    scanf("%d", &n);

    for (int j = 0; j < n; j++)
    {
      int cx, cy, r;
      scanf("%d %d %d", &cx, &cy, &r);

      bool in1 = in(cx, cy, r, x1, y1);
      bool in2 = in(cx, cy, r, x2, y2);

      if (in1 != in2)
        result++;
    }
    printf("%d\n", result);
  }

  return 0;
}
