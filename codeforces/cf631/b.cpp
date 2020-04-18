// Author : Hardik Upadhyay
// college: SVNIT 
// slogan : Ab to phod dunga
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
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
//Number theory library
ll add(ll a,ll b,ll mod){
	return (a%mod+b%mod)%mod;
}
ll sub(ll a,ll b,ll mod){
	return (a%mod-b%mod+mod)%mod;
}
ll mul(ll a,ll b,ll mod){
	return ((a%mod)*(b%mod))%mod;
}
ll power(ll a, ll b,ll mod){
	ll ans = 1;
		while(b>0){
			if(b%2==1)ans=mul(ans,a,mod);
			a = mul(a,a,mod);
			b/=2;
		}
		return ans;
}
int gcd,x,y;
void extendedEuclid(int A,int B){
	if(B==0){
		gcd = A;
		x = 1;
		y = 0;
	}
	else{
		extendedEuclid(B,A%B);
		int temp = x;
		x = y;
		y = temp - (A/B)*y;
	}
}
ll modularInverse(ll A,ll M){
	extendedEuclid(A,M);
	return (x%M+M)%M;
}
//if M is prime 
//Fermat's theorem mod-1 ==> A^(M-2)
ll modularInversePrime(ll A,ll M){
	return power(A,M-2,M);
}
ll div(ll a,ll b,ll mod){
	return ((a%mod)*(modularInverse(b,mod)%mod))%mod;
}

//string library

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
// tree library
struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node * newNode(int element){
	struct node * temp = (node *)malloc(sizeof(node *));
	temp->data = element;
	temp->left = temp->right = NULL;
	return temp;
}
int maxDepth(struct node * v){
	if(v == NULL){
		return 0;
	}
	else {
		int ldepth = maxDepth(v->left);
		int rdepth = maxDepth(v->right);
		return max(ldepth,rdepth)+1;
	}
}

//BST library

void preorder(struct node * root,int q){
	if(root){
		printf("%d ",root->data);
		preorder(root->left,q);
		preorder(root->right,q);
	}
}
void postorder(struct node *root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void inorder(struct node *root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

struct node * insert(struct node *root,int data){
	if(root == NULL){
		return newNode(data);
	}
	else {
		if(data <= root->data){
			root->left = insert(root->left,data);
		}
		else {
			root->right = insert(root->right,data);
		}
	}
	return root;
}

struct node *lca(ll x,ll y,struct node *root){
	if(root->data < x && root->data < y){
		return lca(x,y,root->right);	
	}
	else if( root->data > x && root->data > y){
	 return lca(x,y,root->left);
	}	 
	return root;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		ll n;
		cin>>n;
		ll a[n];
		rep(i,0,n-1)cin>>a[i];
		ll sum1=0,sum2=0;
		bool check[n]={false};
		for(ll i =1; i <= n; i++){
			sum1+=a[i-1];
			sum2+=a[i-1]*a[i-1];
			if(sum1==(i*(i+1))/2 && sum2==(i*(i+1)*(2*i+1)/6)){
				check[i-1] = 1;
			}
		}
		sum1=0,sum2=0;
		bool check1[n]= {false};
		ll k = 1;
		for(ll i =n-1; i >=0; i--){
			sum1+=a[i];
			sum2+=a[i]*a[i];
			if(sum1==(k*(k+1))/2 && sum2==(k*(k+1)*(2*k+1)/6)){
				check1[i] = 1;
			}
			k++;
		}
		
		ll cnt=0;
		bool ans[n] ={0};
		for(ll i = 0; i+1 < n; i++){
			if(check[i]==1&&check1[i+1] == 1){
				cnt++;
				ans[i] = 1;
			}
		}
		cout<<cnt<<nl;
		for(ll i = 0; i < n; i++){
			if(ans[i]){
				cout<<(i+1)<<" "<<(n-1-i)<<nl;
			}
		}
	}
	return 0;
}

