CC = gcc

TARGET = main
MAIN = $(addsuffix .o, $(TARGET))
OBJ = Pilha.o Matriz.o Menu.o $(MAIN)


.PHONY: all clean

all: $(TARGET) clean

ifeq ($(OS), Windows_NT)
clean:
	del $(OBJ)	
else
clean:
	rm -rf $(OBJ)
endif

$(OBJ) : %.o : %.c
	$(CC) -c $< -o $@


$(TARGET): % : $(OBJ)
	$(CC) $(OBJ) -o $@