#include<iostream>
#include<vector>
#include<climits>
#include<bits/stdc++.h>
using namespace std;


long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

typedef struct tr
{
    long long val;
    long long l;
    long long lo;
    long long r;
    long long ro;
    long long o;
}nd;


vector<nd> v;

template<class T,class MF,class UN> class segmentTree
{
	public:
		typedef T value_type;
		vector<value_type> tree;

        void buildTree(const vector<value_type> &A,size_t low,size_t high, size_t node)
		{
		   // cout<<"here : "<<"low : "<<low<<"  high : "<<high<<"  high : "<<high<<endl;

			if(low==high)
				tree[node]=A[low];
			else if(low>high)
				return;
			else
			{
				buildTree(A,low,(low+high)/2,leftChild(node));
				buildTree(A,(low+high)/2+1,high,rightChild(node));
				tree[node]=mergeFunction(tree[leftChild(node)],tree[rightChild(node)]);
			}
		}

	private:

		MF mergeFunction;
		UN updateNode;
		size_t sz;

		bool inRange(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight) const
		{
			if(nodeLeft > nodeRight || nodeLeft > queryRight || nodeRight < queryLeft)
				return false;
			return true;
		}

		size_t leftChild(size_t node)
		{
			return (node<<1)+1;
		}
		size_t rightChild(size_t node)
		{
			return (node<<1)+2;
		}



		value_type query(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node)
		{
			if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
				return tree[node];
			else
			{
				bool leftInRange=inRange(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2);
				bool rightInRange=inRange(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight);

				if(leftInRange&&!rightInRange)
					return query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node));

				else if(!leftInRange&&rightInRange)
					return query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));

				else
					return mergeFunction(query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node)),query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node)));
			}
		}

		void update(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node,value_type value)
		{
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
				return;

			if(nodeLeft==nodeRight)
				tree[node]=updateNode(tree[node],value);
			else
			{
				update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),value);
				update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),value);

				tree[node]=mergeFunction(tree[leftChild(node)],tree[rightChild(node)]);
			}
		}

	public:
		segmentTree()
		{
			sz=0;
		}

		segmentTree(size_t size,value_type initial=value_type())
		{
			assign(size,initial);
		}

		segmentTree(const vector<value_type> &A)
		{
			clear();
			assign(A);
		}

		void assign(size_t size,value_type initial=value_type())
		{
			clear();
			sz=size;
			tree.resize(4*size,initial);
		}

		void assign(const vector<value_type> &A) // assumes vector to be 0 indexed
		{
			assign(A.size());
			buildTree(A,0,A.size()-1,0);
		}

		void clear()
		{
			sz=0;
			tree.clear();
		}

		void update(size_t pos,const value_type &value)
		{
			update(pos,pos,0,sz-1,0,value);
		}

		value_type query(size_t low,size_t high)
		{
			return query(low,high,0,sz-1,0);
		}
		~segmentTree()
		{
			clear();
		}
};
struct updateNode
{
	nd operator()(nd node,nd newValue)
	{
	    nd newnode;
		return newnode;
	}
};

struct mergeNode
{
	nd operator()(nd left,nd right)
	{
	    nd newnode;
        long long temp;
        long long t1;


            t1=0;
            if(left.r==right.l)
            {
                t1=left.ro+right.lo;
            }

            temp=max2(t1,max2(left.o,right.o));

            newnode.o=temp;

            newnode.lo=left.lo;
            newnode.ro=right.ro;

            if(left.l==right.l)
            {
                newnode.lo=left.lo+right.lo;
            }

            if(right.r==left.r)
            {
                newnode.ro=right.ro+left.ro;
            }


        newnode.l=left.l;
        newnode.r=right.r;

	    return newnode;
		//return left+right;
	}
};

int main()
{
	long long n,temp;
	long long i,j,k;
	long long q;
	long long type;

	nd node1;

	scanf("%lld",&n);
	while(n)
	{

        scanf("%lld",&q);
        segmentTree<nd,mergeNode,updateNode> T(n);
        v.resize(n+1);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&temp);
            v[i].o=1;
            v[i].r=temp;
            v[i].ro=1;
            v[i].l=temp;
            v[i].lo=1;
        }

        T.assign(v);



        for(i=0;i<q;i++)
        {
            long long a,b;
            scanf("%lld%lld",&a,&b);
            a--;
            b--;
            /*if(type)
                T.update(a,node1);
            else*/
            printf("%lld\n",T.query(a,b).o);

                //cout<<T.query(a,b).val<<endl;
        }
        scanf("%lld",&n);
	}
    return 0;

}




/*

#include<iostream>
#include<vector>
#include<climits>
#include<bits/stdc++.h>
using namespace std;


int max2(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

typedef struct tr
{
    int l;
    int r;
    int val;
}nd;


vector<nd> v;

template<class T,class MF,class UN> class segmentTree
{
	public:
		typedef T value_type;
		vector<value_type> tree;

        void buildTree(const vector<value_type> &A,size_t low,size_t high, size_t node)
		{
		   // cout<<"here : "<<"low : "<<low<<"  high : "<<high<<"  high : "<<high<<endl;

			if(low==high)
				tree[node]=A[low];
			else if(low>high)
				return;
			else
			{
				buildTree(A,low,(low+high)/2,leftChild(node));
				buildTree(A,(low+high)/2+1,high,rightChild(node));
				tree[node]=mergeFunction(tree[leftChild(node)],tree[rightChild(node)]);
			}
		}

	private:

		MF mergeFunction;
		UN updateNode;
		size_t sz;

		bool inRange(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight) const
		{
			if(nodeLeft > nodeRight || nodeLeft > queryRight || nodeRight < queryLeft)
				return false;
			return true;
		}

		size_t leftChild(size_t node)
		{
			return (node<<1)+1;
		}
		size_t rightChild(size_t node)
		{
			return (node<<1)+2;
		}



		value_type query(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node)
		{
			if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
				return tree[node];
			else
			{
				bool leftInRange=inRange(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2);
				bool rightInRange=inRange(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight);

				if(leftInRange&&!rightInRange)
					return query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node));

				else if(!leftInRange&&rightInRange)
					return query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));

				else
					return mergeFunction(query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node)),query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node)));
			}
		}

		void update(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node,value_type value)
		{
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
				return;

			if(nodeLeft==nodeRight)
				tree[node]=updateNode(tree[node],value);
			else
			{
				update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),value);
				update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),value);

				tree[node]=mergeFunction(tree[leftChild(node)],tree[rightChild(node)]);
			}
		}

	public:
		segmentTree()
		{
			sz=0;
		}

		segmentTree(size_t size,value_type initial=value_type())
		{
			assign(size,initial);
		}

		segmentTree(const vector<value_type> &A)
		{
			clear();
			assign(A);
		}

		void assign(size_t size,value_type initial=value_type())
		{
			clear();
			sz=size;
			tree.resize(4*size,initial);
		}

		void assign(const vector<value_type> &A) // assumes vector to be 0 indexed
		{
			assign(A.size());
			buildTree(A,0,A.size()-1,0);
		}

		void clear()
		{
			sz=0;
			tree.clear();
		}

		void update(size_t pos,const value_type &value)
		{
			update(pos,pos,0,sz-1,0,value);
		}

		value_type query(size_t low,size_t high)
		{
			return query(low,high,0,sz-1,0);
		}
		~segmentTree()
		{
			clear();
		}
};
struct updateNode
{
	nd operator()(nd node,nd newValue)
	{
	    nd newnode;
		return newnode;
	}
};

struct mergeNode
{
	nd operator()(nd left,nd right)
	{

	    int l1,r1,val1;
	    nd newnode;

	    newnode.val=max2(max2(max2(left.val+right.val,left.r+right.val),max2(left.val+right.l,left.r+right.l)),max2(left.val,right.val));
	    newnode.l=max2(left.val,max2(left.l,left.r));
	    newnode.r=max2(right.val,max2(right.l,right.r));

	    return newnode;
		//return left+right;
	}
};

int main()
{
	int n,temp;
	int i,j,k;
	nd node1;

	cin>>n;
	segmentTree<nd,mergeNode,updateNode> T(n);
    v.resize(n+1);
	for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        v[i].val=temp;
    }

    T.assign(v);

	while(1)
	{
		int type, a,b;
		cin>>type>>a>>b;
		if(type)
			T.update(a,node1);
		else
            cout<<T.query(a,b).val<<endl;
	}
}


*/
