#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define nl "\n"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout<<"priority queue"<<nl;
	priority_queue<int,vector<int>,greater<int>> q1;
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	cout<<q1.top()<<nl;
	q1.pop();
	cout<<q1.top()<<nl;
	cout<<"Queue"<<nl;
	queue<int> q;
	q.push(3);
	cout<<"Stack"<<nl;
	stack<int> s3;
	s3.push(1);
	s3.push(3);
	s3.push(5);
	cout<<"old top"<<nl;
	cout<<s3.top()<<nl;
	s3.pop();
	cout<<"new top"<<nl;
	cout<<s3.top()<<nl;
	cout<<"Deque"<<endl;
	deque<int> d;
	d.PB(2);
	d.PB(1);
	d.PB(3);
	d.PB(5);
	cout<<d.back()<<nl;
	d.pop_back();
	cout<<"new back "<<d.back()<<nl;
	cout<<d.front()<<nl;
	d.pop_front();
	cout<<"New front "<<d.front()<<nl;
	cout<<"Bit stuff made easier"<<endl;
	bitset<10> s1(string("1010010000"));
	bitset<10> s2(string("1000001001"));
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<(s1&s2)<<endl;
	cout<<"finding an element nearest to x in a set"<<endl;
	set<int> s;
	s.insert(2);
	s.insert(3);
	s.insert(6);
	s.insert(6);
	//auto it = s.begin();
	cout<<"Here are the elements of the set"<<endl;
	for(auto it = s.begin();it!=s.end();it++){
		cout<<*it<<endl;
	}
	int x = 4;
	auto it = s.lower_bound(4);
	cout<<"Nearest element of "<<x<<" is "<<endl;
	if(it==s.begin()){
		cout<<*it<<endl;
	}
	else if(it==s.end()){
		it--;
		cout<<*it<<endl;
	}
	else{
		int a = *it;
		it--;
		int b = *it;
		if(x-b<a-x)cout<<b<<endl;
		else cout<<a<<endl;
	}
	return 0;

}



