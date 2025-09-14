SERVER			=		server
CLIENT			=		client
CC              =       cc
CFLAGS          =		-Wall -Wextra -Werror


SMAND_SRC		=		./src/server.c	\
						./src/util.c
SMAND_OBJ		=		$(SMAND_SRC:.c=.o)

CMAND_SRC		=		./src/client.c	\
						./src/util.c
CMAND_OBJ		=		$(CMAND_SRC:.c=.o)


SBONUS_SRC		=		./src_bonus/server_bonus.c	\
						./src_bonus/util_bonus.c
SBONUS_OBJ		=		$(SBONUS_SRC:.c=.o)

CBONUS_SRC		=		./src_bonus/client_bonus.c	\
						./src_bonus/util_bonus.c
CBONUS_OBJ		=		$(CBONUS_SRC:.c=.o)



LIBFT_DIR		=		./lib/libft
LIBFT_ARC		=		./lib/libft/libft.a

PRINTF_DIR		=		./lib/ft_printf
PRINTF_ARC		=		./lib/ft_printf/libftprintf.a

ifdef FLAG
    SERVER_OBJ = $(SBONUS_OBJ)
    CLIENT_OBJ = $(CBONUS_OBJ)
else
    SERVER_OBJ = $(SMAND_OBJ)
    CLIENT_OBJ = $(CMAND_OBJ)
endif

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;

all : $(SERVER) $(CLIENT)

bonus :
	make all FLAG=1

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "    - Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN) "        - Complete -\n"$(NONE)

$(SERVER) : $(SERVER_OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_ARC) $(PRINTF_ARC) $^ -o $@
	@echo $(CURSIVE)$(YELLOW) "    - Compiling SERVER -" $(NONE)
	@echo $(GREEN) "        - Complete -\n"$(NONE)

$(CLIENT) : $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_ARC) $(PRINTF_ARC) $^ -o $@
	@echo $(CURSIVE)$(YELLOW) "    - Compiling CLIENT -" $(NONE)
	@echo $(GREEN) "        - Complete -\n"$(NONE)

clean :
	@rm -fr $(SMAND_OBJ) $(SBONUS_OBJ) $(CMAND_OBJ) $(CBONUS_OBJ)
	@echo $(CURSIVE)$(BLUE) "    - clean OBJ files -\n" $(NONE)

fclean : clean
	@echo $(CURSIVE)$(PURPLE)"      - clean $(SERVER) file -"$(NONE)
	@rm -fr $(SERVER)
	@echo $(CURSIVE)$(PURPLE)"      - clean $(CLIENT) file -"$(NONE)
	@rm -fr $(CLIENT)
	@echo $(CURSIVE)$(PURPLE)"      - clean lib file -\n"$(NONE)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

re  :
	@make fclean
	@make all

.PHONY: all make clean fclean bonus re
