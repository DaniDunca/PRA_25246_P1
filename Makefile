bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

