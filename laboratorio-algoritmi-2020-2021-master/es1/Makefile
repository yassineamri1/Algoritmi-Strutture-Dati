CFLAG		= -g -Wall -Wextra -Wpedantic -Wconversion
INCLUDE_PATH	= lib
COMMON_DEPS	= $(INCLUDE_PATH)/*.h Makefile

all: sort hybrid_sort

obj/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) -c $< -o $@

sort: obj/sort.o obj/utility.o

utility_test: obj/utility_test.o obj/utility.o obj/unity.o $(COMMON_DEPS)
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) obj/utility_test.o obj/utility.o obj/unity.o -o bin/$@
	./bin/utility_test

sort_test: obj/sort_test.o obj/sort.o obj/unity.o obj/utility.o $(COMMON_DEPS)
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) obj/sort_test.o obj/sort.o obj/unity.o obj/utility.o -o bin/$@
	./bin/sort_test

arrgen_test: src/arrgen_test.c obj/arrgen.o obj/unity.o  $(COMMON_DEPS)
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) src/arrgen_test.c  obj/arrgen.o obj/unity.o -o bin/$@
	./bin/arrgen_test

implementation: src/implementation.c obj/sort.o obj/utility.o
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) src/implementation.c obj/sort.o obj/utility.o -o bin/$@
	./bin/implementation

clean:
	$(RM) obj/*.o
	$(RM) bin/*
			
