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
ll mod=998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	int mark[200001] = {0};
	int a[n],b[n];
	for(int i = 0 ; i < n; i++){
		cin>>a[i];
		b[i] = a[i];	
	}
	sort(a,a+n);
	ll sum=0;
	for(int i = 0; i < k; i++){
		sum+=a[n-1-i];
		mark[a[n-1-i]] = 1;
	}
	int last_mark = -1;
	ll cnt=1;
	for(int i = 0; i < n; i++){
		if(mark[b[i]] == 1){
			if ( i - last_mark > 1){
				if(last_mark!=-1)
				cnt = ((cnt%mod)*(i - last_mark)%mod)%mod;
			}
			last_mark = i;
		}
	}
		cout<<sum<<" "<<cnt%mod<<nl;
	return 0;
}




