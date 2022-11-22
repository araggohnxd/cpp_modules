NAME				:= animal

HEADER_FILES		:= Animal.hpp Dog.hpp Cat.hpp Brain.hpp

SOURCE_PATH			:= ./
SOURCE_FILES		:= main.cpp
SOURCE_FILES		+= Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJECT_PATH			:= ./objects
OBJECT_FILES		:= $(SOURCE_FILES:%.cpp=$(OBJECT_PATH)/%.o)

CC					:= c++
CFLAGS				:= -Wall -Wextra -std=c++98 -g
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
