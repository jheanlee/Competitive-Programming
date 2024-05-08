// 17.4.1.2 Headers

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
    // x %= m;
    if (b % 2)
    {
      x *= a;
      // x %= m;
    }
    return x;
  }
}

#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

/*-----SECTION: Bruteforce [ O(n^2) (TLE) ]-----*/
vector<bool> bf_hit;
int bf_spell(vector<vi> &board, int castI, int castJ) { // O(1)
  int rtn = 0;

  for (int tmpI = castI - 2; tmpI <= castI + 2 && tmpI < board.size(); tmpI++) {
    if (tmpI < 0) continue;
    for (int tmpJ = castJ - 2; tmpJ <= castJ + 2 && tmpJ < board.size(); tmpJ++) {
      if (tmpJ < 0) continue;
      if (board[tmpI][tmpJ] == -1) continue;
      if ((tmpI == castI - 2 || tmpI == castI + 2) && (tmpJ == castJ - 2 || tmpJ == castJ - 2)) continue;
      if (!bf_hit[board[tmpI][tmpJ]]) {bf_hit[board[tmpI][tmpJ]] = true; rtn++;}
    }
  }

  return rtn;
}

void bf_construct_board(vector<vi> &board, int conI, int conJ, int count) { // O(1)
  //guaranteed that buildings would not exceed the boundary
  board[conI - 1][conJ - 1] = count;
  board[conI - 1][conJ] = count;
  board[conI - 1][conJ + 1] = count;
  board[conI][conJ - 1] = count;
  board[conI][conJ] = count;
  board[conI][conJ + 1] = count;
  board[conI + 1][conJ - 1] = count;
  board[conI + 1][conJ] = count;
  board[conI + 1][conJ + 1] = count;
}

void bruteforce() { // O(n)
  int n, m;
  cin >> n >> m;

  vector<vi> board(n, vector<int>(n, -1));
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    bf_construct_board(board, a - 1, b - 1, i);
  }

  int maxi = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bf_hit = vector<bool> (m + 1, false);
      maxi = max(bf_spell(board, i, j), maxi);
    }
  }

  cout << maxi << endl;
}



/*-----SECTION: Bruteforce Optimised - only cells with a building [ O(m) ] -----*/
vector<bool> bf_o_hit;
int bf_o_spell(vector<vi> &board, int castI, int castJ) { // O(1) //No optimisation
  int rtn = 0;

  for (int tmpI = castI - 2; tmpI <= castI + 2 && tmpI < board.size(); tmpI++) {
    if (tmpI < 0) continue;
    for (int tmpJ = castJ - 2; tmpJ <= castJ + 2 && tmpJ < board.size(); tmpJ++) {
      if (tmpJ < 0) continue;
      if (board[tmpI][tmpJ] == -1) continue;
      if ((tmpI == castI - 2 || tmpI == castI + 2) && (tmpJ == castJ - 2 || tmpJ == castJ - 2)) continue;
      if (!bf_o_hit[board[tmpI][tmpJ]]) {bf_o_hit[board[tmpI][tmpJ]] = true; rtn++;}
    }
  }
  return rtn;
}

void bf_o_construct_board(vector<vi> &board, int conI, int conJ, int count, vector<pair<int,int> > &building) { // O(1)
  //guaranteed that buildings would not exceed the boundary
  board[conI - 1][conJ - 1] = count;
  board[conI - 1][conJ] = count;
  board[conI - 1][conJ + 1] = count;
  board[conI][conJ - 1] = count;
  board[conI][conJ] = count;
  board[conI][conJ + 1] = count;
  board[conI + 1][conJ - 1] = count;
  board[conI + 1][conJ] = count;
  board[conI + 1][conJ + 1] = count;

  //Add cells with a building to a vector
  building.pb(mp(conI - 1, conJ - 1));
  building.pb(mp(conI - 1, conJ));
  building.pb(mp(conI - 1, conJ + 1));
  building.pb(mp(conI, conJ - 1));
  building.pb(mp(conI, conJ));
  building.pb(mp(conI, conJ + 1));
  building.pb(mp(conI + 1, conJ - 1));
  building.pb(mp(conI + 1, conJ));
  building.pb(mp(conI + 1, conJ + 1));
}

void bruteforce_optimised() { // O(m)
  int n, m;
  cin >> n >> m;

  vector<vi> board(n, vector<int>(n, -1));
  vector<pair<int, int> > building;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    bf_o_construct_board(board, a - 1, b - 1, i, building);
  }

  int maxi = 1; //can hit at least one building
  for (auto &p : building) { //iterate through all cords with a building
    bf_o_hit = vector<bool> (m + 1, false);
    maxi = max(bf_o_spell(board, p.first, p.second), maxi);
  }

  cout << maxi << endl;
}





void run_with_timer() {
  clock_t start_time, end_time;
  start_time = clock();

/*---Write code to time here---*/

  bruteforce_optimised();
  
/*-----------------------------*/
  end_time = clock();
  double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
  cout << endl << "------------------------------------------------------------" << endl;
  cout << "Execution Time: " << fixed << time_taken << setprecision(5);
  cout << " sec" << endl;
  cout << "------------------------------------------------------------" << endl;
}


int main() {
  fastio

  run_with_timer();

  return 0;
}
