#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>


int main( void )
{
	using namespace boost::interprocess;
	shared_memory_object shm(create_only,"shared_memory", read_write);
	shm.truncate(1000);
	mapped_region region(shm, read_write);
	std::memset(region.get_address(), 1, region.get_size());
	char *mem = static_cast<char*>(region.get_address());
	*mem = 0x48;
    *(mem+1) = 0x45;
	*(mem+2) = 0x4C;
	*(mem+3) = 0x4C;
	*(mem+4) = 0x4F;
	*((float *)mem+5) = 0.1;
	std::cin.get();
	shared_memory_object::remove("shared_memory");

	return 0;
}
