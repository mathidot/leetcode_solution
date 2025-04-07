test:
	gcc -g -O0 lengthLongestPath.cpp -lstdc++
	./a.out
clean:
	rm *.out

.PHONY: test
