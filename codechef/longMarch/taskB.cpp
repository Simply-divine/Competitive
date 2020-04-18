#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MAXN 100005
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define SQ(a) (a)*(a)
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
		ll n,q;
		cin>>n>>q;
		ll a[n];
		ll cnt[32];
		ll ones = 0;
		ll e = 0,o=0;
		rep(i,0,n-1){
			cin>>a[i];
			rep(i,0,31){
				if(a[i]&(1<<i)){
					cnt[i]++;
				}
			}
			int ones =  __builtin_popcount(a[i]);
			if(ones%2==0)e++;
			else o++;	
		}
		while(q-->0){
			ll p;
			cin>>p;
			int cnt = 0;
			rep(i,0,31){
				if(p&(1<<i)){
					cnt++;			
				}
			}
			if(cnt%2==0){
				cout<<e<<" "<<o<<nl;
			}
			else cout<<o<<" "<<e<<nl;
		}	
	}
	return 0;
}




