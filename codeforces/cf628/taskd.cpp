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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a,b;	
	cin>>a>>b;
	int cnt[61] = {0};
	int f =1;
	if(( a > b) || (abs(a-b))%2!=0){
		f = 0;
	}
	int carry =0;
	ll a0=0,a1=0,a2=0;
	if(f){
		for(int i = 0; i <=60;i++){
			if( (a & (1LL<<i)) == 0){
				if((( b & (1LL <<i)) ==0 && carry == 0 )||(((1LL<<i)&b)!=0 && carry !=0)){

					cnt[i] = 0;
					carry  = 1;
				}
				else{
					cnt[i] = 0;
					cnt[i-1]+=2;
					carry = 0;
				}
			}
			else{
				if((( b & (1LL <<i)) ==0 && carry == 0 )||((1LL<<i)&b!=0 && carry !=0)){
					cnt[i] = 1;
					carry = 1;
					cnt[i-1]+=2;
				}
				else{
					cnt[i] = 1;
					carry = 0;
				}
			}
		}
		for(int i = 0; i <= 60; i++){
			if(cnt[i] == 1){
				a0 = a0|(1LL<<i);
			}
			else if(cnt[i]==2){
				a0 = a0|(1LL<<i);
				a1 = a1|(1LL<<i);
			}
			else if(cnt[i]==3){
				a0 = a0|(1LL<<i);
				a1 = a1|(1LL<<i);
				a2 = a1|(1LL<<i);
			}
		}
		int cnt = 0;
		if (a0 != 0 ){
			cnt++;		
		}
		if(a1!=0){
			cnt++;
		}
		if(a2!=0){
			cnt++;
		}
		cout<<cnt<<nl;
		if(a0)cout<<a0<<" ";
		if(a1)cout<<a1<<" ";
		if(a2)cout<<a2<<nl;
	}
	else cout<<"-1"<<nl;
	return 0;
}




