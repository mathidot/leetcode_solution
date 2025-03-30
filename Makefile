test:
	gcc -g -O0 checkInclusion.cpp -lstdc++
	./a.out

.PHONY: test
