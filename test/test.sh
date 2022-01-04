#!/bin/bash
rm -f ../get_next_line.o main.o
rm -f test_gnl
make -C ../libft/ fclean && make -C ../libft/
gcc -g -Wall -Wextra -Werror -I ../libft/includes -o ../get_next_line.o -c ../get_next_line.c
gcc -g -Wall -Wextra -Werror -I ../libft/includes -o main.o -c main.c
gcc -g -o test_gnl main.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft
rm -f ../get_next_line.o

echo "*----------------------*"
echo "*---READ FROM A FILE---*"
echo "*----------------------*"
echo "4 Characters:"
./test_gnl 4chars.txt

echo "*----------------------*"
echo "8 Characters:"
./test_gnl 8chars.txt

echo "*----------------------*"
echo "16 Characters:"
./test_gnl 16chars.txt

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
./test_gnl 16chars.txt

echo "*----------------------*"
echo "16·character·2L:"
./test_gnl 16chars2.txt

echo "*----------------------*"
echo "16·character· X L:"
./test_gnl 16chars40.txt

echo "*----------------------*"
echo "*----·ADVANCED·TEST·---*"
echo "*----------------------*"

echo "*----------------------*"
echo "*---READ·FROM·STDOUT---*"
echo "*----------------------*"
echo "4·chacaracter·1L:"
cat 4chars.txt | ./test_gnl

echo "*----------------------*"
echo "4·chacaracter·2L:"
cat advancedtest4c2L.txt | ./test_gnl

echo "*----------------------*"
echo "4·chacaracter··x·L:"
cat 4chars40.txt | ./test_gnl

echo "*----------------------*"
echo "*---READ·FROM·A·FILE---*"
echo "*----------------------*"
echo "4·chacaracter·1L:"
./test_gnl 4chars.txt

echo "*----------------------*"
echo "4·chacaracter·2L:"
./test_gnl 4chars2.txt


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
