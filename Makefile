test:
	gcc -g -O0 MyCircularDeque.cpp -lstdc++
	./a.out
clean:
	rm *.out

.PHONY: test
