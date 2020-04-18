#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define DEBUG printf("hello\n")
#define nl "\n"
#define INF std::numeric_limits<int>::max()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
ll mod=1000000009;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		int n;
		map<pair<int,int>,int> vis;
		cin>>n;
		string s;
		cin>>s;
		int x=0,y=0;
		int f=0;
		vis[MP(0,0)] = -1;
		int min = 200005;
		int minl = - 1, minr = -1;
		for(int i = 0; i < n ;i++){
			if(s[i]=='L'){ x--;}
			else if(s[i]=='R')x++;
			else if(s[i] == 'D')y++;
			else y--;
			//cout << x<<" "<<y<<nl;
			if(vis.count(MP(x,y))==0){
			//	cout<<"sd"<<nl;
			}
			else {
				if( (i+1) - vis[MP(x,y)] - 2 <min){
					min = (i+1) - vis[MP(x,y)] - 2;
					//cout<<min<<" s"<<nl;
					minl = vis[MP(x,y)]+2;
					minr = i+1;		
				}
				f = 1;
			}
				vis[MP(x,y)] = i;
		}
		if(f==0){
			cout<<"-1"<<nl;
		}
		else{
			cout<<minl<<" "<<minr<<nl;
		}
	}
	return 0;
}




