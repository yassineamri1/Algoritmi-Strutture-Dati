CFLAG		= -g -Wall -Wextra -Wpedantic -Wconversion
INCLUDE_PATH	= lib
COMMON_DEPS	= $(INCLUDE_PATH)/*.h Makefile

all: sort hybrid_sort

obj/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) -c $< -o $@

matrix_test: src/matrix_test.c obj/matrix.o obj/unity.o  $(COMMON_DEPS)
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) src/matrix_test.c  obj/matrix.o obj/unity.o -o bin/$@
	./bin/matrix_test

edit_distance_test: src/edit_distance_test.c obj/unity.o  obj/edit_distance.o obj/matrix.o $(COMMON_DEPS)
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) src/edit_distance_test.c obj/matrix.o obj/edit_distance.o obj/unity.o -o bin/$@
	./bin/edit_distance_test

edit_distance_dyn_test: src/edit_distance_dyn_test.c obj/unity.o  obj/edit_distance.o obj/matrix.o $(COMMON_DEPS)
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) src/edit_distance_dyn_test.c obj/matrix.o obj/edit_distance.o obj/unity.o -o bin/$@
	./bin/edit_distance_dyn_test

implementation: src/implementation.c obj/edit_distance.o obj/matrix.o $(COMMON_DEPS)
	$(CC) $(CFLAG) -I$(INCLUDE_PATH) src/implementation.c obj/matrix.o obj/edit_distance.o -o bin/$@
	./bin/implementation

clean:
	$(RM) obj/*.o
	$(RM) bin/*
			
