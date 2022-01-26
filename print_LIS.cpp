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
     public:
     int i;
     int val;
     string asf;
     paiir(int i=0,int val=0,string asf="")
     {
          this->i=i;
          this->val=val;
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
     vector<int>dp(n,0);
     dp[0]=1;
     int ans=0;
     int valu=0;
     for(int i=1;i<n;i++)
     {
          int p=0;
          int j=i-1;
          while(j>=0)
          {
              if(v[j]<=v[i]){
              if(p<dp[j])
                p=dp[j];
              }
              dp[i]=p+1;
              j--;
              if(ans<dp[i])
              {ans=dp[i];
              valu=i;}
          }
     }
     ans>dp[0]?ans=ans:ans=dp[0];
     cout << ans << endl;
     queue<paiir>q;
     for(int i=0;i<n;i++)
     {
     if(dp[i]==ans){
     paiir k(i,ans,""+to_string(v[i]));
     q.push(k);}}
     while(q.size())
     {
           paiir t=q.front();
          // cout << t.i << " " << t.val << " " << t.asf << endl;
         
          q.pop();
          if(t.val==1)
          cout << t.asf << endl;
          else{
          int j=t.i-1;
          while(j>=0)
          {
               // cout << t.val-1 << " check " << v[j] << endl;
               if(dp[j]==t.val-1 and v[j]<=v[t.i])
               {
                    paiir h;
                    h.i=j;
                    h.val=t.val-1;
                    h.asf=to_string(v[j])+" -> " + t.asf;
                    q.push(h);
               }
               j--;
          }}
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