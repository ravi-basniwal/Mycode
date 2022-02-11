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
     string s1,s2;
     cin >> s1 >> s2;
     int n=s1.length();
     int m=s2.length();
     vector<int>temp(m+1,0);
     vector<vector<int>>dp(n+1,temp);
     for(int i=n;i>=0;i--)
     {
          for(int j=m;j>=0;j--)
          {
               if(j!=m and i!=n)
               {
                    if(s1[i]==s2[j])
                    dp[i][j]=dp[i+1][j+1]+1;
                    else 
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
               }
               
          }
     }
     // for(auto x:dp)
     // {
     //      for(auto p:x)
     //      cout << p << " ";
     //      cout << endl;
     // }
    cout << dp[0][0] << endl;

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