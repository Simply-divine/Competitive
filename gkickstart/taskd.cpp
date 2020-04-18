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
	for(int q = 0; q < t; q++){
		int n,k;
		cin>>n>>k;
		string s[n];
		for(int i = 0; i < n; i++){
			cin>>s[i];
		}
		sort(s,s+n);
		int sum=0;
		for(int i = 0;i<n;i+=k){
			int cnt=0;
			int sz =  min(s[i].length(),s[i+k-1].length());
			int j=0;
			while(j<sz&&s[i][j] == s[i+k-1][j]) j++;
			sum+=j;
		}
		cout<<"Case #"<<(q+1)<<": "<<sum<<nl;
	}
	return 0;
}




