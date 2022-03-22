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
void topo_sort(int v,vector<pair<int,int>>*adj,int i,stack<int>&s,vector<bool>&visited)
{
    for(auto x:adj[i])
    {
        if(!visited[x.first])
        {
            visited[x.first]=true;
            topo_sort(v,adj,x.first,s,visited);
        }
    }
    s.push(i);
}
const int N = 200005;
void solve() {
     int v=10;
     //  cin >> v;
     int e=10;
     //  cin >> e;
     vector<pair<int,pair<int,int>>>edge{{5,{1,3}},{2,{3,4}},{2,{2,4}},{1,{3,2}},{2,{2,5}},{4,{9,3}},{1,{6,7}},{8,{7,8}},{6,{8,1}},{1,{9,10}},{2,{10,1}}};
     // vector<pair<int,int>>edge{{6,1},{5,1},{5,2},{6,3},{3,4},{4,2}};
     vector<pair<int,int>>adj[v+1];
  for(auto x:edge)
     {
         int wgt=x.first;
        int frm=x.second.first;
        int to=x.second.second;
          adj[frm].push_back({to,wgt});
       
     }
     for(auto x:adj)
     {
         for(auto p:x)
         cout <<"{"<< p.first << " " << p.second << "}, ";
         cout << endl;
     }
     stack<int>s;
     vector<bool>visited(v+1,false);
     for(int i=1;i<=v;i++)
     {
         if(!visited[i])
         {
             visited[i]=true;
            
             topo_sort(v,adj,i,s,visited);
         }
     }
    //  while(s.size())
    //  {
    //      cout << s.top() << " ";
    //      s.pop();
    //  }
    //  cout << endl;
    for(int i=1;i<=v;i++)
    {
        stack<int>temp=s;
        vector<int>distance(v+1,INT_MAX);
        distance[i]=0;
        while(temp.size())
        {
            int topp=temp.top();
            temp.pop();
            for(auto x:adj[topp])
            {
                if(distance[topp]!=INT_MAX)
                {
                    if(distance[x.first]>=distance[topp]+x.second)
                    distance[x.first]=distance[topp]+x.second;
                }
            }
        }
        cout << i << "-> ";
        for(auto p:distance)
        {
            if(p==INT_MAX)
            cout << "inf" << " ";
            else
            cout << p  << " ";
        }
        cout << endl;
    }
 
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
