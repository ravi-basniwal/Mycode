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
class paiir
{
     public : 
     int i;
     string asf;
     paiir(int i=0,string asf="")
     {
          this->i=i;
          this->asf=asf;
     }
     
};
void solve() {
     int n;
     cin >> n;
     vector<int>v;
     for(int  i=0;i<n;i++)
     {
          int a;
          cin >> a;
          v.push_back(a);
     }
     vector<int>dp(n,0);
     dp[0]=v[0];
     for(int i=1;i<n;i++)
     {
          int sum=0;
          int j=i;
          while(j)
          {
             if(v[j-1]<=v[i])
             {
                  if(sum<=dp[j-1]+v[i])
                  {
                       sum=dp[j-1]+v[i];
                  }
             }
             j--;
          }
          if(sum==0)
          dp[i]=sum+v[i];
          else
          dp[i]=sum;
          
     }
     int r=INT_MIN;
     for(auto x:dp)
     r=max(r,x);
     queue<paiir>q;
     for(int i=0;i<n;i++)
     {
          if(dp[i]==r)
          {paiir p(i,""+to_string(v[i]));
          q.push(p);}
     }
     while(q.size())
     {
          paiir p=q.front();
          q.pop();
          int j=p.i;
          int k=dp[j]-v[j];
          if(p.i<=0)
          cout << p.asf << endl;
         
          while(j>=0)
          {
             if(dp[j]==k)
             {
               paiir g(j,""+to_string(v[j])+" "+p.asf);
               q.push(g); 
             }
             j--;
             
          }
     }
     // for(auto x:dp)
     // cout << x << " ";
     // for printing 
     
    

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