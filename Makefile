test:
	gcc -g -O0 minOperations.cpp -lstdc++
	./a.out
clean:
	rm *.out

.PHONY: test
