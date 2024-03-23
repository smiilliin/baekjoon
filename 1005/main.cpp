#include <iostream>
#include <vector>

using namespace std;

struct Building
{
  vector<Building *> next;
  int delay;
  int delayCache;

  Building(int delay) : delay(delay), delayCache(-1) {}

  void join(Building *node)
  {
    next.push_back(node);
  }
  int getDelay()
  {
    if (delayCache != -1)
      return delayCache;

    int maxDelay = 0;

    for (auto i : next)
    {
      int delayTemp = i->getDelay();

      if (maxDelay < delayTemp)
      {
        maxDelay = delayTemp;
      }
    }
    delayCache = maxDelay + delay;
    return delayCache;
  }
};

int main()
{
  int T;
  cin >> T;
  for (int t = 0; t < T; t++)
  {
    vector<Building *> buildings;

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
      int D;
      cin >> D;
      buildings.push_back(new Building(D));
    }
    for (int k = 0; k < K; k++)
    {
      int A, B;
      cin >> A >> B;

      buildings[B - 1]->join(buildings[A - 1]);
    }
    int W;
    cin >> W;

    auto start = buildings[W - 1];
    cout << start->getDelay() << endl;

    for (auto i : buildings)
    {
      delete i;
    }
  }
  return 0;
}