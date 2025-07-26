# Push swap test cases

This repository does not have all the test cases because you can just generate them on your own.
Some generation commands you can use are:

`seq 0 4 | xargs > sorted.txt && ARGS="$(cat sorted.txt)"; ./push_swap $ARGS`

`seq 0 4 | sort -rn | xargs > unsorted.txt && ARGS="$(cat unsorted.txt)"; ./push_swap $ARGS`

`seq -100 100 | shuf | head -n 100 | xargs > 100_unsorted.txt && ARGS="$(cat 100_unsorted.txt)"; ./push_swap $ARGS | ./checker_linux $ARGS`

`ARGS="$(cat 100_unsorted.txt)"; ./push_swap $ARGS | wc -l`

These are the test cases to faciliate evaluations for push swap. Remember to valgrind too. Remember to use the checker_linux. Not exhaustive... Idk what I have missed...

#### **No** output:
- **Only argv[0]**<br>
	`./push_swap`<br>
- **One number in argv[1]**<br>
	`./push_swap 42`<br>
	`./push_swap "42"`<br>
- List **already sorted**<br>
	`./push_swap 4 5 6`<br>
	`./push_swap "4 5 6"`<br>
#### **Error** output:
- **Empty string**<br>
	`./push_swap ""`<br>
	`./push_swap "" 5`<br>
	`./push_swap "" 5 -110`<br>
	`./push_swap 5 "" -110`<br>
- **Duplicates** in argument<br>
	`./push_swap 2 2 3 4`<br>
	`./push_swap "2 2 3 4"`<br>
- **Anything except numbers** in argument<br>
	`./push_swap A -3 4`<br>
	`./push_swap "A -3 4"`<br>
- **Decimals** in argument<br>
	`./push_swap 2 0.3 4`<br>
	`./push_swap "2 0.3 4"`<br>
- **Single quotes** instead of double quotes<br>
	`./push_swap '2 3 4 -2'`<br>
- **More than two signs** in a row<br>
	`./push_swap "2 3 4 +-2"`<br>
	`./push_swap "2 3 --4 -+2"`<br>
- **Addition or subtraction**<br>
	`./push_swap "-1 + 2"`<br>
	`./push_swap "21 - 3"`<br>
- **More than** INT MAX or **Less than** INT MIN<br>
	`./push_swap 2 3 -2147483649`<br>
	`./push_swap "2 3 2147483648"`<br>
#### Operation Moves output:
- **Extra spaces** at back or front within argv[1 and beyond]<br>
	`./push_swap "2 3    5      -10"`<br>
- **Spaces in front or back** within argv[1 and beyond]<br>
	`./push_swap "      2 3    5      -10"`<br>
- **With one space** at back or front within argv[1 and beyond]<br>
	`./push_swap "2 3 5 -10 "`<br>
- **Without space at end of double quotes**<br>
	`./push_swap "2 3 5 -10"`<br>
- **Negative Numbers**<br>
	`./push_swap "2 3 -5 -10"`<br>
- **Plus sign**<br>
	`./push_swap "2 3 -5 +10"`<br>
- INT MAX or INT MIN<br>
	`./push_swap 2 -2147483648 -10`<br>
	`./push_swap 2 2147483647 -10`<br>
- Test cases within **more than one set of Double quotes**<br>
	`./push_swap "2 3 -10 -5" "6 -7 -53"`<br>
	`./push_swap "string" "string"`<br>
- Another funny test case<br>
	`./push_swap "  2 3 -5 10 " 0 4 "15 -43"`<br>
	`./push_swap "string" args args "string"`<br>
- Another funny test case Part 2<br>
	`./push_swap 4"" -54`<br>
	`./push_swap 4 ""-54`<br>
	`./push_swap args"empty string" args`<br>

#### Count the number of operations executed by program
This is the binary code that 42 wants you to test with:<br>
`ARGS="$(cat output.txt)"; ./push_swap $ARGS`<br>
just add `| wc -l` to count the lines
`ARGS="$(cat output.txt)"; ./push_swap $ARGS | wc -l`<br>

#### What you cannot do with the binary:
`ARGS=4"" 5; ./push_swap $ARGS`<br>