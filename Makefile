# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 19:30:36 by rihoy             #+#    #+#              #
#    Updated: 2024/01/26 17:25:38 by rihoy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#Compilateur - Options
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
RM = rm -fr

# Couleurs
NOIR = \033[0;30m
ROUGE = \033[1;31m
VERT = \033[1;32m
JAUNE = \033[0;33m
BLEU = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
BLANC = \033[0;37m
RESET = \033[0m

BOLD = \033[1m

# Calculer le nombre total de fichiers à compiler
TOTAL_FILES = $(words $(SRCS_MAIN))
FILES_COMPILED = 0

# Fonction pour calculer et afficher le pourcentage et le nom du fichier
define update_progress
	$(eval FILES_COMPILED=$(shell echo $$(($(FILES_COMPILED)+1))))
	@echo "$(JAUNE)[$(shell echo $$(($(FILES_COMPILED)*100/$(TOTAL_FILES))))%] Compilation de $<$(RESET)"
endef
# **************************************************************************** #

# Name of prog
NAME = pipex

# Directory
SRCS = srcs
LIB = utils
OBJS = objs
PARS = parsing
EXEC = exec

# Fichier .c
FILE_LIB_C =	$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/ \
			$(SRCS)/$(LIB)/
			
FILE_PARS_C =	$(SRCS)/$(PARS)/gestion_error.c \
			$(SRCS)/$(PARS)/pathenv.c \
			$(SRCS)/$(PARS)/lstcmd.c

FILE_EXEC_C =	$(SRCS)/$(EXEC)/cmd_access.c \
			$(SRCS)/$(EXEC)/exec_cmd.c \
			$(SRCS)/$(EXEC)/gestion_pipe.c

# Fichier .o
LIB_O = $(FILE_LIB_C:$(SRCS)/$(LIB)/%.c=$(OBJS)/%.o)
PARS_O = $(FILE_PARS_C:$(SRCS)/$(PARS)/%.c=$(OBJS)/%.o)
EXEC_O = $(FILE_EXEC_C:$(SRCS)/$(EXEC)/%.c=$(OBJS)/%.o)
# **************************************************************************** #
# Compilation / creation des dir neccessaire
all : $(NAME)
	@echo "$(VERT)FINISH $(NAME)$(RESET)"

$(NAME) : $(LIB_O) $(PARS_O) $(EXEC_O)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB_O) $(PARS_O) $(EXEC_O) $(SRCS)/main.c

$(OBJS)/%.o : $(SRCS)/$(LIB)/%.c
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(JAUNE)loading : $<"

$(OBJS)/%.o : $(SRCS)/$(PARS)/%.c
	@echo "$(JAUNE)loading : $<"
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJS)/%.o : $(SRCS)/$(EXEC)/%.c
	@echo "$(JAUNE)loading : $<"
	@$(CC) $(FLAGS) -c $< -o $@
# **************************************************************************** #
# Regle / COMMAND

clean :
	@$(RM) $(OBJS)
	@echo "$(ROUGE)FILES DELETED$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(ROUGE)EXEC DELETED$(RESET)"
	
re : fclean all