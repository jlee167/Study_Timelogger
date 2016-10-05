#include <iostream>
#include <fstream>


int contents[9] = {
 	22 * 3600,
	15 * 3600,
 	10 * 3600,
	15 * 3600,
 	5  * 3600,
	2 * 3600,
	6 * 3600,
	2 * 3600, 
	2 * 3600};
int main()
{
	std::ofstream myfile;
	myfile.open ("data.bin", std::ios::binary);
	myfile.write((char*)contents,40);
	myfile.close();
	return 0;
}
