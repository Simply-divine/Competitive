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
	ll n;
	cin>>n;
	ll x,y;
	cin>>x>>y;
	ll a[n];
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<n;i++){
		bool flag = true;
		for(ll j = max(i-x,0LL);j<=min(i+y,n-1);j++){
			if(i^j)
			if(a[j]<=a[i]){
				flag = false;
				break;
			}
		}
		if(flag){
			cout<<(i+1)<<nl;
			break;
		}
	}
	return 0;
}




