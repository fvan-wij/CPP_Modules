#include "Serializer.hpp"
#include <iostream>

bool	testSerializeToDeserialize() {
	Data *test = new Data;

	if (Serializer::deserialize(Serializer::serialize(test)) == test) {
		std::cout << "(testSerializeToDeserialize) return val: " << Serializer::deserialize(Serializer::serialize(test)) << std::endl;
		std::cout << "(testSerializeToDeserialize) test: " << test << std::endl;
		delete test;
		return true;
	}
	return false;
}

void	testPrintAddresses() {
	Data*	a = new Data;

	uintptr_t p = Serializer::serialize(a);
	Data*	döppelganger = Serializer::deserialize(p);
	std::cout << "Address a: \t\t\t\t" << a << std::endl;
	std::cout << "Value of p (a serialized): \t\t" << "0x" << std::hex << p << std::endl;
	std::cout << "p deserialized as döppelganger: \t" << döppelganger << std::endl;
	std::cout << std::endl;
	delete a;
}

int main() {
	testPrintAddresses();
	if (testSerializeToDeserialize())
		std::cout << "The return value of serialize(Data) passed to deserialize() is equal to the original pointer" << std::endl;
	else
		std::cout << "The return value of serialize(Data) passed to deserialize() is NOT equal to the original pointer" << std::endl;
	return 0;
}
