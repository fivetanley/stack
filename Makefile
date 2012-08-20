all:
	@rm -rf build; mkdir -p build
	cd build; cmake ../
	cd build; make
	./build/stack-test

.PHONY: all
