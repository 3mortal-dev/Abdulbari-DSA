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

std::set<std::string> s;

void repeat(std::string comb, std::string norm)
{
  if (norm.size() == 0)
  {
    s.emplace(comb);
    return;
  }
  for (int i = 0; i < norm.size(); ++i)
  {
    std::string temp = norm;
    repeat(comb + norm[i], temp.erase(i, 1));
  }
}

ll solve()
{
  std::string str;
  std::cin >> str;

  repeat("", str);

  std::cout << s.size() << endl;

  for (const auto &v : s)
  {
    std::cout << v << endl;
  }

  return 0;
}

int main()
{
  fast_io;
  int testCases = 1;
  while (testCases--)
  {
    solve();
  }
  return 0;
}