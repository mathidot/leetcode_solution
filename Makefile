test:
	gcc -g -O0 buildTree.cpp -lstdc++
	./a.out
clean:
	rm *.out

.PHONY: test
