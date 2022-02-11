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
    int n=s.length();
    vector<int>v(n,0);
    vector<vector<int>>dp(n,v);
    for(int gap=0;gap<n;gap++)
    {
         for(int i=0,j=gap;j<n;j++,i++)
         {
            if(gap==0)
            dp[i][j]=1;
            else if(gap==1)
            {
                 if(s[i]==s[j])
                 dp[i][j]=3;
                 else
                 dp[i][j]=2;
            }
            else
            {
                if(s[i]==s[j])
                 dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
                 else
                 dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];  
            }
         }
    }
//    for(auto x:dp)
//    {
//         for(auto p:x)
//         cout << p << " ";
//         cout << endl;
//    }
    cout << dp[0][n-1] << endl;
    

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