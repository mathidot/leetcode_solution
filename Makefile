test:
	gcc -g -O0 codeAndDecode.cpp -lstdc++
	./a.out
clean:
	rm *.out

.PHONY: test
