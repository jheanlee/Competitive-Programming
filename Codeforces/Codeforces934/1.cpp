#include <bits/stdc++.h>
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

int main() {
	fastio

  int runs;
  cin >> runs;

  for (int run = 0; run < runs; run++) {
    int n, k;
    cin >> n >> k;

    if (k >= n-1) {cout << 1 << endl;}
    else {cout << n << endl;}
  }

	return 0;
}