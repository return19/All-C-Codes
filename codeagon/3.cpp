// Program for range minimum query using segment tree
#include<bits/stdc++.h>
using namespace std;
long long st1[1100000];

// A utility function to get minimum of two numbers
long long minVal(long long x, long long y) { return (x > y)? x: y; }

// A utility function to get the middle index from corner indexes.
long long getMid(long long s, long long e) {  return s + (e -s)/2;  }

/*  A recursive function to get the minimum value in a given range of array
    indexes. The following are parameters for this function.

    st    --> Polong longer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
pair<long long,long long> RMQUtil(long long *st, long long ss, long long se, long long qs, long long qe, long long index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= ss && qe >= se)
        return make_pair(st[index],st1[index]);

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return make_pair(-1,1);

    // If a part of this segment overlaps with the given range
    long long mid = getMid(ss, se);

    pair<long long,long long> low=RMQUtil(st, ss, mid, qs, qe, 2*index+1);
    pair<long long,long long> high=RMQUtil(st, mid+1, se, qs, qe, 2*index+2);

    long long c=0,c1;

    if(low.first==high.first)
    {
        c=low.second+high.second;
        c1=low.first;
    }
    else if(low.first>high.first)
    {
        c=low.second;
        c1=low.first;
    }
    else{
        c=high.second;
        c1=high.first;
    }

    return make_pair(c1,c);
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
pair<long long,long long> RMQ(long long *st,
                              long long n, long long qs, long long qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return make_pair(0,1);
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
pair<long long,long long> constructSTUtil(long long arr[], long long ss, long long se, long long *st, long long si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        st1[si]=1;
        return make_pair(arr[ss],st1[si]);
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    long long mid = getMid(ss, se);
    pair<long long,long long> low=constructSTUtil(arr, ss, mid, st, si*2+1);

    pair<long long,long long> high=constructSTUtil(arr, mid+1, se, st, si*2+2);

    st[si] =  minVal(low.first,high.first);

    if(low.first==high.first)
        st1[si]=low.second+high.second;
    else if(low.first>high.first)
        st1[si]=low.second;
    else
        st1[si]=high.second;

    return make_pair(st[si],st1[si]);
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
long long *constructST(long long arr[], long long n)
{
    // Allocate memory for segment tree
    long long x = (long long)(ceil(log2(n))); //Height of segment tree
    long long max_size = 2*(long long)pow(2, x) - 1; //Maximum size of segment tree
    long long *st = new long long[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}
long long arr[110000];
// Driver program to test above functions
int main()
{

    long long i,j,k;
    long long n;
    scanf("%lld%lld",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    //int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    long long *st = constructST(arr, n);

    long long qs,qe;

    //int qs = 0;  // Starting index of query range
    //int qe = 5;  // Ending index of query range
long long x,y;
    for(i=0;i<k;i++)
    {


        scanf("%lld%lld",&x,&y);

        qs=x-1;
        qe=y-1;

        printf("%lld\n",RMQ(st, n, qs, qe).second);
    }

    // Print minimum value in arr[qs..qe]
  /*  printf("Minimum of values in range [%d, %d] is = %d %d\n",
                           qs, qe, RMQ(st, n, qs, qe).first,RMQ(st, n, qs, qe).second);
*/
    return 0;
}
