#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef vector<int> vi;
typedef vector<vi> vv;

struct element{
    int * arr;
    int size;
};

typedef element element;


element tree[4 * 100005];
int a[100005];
int curr, l, r, n;
bool found = false;

//merge
void _merge(int node){
        int left = node * 2;
        int right = node * 2 + 1;
        int i = 0, j = 0, c = 0;
        int lSize =  tree[left].size;
        int rSize =  tree[right].size;
        int newSize = lSize + rSize;
        tree[node].size = newSize;
        tree[node].arr = new int[newSize];

        while(i < lSize && j < rSize){
            if(tree[left].arr[i] < tree[right].arr[j]){
                tree[node].arr[c] = tree[left].arr[i];
                i++;
            }else{
                tree[node].arr[c] = tree[right].arr[j];
                j++;
            }
            c++;
        }

        while(i < lSize)
            tree[node].arr[c++] = tree[left].arr[i++];



        while(j < rSize)
            tree[node].arr[c++] = tree[right].arr[j++];

}


void initialize(int node, int st, int en){
    if(st == en){
        tree[node].arr = new int[1];
        tree[node].arr[0] = a[st];
        tree[node].size = 1;
    }else{
        int mid = (st+en)/2;
        initialize(node * 2, st, mid);
        initialize(node * 2 + 1, mid + 1 , en);
        _merge(node);
    }
}

int query(int node, int st, int en){
    if(l > en || r < st)
        return 0;
    if(l <= st && r >= en){
        int lo = 0, hi = tree[node].size - 1, mid;

        while(lo < hi){
            mid = (lo + hi)/2;
            if(tree[node].arr[mid] >= curr){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        //check if the element is in the interval
        if(tree[node].arr[lo] == curr)
            found = true;
        return lo + (tree[node].arr[lo] < curr ? 1:0);
    }else{
        int mid = (st+en)/2;
        return query(node*2, st, mid) + query(node * 2 +1, mid + 1, en);
    }
}

struct elem
{
    int val;
    int i;
};


int cmp(elem a,elem b)
{
    return a.val<b.val;
}


elem arr[101000];

int val[101000];
int org[101000];

int main() {

    int m, k;
    int lo ,hi, res, mid;

    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        org[i]=a[i];

    }

    for(int i=0;i<n;i++)
    {
        arr[i].val=a[i];
        arr[i].i=i;
    }
    sort(arr,arr+n,cmp);

    for(int i=0;i<n;i++)
    {
        val[i]=arr[i].val;
        a[i]=arr[i].i;
    }

    /*for(int i=0;i<n;i++)
    {
        cout<<arr[i].val<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].i<<" ";
    }
    cout<<endl;*/

    initialize(1, 0, n-1);

    int x,y;

    for(int i = 0 ; i < m ; i++){
        scanf("%d %d", &x, &y);


        int l_b=lb(val,val+n,x)-val;

        l=l_b;
        r=n-1;

       // cout<<"l :"<<l<<endl;

        k=y;

        //give l r k

        lo = 0;
        hi = tree[1].size - 1;

        while(lo <= hi){
            found = false;
            mid = (lo + hi) / 2;
            curr = tree[1].arr[mid];
            res = query(1, 0 , n-1);


            if(res == k - 1 && found){
                printf("%d\n", org[curr]);
                break;
            }

            if(res > k - 1)
                hi = mid - 1;
            else
                lo = mid + 1;

        }
    }
    return 0;
}
