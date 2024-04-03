#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int a, b;
    cin >> a >> b;

    int x = 1;
    int y = a;

    while (b != 0)
    {
      if (b & 0x1 == 1)
      {
        x *= y;
        x %= 10;
      }

      b >>= 1;
      y = pow(y, 2);
      y %= 10;
    }

    cout << (x == 0 ? 10 : x) << endl;
  }

  return 0;
}