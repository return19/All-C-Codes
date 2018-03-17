template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree;

		void increase(size_t idx, const value_type &val)
		{
			while (idx <= tree.size()-1)
			{
				tree[idx] += val;
				idx += (idx & (- idx));
			}
		}
	public:
		BIT(){}

		BIT(size_t n)
		{
			assign(n);
		}

		void assign(int n)
		{
			tree.clear();
			tree.resize(n+1);
		}

	 	value_type query(size_t idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}

		value_type update(size_t a,size_t b,const value_type &value)
		{
			increase(a,value);
			increase(b+1,-value);

		}
		void clear()
		{
			tree.clear();
		}
};
