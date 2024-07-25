#include <iostream>
#include "iter.hpp"

int main()
{
	char charArr[5] = {'a', 'b', 'c', 'd', '\0'};
	float floatArr[5] = {0.5f, 1.0f, 2.0f, 3.0f};

	::iter(charArr, 5, ::print<char>);
	::iter(floatArr, 5, ::print<float>);

	return 0;
}
