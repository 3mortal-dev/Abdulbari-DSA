#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define fast_io                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr)
#define vi std::vector<ll>
#define si std::set<ll>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

int n;

class Board
{
public:
  std::vector<std::vector<char>> st;

  Board(int size) : st(size, std::vector<char>(size, '.')) {}

  bool operator<(const Board &other) const
  {
    return this->st < other.st;
  }

  void print_board()
  {
    for (int i = 0; i < (int)st.size(); i++)
    {
      for (int j = 0; j < (int)st.size(); ++j)
      {
        std::cout << st[i][j];
      }
      std::cout << endl;
    }
  }
  bool is_safe(int curr_i, int curr_j)
  {

    // prevent putting 2 queens
    if ((this->st)[curr_i][curr_j] == 'Q')
      return false;

    for (int i = 0; i < (int)st.size(); i++)
    {
      for (int j = 0; j < (int)st.size(); ++j)
      {
        if ((this->st)[i][j] == 'Q')
        {

          // H,V
          if (curr_i == i || curr_j == j)
            return false;

          // diagonal
          if (curr_i - i == curr_j - j)
            return false;

          // off_diagonal
          if (curr_i + curr_j == i + j)
            return false;
        }
      }
    }
    return true;
  }
};

std::set<Board> boards;

void func(Board board, int row)
{
  if (row == n)
  {
    boards.emplace(board);
    return;
  }

  for (int j = 0; j < n; ++j)
  {
    if (board.is_safe(row, j))
    {
      board.st[row][j] = 'Q';
      func(board, row + 1);
      board.st[row][j] = '.';
    }
  }
}

ll solve()
{
  std::cin >> n;
  Board board(n);
  func(board, 0);
  for (auto c : boards)
  {
    c.print_board();
    std::cout << endl;
  }
  return 0;
}

int main()
{
  fast_io;

  int testCases = 1;
  // cin >> testCases;
  while (testCases--)
  {
    solve();
  }
  return 0;
}