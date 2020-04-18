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
	int n,m,k,moves=0;
	cin>>n>>m>>k;
	set<int> finx[n+1];
	set<int> finy[m+1];
	int sx[k],sy[k],fx[k],fy[k];
	rep(i,0,k-1){
		cin>>sx[i];
		cin>>sy[i];
	}
	minx = m;
	maxx = 0;
	string ans = "";
	rep(i,0,k-1){
		cin>>fx[i];
		minx = min(fx[i] - sx[i],minx);
		maxx = max(fx[i] - sx[i],maxx);
		finx[fx[i]].insert(i);
		cin>>fy[i];
		finy[fy[i]].insert(i);
	}
	for(int i = 0; i > minx; i--){
		ans+="L";
		for(int j = 0;j < m; j++){
			for(auto ind:finx[fx[j]]){
				while(sy[ind]<fy[ind]){
					
				}
			}
		}
	}
	int i = 0;
	int cnt=0;
	string ans = "";
	
	return 0;
}




