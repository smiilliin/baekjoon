#include <iostream>
#include <vector>

using namespace std;

void solveABC(int startIndex, int N, int W, vector<int> count[2], vector<int> &A, vector<int> &B, vector<int> &C)
{
  for (int i = startIndex;; i++)
  {
    C[i] = min(A[i - 1] + 1, B[i - 1] + 1);

    if (i > 1 && count[0][i - 2] + count[0][i - 1] <= W && count[1][i - 2] + count[1][i - 1] <= W)
    {
      C[i] = min(C[i], C[i - 2] + 2);
    }
    if (count[0][i - 1] + count[1][i - 1] <= W)
    {
      C[i] = min(C[i], C[i - 1] + 1);
    }
    if (i == N)
      break;

    A[i] = C[i] + 1;
    B[i] = C[i] + 1;

    if (count[0][i - 1] + count[0][i] <= W)
    {
      A[i] = min(A[i], B[i - 1] + 1);
    }
    if (count[1][i - 1] + count[1][i] <= W)
    {
      B[i] = min(B[i], A[i - 1] + 1);
    }
  }
}
void resetABC(int N, vector<int> &A, vector<int> &B, vector<int> &C)
{
  A.assign(N, 0);
  B.assign(N, 0);
  C.assign(N + 1, 0);

  A[0] = 1;
  B[0] = 1;
  C[0] = 0;
}
int solve(int N, int W, vector<int> count[2])
{
  vector<int> A, B, C;

  bool dupUp = false, dupDown = false;

  if (N > 1)
  {
    dupUp = count[0][0] + count[0][N - 1] <= W;
    dupDown = count[1][0] + count[1][N - 1] <= W;
  }

  resetABC(N, A, B, C);

  solveABC(1, N, W, count, A, B, C);
  int result = C[N];

  if (dupUp && dupDown)
  {
    resetABC(N, A, B, C);

    A[1] = 1;
    B[1] = 1;
    C[1] = 0;

    solveABC(2, N, W, count, A, B, C);
    result = min(result, C[N - 1] + 2);
  }
  if (dupUp)
  {
    resetABC(N, A, B, C);

    A[1] = 2;
    B[1] = count[1][0] + count[1][1] <= W ? 1 : 2;
    C[1] = 1;

    solveABC(2, N, W, count, A, B, C);
    result = min(result, B[N - 1] + 1);
  }
  if (dupDown)
  {
    resetABC(N, A, B, C);

    A[1] = count[0][0] + count[0][1] <= W ? 1 : 2;
    B[1] = 2;
    C[1] = 1;
    solveABC(2, N, W, count, A, B, C);
    result = min(result, A[N - 1] + 1);
  }
  return result;
}
int main()
{
  int T, N, W;
  cin >> T;

  vector<int> count[2];

  for (int t = 0; t < T; t++)
  {
    cin >> N >> W;

    int tmp;

    count[0].clear();
    count[1].clear();

    for (int i = 0; i < N; i++)
    {
      cin >> tmp;
      count[0].push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
      cin >> tmp;
      count[1].push_back(tmp);
    }

    cout << solve(N, W, count) << endl;
  }

  return 0;
}