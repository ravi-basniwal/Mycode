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
    stack<int>topo;
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
                bool flag=true;
                for(auto x:adj[top_ele])
                {
                    if(!visited[x])
                    {
                        visited[x]=true;
                        flag=false;
                        ms.push(x);
                    }
                }
                if(flag)
                topo.push(top_ele);
            }
        }
    }
    return ans;
}
bool is_cycle_in_dg(int v,vector<int>*adj,int i,vector<bool>&visited,vector<bool>&dfsvisited)
{
   for(auto x:adj[i])
   {
       if(!visited[x])
       {
           visited[x]=true;
           dfsvisited[x]=true;
           if(is_cycle_in_dg(v,adj,x,visited,dfsvisited))
           return true;
       }
       else
       {
          if(dfsvisited[x])
          return true;
       }
   }
   dfsvisited[i]=false;
   return false;
}
void topo_dfs_recursive(int v,vector<int>*adj,int i,vector<bool>&visited,stack<int>&s)
{
    for(auto x:adj[i])
    {
        if(!visited[x])
        {
            visited[x]=true;
            topo_dfs_recursive(v,adj,x,visited,s);
        }
    }
    s.push(i);
}
vector<int>in_degree(int v,vector<int>*adj)
{
    vector<int>degree_in(v+1,0);
    for(int i=1;i<=v;i++)
    {
        for(auto x:adj[i])
        {
        degree_in[x]++;
        }
    }
    return degree_in;
}
vector<int>distance_in_udcg(int v,vector<int>*adj,int source)
{
    vector<int>distance(v+1,INT_MAX);
    queue<int>q;
    q.push(source);
    distance[source]=0;
    while(q.size())
    {
        int topp=q.front();
        q.pop();
        for(auto x:adj[topp])
        {
            if(distance[x]==INT_MAX)
            {
                q.push(x);
                
            }
            distance[x]=min(distance[x],distance[topp]+1);
        }
    }
    return distance;
}
void solve() {
     int v=10;
     //  cin >> v;
     int e=10;
     //  cin >> e;
     vector<pair<int,int>>edge{{1,3},{3,4},{2,4},{3,2},{2,5},{6,7},{7,8},{8,1},{9,10},{10,1}};
     // vector<pair<int,int>>edge{{6,1},{5,1},{5,2},{6,3},{3,4},{4,2}};
     vector<int>adj[v+1];
    //   vector<vector<int>>matrix(v+1,vector<int>(v+1,0));
  for(auto x:edge)
     {
        int frm=x.first;
        int to=x.second;
        adj[frm].push_back(to);
          adj[to].push_back(frm);
       //   matrix[frm][to]=1;
      //   matrix[to][frm]=1;
      
      }
     bool flag=false;
     for(int i=1;i<=v;i++)
     {
    vector<bool>visited(v+1,false);
    vector<bool>dfsvisited(v+1,false);
    if(!visited[i])
    {
        visited[i]=true;
        if(is_cycle_in_dg(v,adj,i,visited,dfsvisited))
        {
            flag=true;
            break;
        }
    }
}
     flag?cout << "Yes It has a cycle":cout << "No cycle found in the graph";
     cout << endl;
     vector<bool>visited(v+1,false);
     stack<int>s;
     for(int i=1;i<=v;i++)
     {
    if(!visited[i])
    {   visited[i]=true;
        topo_dfs_recursive(v,adj,i,visited,s);
       
    }
}
     while(s.size())
     {
     cout << s.top() << " ";
     s.pop();
     }
     cout << endl;
     queue<int>q;
     vector<int>degree_in=in_degree(v,adj);
     for(auto x:degree_in)
     cout << x << " ";
     cout << endl;
     for(int i=1;i<=v;i++)
     {
    if(degree_in[i]==0)
    {
        q.push(i);
        degree_in[i]=-1;
    }
    }

    while(q.size())
    {
    int top=q.front() ;
    cout <<top << " ";
    q.pop();
    for(auto x:adj[top])
    {
        if(degree_in[x]!=-1)
        {
           
                degree_in[x]--;
                if(degree_in[x]==0){
                 q.push(x);
                degree_in[x]=-1;}
            
            
        }
    }
}
cout << endl;
vector<int>distance=distance_in_udcg(v,adj,1);
for(int i=1;i<=v;i++)
cout << distance[i] << " " ;
cout << endl;
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
