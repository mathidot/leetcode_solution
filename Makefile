test:
	gcc -g -O0 merge.cpp -lstdc++
	./a.out

.PHONY: test
