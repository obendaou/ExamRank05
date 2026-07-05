#include "vect2.hpp"

vect2::vect2()
{
	v.push_back(0);
	v.push_back(0);
}

vect2::vect2(int a, int b)
{
	v.push_back(a);
	v.push_back(b);
}

vect2::~vect2(){}

vect2 &vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		v = other.v;
	}
	return *this;
}

int &vect2::operator[](unsigned int n)
{
	return v[n];
}
const int &vect2::operator[](unsigned int n) const
{
	return v[n];
}
vect2 vect2::operator*(int n) const
{
	return (vect2(v[0] * n, v[1] * n));
}

vect2 vect2::operator*(const vect2 &other) const
{
	return (vect2(v[0] * other.v[0], v[1] * other.v[1]));
}

vect2 vect2::operator+(const vect2 &other) const
{
	return (vect2(v[0] + other.v[0], v[1] + other.v[1]));
}

vect2 vect2::operator+(int n) const
{
	return (vect2(v[0] + n, v[1] + n));
}

vect2 vect2::operator-(const vect2 &other) const
{
	return (vect2(v[0] - other.v[0], v[1] - other.v[1]));
}

vect2 vect2::operator-(int n) const
{
	return (vect2(v[0] - n, v[1] - n));
}

vect2 &vect2::operator+=(const vect2 &other)
{
	v[0] += other.v[0];
	v[1] += other.v[1];
	return(*this);
}

vect2 &vect2::operator+=(int n)
{
	v[0] += n;
	v[1] += n;
	return (*this);
}

vect2 &vect2::operator-=(const vect2 &other)
{
	v[0] -= other.v[0];
	v[1] -= other.v[1];
	return(*this);
}

vect2 &vect2::operator-=(int n)
{
	v[0] -= n;
	v[1] -= n;
	return (*this);
}

vect2 &vect2::operator*=(const vect2 &other)
{
	v[0] *= other.v[0];
	v[1] *= other.v[1];
	return(*this);
}

vect2 &vect2::operator*=(int n)
{
	v[0] *= n;
	v[1] *= n;
	return (*this);
}

vect2 &vect2::operator++()
{
	*this += 1;
	return (*this);
}

vect2 vect2::operator++(int n)
{
	(void) n;
	vect2 res = *this;
	++*this;
	return (res);
}

vect2 &vect2::operator--()
{
	*this -= 1;
	return (*this);
}

vect2 vect2::operator--(int n)
{
	(void) n;
	vect2 res = *this;
	--*this;
	return (res);
}

bool vect2::operator==(const vect2 &other) const
{
	return (v == other.v);
}

bool vect2::operator!=(const vect2 &other) const
{
	return (v != other.v);
}

std::ostream &operator<<(std::ostream &os, const vect2 &vect)
{
	os << "{" << vect.getV0() << ", " << vect.getV1() << "}" << std::endl;
	return os;
}

vect2 operator+(int n,const vect2 &vect)
{
	return (vect2(n + vect.getV0(), n + vect.getV1()));
}

vect2 operator-(int n,const vect2 &vect)
{
	return (vect2(n - vect.getV0(), n - vect.getV1()));
}

vect2 operator*(int n,const vect2 &vect)
{
	return (vect2(n * vect.getV0(), n * vect.getV1()));
}

int vect2::getV0() const
{
	return (v[0]);
}

int vect2::getV1() const
{
	return (v[1]);
}

vect2 vect2::operator+() const
{
	return (vect2(+v[0], +v[1]));
}

vect2 vect2::operator-() const
{
	return (vect2(-v[0], -v[1]));
}