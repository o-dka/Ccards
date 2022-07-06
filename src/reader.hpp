#pragma once
#include <fstream>
#include <iostream>
#include <string>
class reader {
    public:
	std::string filename = "./files/list.txt";
	reader();
	std::string find();
	void read(std::string);
};
