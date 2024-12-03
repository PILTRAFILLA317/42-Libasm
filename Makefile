# Variables
AS = nasm
AR = ar
FLAGS = -f elf64 
LIB = libasm.a
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s
MAIN = main.s            # Archivo principal
CMAIN = main.c           # Archivo principal en C
MAIN_OBJS = $(MAIN:.s=.o)  # Objeto principal
OBJS = $(SRCS:.s=.o)       # Objetos de la librería
OUTPUT = test          # Nombre del ejecutable en C

test: all $(OUTPUT)

$(OUTPUT): $(CMAIN) $(LIB)
	gcc -fsanitize=address -g3 -o $@ $< $(LIB)

# Regla para compilar el archivo principal
$(MAIN_OBJS): $(MAIN)
	$(AS) $(FLAGS) -o $@ $<

# Regla principal para crear la librería
all: $(LIB)

# Crear la librería estática
$(LIB): $(OBJS)
	$(AR) rcs $@ $^

# Compilar los archivos de la librería a objetos
%.o: %.s
	$(AS) $(FLAGS) -o $@ $<

# Limpiar archivos intermedios
clean:
	rm -f $(MAIN_OBJS) $(OBJS)

# Limpiar todo
fclean: clean
	rm -f $(LIB) $(OUTPUT)
