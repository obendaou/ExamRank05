#include "set.hpp"

set::set(searchable_bag &bag) : data(bag) {}

set::~set(){}

void set::insert(int n)
{
	if (!data.has(n))
		data.insert(n);
}

void set::insert(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		insert(arr[i]);
	}
}

void set::print() const
{
	data.print();
}

void set::clear()
{
	data.clear();
}

bool set::has(int n) const
{
	return (data.has(n));
}

searchable_bag &set::get_bag() const
{
	return data;
}