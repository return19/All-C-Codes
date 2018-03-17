#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10000
#define ii pair< int, int >
#define INF 1000000000
#define vi vector<int>
int sol;

struct mod{
    mod(){ zero=0; one=0;two=0;}
    int zero;
    int one;
    int two;
};

class SegmentTree {
public: int lazy[MAX_N];
  mod st[MAX_N];
  int n;
  int left (int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R){
        if(L == R)
            st[p].zero=1;
        else{
            st[p].zero = R - L + 1;
            build(left(p), L, (L + R) / 2);
            build(right(p), ((L + R) / 2) + 1, R);
        }
        return;
  }

  void query(int p, int L, int R, int i, int j) {
    if (L > R || i > R || j < L) return;

    if(lazy[p]!=0){     // Check if this no has to be updated
        for(int k=0;k<lazy[p];k++){
            swap(st[p].zero,st[p].two);
            swap(st[p].one, st[p].two);
        }
        if(L != R){
            lazy[left(p)] = (lazy[left(p)] + lazy[p]) % 3;
            lazy[right(p)] = (lazy[right(p)] + lazy[p]) % 3;
        }
        lazy[p] = 0;
    }


    if (L >= i && R <= j) { sol += st[p].zero;   return; }


    query(left(p) , L              , (L+R) / 2, i, j);
    query(right(p), (L+R) / 2 + 1, R          , i, j);

    return;
  }

  pair < int, ii > update_tree(int p, int L, int R, int i, int j) {

    if (L > R || i > R || j < L){
      pair< int, pair< int, int > >  PP; PP.first=PP.second.first=PP.second.second=INF;
      return PP;
    }

    if(lazy[p]!=0){     // Check if this no has to be updated
        for(int k=0;k<lazy[p];k++){
            swap(st[p].zero,st[p].two);
            swap(st[p].one, st[p].two);
        }
        if(L != R){
            lazy[left(p)] = (lazy[left(p)] + lazy[p]) % 3;
            lazy[right(p)] = (lazy[right(p)] + lazy[p]) % 3;
        }
        lazy[p] = 0;
    }

    if(L>=i && R<=j){
        swap(st[p].zero, st[p].two);
        swap(st[p].one, st[p].two);
        if(L != R){
            lazy[left(p)] = (lazy[left(p)] + lazy[p]) % 3;
            lazy[right(p)] = (lazy[right(p)] + lazy[p]) % 3;
        }
        pair< int, pair< int, int > > t; t.first = st[p].zero-st[p].one; t.second.first = st[p].one-st[p].two; t.second.second = st[p].two-st[p].zero;
        return t;
    }

    pair< int, pair< int, int > > s = update_tree(left(p), L, (L+R)/2, i, j); // Updating left child
    pair< int, pair< int, int > > s2 = update_tree(right(p), 1+(L+R)/2, R, i, j); // Updating right child
    pair< int, pair< int, int > > d2;
    d2.first = ( (s.first!=INF ? s.first : 0) + (s2.first!=INF ? s2.first : 0) ); // Calculating difference from the ones given by the children
    d2.second.first = ( (s.second.first!=INF ? s.second.first : 0) + (s2.second.first!=INF ? s2.second.first : 0) );
    d2.second.second = ( (s.second.second!=INF ? s.second.second : 0) + (s2.second.second!=INF ? s2.second.second : 0) );
    st[p].zero += d2.first; st[p].one += d2.second.first; st[p].two += d2.second.second; // Updating root
    return d2;  // Return difference
  }

  public:
  SegmentTree(const vi &_A) {
    n = (int)_A.size();
    build(1, 0, n - 1);
  }

  void query(int i, int j) { return query(1, 0, n - 1, i, j); }

  pair< int, pair< int, int > > update_tree(int i, int j) {
    return update_tree(1, 0, n - 1, i, j); }
};


int N,Q;

int main() {
   // FILE * in; FILE * out;
   // in = fopen("input.txt","r"); out = fopen("output.txt","w");

   // fscanf(in, "%d %d" , &N, &Q);
    cin>>N>>Q;
    int arr[N];
    vi A(arr,arr+N);

    SegmentTree *st = new SegmentTree(A);

    for(int i=0;i<Q;i++){
        int t,q,q2;
       // fscanf(in, "%d %d %d " , &t, &q, &q2);
        cin>>t>>q>>q2;
        if(q > q2) swap(q, q2);
        if(t){
            sol=0;
            st->query(q,q2);
            //fprintf(out, "%d\n", sol);
            cout<<sol<<endl;
        }
        else{
            pair<int, pair< int, int > > t = st->update_tree(q,q2);
        }
    }

 //   fclose(in); fclose(out);
    return 0;
}
