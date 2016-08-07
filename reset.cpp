#include <iostream>
#include <fstream>


int contents[9] = {
	20 * 3600,
 	12 * 3600,
	10 * 3600,
 	10 * 3600,
 	10 * 3600,
 	5  * 3600,
	3 * 3600,
	7 * 3600,
	3 * 3600 };
int main()
{
	std::ofstream myfile;
	myfile.open ("data.bin", std::ios::binary);
	myfile.write((char*)contents,36);
	myfile.close();
	return 0;
}
