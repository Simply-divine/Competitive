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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	for(int i =31;i>=0;i--){
			if(n&(1<<i))cout<<"1";
			else cout<<"0";
	}
	cout<<nl;
	cout<<__builtin_clzll(n)<<nl;
	
	cout<<__builtin_ctzll(n)<<nl;
	
	cout<<__builtin_popcountll(n)<<nl;
	
	cout<<__builtin_parityll(n)<<nl;
	
	//cool thing is to represent set using bits

	ll x = 0;
	x|=(1<<1);
	x|=(1<<3);
	x|=(1<<4);
	cout<<__builtin_popcountll(x);
	int b = 0;cout<<" the elements of set x are"<<nl;
	do{
		for(int i = 0; i <= 32; i++)
			if(b&(1<<i)) cout<< i <<" ";
		cout<<nl;
	}while(b = (b - x)&x);
	return 0;
}




