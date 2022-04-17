
   
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
bool check(int i,int j,vector<vector<bool>>&visited)
{
    if(i<0 or j<0 or i>=visited.size() or j>=visited[0].size() or visited[i][j]==true)
    return false;
    return true;
}
void solve() {
    int n;
     cin >> n;
     int m;
     cin >> m;
     vector<vector<int>>map(n,vector<int>(m,0));
     vector<vector<bool>>visited(n,vector<bool>(m,false));
     int si;
     int sj;
     int ei;
     int ej;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             char c;
             cin >> c;
             if(c=='A')
             {map[i][j]=2;
                si=i;
                sj=j;
             }
             else if(c=='B')
            { map[i][j]=3;
                ei=i;
                ej=j;
            }
             else if(c=='#')
            { map[i][j]=0;
                visited[i][j]=true;
            }
             else 
             map[i][j]=1;
         }
     }
     vector<vector<pair<int,int>>>path(n,vector<pair<int,int>>(m,{0,0}));
     vector<pair<int,int>>moves{{-1,0},{1,0},{0,-1},{0,1}};
     
     queue<pair<int,int>>q;
     q.push({si,sj});
     visited[si][sj]=true;
     bool flag=false;
     while(q.size())
     {
         pair<int,int>top=q.front();
         q.pop();
         for(auto x:moves)
         {
             int mvx=x.first;
             int mvy=x.second;
             int nextx=top.first+mvx;
             int nexty=top.second+mvy;
             if(check(nextx,nexty,visited))
            {
              visited[nextx][nexty]=true;
               path[nextx][nexty]=make_pair(mvx,mvy);
               if(map[nextx][nexty]==3)
              {flag=true;
              break;}
              q.push({nextx,nexty});
             
            }
         }
         if(flag)
         break;
         
     }
     if(!flag)
     cout << "NO" << endl;
     else
     {
         string ans="";
         int i=ei;
         int j=ej;
        //  cout << i << " " << j << endl;
        //  cout << si << " " << sj << endl;
        //  for(auto x:path)
        //  {
        //      for(auto p:x)
        //      cout << p.first << "," << p.second << "          ";
        //      cout << endl;
        //  }
        while(i!=si or j!=sj)
        {
          if(path[i][j].first==-1)
          ans+="U";
          else if(path[i][j].first==1)
          ans+="D";
          else if(path[i][j].second==-1)
          ans+="L";
          else if(path[i][j].second==1)
          ans+="R";
          int k=path[i][j].first;
          int p=path[i][j].second;
          i=-k+i;
          j=j-p;
          
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i];
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
