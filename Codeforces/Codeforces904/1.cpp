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

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

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

#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

int getSum(int num) {
  int sum = 0;
  while (num > 0) {
    int m = num % 10;
    sum += m;
    num /= 10;      
  }

  return sum;
}

int main() {
	fastio
  

  int run;
  cin >> run;

  for (int runs = 0; runs < run; runs++) {
    int x, k;
    cin >> x >> k;
    int curr = x;
    
    for (;; curr++) {
      if (getSum(curr) % k == 0) {
        cout << curr << endl;
        break;
      } 
    }
  }

	return 0;
}