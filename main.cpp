#include <string>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

/*
 * Constraint 1: Each process can output at most one character. If you want to output more
 * than a single character, you must fork one or more processes in order to do that, and
 * each of the forked processes in turn outputs a single character.
 *
 * Constraint 2: Each process can fork at most one other process.
 */

string parse_args(int, char*[]);

int main(int argc, char* argv[]) {
	string string_to_invert = parse_args(argc, argv);

	if (string_to_invert == "") {
		return 1;
	}

	pid_t child_process = 0;
	int index;

	for (index = 0; index <= string_to_invert.length() - 1; index++) {
		child_process = fork();
		
		if (child_process == (pid_t) 0) {
			// This process is a child process
			// Print the end char - index
			cerr << string_to_invert[string_to_invert.length() - 1 - index];
			continue; // Skip to the next for-loop iteration
		}
		else {
			// Process is parent process, do nothing
			break;
		}
	}
	// Wait for the child process to finish
	wait(NULL);
}

string parse_args(int argc, char* argv[]) {
	// Check program has one and only 1 arguement
	if (argc != 2) {
		cerr << "Incorrect program usage" << endl;
		return "";	
	}

	string arguement = argv[1];
	return arguement;	
}
