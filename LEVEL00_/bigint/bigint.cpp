#include "bigint.hpp"

bigint::bigint(): number("0")
{}

bigint::bigint(unsigned int num)
{
	setbignum(num);
}

bigint::bigint(const std::string &num)
{
	setbignum(num);
}

bigint::~bigint()
{

}

bigint bigint::operator+(const bigint &other) const
{
	std::string res;

	ssize_t i = number.size();
	ssize_t j = other.number.size();
	unsigned int baqi = 0;
	while (i >= 0 || j >= 0 || baqi != 0)
	{
		unsigned int a = 0;
		unsigned int b = 0;

		if (i >= 0)
		{
			a = number[i] - '0';
			i--;
		}
		if (j >= 0)
		{
			j = other.number[j];
			j--;
		}
		unsigned int resn = a + b + baqi;
		baqi = resn / 10;
		resn = resn % 10;
		char c = (char)resn + '0';
		res.insert(res.begin(), c);
	}
	return (bigint(res));
}