
   
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
class bfshelp
{
    public :
    int node;
    int cmptr;
    string ans;
    bfshelp(int node,int cmptr,string ans)
    {
        this->node=node;
        this->cmptr=cmptr;
        this->ans=ans;
    }
};
void solve() {
     int n;
     cin >> n;
     int m;
     cin >> m;
     vector<int>adj[n+1];
     for(int i=0;i<m;i++)
     {
         int frm;
         int to;
         cin >> frm >> to;
         adj[frm].push_back(to);
         adj[to].push_back(frm);
     }
    //  for(auto x:adj)
    //  {
    //      for(auto p:x)
    //      cout << p << " ";
    //      cout <<endl;
    //  }
     queue<bfshelp>q;
     bfshelp start(1,1,"1");
     q.push(start);
     vector<bool>visited(n+1,false);
     visited[1]=true;
     bool flag=false;
     while(q.size())
     {
        bfshelp top=q.front();
        q.pop();
        // cout << top.node << " " << top.cmptr << " " << top.ans << endl;
        if(top.node==n)
        {
            flag=true;
            cout << top.cmptr << endl;
            cout << top.ans<< endl;
            break;
        }
        for(auto x:adj[top.node])
        {
            // cout << x << " ";
            if(!visited[x])
            {
                visited[x]=true;
                bfshelp tempnode(x,top.cmptr+1,top.ans+" "+to_string(x));
                q.push(tempnode);
            }
        }
        // cout << endl;
        // for(auto x:adj[top.node])
        // cout << x << " ";
     }
     if(!flag)
     cout << "IMPOSSIBLE" << endl;
     
     
    

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
