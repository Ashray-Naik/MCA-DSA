# Compiler
CC = gcc  # Specify the compiler to use (gcc)

# Compiler flags
CFLAGS = -Wall -Wextra  # Enable all warnings and extra warnings for better code quality

# Source files
SRCS = main.c finance_management.c  # List of all source files

# Object files
OBJS = $(SRCS:.c=.o)  # Create a list of object files by replacing .c with .o in source files

# Output executable
TARGET = final  # Name of the final executable

# Default rule
all: $(TARGET)  # Default target that builds the final executable

# Linking
$(TARGET): $(OBJS)  # Rule for linking object files to create the executable
	$(CC) -o $@ $^  # $@ is the target name (final), $^ are all the dependencies (object files)

# Compiling
%.o: %.c finance_management.h  # Rule for compiling .c files into .o files
	$(CC) $(CFLAGS) -c $<  # $< is the first prerequisite (the source file), -c flag compiles without linking

# Clean up
clean:  # Target to clean up the build environment
	rm -f $(OBJS) $(TARGET)  # Remove all object files and the final executable

# Phony targets
.PHONY: all clean  # Declares that 'all' and 'clean' are phony targets (not actual files)

