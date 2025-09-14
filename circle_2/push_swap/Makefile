NAME			=		push_swap
BONUS			=		checker
CC				=		cc
CFLAGS			=		-Wall -Wextra -Werror
PRINTF_DIR		=		lib/ft_printf
PRINTF_ARC		=		lib/ft_printf/libftprintf.a

LIBFT_DIR		=		./lib/libft
LIBFT_ARC		=		./lib/libft/libft.a

PUSH_SWAP		=		./srcs/push_swap/push_swap.c						\
						./srcs/push_swap/0_node/node.c						\
						./srcs/push_swap/0_node/node_method.c				\
						./srcs/push_swap/1_push_swap/push_swap_err.c		\
						./srcs/push_swap/1_push_swap/push_swap_method1.c	\
						./srcs/push_swap/1_push_swap/push_swap_method2.c	\
						./srcs/push_swap/1_push_swap/push_swap_method3.c	\
						./srcs/push_swap/2_parse/parsing.c					\
						./srcs/push_swap/2_parse/indexing.c					\
						./srcs/push_swap/3_sort/sort.c						\
						./srcs/push_swap/3_sort/sort_method.c				\
						./srcs/push_swap/3_sort/sandglass.c					\
						./srcs/push_swap/3_sort/a_to_b.c					\
						./srcs/push_swap/3_sort/b_to_a.c					\

PUSH_SWAP_OBJ	=		$(PUSH_SWAP:.c=.o)

CHECKER			=		./srcs/checker/checker_bonus.c							\
						./srcs/checker/0_node/node_bonus.c						\
						./srcs/checker/0_node/node_method_bonus.c				\
						./srcs/checker/1_push_swap/push_swap_err_bonus.c		\
						./srcs/checker/1_push_swap/push_swap_method1_bonus.c	\
						./srcs/checker/1_push_swap/push_swap_method2_bonus.c	\
						./srcs/checker/1_push_swap/push_swap_method3_bonus.c	\
						./srcs/checker/2_parse/indexing_bonus.c					\
						./srcs/checker/2_parse/parsing_bonus.c					\

CHECKER_OBJ		=		$(CHECKER:.c=.o)

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;

all : $(NAME)

$(NAME) : $(PUSH_SWAP_OBJ)
	@echo $(CURSIVE)$(YELLOW) "		- Making $(NAME) -" $(NONE)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBFT_ARC) $(PRINTF_ARC)
	@echo $(CURSIVE)$(YELLOW) "		- Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "		- Complete -"$(NONE)

bonus : $(BONUS)

$(BONUS) : $(CHECKER_OBJ)
	@echo $(CURSIVE)$(YELLOW) "		- Making $(BONUS) -" $(NONE)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBFT_ARC) $(PRINTF_ARC)
	@echo $(CURSIVE)$(YELLOW) "		- Compiling $(BONUS) -" $(NONE)
	@echo $(GREEN) "		- Complete -"$(NONE)

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "		- Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(PUSH_SWAP_OBJ)
	@rm -fr $(CHECKER_OBJ)
	@echo $(CURSIVE)$(BLUE) "		- clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@rm -fr $(BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@echo $(CURSIVE)$(PURPLE)"		- clean $(NAME) file -"$(NONE)

re  :
	@make fclean
	@make all

.PHONY: all make clean fclean bonus re