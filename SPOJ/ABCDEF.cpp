
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-9
#define OO 100000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<int> point;
#define X real()
#define Y imag()

#define vec(a,b) (b-a)
#define angle(a) (atan2(((a).Y),((a).X)))

#define length(a) (hypot(((a).real()),((a).imag())))
#define normalize(a) ((a)/(length(a)))

#define dotp(a,b) ((conj(a)*(b)).real())
#define crossp(a,b) ((conj(a)*b).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }






int main(){

   ll n;
   cin>>n;
   vector<ll> data(n);
   lp(i,n){
    cin>>data[i];
   }

   vector<ll> gen(n*n*n);
   ll lastidx=0;
   lp(i,n){
    lp(j,n){
        lp(k,n){
            
            gen[lastidx++]=data[i]*data[j]+data[k];
            
        }
    }
   }
   sort(gen.begin(),gen.end());
   ll ans=0;
   lp(i,n){
        lp(j,n){
            lp(k,n){
                if(data[k]==0) continue;
                auto it =equal_range(gen.begin(),gen.end(), data[k]*(data[i]+data[j]));
                ans+=(ll)(it.ss-it.ff);
            }
        }
   }

   cout<<ans<<endl;
}

