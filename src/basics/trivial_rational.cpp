#include <iostream>
#include "ra/rational.hpp"

template <class T>
void do_test()
{
	namespace rm = ra::math;

	{
		typename rm::rational<T>::int_type i;
	}
	{
		rm::rational<T> a;
		rm::rational<T> b(1);
		rm::rational<T> c(1, 2);
	}

	{
		const rm::rational<T> c;
		rm::rational<T> a(c);
		rm::rational<T> b;
		b = a;
	}

	{
		rm::rational<T> a;
		rm::rational<T> b(std::move(a));
		a = std::move(b);
	}

	{
		const rm::rational<T> c;
		c.numerator();
		c.denominator();
		c.truncate();
		c.is_integer();
		!c;
		c == c;
		c != c;
		c < c;
		c > c;
		c <= c;
		c >= c;
	}

	{
		rm::rational<T> a(1);
		const rm::rational<T> c(1, 2);
		a += c;
		a -= c;
		a *= c;
		a /= c;
		++a;
		a++;
		--a;
		a--;
		+c;
		-c;
		c + c;
		c - c;
		c * c;
		c / c;
		std::cout << c << '\n';
		std::cin >> a;
	}
	{
		rm::rational<T> a(1);
		rm::rational<T> b(1);
		rm::rational<T> c(1);
		a += b += c;
		a *= b *= c;
		a -= b -= c;
		a /= b /= c;
		a = b = c;
		++++a;
		----a;
	}

	{
	}

}

int main()
{
	do_test<short int>();
	do_test<int>();
	do_test<long>();
	do_test<long long>();
}
