#include <iostream>
#include "ra/random.hpp"

using lcg = ra::random::linear_congruential_generator;

int main()
{
	lcg::int_type i;
	lcg g(10, 10, 10);
	const lcg cg(10, 10, 10);
	const lcg cg2(10, 10, 10, 4);
	cg.multiplier();
	cg.increment();
	cg.modulus();
	cg.min();
	cg.max();
	cg.max();
	cg == cg;
	cg != cg;
	std::cout << cg << '\n';
	{
		auto g2 = g;
		g2 = std::move(g);
		g = g2;
		auto g3(g);
		auto g4(std::move(g3));
		g.seed(lcg::int_type(42));
		g();
		g.discard(100);
	}
	std:: cout << lcg::default_seed() << '\n';
}
