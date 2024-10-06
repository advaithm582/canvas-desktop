CC:=gcc
CCS:=$(CC) -ansi -pedantic
LIBCANVAS_SRC:=src/libcanvas
BUILD_DIR:=build

$(BUILD_DIR)/libcanvas/*.o: $(LIBCANVAS_SRC)/*.c
	@echo "Build object files..."
	@mkdir -p build/libcanvas
	@for i in $^; do\
		j=$${i##*/};\
		j=$${j%.c};\
		$(CCS) -c -Wall -Werror -fpic $$i -o $(BUILD_DIR)/libcanvas/$$j.o;\
		done

libcanvas_build: $(BUILD_DIR)/libcanvas/*.o
	@echo "Build shared object..."
	@$(CC) -shared -o build/libcanvas.so $^

libcanvas_test_build: libcanvas_build
	@echo Build test executable...
	@$(CC) -ansi \
		-I$(CURDIR)/src/ $(shell pkg-config --cflags glib-2.0) -Wall \
		-o build/testlibcanvas $(wildcard test/libcanvas/*.c) \
		-L$(CURDIR)/build/ -lcanvas \
		 $(shell pkg-config --libs glib-2.0)

libcanvas_test: libcanvas_test_build
	@echo Run test executable...
	@LD_LIBRARY_PATH=$(CURDIR)/build/:$$LD_LIBRARY_PATH ./build/testlibcanvas\
		--verbose

libcanvas_test_machine: libcanvas_test_build
	@LD_LIBRARY_PATH=$(CURDIR)/build/:$$LD_LIBRARY_PATH ./build/testlibcanvas\
		--tap > build/test_output.txt

clean:
	@rm -r $(BUILD_DIR)/
