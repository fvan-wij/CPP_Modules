#include <iostream>
#include "Base.hpp"
#include "DerivedA.hpp"
#include "DerivedB.hpp"
#include "DerivedC.hpp"

int main() {
	Base *pointer = generate();
	Base &reference = *pointer;
	identify(pointer);
	identify(reference);
	delete pointer;
	return 0;
}
