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
vector<int>prim_algo(int v,vector<pair<int,int>>*adj)
{
    vector<int>key(v+1,INT_MAX),parents(v+1,-1);
    vector<bool>mst(v+1,false);
    key[1]=0;
    for(int cnt=0;cnt<v-1;cnt++)
    {
        int minu=INT_MAX;
        int u;
        for(int i=0;i<=v;i++)
        {
            if(mst[i]==false and minu>key[i])
            minu=key[i],u=i;
        }
        mst[u]=true;
    
    for(auto x:adj[u])
    {
        if(mst[x.first]==false and key[x.first]>x.second)
        parents[x.first]=u,key[x.first]=x.second;
    }}
    return parents;
}
class prims_pair
{
    public :
    int v;
    int u;
    int wgt;
    prims_pair(int v,int u,int wgt)
    {
        this->v=v;
        this->u=u;
        this->wgt=wgt;
    }
};
struct mycom {
    constexpr bool operator()(prims_pair* a,prims_pair*  b)
        const noexcept
    {
        return a->wgt > b->wgt;
    }};
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
          adj[to].push_back({frm,wgt});
       
     }
     vector<int>mst=prim_algo(v,adj);
     for(auto x:mst)
     cout << x << " ";
     cout << endl;
     vector<int>parentss(v+1,-1),key(v+1,-1);
     vector<bool>visited(v+1,false);
    priority_queue<prims_pair*,vector<prims_pair*>,mycom>pq;
    prims_pair *p=new prims_pair(1,-1,0);
    pq.push(p);
    while(pq.size())
    {
        prims_pair *k=pq.top();
        pq.pop();
        if(!visited[k->v])
        {
            visited[k->v]=true;
            // cout << k->v << " " << k->u << " " << k->wgt << endl;
            parentss[k->v]=k->u;
            key[k->v]=k->wgt;
        }
        for(auto x:adj[k->v])
        {
            if(!visited[x.first])
            {
                prims_pair *temp=new prims_pair(x.first,k->v,x.second);
                pq.push(temp);
            }
        }
        
    }
    for(auto x:parentss)
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