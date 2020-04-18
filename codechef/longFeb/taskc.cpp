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
ll tot[(1<<4)][4];
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
ll sum;
void solve(){
	ll n;
	cin>>n;
	ll movie[4][4];
	rep(i,0,3)rep(j,0,3)movie[i][j] = 0;
	rep(i,0,n-1){
		char mvi;
		int time;
		cin>>mvi>>time;
		if(time == 12)
		movie[mvi-'A'][0]++;
		else movie[mvi - 'A'][time/3]++;
	}
	vi per;
	rep(i,0,4-1)per.PB(i);
	ll mx = -100000001;
	do{
		vi temp;
		temp.PB(movie[0][per[0]]);
		temp.PB(movie[1][per[1]]);
		temp.PB(movie[2][per[2]]);
		temp.PB(movie[3][per[3]]);
		sort(temp.begin(),temp.end());
		ll ans = temp[0]*25+temp[1]*50+temp[2]*75+temp[3]*100;
		if(temp[0]==0){
			ans-=100;
		}

		if(temp[1]==0){
			ans-=100;
		}
		if(temp[2]==0){
			ans-=100;
		}
		if(temp[3]==0){
			ans-=100;
		}
		mx = max(mx,ans); 
	}
	while(next_permutation(per.begin(),per.end()));
			cout<<mx<<nl;
	sum+=mx;
}

int main()
{
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	
	cin.tie(0);
	int t;
	cin>>t;
	sum=0;
	while(t-->0)
		solve();
	cout<<sum<<nl;
	return 0;
}





