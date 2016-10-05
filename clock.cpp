#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int class_index;

	if (argc != 2)
	{
		std::cout << "Invalid Class Name!\n";
		return 0;
	}

	else
	{
		if (strcmp(argv[1],"ECE425") == 0)
				class_index = 0;
		else if (strcmp(argv[1],"ECE329") == 0 )
                                class_index = 1;
                else if (strcmp(argv[1],"ECE462") == 0)
                                class_index = 2;
                else if (strcmp(argv[1],"CS431") == 0)
                                class_index = 3;
                else if (strcmp(argv[1],"DUTCH") == 0)
                                class_index = 4;
		else if (strcmp(argv[1],"C/C++") == 0)
				class_index = 5;
                else if (strcmp(argv[1],"LINUX") == 0)
                                class_index = 6;
                else if (strcmp(argv[1],"TCL/PERL") == 0)
                                class_index = 7;
                else if (strcmp(argv[1],"JAVA") == 0)
                                class_index = 8;
		else
		{ std::cout << "Invalid Class Name!\n";
		  return 0;                            }

	}

	char* course_name[9] = {"ECE425", "ECE329","ECE462","CS431","DUTCH","C/C++",
				"LINUX","TCL/PERL","JAVA"};	

	int *memblock = new int[9];
	std::ifstream file("data.bin", std::ios::binary);
	if (file.is_open())
	{
		for (int i = 0; i < 9; i++)
			file.read((char*)&memblock[i],4);
	}
	for (int i = 0; i < 9; i++)
		std::cout << course_name[i] << '\t' << 
		(int)(memblock[i]/3600) <<" : " <<
		(int)((memblock[i]%3600)/60) << " : " << 
		(int)(memblock[i]%60) << '\n';

	time_t begin, end, result;
	time(&begin);
	std::cout << begin << '\n';

	char command[20] = "";
	while ( strcmp(command,"quit") != 0 )
	{
		command == "";
		std::cout << "Enter Command:";
		std::cin >> command;
		std::cout << '\n';
	}


	time(&end);
	result = end - begin;
	std::cout << result << '\n';	
	if (memblock[class_index] - int(result) < 0) 
		memblock[class_index] = 0;
	else
		memblock[class_index] -= int(result);

	        for (int i = 0; i < 9; i++)
                std::cout << course_name[i] << '\t' << 
                (int)(memblock[i]/3600) <<" : " <<
                (int)((memblock[i]%3600)/60) << " : " << 
                (int)(memblock[i]%60) << '\n';

	std::ofstream myfile;
        myfile.open ("data.bin", std::ios::binary);
        myfile.write((char*)memblock,40);

	file.close();
	myfile.close();


	return 0;
}
