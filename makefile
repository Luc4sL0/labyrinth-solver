PROJ_NAME=labyrinthGame
C_SOURCE=$(wildcard ./source/*.c)
H_SOURCE=$(wildcard ./source/*.h)
OBJ=$(subst .c,.o,$(subst source,objects,$(C_SOURCE)))

CC=gcc
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic

RM = rm -rf

all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Construindo o binário utilizando o linker GCC: $@'
	$(CC) $^ -o $@
	@ echo 'Operação concluída com êxito - STATUS 0: $@'
	@ echo ' '

./objects/%.o: ./source/%.c ./source/%.h
	@ echo 'Construindo target usando o compilador GCC: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./objects/main.o: ./source/main.c $(H_SOURCE)
	@ echo 'Construindo target usando o compilador GCC: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects

clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects

.PHONY: all clean