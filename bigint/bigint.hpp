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
		bigint(int num);
		bigint &operator=(const bigint &other);
		bigint operator+(const bigint &other);
		bigint &operator+=(const bigint &other);
		bigint &operator>>=(const bigint &other);
		bigint &operator<<=(const bigint &other);
		bigint &operator>>=(int nb);
		bigint &operator<<=(int nb);
		bool operator==(const bigint &other);
		bool operator<(const bigint &other);
		bool operator>(const bigint &other);
		bool operator<=(const bigint &other);
		bool operator>=(const bigint &other);
		bool operator!=(const bigint &other);
		bigint &operator<<(int nb);
		bigint &operator<<(const bigint &other);
		bigint &operator>>(int nb);
		bigint &operator>>(const bigint &other);
		bigint &operator++(int nb);
		bigint &operator++();
};

std::ostream &operator<<(const std::ostream &os, const bigint &num);

#endif