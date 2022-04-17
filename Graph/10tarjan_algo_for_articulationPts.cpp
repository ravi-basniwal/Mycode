
   
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
void dfs(int v,int i,vector<pair<int,int>>*adj,vector<bool>&visited,vector<int>&prnt,vector<int>&dis,vector<int>&low,int timer,vector<bool>&ans)
{
     timer++;
     int c=0;
     dis[i]=timer;
     low[i]=timer;
    for(auto x:adj[i])
    {
        int node=x.first;
        int wgt=x.second;
       
        if(prnt[node]==i)
        continue;
        else if(visited[node])
        low[i]=min(low[i],dis[node]);  
        else
        {
          visited[node]=true;
          prnt[node]=i;
          c++;
          dfs(v,node,adj,visited,prnt,dis,low,timer,ans);
          low[i]=min(low[i],low[node]);
          if(prnt[i]==-1)
          {
             if(c>=2)
             ans[i]=true;
          }
          else
          {
              if(low[node]>=dis[i])
              ans[i]=true;
          }
        }
    }
}
void solve() {
     int v=10;
     //  cin >> v;
     int e=10;
     //  cin >> e;
     vector<pair<int,pair<int,int>>>edge{{5,{1,3}},{2,{3,4}},{12,{2,4}},{1,{3,2}},{2,{2,5}},{4,{9,3}},{1,{9,10}},{2,{10,1}}};
     // vector<pair<int,int>>edge{{6,1},{5,1},{5,2},{6,3},{3,4},{4,2}};
     vector<pair<int,int>>adj[v+1];
      for(auto x:edge)
        {
           int wgt=x.first;
           int frm=x.second.first;
           int to=x.second.second;
            adj[frm].push_back({to,wgt});
            adj[to].push_back({frm,wgt});
       
         }
         vector<bool>visited(v+1,false);
         vector<int>prnt(v+1,-1);
         vector<int>dis(v+1,0);
         vector<int>low(v+1,0);
         int p=0;
         for(int i=1;i<=v;i++)
         {
            if(!visited[i])
            {
                vector<bool>ans(v+1,false);
                visited[i]=true;
                dfs(v,i,adj,visited,prnt,dis,low,0,ans);
                for(auto x:ans)
               { if(x)
                p++;}
            }
         }
         cout << p << endl;
         
     
    
 
  
    

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
