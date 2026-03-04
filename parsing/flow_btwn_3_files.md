# Push-Swap Parsing Flow

## Overview
when the ```push_swap``` recieves input from the command line, it passes through three files before any sorting begins. 
```Bash
main recieves argc/argv
		|
		|
		v
Pargse_arg.c - splits and converts to ints 
		|
		|
		v
Validation.c - Checks valid int, no dupes, no overflow
		|
		|
		v
inits_stack.c - pushes valid values onto stack_a
``` 
## File responsibility 
>```parse_arg.c```
- Splits arguments form ```argv```
- Converst Strings to integers (```"42" --> 42```)
- Handles the quoted string case (```"3 2 1"```) as a single argument

>```validation.c```
- Checks that each value is a valid integer
- Checks for duplicate values 
- Checks for integer overflow (min/max 32-bit int)
- Exits with ```"Error\n"``` if any check fails

>```init_stack.c```
- Takes the validated integers
- Creates nodes via ```ft_new_node```
- Pushes them ontp ```stack_a``` via ```ft_stack_push```.

## Input Formats 
! Both must work ! 
```Bash
./push_swap 3 2 1 	# Seperate Arguments
./push_Swap "3 2 1"	# Single quoted string
```
## Error Handling 
If inputs is invalud, write to ```stderr`` and ```exit```. 
```C
write(2, "Error\n", 6);
exit(1);
```
## Reasons to error: 
- Non-integer input (e.g ```"abc"```, ```"3.5"```)
- Duplicate Values
- Value exceeds ```INT_MAX``` or ```INT_MIN```
- No arguments provided 