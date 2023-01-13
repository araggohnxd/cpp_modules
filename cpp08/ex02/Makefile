NAME				:= mstack

HEADER_FILES		:= MutantStack.hpp MutantStack.tpp

SOURCE_PATH			:= ./
SOURCE_FILES		:= main.cpp

OBJECT_PATH			:= ./objects
OBJECT_FILES		:= $(SOURCE_FILES:%.cpp=$(OBJECT_PATH)/%.o)

CC					:= c++
CFLAGS				:= -Wall -Wextra -Werror -std=c++98
IFLAGS				:= -I./
REMOVE				:= rm -rf

vpath				%.cpp $(SOURCE_PATH)
vpath				%.hpp $(SOURCE_PATH)

all:				$(NAME)

$(NAME):			$(OBJECT_FILES) | $(OBJECT_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJECT_FILES)

$(OBJECT_PATH)/%.o:	%.cpp $(HEADER_FILES) Makefile | $(OBJECT_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJECT_PATH):
					mkdir -p $@

clean:
					$(REMOVE) $(OBJECT_PATH)

fclean:				clean
					$(REMOVE) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
