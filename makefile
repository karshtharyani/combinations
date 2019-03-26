combine: combine.cpp
	g++ combine.cpp -o combine && ./combine

clean:
	rm -rf *.o

.PHONY: clean
