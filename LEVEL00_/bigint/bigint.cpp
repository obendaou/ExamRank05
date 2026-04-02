#include "bigint.hpp"

bigint::bigint(std::string num)
{
	for (size_t i = 0; i < num.size(); i++)
	{
		if (!std::isdigit(num[i]))
		{
			bignum = "0";
			return;
		}
	}
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

bigint::bigint(unsigned int num)
{
	bignum = std::to_string(num);
}

bigint::bigint(){bignum = '0';}

bigint &bigint::operator=(const bigint &other)
{
	if (this != &other)
		bignum = other.bignum;
	return (*this);
}

bigint bigint::operator+(const bigint &other) const
{
	std::string res;
	ssize_t i = other.bignum.size() - 1;
	ssize_t j = bignum.size() - 1;
	int tmp = 0;

	while (i >= 0 || j >= 0)
	{
		if (i >= 0 && j >= 0)
		{
			res.insert(0, 1, ((other.bignum[i] - '0' + bignum[j] - '0' + tmp) % 10) + '0');
			tmp = (other.bignum[i] - '0' + bignum[j] - '0' + tmp) / 10;
		}
		else if (i >= 0)
		{
			res.insert(0, 1, ((other.bignum[i] - '0' + tmp) % 10) + '0');
			tmp = (other.bignum[i] - '0' + tmp) / 10;
		}
		else
		{
			res.insert(0, 1, ((bignum[j] - '0' + tmp) % 10) + '0');
			tmp = (bignum[j] - '0' + tmp) / 10;
		}
        if (i > -1)
            i--;
        if (j > -1)
            j--;
	}
    if (tmp != 0)
	{
        res.insert(0, 1, tmp + '0');
	}
	return (bigint(res));	
}

bigint &bigint::operator+=(const bigint &other)
{
	std::string tmps;
	ssize_t i = other.bignum.size() - 1;
	ssize_t j = bignum.size() - 1;
	int tmp = 0;

	while (i >= 0 || j >= 0)
	{
		if (i >= 0 && j >= 0)
		{
			tmps.insert(0, 1, ((other.bignum[i] - '0' + bignum[j] - '0' + tmp) % 10) + '0');
			tmp = (other.bignum[i] - '0' + bignum[j] - '0' + tmp) / 10;
		}
		else if (i >= 0)
		{
			tmps.insert(0, 1, ((other.bignum[i] - '0' + tmp) % 10) + '0');
			tmp = (other.bignum[i] - '0' + tmp) / 10;
		}
		else
		{
			tmps.insert(0, 1, ((bignum[j] - '0' + tmp) % 10) + '0');
			tmp = (bignum[j] - '0' + tmp) / 10;
		}
        if (i > -1)
            i--;
        if (j > -1)
            j--;
	}
    if (tmp != 0)
	    tmps.insert(0, 1, tmp + '0');
	bignum = tmps;
	return (*this);
}

bigint &bigint::operator>>=(const bigint &other)
{
	if (other >= bignum.size())
	{
		bignum = "0";
		return (*this);
	}
	char *ptr = NULL;
	bignum.erase(bignum.size() - std::strtoul(other.bignum.c_str(), &ptr, 10), std::strtoul(other.bignum.c_str(), &ptr, 10));
	return (*this);
}

bigint &bigint::operator<<=(const bigint &other)
{
	if (other >= bignum.size())
	{
		bignum = "0";
		return (*this);
	}
	char *ptr = NULL;
	bignum.erase(0, std::strtoul(other.bignum.c_str(), &ptr, 10));
	return (*this);
}

bigint &bigint::operator>>=(unsigned int nb)
{
	if (nb >= bignum.size())
	{
		bignum = "0";
		return (*this);
	}
	char *ptr = NULL;
	bignum.erase(bignum.size() - nb, nb);
	return (*this);
}

bigint &bigint::operator<<=(unsigned int nb)
{
	if (nb >= bignum.size())
	{
		bignum = "0";
		return (*this);
	}
	char *ptr = NULL;
	bignum.erase(0, nb);
	return (*this);
}

bool bigint::operator==(const bigint &other) const
{
	return (other.bignum == bignum);
}

bool bigint::operator<(const bigint &other) const
{
	if (other.bignum.size() != bignum.size())
		return (bignum.size() < other.bignum.size());
	return (bignum < other.bignum);
}

bool bigint::operator>(const bigint &other) const
{
	if (other.bignum.size() != bignum.size())
		return (bignum.size() > other.bignum.size());
	return (bignum > other.bignum);
}

bool bigint::operator<=(const bigint &other) const
{
	if (other.bignum.size() != bignum.size())
		return (bignum.size() <= other.bignum.size());
	return (bignum <= other.bignum);
}

bool bigint::operator>=(const bigint &other) const
{
	if (other.bignum.size() != bignum.size())
		return (bignum.size() >= other.bignum.size());
	return (bignum >= other.bignum);
}

bool bigint::operator!=(const bigint &other) const
{
	return (bignum != other.bignum);
}

bigint bigint::operator>>(const bigint &other) const
{
	bigint res;

	if (other >= bignum.size())
		return (res);
	char *ptr = NULL;
	res.bignum.assign(bignum, 0, bignum.size() - std::strtoul(other.bignum.c_str(), &ptr, 10));
	return (res);
}

bigint bigint::operator<<(const bigint &other) const
{
	bigint res;

	if (other >= bignum.size())
		return (res);
	char *ptr = NULL;
	res.bignum.assign(bignum, std::strtoul(other.bignum.c_str(), &ptr, 10));
	return (res);
}

bigint bigint::operator>>(unsigned int nb) const
{
	bigint res;

	if (nb >= bignum.size())
		return (res);
	res.bignum.assign(bignum, 0, bignum.size() - nb);
	return (res);
}

bigint bigint::operator<<(unsigned int nb) const
{
	bigint res;

	if (nb >= bignum.size())
		return (res);
	char *ptr = NULL;
	res.bignum.assign(bignum, nb);
	return (res);
}

bigint bigint::operator++(int nb)
{
	++*this;
	(void) nb;
	return (*this + 1);
}

bigint bigint::operator++()
{
	*this += 1;
	return (*this);
}

std::string bigint::get_num() const
{
	return (bignum);
}

std::ostream &operator<<(std::ostream &os, const bigint &num)
{
	os << num.get_num();
	return os;
}