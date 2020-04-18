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

vi prefix_function(string s){
	int n = s.length();
	vector<int> p(n);
	p[0] = 0;
	for(int i = 1; i < n; i++){
		int j = p[i - 1];
		while ( j > 0  && s[i]!=s[j]){
			j = p[j - 1];            // if current j is not the solution 	
		}
		if ( s[i] == s[j] ){
			j++;
		}
		p[i] = j;
	}
	return p; 
}

void reverse(string& s){
	reverse(s.begin(),s.end());
}
int power(int a,int b,int mod){
	if( b == 0){
		return 1;
	}
	if( b%2 == 0){
		return (power(a,b/2,mod)%mod*power(a,b/2,mod)%mod)%mod;
	}
	else{
		return ((a%mod*power(a,b/2,mod)%mod)%mod*power(a,b/2,mod)%mod)%mod;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		int a[n];
		int pre[n];
		rep(i,0,n-1)cin>>pre[i];
		int ans = 1;
		int check = true;
		rep(i,1,n-1){
			for(int i = 0; i <= 30; i++){
				if((pre[i]&(1<<i)==0)&&(pre[i-1]&(1<<i)!=0)){
					check = false;
					break;
				}
			}
			if(!check)break;
			int or1 = pre[i]&pre[i-1];
		 	int cnt = __builtin_popcount(or1);
			ans = (ans%mod*power(2,cnt,mod)%mod)%mod;
		}
		if(!check)ans = 0;
		else
		cout<<ans<<nl;
	}
	return 0;
}




