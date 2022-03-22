
   
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
vector<int>bfs(int v,vector<int>*adj)
{
    // to find the total number of components in a graph see only how many time the if condition is true
    vector<int>ans;
    vector<bool>visited(v+1,false);
    for(int i=1;i<=v;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            queue<int>q;
            q.push(i);
            while(q.size())
            {
                int top_ele=q.front();
                ans.push_back(top_ele);
                q.pop();
                for(auto x:adj[top_ele])
                {
                    if(!visited[x]){
                    visited[x]=true;
                    q.push(x);}
                }
            }
        }
    }
    return ans;
}
vector<int>dfs(int v,vector<int>*adj)
{
    vector<int>ans;
    vector<bool>visited(v+1,false);
    for(int i=1;i<=v;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            stack<int>ms;
            ms.push(i);
            while(ms.size())
            {
                int top_ele=ms.top();
                ans.push_back(top_ele);
                ms.pop();
                // stack<int>temp;
                for(auto x:adj[top_ele])
                {
                    if(!visited[x])
                    {
                        visited[x]=true;
                        ms.push(x);
                    }
                }
            }
        }
    }
    return ans;
}
void solve() {
     int v=10;
    //  cin >> v;
     int e=10;
    //  cin >> e;
     vector<pair<int,int>>edge{{1,3},{3,2},{3,4},{2,5},{6,7},{7,8},{8,9},{9,10},{10,6},{10,7}};
    //  for(int i=0;i<e;i++)
    //  {
    //      int frm,to;
    //      cin >> frm >> to;
    //      edge.push_back({frm,to});
    //  }
  vector<int>adj[v+1];
  vector<vector<int>>matrix(v+1,vector<int>(v+1,0));

  for(auto x:edge)
  {
      int frm=x.first;
      int to=x.second;
      adj[frm].push_back(to);
      adj[to].push_back(frm);
      matrix[frm][to]=1;
      matrix[to][frm]=1;
      
  }
  for(auto x:bfs(v,adj))
  cout << x << " ";
  cout << endl;
  for(auto x:dfs(v,adj))
  cout << x << " ";
  
    

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
