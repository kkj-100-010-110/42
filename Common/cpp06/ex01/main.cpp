#include "data.hpp"

uintptr_t serialize(Data *d)
{
	return reinterpret_cast<uintptr_t>(d);
}

Data* deserialize(uintptr_t p)
{
	return reinterpret_cast<Data*>(p);
}

int main()
{
	Data *d = new Data;
	uintptr_t cast;

	cast = serialize(d);

	d->name = "gyeokim";
	d->day = 2;

	std::cout << "data address" << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;
	std::cout << "serialized uintptr_t" << std::endl;
	std::cout << std::hex << cast << std::endl;
	std::cout << std::endl;
	std::cout << "data value" << std::endl;
	std::cout << "Name: " << d->name << std::endl;
	std::cout << "Day: " << d->day << std::endl;
	std::cout << std::endl;
	std::cout << "deserialized uintptr_t data value" << std::endl;
	std::cout << "Name: " << deserialize(cast)->name << std::endl;
	std::cout << "Day: " << deserialize(cast)->day << std::endl;

	delete d;
	
	return 0;
}
