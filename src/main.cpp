#include <fstream>
#include <iostream>
#include <string>
struct copy_pasta {
	std::string file_name;	// file path + name
	int line = 0;		// line number
};
int main(int argc, char *argv[])
{
	switch (*argv[1]) {
		case 'o':  // open a copy pasta (to view)

			break;
		case 'a':  // add a copy pasta
			break;
		case 'd':  // remove a copy pasta
			break;
	}

	return 0;
}
