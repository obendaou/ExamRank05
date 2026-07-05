#include "searchable_array_bag.hpp"

bool searchable_array_bag::has(int n) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == n)
			return true;
	}
	return false;
}

searchable_array_bag::searchable_array_bag() : array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other) : array_bag(other) {}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other)
{
	if (this != &other) {
		if (data != nullptr) {
			delete[] data;
			data = nullptr;
		}
		size = other.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

searchable_array_bag::~searchable_array_bag(){}