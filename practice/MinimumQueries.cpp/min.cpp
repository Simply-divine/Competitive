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
	pi p;
	map<pi,bool> mp;
	while(t-->0){
		int n;
		string s;
		cin>>s;
		int x = 0,y=0;
		p = MP(0,0);
		mp[p] = true;
		int cnt = 0;
		int ans = 1000001;
		int l = -1,r = -1;
		//cout<<mp[p]<<nl;
		REP(i,0,n-1){
			if(s[i]=='L')x--;
			else if(s[i]=='R')x++;
			else if(s[i]=='U')y++;
			else y--;
			cout<<x<<y;
			p = MP(x,y);
			if(mp[p]){
				if(cnt< ans){
					ans = cnt;
					r = i;
					l = r - cnt + 1;
					cnt = 0;
				}	
			}
			mp[p] = true;
			cnt++;
		}
		cout<<(l+1)<<" "<<(r+1)<<nl;
	}
	return 0;

}



