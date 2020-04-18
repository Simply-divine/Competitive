#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define DEBUG printf("hello\n")
#define nl "\n"
#define INF std::numeric_limits<int>::max()
#define MAXN 100001
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
ll mod=1000000009;
int t[2*MAXN],n;
void build(int a[],int v,int tl,int tr){
	if(tl == tr){
		t[v] = a[tl];
	}
	else {
		int tm = (tl + tr)/2;
		build(a,2*v,tl,tm);
		build(a,2*v+1,tm+1,tr);
		t[v] = t[2*v] + t[2*v+1]; 
	}	
}
int sum(int a,int b){
	a+=n,b+=n;
	int s = 0;
	while(a<=b){
		if(a%2==1)s+=t[a++];
		if(b%2==0)s+=t[b--];
		a/=2;
		b/=2;
	}
	return s;
}
void add(int k,int x){
	k+=n;
	t[k]+=x;
	for(k/=2;k>=1;k/=2){
		t[k] = t[2*k]+t[2*k+1];
	}

}
int sum(int v,int tl,int tr,int l,int r){
	if(l > r)return 0;
	if(l == tl && r == tr) return t[v];
	int tm = (tl + tr)/2;
	return sum(2*v,tl,tm,l,min(r,tm))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int a[n];
	build(a,0,0,n-1);
		
	return 0;
}




