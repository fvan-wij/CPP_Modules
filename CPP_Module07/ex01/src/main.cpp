#include <iostream>
#include "iter.hpp"

int main()
{
	char charArr[6] = {'a', 'b', 'c', 'd', '1', '\0'};
	float floatArr[5] = {0.5f, 1.0f, 2.0f, 3.0f};
	int intArr[5] = {0, 1, 2, 3};

	::iter(charArr, 5, ::print<char>);
	::iter(floatArr, 5, ::print<float>);
	::iter(intArr, 5, ::is_digit<int>);
	::iter(charArr, 5, ::is_digit<char>);

	return 0;
}
