test:
	gcc -g -O0 numSubarrayProductLessThanK.cpp -lstdc++
	./a.out
clean:
	rm *.out

.PHONY: test
