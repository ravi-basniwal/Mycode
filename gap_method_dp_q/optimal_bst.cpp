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
      vector<int>node;
     vector<int>fre;
      for(int i=0;i<n;i++)
      {
           int a;
           cin >> a;
           node.push_back(a);
      }
     for(int i=0;i<n;i++)
     {
          int a;
          cin >> a;
          fre.push_back(a);
     }
     vector<int>temp(n,0);
     vector<vector<int>>dp(n,temp);
    for(int i=0;i<n;i++)
    {
         for(int j=i;j<n;j++)
         {
              if(i==j)
              dp[i][j]=fre[j];
              else
              {
                   dp[i][j]=dp[i][j-1]+fre[j];
              }
         }
    }
    for(int gap=0;gap<n;gap++)
    {
         for(int i=0,j=gap;j<n;j++,i++)
         {
              
              if(gap>=1){
			  int sum=dp[i][j];
              dp[i][j]=INT_MAX;
             for(int k=i;k<=j;k++)
             {
                  if(i==k)
                  dp[i][j]=min(dp[i][j],sum+dp[k+1][j]);
                  else if(j==k)
                   dp[i][j]=min(dp[i][j],sum+dp[i][k-1]);
                   else 
                   dp[i][j]=min(dp[i][j],sum+dp[k+1][j]+dp[i][k-1]);
                  
             }}
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
