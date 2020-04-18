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
int t[4*MAXN],n;
void build(int a[],int v,int tl,int tr){
	if( tl == tr) t[v] = a[tl];
	else{
		int tm = (tl + tr)/2;
		build(a,2*v,tl,tm);
		build(a,2*v+1,tm+1,tr);
		t[v] = min(t[2*v],t[2*v+1]);
	}
}

int min(int v,int tl,int tr,int l,int r){
	if(l > r){
		return INF - 1;
	}	
	if(l == tl && r == tr)
		return t[v];
	else{
		int tm = (tl + tr)/2;
		return min(min(2*v,tl,tm,l,min(tm,r)),min(2*v+1,tm+1,tr,max(tm+1,l),r));
	}
}

void update(int v,int tl,int tr,int pos,int new_val){
	if(tl == tr){
		t[v] = new_val;
	}
	else{
		int tm = (tl + tr)/2;
		if(pos<=tm)
			update(2*v,tl,tm,pos,new_val);
		else update(2*v+1,tl,tm,pos,new_val);
		t[v] = min(t[2*v],t[2*v+1]);
	}
}
ll dow(ll y, ll m, ll d)
{
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
ll d[401];
ll go(ll y1,ll y2){
	ll cnt=0;
	for(ll i=y1; i <= y2; i++){
		if(d[i]==6){
			cnt++;
		}
		if(d[i] == 0){	
			if((i)%400==0||((i)%4==0&&(i)%100!=0)){
			}
			else{
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	d[0] = 2;
	rep(i,1,400){
		d[i] = dow(i,2,1);
	}
	while(t-->0){
		ll y1,y2,m1,m2;
		cin>>m1>>y1;
		cin>>m2>>y2;
		if(m1>2)y1++;
	        if(m2<2)y2--;	
		ll ans;
		if ( y1/400 == y2/400){
			ans = go(y1%400,y2%400);
			cout<<ans<<nl;
		}
		else{
			ll times = y2/400  - y1/400 -1 ;
			ans = go(y1%400,400) + times*go(1,400) + go(1,y2%400);
			cout<<ans<<nl;
		}
	}
	return 0;
}


