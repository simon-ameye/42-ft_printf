cd ..
make
gcc -c test.c -I includes
gcc -o test test.o libftprintf.a
./test
rm -rf test test.o