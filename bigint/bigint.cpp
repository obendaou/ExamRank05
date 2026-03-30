#include "bigint.hpp"

bigint::bigint(std::string num)
{
	size_t i = 0;
	while (num[i] == '0')
	{
		num.erase(i, 1);
		i++;
	}
	if (num.empty())
	{
		bignum = "0";
		return;
	}
	bignum = num;
}