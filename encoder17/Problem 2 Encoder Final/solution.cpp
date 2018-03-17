#include<bits/stdc++.h>
using namespace std;
template<class T>
class stackOperation
{
	private: vector<T> st;
	public:
	void push(T elem)
	{
		st.push_back(elem);
	}
	void push(int n, T elem)
	{
		while(n--)
		{
			st.push_back(elem);
		}
	}
	T pop()
	{
		if(st.empty())
		    return 0;
		T temp = st.back();
		st.pop_back();
		return temp;
	}
	T pop(int n)
	{
		T temp = 0;
		while(n--)
		{
			if(st.empty()) break;
			temp += st.back();
			st.pop_back();
		}
		return temp;
	}
	T print()
	{
		T temp = 0;
		for(int i=0;i<st.size();i++)
		{
			temp+=st[i];
		}
		return temp;
	}
};
int main()
{
    //freopen("samplein01.txt","r",stdin);
    //freopen("sampleout01.txt","w",stdout);
	int q,type,x,n;
	scanf("%d",&q);
	stackOperation<int> obj;
	while(q--)
	{
		scanf("%d",&type);
		switch(type)
		{
			case 1: scanf("%d",&x);
			        obj.push(x);
			        break;
			case 2: scanf("%d %d",&n,&x);
			        obj.push(n,x);
					break;
			case 3: printf("%d\n",obj.pop());
			        break;
			case 4: scanf("%d",&n);
			        printf("%d\n",obj.pop(n));
			        break;
			case 5: printf("%d\n",obj.print());
			        break;
		}
	}
	return 0;
}
