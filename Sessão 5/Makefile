# ============================================================
#  Configurações do projeto
# ============================================================
TARGET   := bin/game
CC       := gcc

# Pastas
SRC_DIR  := lib
OBJ_DIR  := .obj
BIN_DIR  := bin

# Raylib
RAYLIB_DIR  := raylib
RAYLIB_INC  := $(RAYLIB_DIR)/include
RAYLIB_LIB  := $(RAYLIB_DIR)/lib

# ============================================================
#  Fontes e objetos
# ============================================================
SRCS := main.c $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# ============================================================
#  Flags
# ============================================================
CFLAGS  := -Wall -Wextra -I$(RAYLIB_INC) -Ilib
LDFLAGS := -L$(RAYLIB_LIB) -l:libraylib.a -lm

# Flags extras de plataforma
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	LDFLAGS += -ldl -lpthread -lGL -lrt -lX11
endif
ifeq ($(UNAME), Darwin)
	LDFLAGS += -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif

# ============================================================
#  Targets
# ============================================================
.PHONY: all run clean

all: $(TARGET)

## Linka o executável final
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo ">>> Build OK: $@"

## Compila main.c -> .obj/main.o
$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

## Compila lib/*.c -> .obj/lib/*.o
$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)/$(SRC_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ============================================================
#  Criação de pastas (order-only prerequisites)
# ============================================================
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/$(SRC_DIR):
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)

# ============================================================
#  run — compila e executa
# ============================================================
run: all
	./$(TARGET)

# ============================================================
#  clean — remove objetos e binário
# ============================================================
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo ">>> Limpo."