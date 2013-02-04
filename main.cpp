#include <string>
#include <iostream>

using namespace std;

string parse_args(char*);

int main(int argc, char* argv[]) {
	// Check program has one arguement
	if (argc != 2)
		return -1;

	string string_to_invert = parse_args(argv[1]);
}

string parse_args(char* argv) {
	string arguement = argv;
	return arguement;	
}
