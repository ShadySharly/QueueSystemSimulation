#########################################################################################################################################################
#################################################################### VARIABLES ##########################################################################
#########################################################################################################################################################

CC = gcc
CL = clean
SRC_DIR = ./src
OBJ_DIR = ./obj
MAIN_OBJ = $(OBJ_DIR)/main.o
MM1_OBJ = $(OBJ_DIR)/mm1.o
MAIN_SRC = $(SRC_DIR)/main.c
MM1_SRC = $(SRC_DIR)/mm1.c
EXEC = mm1
C_FLAGS = -g -Wall
MATH_FLAG = -lm

#########################################################################################################################################################
##################################################################### TARGETS ###########################################################################
#########################################################################################################################################################

.PHONY: all
all: $(EXEC)

$(EXEC): clean obj $(MAIN_OBJ) $(MM1_OBJ)
	$(CC) $(C_FLAGS) $(MAIN_OBJ) $(MM1_OBJ) -o $@ $(MATH_FLAG)

$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(C_FLAGS) -c $< -o $@

$(MM1_OBJ): $(MM1_SRC)
	$(CC) $(C_FLAGS) -c $< -o $@

.PHONY: obj
obj: 
	mkdir $(OBJ_DIR)

.PHONY: clean
clean: 
	rm -rf $(OBJ_DIR)
	rm -rf $(EXEC)

#########################################################################################################################################################