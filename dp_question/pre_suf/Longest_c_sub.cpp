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
    string s;
    cin >> s;
    string p;
    cin >>p ;
    int n=s.length();
    int m=p.length();
    vector<int>temp(n,0);
    vector<vector<int>>dp(m,temp);
    int c=0;
    for(int i=0;i<m;i++)
    {
         for(int j=0;j<n;j++)
         {
              if(i==0)
              {
                   if(s[j]==p[i])
                   dp[i][j]=1;
              }
              else if(j==0)
              {
                   if(s[j]==p[i])
                   dp[i][j]=1; 
              }
              else 
              {
                   if(s[j]==p[i])
                   dp[i][j]=1+dp[i-1][j-1];   
              }
              c<dp[i][j]?c=dp[i][j]:c=c;
         }
    }
//    for(auto x: dp)
//    {
//         for(auto e:x)
//         cout << e << " ";
//         cout << endl;
//    }
   cout << c << endl;
    

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