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
ll mod=1e9+7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	ll a[n] = {0};
	ll cmn_cnt[63] = {0};
	for(ll i = 0 ; i < n ; i++) {
		cin>>a[i];
	}
	ll ans = 0;
	for(ll i = 0; i <= 60;i++){
		ll cnt=0;
		for(int j = 0; j < n; j++){
				cnt+=(a[j]>>i)&1;
		}
		ans=(ans+(((((1LL<<i)%mod)*cnt)%mod)*(n-cnt))%mod)%mod;
	}
	cout<<ans%mod<<nl;
	return 0;
}




