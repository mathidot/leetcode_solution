test:
	gcc -g -O0 FrontMiddleBackQueue.cpp -lstdc++
	./a.out
clean:
	rm *.out

.PHONY: test
