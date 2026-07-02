#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <sstream>
#include <aio.h>
#include <iostream>

class bigint
{
	private:
		std::string number;
	public:
		bigint(const std::string &str);
		bigint();
		bigint(unsigned int num);
		~bigint();
		bigint &operator=(const bigint &other);
		bigint operator+(const bigint &other) const;
		bigint &operator+=(const bigint &other);
		bool operator==(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator!=(const bigint &other) const;
		bigint operator<<(const bigint &other) const;
		bigint operator<<(unsigned int n) const;
		bigint operator>>(const bigint &other) const;
		bigint operator>>(unsigned int n) const;
		bigint &operator<<=(const bigint &other);
		bigint &operator<<=(unsigned int n);
		bigint &operator>>=(const bigint &other);
		bigint &operator>>=(unsigned int n);
		bigint &operator++();
		bigint operator++(int num);
		std::string getbignum() const;
		void setbignum(unsigned int num);
		void setbignum(const std::string &num);

};

std::ostream &operator<<(std::ostream &os, const bigint &bignum);

#endif