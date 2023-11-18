CC =gcc -g -Wall -Werror -Wextra -std=c11 -D_GNU_SOURSE
OS = $(shell uname -s)
ifeq ($(OS), Linux)
UBU =  -lm -lpthread -lrt -lsubunit
else
UBU = 
endif
PATH_EXE=~/'Рабочий стол'/3D_Viewer

all:install

install:
	cd 3D_Viewer/ && mkdir build
	cd 3D_Viewer/build && cmake .. && make
	cd 3D_Viewer/build && cp -r 3D_Viewer $(PATH_EXE)
	rm -drf 3D_Viewer/build

uninstall:
	rm -rf $(PATH_EXE)

dvi:
	open README.md

dist: install
	tar -czf calk.tar.gz $(PATH_EXE)
	rm -rf $(PATH_EXE)

test:
	$(CC)  test.c calk.c -o test.out -lcheck $(UBU)
	./test.out
	
gcov_report:
	$(CC) --coverage test.c calk.c -o test.out -lcheck $(UBU)
	./test.out
	lcov -t "my_test" -c -d ./ --output-file ./test.info
	genhtml -o report test.info
	rm -rf *.gcda *.gch *.gcno *.out *.o *.out
	open report/index.html

clean:
	rm -rf *.o *.a *.out *.info report test.out.dSYM *.gcno

style:
	clang-format -i --style=Google *.c
	clang-format -n --style=Google *.c
