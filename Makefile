CC = cc
RM = rm -rf
AR = ar rcs
MKDIR = mkdir -p

IFLAGS = -I. -I ./incs
CFLAGS = -Wall -Werror -Wextra -fPIE

VPATH = srcs
SRCS = mem_utils.c mem_alloc.c mem_clean.c

OUT_DIR = build

OBJS_DIR = build/objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

NAME_DIR = build/libs
NAME = $(NAME_DIR)/libmem.a

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@ $(IFLAGS)

all: dir $(NAME)

dir:
	@if [ ! -d $(OBJS_DIR) ]; then \
		$(MKDIR) $(OBJS_DIR); \
	fi
	@if [ ! -d $(NAME_DIR) ]; then \
		$(MKDIR) $(NAME_DIR); \
	fi

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OUT_DIR)

re: fclean all

.PHONY: all clean fclean re dir
