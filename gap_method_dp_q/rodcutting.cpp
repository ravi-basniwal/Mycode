#include <bits/stdc++.h>
using namespace std;

#define int            long long int
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

void solve() {
     int n;
     cin >> n;
     vector<int>v;
     for(int i=0;i<n;i++)
     {
          int a;
          cin >> a; 
          v.push_back(a);
     }
     vector<int>dp(n+1,0);
     dp[0]=0;
     dp[1]=v[0];
     for(int i=2;i<=n;i++)
     {
       dp[i]=v[i-1];
       int j=i;
       while(j>=1)
       {
          dp[i]=max(dp[i],v[j-1]+dp[i-j]);
          j--;
       }
     }
     vector<int>dp2(n+1,0);
     dp2[0]=0;
     dp2[1]=v[0];
      for(int i=2;i<=n;i++)
     {
       dp2[i]=v[i-1];
       int j=i;
       while(j>=i/2)
       {
          dp2[i]=max(dp2[i],dp2[j]+dp2[i-j]);
          j--;
       }
     }
     // for(auto x:dp2)
     // cout << x << " ";
     // cout << endl;
     // for(auto x:dp)
     // cout << x << " ";
     // cout << endl;
    cout << dp[n]  << endl;

}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt",  "r",  stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	clock_t z = clock();

	int t = 1;
// 	cin >> t;
	while (t--) solve();

// 	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}