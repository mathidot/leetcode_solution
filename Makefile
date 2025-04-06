test:
	gcc -g -O0 NumMatrix.cpp -lstdc++
	./a.out
clean:
	rm *.out

.PHONY: test
