This directory will be home to all files required for successful creation of the monty Program:

(*)	USAGE: monty file
	->	where 'file' is the path to the file containing Monty byte code

(*)	If the user does not give any file or more than one argument to the program, print the error message;
<USAGE: monty file>
...followed by a new line, and exit with the status EXIT_FAILURE

(*)	If, for any reason, it’s not possible to open the file, print the error message;
<Error: Can't open file <file>>
...followed by a new line, and exit with the status EXIT_FAILURE
	->	where <file> is the name of the file

(*)	If the file contains an invalid instruction, print the error message;
<L<line_number>: unknown instruction <opcode>>
...followed by a new line, and exit with the status EXIT_FAILURE
	->	where <line_number> is the line number where the instruction appears.
	->	Line numbers always start at 1

(*)	The monty program runs the bytecodes line by line and stop if either:
	->	it executed every line of the file
	->	it finds an error in the file
	->	an error occured
	
(*)	If the monty program can’t malloc anymore, print the error message:
<Error: malloc failed>
...followed by a new line, and exit with status EXIT_FAILURE.

(*)	The Monty Program has to use malloc and free and is not allowed to use any other function from man malloc (realloc, calloc, …)