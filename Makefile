NAME=
CFLAGS=
INCLUDE=
SRCS=

OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@echo "Making executable: "$@
	@$(CC) $^ -o build/$@

%.o : %.c
	@echo "Compiling: "$<
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean

clean:
	@rm -f src/*.o $(NAME)
	@echo "Removed object files and executable..."

