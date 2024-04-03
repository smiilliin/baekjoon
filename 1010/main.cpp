#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int T;

  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int N, M;

    cin >> N >> M;

    // MCN
    if (M - N < N)
      N = M - N;

    double x = 1;

    for (int j = 0; j < N; j++)
    {
      x *= M--;
      x /= (N - j);
    }

    cout << (int)round(x) << endl;
  }
}