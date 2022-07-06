#include "reader.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
reader::reader() { std::ifstream file(filename); }

std::string find(filename, line_number)
{
	int curr_line = 0;
	while (!file.eof() || curr_line != line_number) curr_line++;

	return getline(file, line_cont, '|');
}
void read(line_cont)
{
	const char *msg = "cat" + line_cont;
	std::system(msg);
}
