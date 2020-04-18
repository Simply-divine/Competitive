// Author : Hardik Upadhyay
// college: SVNIT 
// slogan : Ab to phod dunga
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i = a ; i >= b; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define sq(a) (a)*(a)
#define nl "\n"
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int MAXN = 100005;
ll mod=998244353;

ll mul(ll a, ll b){
	return ((a%mod)*(b%mod))%mod;
}
ll power(ll a, ll b){
	if( b == 0) return 1;
	ll ans = power(a,b/2);
	if(b%2 == 0) return mul(ans,ans);
	else return mul(a,mul(ans,ans));
}
vector<int> solve(vector<int> tp,vector<int> tpnext, char op){
	vector<int> ans(4,0);
	if(op == '&'){
		for(auto x: tpnext){
			ans[0]+=mul(tp[0],x);	
			ans[0]%=mod;
		}
		ans[0]+=mul(tp[1],tpnext[0]); 
		ans[0]%=mod;
		ans[0]+=mul(tp[2],tpnext[3]);
		ans[0]%=mod;
		ans[0]+=mul(tp[2],tpnext[0]);
		ans[0]%=mod;
		ans[0]+=mul(tp[3],tpnext[2]);
		ans[0]%=mod;
		ans[0]+=mul(tp[3],tpnext[0]);
		ans[0]%=mod;

		ans[1]+=mul(tp[1],tpnext[1]);
		ans[1]%=mod;

		ans[2]+=mul(tp[1],tpnext[2]);
		ans[2]%=mod;
		ans[2]+=mul(tp[2],tpnext[1]);
		ans[2]%=mod;
		ans[2]+=mul(tp[2],tpnext[2]);
		ans[2]%=mod;

		ans[3]+=mul(tp[1],tpnext[3]);
		ans[3]%=mod;
		ans[3]+=mul(tp[3],tpnext[1]);
		ans[3]%=mod;
		ans[3]+=mul(tp[3],tpnext[3]);
		ans[3]%=mod;
		
	}	
	else if(op == '|'){
		debug("here");	
		ans[0]+=mul(tp[0],tpnext[0]);
		ans[0]%=mod;

		for(int i = 0; i < 4; i++){
					ans[1]+=mul(tp[1],tpnext[i]);
					ans[1]%=mod;
					if(i!=1)
					ans[1]+=mul(tp[i],tpnext[1]);
					ans[1]%=mod;
		}
		ans[1]+=mul(tp[2],tpnext[3]);
		ans[1]+=mul(tp[3],tpnext[2]);
		ans[2]+=mul(tp[0],tpnext[2]);
		ans[2]%=mod;
		ans[2]+=mul(tp[2],tpnext[2]);
		ans[2]%=mod;
		ans[2]+=mul(tp[2],tpnext[0]);
		ans[2]%=mod;
		ans[3]+=mul(tp[0],tpnext[3]);
		ans[3]%=mod;
		ans[3]+=mul(tp[3],tpnext[3]);
		ans[3]%=mod;
		ans[3]+=mul(tp[3],tpnext[0]);
		ans[3]%=mod;
	}
	else{
		rep(i,0,3){
			ans[0] +=mul( tp[i],tpnext[i]);
			ans[0]%=mod;
		}

		ans[1]+=mul( tp[1],tpnext[0]);
		ans[1]%=mod;
		ans[1]+=mul( tp[0],tpnext[1]);
		ans[1]%=mod;
		ans[1]+=mul( tp[2],tpnext[3]);
		ans[1]%=mod;
		ans[1]+=mul( tp[3],tpnext[2]);
		ans[1]%=mod;

		ans[2]+=mul(tp[1],tpnext[3]);
		ans[2]%=mod;
		ans[2]+=mul(tp[3],tpnext[1]);
		ans[2]%=mod;
		ans[2]+=mul(tp[0],tpnext[2]);
		ans[2]%=mod;
		ans[2]+=mul(tp[2],tpnext[0]);
		ans[2]%=mod;

		ans[3]+=mul(tp[0],tpnext[3]);
		ans[3]%=mod;
		ans[3]+=mul(tp[3],tpnext[0]);
		ans[3]%=mod;
		ans[3]+=mul(tp[1],tpnext[2]);
		ans[3]%=mod;
		ans[3]+=mul(tp[2],tpnext[1]);
		ans[3]%=mod;

	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin>>tt;
	while(tt-->0){
		string L;
		cin>>L;
		stack<char> operators;
		stack<vector<int>> operands;
		for(int i = 0; i < L.size(); i++){
			if(L[i] == '&'|L[i] == '|'||L[i] == '^'){
				operators.push(L[i]);
			}
			else if (L[i] == ')'){
				vector<int> tp = operands.top();
				operands.pop();
				vector<int> tpnext = operands.top();
				operands.pop();
				char op = operators.top();
				operators.pop();
				operands.push(solve(tp,tpnext,op));
			}
			else if(L[i] == '#'){
				operands.push({1,1,1,1});
			}
		}
		vector<int> ans  = operands.top();
		ll tot = 0;
		rep(i,0,ans.size() -1){
		 	tot+=ans[i];
			tot%=mod;
		}
		ll ans1 = mul(ans[0],power(tot,mod-2));
		ll ans2 = mul(ans[1],power(tot,mod-2));
		ll ans3 = mul(ans[2],power(tot,mod-2));
		ll ans4 = mul(ans[3],power(tot,mod-2));
		cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<nl;
	}
	return 0;
}
