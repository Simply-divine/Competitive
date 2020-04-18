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
#define low(a,x) int(lower_bound(a.begin(),a.end(),x) - a.begin())
#define up(a,x) int(upper_bound(a.begin(),a.end(),x) - a.begin())
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MAXN = 100005;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// if a[i] > b[i] cnt1++ 
	// lets say diff = a[i] - b[i]..
	//if there exists an a[j] < b[j] such that diff between b[j] and a[j] is less than diff
	// b[j] - a[j] < diff cnt++.. 
	//in other words we have to find the pos of b[j] - a[j] in diff array and that many number
	//will be cnt++
	// so we will store the difference between a[i] and b[i] in one array 
	// and then find pos of b[j] and a[j];
	int n;
	cin>>n;
	ll  a[n],b[n];
	rep(i,0,n-1)cin>>a[i];
	rep(i,0,n-1)cin>>b[i];
	ll diff[n];
	for(int i= 0; i  < n; i++){
		diff[i] = ( b[i] - a[i] );
	}
	sort(diff,diff+n);
	ll cnt=0;
	for(int i = 0;i < n; i++){
			ll temp= ll(lower_bound(diff,diff+n,(a[i] - b[i])) - diff);
			cnt+=temp;
			if ( a[i] > b[i] ) cnt--;
	}
	cout<<cnt/2<<nl;
	return 0;
}




