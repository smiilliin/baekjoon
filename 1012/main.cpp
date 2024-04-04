#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Vector
{
  int x;
  int y;

  Vector(int x, int y) : x(x), y(y)
  {
  }
  bool inMap(int w, int h) const
  {
    return (x < w && x >= 0 && y < h && y >= 0);
  }
  Vector up() const
  {
    return Vector(x, y + 1);
  }
  Vector down() const
  {
    return Vector(x, y - 1);
  }
  Vector left() const
  {
    return Vector(x - 1, y);
  }
  Vector right() const
  {
    return Vector(x + 1, y);
  }
  bool &fromMap(bool **map) const
  {
    return map[y][x];
  }
};
bool takeArea(bool **map, int w, int h, Vector v)
{
  vector<Vector> next;

  next.push_back(v);

  bool took = false;

  for (int i = 0; i < next.size(); i++)
  {
    auto current = next[i];

    auto &value = current.fromMap(map);

    if (!value)
      continue;

    took = true;
    value = false;

    auto up = current.up();
    auto down = current.down();
    auto left = current.left();
    auto right = current.right();

    if (up.inMap(w, h) && up.fromMap(map))
    {
      next.push_back(up);
    }
    if (down.inMap(w, h) && down.fromMap(map))
    {
      next.push_back(down);
    }
    if (left.inMap(w, h) && left.fromMap(map))
    {
      next.push_back(left);
    }
    if (right.inMap(w, h) && right.fromMap(map))
    {
      next.push_back(right);
    }
  }

  return took;
}

int main()
{
  int T;

  cin >> T;

  for (int t = 0; t < T; t++)
  {
    int W, H, K;

    cin >> W >> H >> K;

    bool **map = new bool *[H];

    for (int y = 0; y < H; y++)
    {
      auto line = new bool[W];

      map[y] = line;

      for (int x = 0; x < W; x++)
      {
        line[x] = false;
      }
    }

    vector<Vector> enabled;
    for (int i = 0; i < K; i++)
    {
      int x, y;

      cin >> x >> y;

      Vector v(x, y);

      v.fromMap(map) = true;
      enabled.push_back(v);
    }

    int count = 0;
    for (auto &v : enabled)
    {
      if (takeArea(map, W, H, v))
      {
        count++;
      }
    }
    cout << count << endl;

    for (int y = 0; y < H; y++)
    {
      delete[] map[y];
    }
    delete[] map;
  }

  return 0;
}