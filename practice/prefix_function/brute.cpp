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
void reverse(string& s){
	reverse(s.begin(),s.end());
}
string prefix_function(string s){
	string a = s;
	reverse(a);
	s = s + "#" + a;
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
	return s.substr(0,p[n-1]);
}
void solve(){
	string s;
	cin>>s;
	int n = s.length();
	int mid = n/2;
	int l = 0;
	for(int i = 0; i < mid; i++){
		if(s[i]!=s[n-1-i]){
			break;
		}
		l++;
	}
	string temp = "";
	if(l > 0){
	temp = s.substr(0,l);
	}
	string a = s.substr(l,n - 2*l);
	string ans1 = prefix_function(a);
	reverse(a);
	string ans2 = prefix_function(a);
	if ( ans2.size() > ans1.size()) swap(ans1,ans2);
	cout << temp <<ans1 ;
	reverse(temp);	
	cout<<temp<<nl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		solve();
	}
	return 0;
}




