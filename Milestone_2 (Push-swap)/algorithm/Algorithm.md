# Push-Swap Architecture Overview 
*This porject has been created as part of the 42-Cirriculum by kmurhced* 

## The Big picture
```Bash
./push_swap 3 1 2 5 4
	|
	|
	v
	main.c
	|
	|
	v
	init_stack.c ------> ft_stack_init (/stack_utilis.c)
	|
	v
  ┌────────────────────────┐
  │  ft_is_valid_int       │  "abc" → Error
  │  ft_is_overflow        │  "2147483648" → Error
  │  ft_is_duplicate       │  "3 1 3" → Error
  └────────────────────────┘
	|
	|
	v	(Valid input)
	ft_pus_stack x N
	|
	|
	v
	algorithm/
	|
	v
	stdout: pa, pb, ra, rra... etc
```
## File by file 

### `source/main.c` 
**Job:** Entry point, OWns nothing, delegates everything. 
```Bash
Main(argc, argv)
	-> init both stacks
	-> init_stack(parse + fill stack_a)
	-> run algorthim 
	-> free everything 
	-> return 
```
### `parsing/parse_init.c`
**Job:** Bridge between main and parsing.
```Bash
init_stack(stack_a, argc, argv)
	-> ft_stack_init(stack_a) 	// clean initialisation
	-> parse_args(...) 			// Fill clean slate
```
- Main doesn't need to know HOW the stack gets built. 

### `parse/parse_valid.c`
***Job:*** Split, Validate and push input to stack_a.
```Bash
parse_args (Decides which path to take)

--> Parse_split-> ..validates...-> pushes to stack 
or 
--> Parse_each-> ... validates..-> pushes to stack.
```
### Validation Chain:
```
"abc"        → ft_is_valid_int → 0 → Error
"2147483648" → ft_is_overflow  → 1 → Error  
"3 1 3"      → ft_is_duplicate → 1 → Error
"42"         → all pass        → push ✅
```
### `utilis/list_utils.c`
***Job:*** Node lifecycle - The Creator & Destroyer
```bash
ft_new_node(value)
	malloc-> set value -> set next = NULL -> return node 

ft_free_node (node)
	-> if node then free(node)
```
### `utilis/stack_utils.c`
***Job:*** Stack operations: Push, Pop, Init..
```Bash
ft_stack_init:         ft_stack_push(42):      ft_stack_pop:
top → NULL             top → [42] → NULL       saves value + next
bottom → NULL          bottom → [42]           frees top
size = 0               size = 1                top = next
                                               size--
```
### Push onto exisitng stack:
```Bash
Before: top -> [3] -> [1] -> NULL
Push 5: top-> [5] -> [3] -> [1] -> NULL
```

### `utilis/error_free.c`
***Job:*** Handles errors and free memory
```Bash
ft_error()
	->writes "Error" message
	->exit(1)
```

### `Operations/pa_pb.c`
***Job:*** Moves top element between stacks a/b.
```Bash
pb:  stack_a → stack_b          pa:  stack_b → stack_a
Before:                         Before:
a: [5][3][1]  b: empty          a: [3][1]  b: [5]

After:                          After:
a: [3][1]     b: [5]            a: [5][3][1]  b: empty
```

### `Operations/sa_sb.c`
**Job:*** Swap top two elements 
```Bash
sa:
Before: top → [3] → [1] → [2] → NULL
After:  top → [1] → [3] → [2] → NULL
(only values swap, not nodes)
```

### `Operations/ra_rb_rrr.c`
***Job:*** Rotate - top goes to bottom
```Bash
ra:
Before: top → [3] → [1] → [2] → NULL
After:  top → [1] → [2] → [3] → NULL
                              ↑
                           bottom
```
### `Operations/rra_rrb_rrr.c`
***Job:*** Reverse Rotate - Bottom element becomes top.
```Bash
rra:
Before: top → [1] → [2] → [3] → NULL
After:  top → [3] → [1] → [2] → NULL
```

### 'Algortihm/sort_small.c`
**Job:** Optimally sorts 2-3 elements in stack.
```Bash
sort_two:	[2][1] -> sa -> [1][2]

sort_three: 6 possible states, max 2 operations
[1][2][3] -> Nothing 
[2][1][3] -> sa
[3][1][2] -> sa -> rra
[1][3][2] -> sa -> ra
[3][1][2] -> ra
[2][3][1] -> ra
.... 
```

### `Algorithm/cost_calc.c`
**Job:** Main backbone of the sorting algorthim. Calculates how many moves each node in b needs to reach it's target position in a.

```Bash
cost = moves to rotate b (to bring node to top)
	+ moves to rotate a (to bring target to top)
	(using rr/rrr when both rotate same direction)
```

### `Algortihm/target_position.c`
***Job:*** Tracks position of the node that needs to be inserted in either stack-a or stack_b.
```Bash
For node with value V in b:
	Find the largest value in 'a' that is still smaller than 'V'
	That node's position is that target

	If no such value exists -> Target is maximum in 'a'
```

## Data Flow Summary

```Bash
argv
  ↓ parse_valid.c (validate + convert)
stack_a (unsorted linked list)
  ↓ algorithm/
stdout (sequence of operations: sa, pb, ra...)
  ↓ checker
"OK" or "KO"
```
## Memeory Map

```Bash
t_stack:                    t_node:
┌─────────┐                ┌─────────┬──────┐
│ top  ●──┼──→ [val|next]──→[val|next]──→NULL
│ bottom●─┼──────────────────────────↑
│ size: N │
└─────────┘
```
> Every `ft_new_node` -> one `malloc` Every `ft_free_node`->one `free` All nodes freed before `exit`. 

















