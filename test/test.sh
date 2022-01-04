#!/bin/bash
rm -f ../get_next_line.o main.o
rm -f test_gnl
make -C ../libft/ fclean && make -C ../libft/
gcc -g -Wall -Wextra -Werror -I ../libft -o ../get_next_line.o -c ../get_next_line.c
gcc -g -Wall -Wextra -Werror -I ../libft -o main.o -c main.c
gcc -g -o test_gnl main.o ../get_next_line.o -I ../libft -L ../libft/ -lft
rm -f ../get_next_line.o

echo "*----------------------*"
echo "*---READ FROM A FILE---*"
echo "*----------------------*"
echo "4 Characters:"
./test_gnl 4chars

echo "*----------------------*"
echo "8 Characters:"
./test_gnl 8chars

echo "*----------------------*"
echo "16 Characters:"
./test_gnl 16chars

echo "*----------------------*"
echo "*----- MIDDLE TEST ----*"
echo "*----------------------*"
echo "*---READ·FROM·STDOUT---*"
echo "*----------------------*"
echo "4·Characters :"
cat 4nl.txt | ./test_gnl

echo "*----------------------*"
echo "8 Characters:"
cat 8nl.txt | ./test_gnl

echo "*----------------------*"
echo "16·Characters:"
cat 16nl.txt | ./test_gnl

echo "*----------------------*"
echo "*---READ·FROM·A·FILE---*"
echo "*----------------------*"
echo "16·characters·1L:"
./test_gnl 16chars

echo "*----------------------*"
echo "16·character·2L:"
./test_gnl 16chars2

echo "*----------------------*"
echo "16·character· X L:"
./test_gnl 16chars40

echo "*----------------------*"
echo "*----·ADVANCED·TEST·---*"
echo "*----------------------*"

echo "*----------------------*"
echo "*---READ·FROM·STDOUT---*"
echo "*----------------------*"
echo "4·chacaracter·1L:"
cat 4chars | ./test_gnl

echo "*----------------------*"
echo "4·chacaracter·2L:"
cat 4chars2 | ./test_gnl

echo "*----------------------*"
echo "4·chacaracter··x·L:"
cat 4chars40 | ./test_gnl

echo "*----------------------*"
echo "*---READ·FROM·A·FILE---*"
echo "*----------------------*"
echo "4·chacaracter·1L:"
./test_gnl 4chars

echo "*----------------------*"
echo "4·chacaracter·2L:"
./test_gnl 4chars2


echo "*----------------------*"
echo "empty line:"
./test_gnl empty

echo "*----------------------*"
echo "4, 8 and 16 Charactere without \\n"
./test_gnl 4nl.txt
./test_gnl 8nl.txt
./test_gnl 16nl.txt

echo "*------------------------*"
echo "BIG FAT LINE"
./test_gnl bigfatline.txt

echo "*-------------------------*"
echo "MUTIPLE FILE DESCRIPTOR"
./test_gnl 4.txt 4nl.txt 8.txt 8nl.txt 16.txt
