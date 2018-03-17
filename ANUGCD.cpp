#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 1000
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

vector<int> primeList;
template<class T,class MF,class UN> class segmentTree
{
	public:
		typedef T value_type;

	private:
		vector<value_type> tree;
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

		void buildTree(const vector<value_type> &A,size_t low,size_t high, size_t node)
		{

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
	int operator()(int node,int newValue)
	{
		return newValue;
	}
};

struct mergeNode
{
	int operator()(int left,int right)
	{
		return max(left,right);
	}
};

void sieve()
{
    int i,j;
    isprime[0]=0xA28A28AC;
    for(int i=1;i<=MAX/32+1;i+=3)
    {
    	isprime[i]  =0x28A28A28;
        isprime[i+1]=0x8A28A28A;
        isprime[i+2]=0xA28A28A2;
    }
    for(i=5;i*i<=MAX;i+=2)
        if(isSet(i))
            for(j=i*i;j<=MAX;j+=i)
                unset(j);

    for(int i=2;i<=MAX;i++)
    {
    	if(isSet(i))
			primeList.push_back(i);
    }
}

vector<vector<int> > occurances(100010);
vector<segmentTree<int,mergeNode,updateNode> > ST(1000);
int main()
{
	sieve();
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);

	vector<int> a(n);


	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		occurances[a[i]].push_back(i);
	}



	for(int i=0;i<primeList.size();i++)
	{
		vector<int> temporary(n);
		for(int j=0;j<n;j++)
		{
			if(a[j]%primeList[i]==0)
				temporary[j]=a[j];
			else
				temporary[j]=-1;
		}

		ST[primeList[i]]=segmentTree<int,mergeNode,updateNode>(temporary);
	}

	for(int i=0;i<m;i++)
	{
		int ans=-1;
		int G,l,h;
		scanf("%d %d %d",&G,&l,&h);
		l--;
		h--;

		for(int i=0;i<primeList.size();i++)
			if(G%primeList[i]==0)
				ans=max(ans,ST[primeList[i]].query(l,h));

		for(int i=0;i<primeList.size();i++)
			while(G%primeList[i]==0)
				G/=primeList[i];

		if(G>1)
			for(int i=1;G*i<=100000;i++)
				if(upper_bound(occurances[G*i].begin(),occurances[G*i].end(),h)-lower_bound(occurances[G*i].begin(),occurances[G*i].end(),l)>=1)
					ans=max(ans,i*G);
		if(ans==-1)
			printf("-1 -1\n");
		else
			printf("%d %d\n",ans,upper_bound(occurances[ans].begin(),occurances[ans].end(),h)-lower_bound(occurances[ans].begin(),occurances[ans].end(),l));
	}
}
