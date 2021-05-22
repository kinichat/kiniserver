CC = gcc
CC_FLAGS = -Iinclude -Wall -Wextra -c
LD_FLAGS = -Iinclude -Llib -lmsgbox

CC_SRC = $(wildcard *.c)
CC_OBJ = $(CC_SRC:%.c = build/%.o)

KINI_BIN = build/kini

.PHONY: all prebuild clean

all: prebuild $(KINI_BIN)

$(KINI_BIN): $(CC_OBJ)
	@echo -e "LD\t$(KINI_BIN)"
	@$(CC) -o $(KINI_BIN) $(CC_OBJ) $(LD_FLAGS)

prebuild:
	@mkdir -p build

build/%.o: %.c
	@echo -e "CC\t$<"
	@$(CC) $(CC_FLAGS) -o $@ $<

clean:
	@echo -e "CLN\t$(KINI_BIN) $(CC_OBJ)"
	@rm -rf build

