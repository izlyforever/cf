// 标程
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define inf 0x3fffffff
typedef pair<LL, LL> PLL;

LL ccw(PLL a,PLL b,PLL c)
{
    return a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second);
}

int n,a[500010],b[500010];

LL ans;

void binary(int L,int mid,int R)
{
    int r=mid;
    int A=a[mid],B=b[mid];
    for(int l=mid;l>=L;l--)
    {
        A=min(A,a[l]);
        B=min(B,b[l]);
        while(r<R&&a[r+1]>=A&&b[r+1]>=B) r++;
        ans=max(ans,(LL) A*B*(r-l+1));
    }
}

vector<PLL> To;
int flag;
vector<PLL> h[5000000];
int Tre[5000000];

void init()
{
    for (int i=0;i<2*flag;i++)
        h[i].clear();
}

void Re(int cvor,int a,int b)
{
    if(a==b)
    {
        if(a<(int) To.size()) h[cvor].push_back(To[a]);
        Tre[cvor]=(int)h[cvor].size()-1;
        return;
    }
    Re(2*cvor,a,(a+b)/2);
    Re(2*cvor+1,(a+b)/2+1,b);
    h[cvor]=h[2*cvor];
    int p=(a+b)/2+1,k=min(b+1,(int)To.size());
    for (int i=p;i<k;i++)
    {
        int sz=(int) h[cvor].size();
        while(sz>=2 && ccw(h[cvor][sz-2],h[cvor][sz-1],To[i])<=0)
        {
            h[cvor].pop_back();
            sz--;
        }
        h[cvor].push_back(To[i]);
    }
    Tre[cvor]=(int)h[cvor].size()-1;
}

void pre()
{
    for(flag=1;flag<(int)To.size();flag *= 2);
    init();
    Re(1,0,flag-1);
}

LL dp(int t,PLL a)
{
  return t*a.first+a.second;
}

LL ispitaj_hull(int cvor,int t) {
  if(Tre[cvor]==-1) return 0;
  while(Tre[cvor]>0 && dp(t,h[cvor][Tre[cvor]-1])>=dp(t,h[cvor][Tre[cvor]]))
    Tre[cvor]--;
  return dp(t,h[cvor][Tre[cvor]]);
}

LL query(int cvor,int a,int b,int L,int R,int t) {
  if(a>R || b<L) return 0;
  if(a>=L && b<=R) return ispitaj_hull(cvor,t);
  LL lijevi=query(2*cvor,a,(a+b)/2,L,R,t);
  LL desni=query(2*cvor+1,(a+b)/2+1,b,L,R,t);
  return max(lijevi,desni);
}

void binary2(int L,int mid,int R)
{ 
    int A=a[mid],B=b[mid],p=mid,k=mid;
    vector<PLL> In;
    vector<int> Fa;
    for(int l=mid;l>=L;l--)
    { 
        A=min(A,a[l]);
        B=min(B,b[l]);
        while(k<R&&a[k+1]>=A) k++;
        while(p<=R&&b[p]>B) p++;
        In.push_back(PLL(p-mid,k-mid));
        Fa.push_back(A);
    }
    To.clear();
    int res=b[mid];
    for(int r=mid;r<=R;r++)
    {
        res=min(res,b[r]);
        To.push_back(PLL(res,(LL) res*(r+1)));
    }
    pre();
    for(int l=mid;l>=L;l--) {
        int i=mid-l;
        ans=max(ans,(LL) Fa[i]*query(1,0,flag-1,In[i].first,In[i].second,-1*l));
    }
}

void calc(int L,int R,int X)
{
    if(L>R) return;
    if(X)
    { 
        int mid=L+R>>1;
        binary(L,mid,R);
        binary2(L,mid,R);
        if(L==R) return;
        calc(L,mid-1,X);
        calc(mid+1,R,X);
    }
    else
    {
        int mid=L+R+1>>1;
        binary(L,mid,R);
        binary2(L,mid,R);
        if(L==R) return;
        calc(mid+1,R,X);
        calc(L,mid-1,X);
    }
}

void solve()
{
    calc(0,n-1,1);
    reverse(a,a+n);
    reverse(b,b+n);
    calc(0,n-1,0);
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    solve();
    printf("%lld\n",ans);
    return 0;
}

// #include <bits/stdc++.h>
// #define watch(x) std::cout << (#x) << " is " << (x) << std::endl
// using LL = long long;

// int main() {
// 	//freopen("in", "r", stdin);
// 	std::cin.tie(nullptr)->sync_with_stdio(false);
// 	int cas = 1;
// 	std::cin >> cas;
// 	while (cas--) {
		
// 	}
// 	return 0;
// }