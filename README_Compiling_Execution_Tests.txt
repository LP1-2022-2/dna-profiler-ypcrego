## This is a file containing instructions for compiling, executing and testing the code.

## To compile the code, use "make". The flags should automatically be set. The executable is stored in the "bin/" folder. 

## To check for memory leaks, go to the Makefile file and remove the "-O" and "-g" flags from "override CXXFLAGS". Then, use "make clean", "make" and execute a search according to the instructions below. Better results will be found if executing a successful search (a search that results in a match). Instructions for doing that are further below.

## To execute a search, use the syntax:
	- bin/dna_profiler -d <database_file> -s <dna_sequence_file>
 	## Where the arguments are:
    ## <database_file> The DNA database file
    ## <dna_sequence_file> The DNA sequence file you wish to identify (find a match for).

## To check for memory leaks, use the syntax:
	- valgrind -v --leak-check=full --show-reachable=yes bin/dna_profiler -d <database_file> -s <dna_sequence_file>
	## Make sure to remove the "-O" and "-g" flags from Makefile before (re)compiling and executing.
	
## Examples of correct syntax:
	- bin/dna_profiler -d data/data.csv -s data/sequence_alice.txt
	- bin/dna_profiler -d data/data.csv -s data/sequence_empty.txt
	- bin/dna_profiler -d data/empty.csv -s data/sequence_bob.txt

## Examples of incorrect syntax:
	- bin/dna_profiler
	- bin/dna_profiler data.csv data/sequence_alice.txt
	- bin/dna_profiler -d data/data.csv

## Examples of executions using valgrind:
	- valgrind -v --leak-check=full --show-reachable=yes bin/dna_profiler -d data/data.csv -s data/sequence_alice.txt
	- valgrind -v --leak-check=full --show-reachable=yes bin/dna_profiler -d data/data.csv -s data/sequence_charlie.txt


## To produce a successful search, i.e, a search that results in a match, follow the instructions:
	- Set -d to "data/data.csv".
	- Set -s to any of the .txt files inside "data/" that start with "sequence_" and are followed by a given name.
		- For instance, the following file(s) should always result in the expected output: "data/sequence_alice.txt", "data/sequence_bob.txt", "data/sequence_charlie.txt".
	## The result should always produce a successful match.

## To produce a syntax-correct non-matching search, follow the instructions:
	- Set -s to any string-filled .txt file that doesn't follow a successful match naming pattern.
		- For instance, the following file(s) should always result in the expected output: "data/sequence_no_match.txt".

## Incorrect data (.csv) files or empty sequence (.txt) files will always produce a "no data found" message.
	- For instance, the following command(s) should always result in a "no data found" message:
		- bin/dna_profiler -d data/empty.csv -s data/sequence_alice.txt
		- bin/dna_profiler -d data/comma_case.csv -s data/sequence_bob.txt
		- bin/dna_profiler -d data/no_sequences.csv -s data/sequence_charlie.txt
		- bin/dna_profiler -d data/data.csv -s data/empty.txt

## End of file.