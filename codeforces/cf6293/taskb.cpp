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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		ll n,k;
		cin>>n>>k;
		ll a[n];
		ll p1 = n-2,p2;
		k--;
		for(ll i = 0; i< n; i++){
			if(i*(i+1)/2<=k){
				p1 = n-i-2;
				p2 = n - 1 - (k - i*(i+1)/2  );
			}
		}
		char ans[n];
		for(ll i = 0; i < n; i++){
			if(i==p1||i==p2)ans[i] = 'b';
			else ans[i] = 'a';	
		}
		for(ll i = 0; i < n; i++){
			cout<<ans[i];
		}
		cout<<nl;
	}
	return 0;
}




