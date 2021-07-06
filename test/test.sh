cd /Users/speedhacker/temp/printf
make
gcc -c -Wall -Wextra -Werror test/test.c -I libft/ -o test/test.o
gcc -o test/test test/test.o libftprintf.a
./test/test
rm -rf test/test test/test.o