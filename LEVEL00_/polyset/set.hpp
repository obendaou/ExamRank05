#ifndef SET_HPP
#define SET_HPP


#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag &data;
	public:
		set(searchable_bag &bag);
		~set();
		void insert (int);
		void insert (int *, int);
		void print() const;
		void clear();
		bool has(int n) const;
		searchable_bag &get_bag() const;
};

#endif