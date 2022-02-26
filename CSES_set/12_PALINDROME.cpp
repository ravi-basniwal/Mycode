
   
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
    string s;
    cin >> s;
    unordered_map<char,int>m;
    for(auto x:s)
    m[x]++;
    string ans="";
    int check=0;
    char extra;
    int exs=0;
    for(auto x:m)
    {
        if(x.second%2!=0)
        {
            if(check==0)
            {
                extra=x.first;
                exs=x.second;
                check=1;
            }
            else
            {
                cout << "NO SOLUTION" << endl;
                check=2;
                break;
            }
        }
        else
        {
            int p=x.second;
            p=p/2;
            while(p--)
            ans+=x.first;
        }
    }
    if(check<2)
    {
        string temp=ans;
        reverse(ans.begin(),ans.end());
        if(check==1)
        {
            while(exs--)
            temp+=extra;
        }
        cout << temp+ans << endl;
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
