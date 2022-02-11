#include<bits/stdc++.h>
using namespace std;
main()
{
// 	int n;
// 	cin >> n;
	string tf,op;
	cin >> tf >> op;
	int n=tf.length();
	cout << n << endl;
	vector<long long int>temp(n,0);
	vector<vector<long long int>>dpt(n,temp),dpf(n,temp);
	for(int gap=0;gap<n;gap++)
	{
		for(int i=0,j=gap;j<n;i++,j++)
		{
		    if(gap==0)
		    {
		        dpt[i][j]=tf[j]=='T'?1:0;
		        dpf[i][j]=tf[j]=='F'?1:0;
				
		    }
		   else if(gap==1)
			{
				
				if(op[i]=='&')
				{
				dpt[i][j]=  (tf[j-1]=='T'?true:false)& (tf[j]=='T'?true:false)?1:0;
				dpf[i][j]=  (tf[j-1]=='T'?true:false)& (tf[j]=='T'?true:false)?0:1;
				}
				else if(op[i]=='|')
				{
					dpt[i][j]= (tf[j-1]=='T'?true:false)| (tf[j]=='T'?true:false)?1:0;
					dpf[i][j]= (tf[j-1]=='T'?true:false)| (tf[j]=='T'?true:false)?0:1;
				}
				else 
		     	{
					dpt[i][j]= (tf[j-1]=='T'?true:false)^ (tf[j]=='T'?true:false)?1:0;
					dpf[i][j]= (tf[j-1]=='T'?true:false)^ (tf[j]=='T'?true:false)?0:1;
			    }
				
			}
			else
			{
			for(int k=i;k<j;k++)
			{
				cout << k << " " << i <<" " << j << endl;
				cout << dpt[i][j] << endl;
				int lpt=dpt[i][k];
				int rpt=dpt[k+1][j];
				int lpf=dpf[i][k];
				int rpf=dpf[k+1][j];
					if(op[k]=='&')
				{
			       dpt[i][j]= dpt[i][j]+(lpt*rpt);
			       dpf[i][j]= dpf[i][j]+(lpt*rpf)+(lpf*rpf)+(lpf*rpt);
				}
				else if(op[k]=='|')
				{
				   dpf[i][j]=dpf[i][j]+(lpf*rpf);
			       dpt[i][j]=dpt[i][j]+(lpf*rpt)+(lpt*rpf)+(lpt*rpt); 
				}
				else 
		     	{
				   dpf[i][j]=dpf[i][j]+(lpf*rpf)+(lpt*rpt);
			       dpt[i][j]=dpt[i][j]+(lpt*rpf)+(lpf*rpt); 
			    }
				
			}
				
			}
		}
	}
    // for(auto x:dpt)
    // {
    //     for(auto p:x)
    //     cout << p << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for(auto x:dpf)
    // {
    //     for(auto p:x)
    //     cout << p << " ";
    //     cout << endl;
    // }
    // cout << dpt[0][n-1] << endl;
}
