#include <cstdint>
#include "Data.hpp"

class Serializer 
{
	private:
		Serializer();
		virtual ~Serializer() = 0;

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};
