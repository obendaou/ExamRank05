#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <string>
#include <iostream>

class bigint
{
	private:
		std::string bignum;
	public:
		bigint();
		bigint(std::string num);
		bigint(unsigned int num);
		bigint &operator=(const bigint &other);
		bigint operator+(const bigint &other) const;
		bigint &operator+=(const bigint &other);
		bigint &operator>>=(const bigint &other);
		bigint &operator<<=(const bigint &other);
		bigint &operator>>=(unsigned int nb);
		bigint &operator<<=(unsigned int nb);
		bool operator==(const bigint &other) const;
		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
		bool operator!=(const bigint &other) const;
		bigint operator<<(unsigned int nb)  const;
		bigint operator<<(const bigint &other) const;
		bigint operator>>(unsigned int nb) const;
		bigint operator>>(const bigint &other) const;
		bigint operator++(int nb);
		bigint operator++();
		std::string get_num() const;
};

std::ostream &operator<<(std::ostream &os, const bigint &num);

#endif