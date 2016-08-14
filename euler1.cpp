// euler1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cassert>
#include <iostream>
using namespace std;
unsigned long long sum_multiples_of_n(unsigned int n, unsigned int upto)
{
	assert(n > 0);
	if (upto <= n)return 0;
	if (upto == n+1)return n;
	unsigned long long howmanymultiples = (upto-1) / n;
	return n*howmanymultiples*(howmanymultiples + 1) / 2;
}
unsigned int greatest_common_divisor(unsigned int n1, unsigned int n2)
{
	assert(n1 > 0 && n2 > 0);
	if (n1 == n2)return n1;
	if (n1 > n2)return greatest_common_divisor(n2, n1);
	if (n1 == 1)return n2;
	unsigned int remainder;
	while (n2 != 0)
	{
		remainder = n1%n2;
		n1 = n2;
		n2 = remainder;
	}
	return n1;
}
unsigned long long sumofmultiples(unsigned int m, unsigned int n, unsigned int limit)
{
	assert(m > 0 && n > 0);
	assert(m <= limit && n <= limit);
	if (n < m)
	{
		unsigned int temp = m;
		m = n;
		n = temp;
	}
	unsigned long long sumofmultiplesofn = sum_multiples_of_n(n, limit);
	if (n%m == 0)return sumofmultiplesofn;
	unsigned int greatest_common_div = greatest_common_divisor(m, n);
	unsigned long long result = sum_multiples_of_n(m, limit) + sumofmultiplesofn;
	if(m*n / greatest_common_div<limit)result -= sum_multiples_of_n(m*n / greatest_common_div, limit);
	return result;
}
int main()
{
	unsigned int n1(3), n2(5);
	unsigned int limit = 1000;
	cout << sumofmultiples(n1, n2, limit) << endl;
    return 0;
}

