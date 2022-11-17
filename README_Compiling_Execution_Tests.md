# Compiling, executing and testing the DNA Profiler.

### Table of Contents
1. [Intro](#1-intro)
2. [Compiling](#2-compiling)
3. [Executing the code](#3-executing-the-code)
4. [Producing expected results](#4-producing-expected-results)

# 1. Intro
This is a file containing instructions for compiling, executing and testing the DNA Profiler.
	

# 2. Compiling
To compile the code, use "make". The flags should automatically be set. The executable is stored in the "bin/" folder.

To check for memory leaks, go to the Makefile file and remove the "-O" and "-g" flags from "override CXXFLAGS". Then, use "make clean", "make" and execute a search according to the instructions below. Better results will be found if executing a successful search (a search that results in a match). Instructions for doing that are further below.

# 3. Executing the code
To execute a search, use the syntax:
```
 	bin/dna_profiler -d <database_file> -s <dna_sequence_file>

 	Where the arguments are:
   	<database_file> The DNA database file
    	<dna_sequence_file> The DNA sequence file you wish to identify (find a match for).
```

To check for memory leaks, use the syntax:
```
	valgrind -v --leak-check=full --show-reachable=yes bin/dna_profiler -d <database_file> -s <dna_sequence_file>
```
Make sure to remove the "-O" and "-g" flags from Makefile before (re)compiling and executing.
 
## 3.1 Examples of correct syntax:
```
bin/dna_profiler -d data/data.csv -s data/sequence_alice.txt
bin/dna_profiler -d data/data.csv -s data/sequence_empty.txt
bin/dna_profiler -d data/empty.csv -s data/sequence_bob.txt
```

## 3.2 Examples of incorrect syntax:
```
bin/dna_profiler
bin/dna_profiler data.csv data/sequence_alice.txt
bin/dna_profiler -d data/data.csv
```

## 3.3 Examples of executions using valgrind:
```
valgrind -v --leak-check=full --show-reachable=yes bin/dna_profiler -d data/data.csv -s data/sequence_alice.txt
valgrind -v --leak-check=full --show-reachable=yes bin/dna_profiler -d data/data.csv -s data/sequence_charlie.txt
```

# 4. Producing expected results
Here, you will find instructions for producing certain results.
 
## 4.1 Successful searches

To produce a successful search, i.e, a search that results in a match, follow the instructions:
  * Set -d to "data/data.csv".
  * Set -s to any of the .txt files inside "data/" that start with "sequence_" and are followed by a given name.
    * For instance, the following file(s) should always result in the expected output:
      * data/sequence_alice.txt
      * data/sequence_bob.txt
      * data/sequence_charlie.txt


## 4.2 "No matches" searches

To produce a syntax-correct non-matching search, follow the instructions:
  * Set -s to any string-filled .txt file that doesn't follow a successful match naming pattern.
    * For instance, the following file(s) should always result in the expected output:
      * data/sequence_no_match.txt

## 4.3 "No data found" searches

Incorrect data (.csv) files or empty sequence (.txt) files will always produce a "no data found" message.
For instance, the following command(s) should always result in a "no data found" message:
 
```
bin/dna_profiler -d data/empty.csv -s data/sequence_alice.txt
bin/dna_profiler -d data/comma_case.csv -s data/sequence_bob.txt
bin/dna_profiler -d data/no_sequences.csv -s data/sequence_charlie.txt
bin/dna_profiler -d data/data.csv -s data/empty.txt
```