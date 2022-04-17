
   
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
void dfs(int i,vector<bool>&visited,vector<int>*adj)
{
    visited[i]=true;
    for(auto x:adj[i])
    {
        if(!visited[x])
        dfs(x,visited,adj);
    }
}
void solve() {
     int n;
     cin >> n;
     int m;
     cin >> m ;
     vector<int>adj[n+1];
     for(int i=0;i<m;i++)
     {
         int frm;
         int to;
         cin >> frm >> to;
         adj[frm].push_back(to);
         adj[to].push_back(frm);
         
     }
     vector<int>com_first;
     vector<bool>visited(n+1,false);
     for(int i=1;i<=n;i++)
     {
         if(!visited[i])
         {
             
             com_first.push_back(i);
             dfs(i,visited,adj);
         }
     }
     cout << com_first.size()-1 << endl;
     for(int i=1;i<com_first.size();i++)
     cout << com_first[i-1] << " " << com_first[i] <<endl;
     
  
    

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
