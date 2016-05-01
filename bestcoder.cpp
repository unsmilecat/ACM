#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <bitset>
#include <cmath>
#include <utility>
#define Maxn 100005
#define Maxm 1000005
#define lowbit(x) x&(-x)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define PI acos(-1.0)
#define make_pair MP
#define LL long long
#define Inf (1LL<<62)
#define inf 0x3f3f3f3f
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
using namespace std;
LL ans[Maxn],k;
struct Node
{
	LL now;
	int cnt4,cnt7;
};
void BFS()
{
	queue<Node> q;
	Node now;
	now.now=0;now.cnt4=now.cnt7=0;
	q.push(now);
	while(!q.empty())
	{
		Node newnode=q.front();
		q.pop();
		if(newnode.cnt4==newnode.cnt7&&newnode.cnt4+newnode.cnt7)
			ans[k++]=newnode.now;
		Node a,b;
		a=b=newnode;
		a.now=newnode.now*10+4;
		a.cnt4++;
		b.now=newnode.now*10+7;
		b.cnt7++;
		if(a.cnt4+a.cnt7<=18&&a.cnt4<=9&&a.cnt7<=9)
			q.push(a);
		if(b.cnt4+b.cnt7<=18&&b.cnt4<=9&&b.cnt7<=9)
			q.push(b);
	}
}
int main()
{
	input;output;
	int ncase;
	LL n;
	k=0;
	scanf("%d",&ncase);
	BFS();
	sort(ans,ans+k);
	while(ncase--)
	{
		scanf("%I64d",&n);
		if(n>777777777444444444)
			puts("44444444447777777777");
		else
			printf("%I64d\n",*lower_bound(ans,ans+k,n));
	}
	return 0;
}