#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <vector>

class vect2
{
	private:
		std::vector<int> v;
	public:
		vect2(int a, int b);
		vect2();
		~vect2();
		vect2 &operator=(const vect2 &other);
		int &operator[](unsigned int nb);
		const int &operator[](unsigned int nb) const;
		vect2 operator*(int n) const;
		vect2 operator*(const vect2 &other) const;
		vect2 operator+(int n) const;
		vect2 operator-(int n) const;
		vect2 operator+(const vect2 &other) const;
		vect2 operator-(const vect2 &other) const;
		vect2 &operator+=(const vect2 &other);
		vect2 &operator+=(int n);
		vect2 &operator-=(const vect2 &other);
		vect2 &operator-=(int n);
		vect2 &operator*=(const vect2 &other);
		vect2 &operator*=(int n);
		vect2 operator++(int n);
		vect2 &operator++();
		vect2 operator--(int n);
		vect2 &operator--();
		bool operator==(const vect2 &other) const;
		bool operator!=(const vect2 &other) const;
		vect2 operator+() const;
		vect2 operator-() const;
		int getV0()const;
		int getV1()const;
};
vect2 operator*(int n, const vect2 &v);
vect2 operator+(int n, const vect2 &v);
vect2 operator-(int n, const vect2 &v);
std::ostream &operator<<(std::ostream &os, const vect2 &v);
#endif