# BSQ
My solution for the 42 BSQ problem.

# What
The idea is to make a program that process and output the biggest square possible in the empty space of a given map. The program has to be as effective as possible. As the norme states, the only external functions used are `write`, `malloc`, `read` and `exit` from the `stdlib` and the `unistd` libraries, so the only requirement is a Unix system.

# Usage
## Running
`./bsq [<filename> <...>]`
If no files are supplied, the program will expect data from the standard input.
## Return code
`0` if the program was executed successfully.
`1` if an error occured.
`2` if a read error occured.
`3` if a malloc error occured.
