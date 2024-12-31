#if defined(__GNUG__) && !defined(__llvm__)
  #include <bits/stdc++.h>
#else
  // C
  #ifndef _GLIBCXX_NO_ASSERT
  #include <cassert>
  #endif
  #include <cctype>
  #include <cerrno>
  #include <cfloat>
  #include <ciso646>
  #include <climits>
  #include <clocale>
  #include <cmath>
  #include <csetjmp>
  #include <csignal>
  #include <cstdarg>
  #include <cstddef>
  #include <cstdio>
  #include <cstdlib>
  #include <cstring>
  #include <ctime>

  #if __cplusplus >= 201103L
  #include <ccomplex>
  #include <cfenv>
  #include <cinttypes>
  #include <cstdbool>
  #include <cstdint>
  #include <ctgmath>
  #include <cwchar>
  #include <cwctype>
  #endif

  // C++
  #include <algorithm>
  #include <bitset>
  #include <complex>
  #include <deque>
  #include <exception>
  #include <fstream>
  #include <functional>
  #include <iomanip>
  #include <ios>
  #include <iosfwd>
  #include <iostream>
  #include <istream>
  #include <iterator>
  #include <limits>
  #include <list>
  #include <locale>
  #include <map>
  #include <memory>
  #include <new>
  #include <numeric>
  #include <ostream>
  #include <queue>
  #include <set>
  #include <sstream>
  #include <stack>
  #include <stdexcept>
  #include <streambuf>
  #include <string>
  #include <typeinfo>
  #include <utility>
  #include <valarray>
  #include <vector>

  #if __cplusplus >= 201103L
  #include <array>
  #include <atomic>
  #include <chrono>
  #include <condition_variable>
  #include <forward_list>
  #include <future>
  #include <initializer_list>
  #include <mutex>
  #include <random>
  #include <ratio>
  #include <regex>
  #include <scoped_allocator>
  #include <system_error>
  #include <thread>
  #include <tuple>
  #include <typeindex>
  #include <type_traits>
  #include <unordered_map>
  #include <unordered_set>
  #endif
#endif

using namespace std;

typedef long long ll;
typedef float ld;
typedef double db;

typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
typedef pair<double, double> pd;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

//#define f first
//#define s second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl '\n'

#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);

void __pl() { cerr << '\n'; }
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}'; }
template<typename T>
void __print(const T& x) { int n = 0; cerr << '{'; for (auto& i : x) cerr << (n++ ? ", " : ""), __print(i); cerr << "}"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }


#define mod 1000000007
ll powa(ll a, ll b, ll m = mod)
{
  if (b == 0)
    return 1ll;
  else if (b == 1)
    return a;
  else
  {
    ll x = powa(a, b / 2, m);
    x *= x;
    x %= m;
    if (b % 2)
    {
      x *= a;
      x %= m;
    }
    return x;
  }
}

#ifdef DEBUG
  #define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
  #define dbg(x...)
#endif

int main() {
  fastio
  int n, m;
  cin >> n >> m;

  int rtn = 0;
  int v;
  int v1, v2;

  unordered_map<int, int> map; // location = key, num = val;

  for (int run = 0; run < m; run++) {
    cin >> v;
    if (v == 1) {
      cin >> v1 >> v2;
      if (map.find(v1) != map.end() && map.find(v2) != map.end()) {swap(map[v1], map[v2]);}
      else if (map.find(v1) != map.end()) {map[v2] = map[v1]; map[v1] = v2;}
      else if (map.find(v2) != map.end()) {map[v1] = map[v2]; map[v2] = v1;}
      else {map[v1] = v2; map[v2] = v1;}
    } else if (v == 2) {
      cin >> v1;
      if (map.find(v1) != map.end()) {rtn += map[v1];}
      else {rtn += v1;}
    }
  }

  cout << rtn << endl;

  return 0;
}
