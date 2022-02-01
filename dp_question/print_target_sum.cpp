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
class pairr
{
     public :
     int i;
     int j;
     string asf;
     pairr(int i=0,int j=0,string asf="")
     {
          this->i=i;
          this->j=j;
          this->asf=asf;
     }
};
void solve() {
     int n;
     cin >> n;
     vector<int>v;
     for(int i=0;i<n;i++)
     {
          int a;
          cin >> a;
          v.push_back(a);
     }
     int k;
     cin >> k;
     vector<bool>temp(k+1,false);
     vector<vector<bool>>dp(n+1,temp);
     for(int i=0;i<=n;i++)
     {
          for(int j=0;j<=k;j++)
          {
               // cout << i << " " << j << endl;
               if(j==0)
               dp[i][j]=true;
               else if(i==0)
               dp[i][j]=false;
               else if(dp[i-1][j]==true)
               dp[i][j]=true;
               else if(j-v[i-1]>=0 and dp[i-1][j-v[i-1]])
               dp[i][j]=true;
                    
               
          }
     }
     // for(auto x:dp)
     // {
     //      for(auto p:x)
     //      cout << p << " ";
     //      cout << endl;
     // }
     if(dp[n][k])
     {
       queue<pairr>q;
       pairr p(n,k,"");
       q.push(p);
       while(q.size())
       {
            
            pairr t=q.front();
          //   cout <<t.asf << endl;
            q.pop();
            if(t.j==0)
            cout << t.asf << endl;
            else{
            
           
            if(t.j-v[t.i-1]>=0 and dp[t.i-1][t.j-v[t.i-1]])
            {
                 pairr h;
                 h.i=t.i-1;
                 h.j=t.j-v[t.i-1];
                 h.asf=to_string(t.i-1)+" " +t.asf;
                 q.push(h);  
            }
             if(t.i>1 and dp[t.i-1][t.j])
            {
                 pairr h;
                 h.i=t.i-1;
                 h.j=t.j;
                 h.asf=t.asf;
                 q.push(h);
            }
            }
       }
     }
     else 
     cout << "false" << endl;
    

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