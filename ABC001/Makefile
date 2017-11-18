all:

gtest-gen:
	python ../../googletest/googletest/scripts/fuse_gtest_files.py ./

b:
	gcc -c B.c
	g++ testb.cpp ../../googletest/googletest/src/gtest_main.cc gtest/gtest-all.cc -I. -lpthread B.o
	./a.out

clean:
	rm -rf B.o
