#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
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
const int MAXN = 100005;
ll mod=1000000007;
int count_with_k_ones(int a[],int n,int k){
	int cnt=0;
	int res = 0;
	for(int i = 0; i < n;i++){
		if ( a[i] == 0) cnt  = 0;
		else cnt++;
		if ( cnt>=k) {
			res++;
		}
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int a[n],b[m],prea[n] = {0},preb[m] = {0};
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i =0; i < m;i++){
		cin>>b[i];
	}
	ll ans=0;
	for(int i = 1; i*i <= k; i++){
		ll cnt1=0,cnt2=0,cnt3=0,cnt4=0;
		if ( k % i == 0){
				cnt1=count_with_k_ones(a,n,i);	
				cnt2=count_with_k_ones(b,m,k/i);
			if (i*i!=k){
				cnt3=count_with_k_ones(a,n,k/i);
				cnt4=count_with_k_ones(b,m,i);
			}
		}
		ans+=cnt1*cnt2+cnt3*cnt4;
	}
	cout<<ans<<nl;
	return 0;
}




