/*
	Copyright Nathan Hughes 2015

    This file is part of code developed for the Music Perception and Robotics 
	Labrotory at Worcester Polytechnic Institute.

    This file is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    somewhere in this repository.  If not, see <http://www.gnu.org/licenses/>.
*/


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
