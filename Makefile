test:
	gcc -g -O0 simplifyPath.cpp -lstdc++
	./a.out
clean:
	rm *.out

.PHONY: test
