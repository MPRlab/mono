#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>



int main( void )
{
	using namespace boost::interprocess;
	shared_memory_object shm(open_only, "shared_memory", read_only);
	mapped_region region(shm, read_only);
	char *mem = static_cast<char*>(region.get_address());
	printf("%c", *mem);
	printf("%c", *(mem+1));
	printf("%c", *(mem+2));
	printf("%c", *(mem+3));
	printf("%c\n", *(mem+4));
	printf("%f\n", *((float * )mem+5));
	std::cout << sizeof(int) << std::endl;
	return 0;
}
