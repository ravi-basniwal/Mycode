
   
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

void solve() {
     int n;
     cin >> n;
     int m;
     cin >> m;
     vector<string>s;
     for(int i=0;i<n;i++)
     {
         string row;
         cin >> row;
         s.push_back(row);
     }
     int ans=0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(s[i][j]=='#')
             continue;
             else if(s[i][j]=='.')
             {
                 s[i][j]='#';
                
                 ans++;
                 queue<pair<int,int>>q;
                 q.push({i,j});
                 while(q.size())
                 {
                     pair<int,int>temp=q.front();
                     q.pop();
                      int ii=temp.first;
                      int jj=temp.second;
                    //   cout << ii << "{" << ans << "} " << jj << endl ;
                      if(ii+1<n and s[ii+1][jj]=='.')
                     {
                         s[ii+1][jj]='#';
                         q.push({ii+1,jj});
                     }
                     if(jj+1<s[ii].size() and s[ii][jj+1]=='.')
                     {
                        //  cout << ii << " " << jj << endl;
                         s[ii][jj+1]='#';
                          q.push({ii,jj+1});
                     }
                     if(ii-1>=0 and s[ii-1][jj]=='.')
                     {
                         s[ii-1][jj]='#';
                         q.push({ii-1,jj});
                     }
                     if(jj-1>=0 and s[ii][jj-1]=='.')
                     {
                         s[ii][jj-1]='#';
                         q.push({ii,jj-1});
                     }
                     
                 }
                    
                 }
             }
         }
     
    //  for(auto x:s)
    //  cout << x << endl;
     cout << ans << endl;
  
    

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
