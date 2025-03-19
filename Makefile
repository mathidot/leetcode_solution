test:
	gcc -g -O3 array.cpp -lstdc++
	./a.out

.PHONY: test