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
bool check_pal(string s){
	int n = s.size();
	for(int i = 0; i <n; i++){
			if(s[i]!=s[n-1-i]) return false;
	}
	return true;
}
string palindrome_finder(string s){
	int k = 0;
	int n = s.size();
	debug(n);
	for(int i = 0 ; i < n; i++){
		debug(s[i]);
		debug(s[n-1-i]);
		if(s[i] == s[n-1-i]){
			k++;
		}
		else break;
	}
	string start = s.substr(0,k);
	for(int i = ; i < ; i++){
		
	} 
	string ans = "";
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		string s;
		cin>>s;
		string ans = palindrome_finder(s);
		cout<<ans<<nl;
	}
	return 0;
}




