#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int T;

  cin >> T;

  for (int t = 0; t < T; t++)
  {
    int x, y;

    cin >> x >> y;

    int n = (int)sqrt(y - x);
    int result = 2 * n - 1;
    int r = y - x - n * n;

    for (int i = n; i > 0; i--)
    {
      if (i <= r)
      {
        result += (int)(r / i);
        r = r % i;
      }
    }
    cout << result << endl;
  }

  return 0;
}