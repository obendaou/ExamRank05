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

	ssize_t i = number.size() - 1;
	ssize_t j = other.number.size() - 1;
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
			b = other.number[j] - '0';
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

bigint &bigint::operator=(const bigint &other)
{
	if (&other != this)
		number = other.number;
	return (*this);
}

bigint &bigint::operator+=(const bigint &other)
{
	*this = operator+(other);
	return (*this);
}

bool bigint::operator==(const bigint &other) const
{
	return (number == other.number);
}

bool bigint::operator<=(const bigint &other) const
{
	if (number.size() != other.number.size())
		return (number.size() <= other.number.size());
	return (number <= other.number);
}

bool bigint::operator>=(const bigint &other) const
{
	if (number.size() != other.number.size())
		return (number.size() >= other.number.size());
	return (number >= other.number);
}

bool bigint::operator!=(const bigint &other) const
{
	return (number != other.number);
}

bool bigint::operator>(const bigint &other) const
{
	if (number.size() != other.number.size())
		return (number.size() > other.number.size());
	return (number > other.number);
}

bool bigint::operator<(const bigint &other) const
{
	if (number.size() != other.number.size())
		return (number.size() < other.number.size());
	return (number < other.number);
}

bigint bigint::operator<<(const bigint &other) const
{
	unsigned int n;
	std::stringstream ss;

	ss << other;
	ss >> n;
	return operator<<(n);
}

bigint bigint::operator<<(unsigned int n) const
{
	return (bigint(number + std::string(n, '0')));
}

bigint bigint::operator>>(const bigint &other) const
{
	unsigned int n;
	std::stringstream ss;

	ss << other;
	ss >> n;
	return operator>>(n);
}

bigint bigint::operator>>(unsigned int n) const
{
	if (n >= number.size())
		return (bigint("0"));
	return (bigint(number.substr(0, number.size() - n)));
}

bigint &bigint::operator<<=(const bigint &other)
{
	unsigned int n;
	std::stringstream ss;

	ss << other;
	ss >> n;
	return operator<<=(n);
}

bigint &bigint::operator<<=(unsigned int n)
{
	number = number + std::string(n, '0');
	return (*this);
}

bigint &bigint::operator>>=(const bigint &other)
{
	unsigned int n;
	std::stringstream ss;

	ss << other;
	ss >> n;
	return operator>>=(n);
}

bigint &bigint::operator>>=(unsigned int n)
{
	if (n >= number.size())
	{
		number = "0";
		return (*this);
	}
	number = number.substr(0, number.size() - n);
	return (*this);
}

bigint &bigint::operator++()
{
	*this += 1;
	return (*this);
}

bigint bigint::operator++(int nb)
{
	(void) nb;
	bigint r = *this;
	*this += 1;
	return (r);
}

std::string bigint::getbignum() const
{
	return number;
}

void bigint::setbignum(unsigned int n)
{
	std::stringstream ss;

	ss << n;
	ss >> number;
}

void bigint::setbignum(const std::string &str)
{
	size_t i = 0;
	while (i < str.size() && str[i] == '0')
		i++;
	if (i == str.size())
	{
		number = "0";
		return ;
	}
	while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		number.push_back(str[i++]);
	if (i < str.size())
		number = "0";
}

std::ostream &operator<<(std::ostream &os, const bigint &other)
{
	os << other.getbignum();
	return os;
}