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
