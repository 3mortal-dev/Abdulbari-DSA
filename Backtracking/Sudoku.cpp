#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define fast_io                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr)
#define vi std::vector<ll>
#define si std::set<ll>
#define yes std::cout << "YES\n"
#define no std::cout << "NO\n"
#define endl '\n'

template <typename T>
void print2D(const std::vector<std::vector<T>> &vec)
{
  for (const auto &row : vec)
  {
    for (const auto &elem : row)
    {
      std::cout << std::setw(1) << elem << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

bool func(std::vector<std::vector<int>> &sudoku, int zeros)
{
  auto is_valid = [&](int curr_i, int curr_j, int k)
  {
    // Check row
    for (int i = 0; i < 9; ++i)
    {
      if (sudoku[curr_i][i] == k)
        return false;
    }

    // Check Column
    for (int i = 0; i < 9; ++i)
    {
      if (sudoku[i][curr_j] == k)
        return false;
    }

    // Check same box
    int box_i = (curr_i / 3) * 3;
    int box_j = (curr_j / 3) * 3;
    for (int i = box_i; i < box_i + 3; ++i)
    {
      for (int j = box_j; j < box_j + 3; ++j)
      {
        if (sudoku[i][j] == k)
          return false;
      }
    }
    return true;
  };
  if (zeros == 0)
  {
    print2D(sudoku);
    return true;
  }
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      if (sudoku[i][j] != 0)
        continue;
      for (int k = 1; k <= 9; ++k)
      {
        if (is_valid(i, j, k))
        {
          sudoku[i][j] = k;
          if (func(sudoku, zeros - 1))
            return 1;
          sudoku[i][j] = 0;
        }
      }
      return 0;
    }
  }
}

ll solve()
{
  int zeros = 0;
  std::vector<std::vector<int>> sudoku(9, std::vector<int>(9));
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      std::cin >> sudoku[i][j];
      if (sudoku[i][j] == 0)
        zeros++;
    }
  }
  func(sudoku, zeros);
  return 0;
}

int main()
{
  fast_io;

  int testCases = 1;
  // std::cin >> testCases;
  while (testCases--)
  {
    solve();
  }
  return 0;
}