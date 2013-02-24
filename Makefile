#Scott Snow
#s_snow2@u.pacific.edu
#ECPE 170
#2/6/13

# The variable CC specifies which compiler will be used.
# (because different unix systems may use different compilers)
CC=gcc


# The variable CFLAGS specifies compiler options
#   -c :    Only compile (don't link)
#   -Wall:  Enable all warnings about lazy / dangerous C programming 
CFLAGS=-c -Wall -std=c99 -Wextra


# All of the .h header files to use as dependencies
HEADERS=showf.h checkf.h updatef.h substring.h clue.h createArray.h readTF.h play.h

# All of the object files to produce as intermediary work
OBJECTS=main.o play.o readTF.o showf.o updatef.o


# The final program to build
EXECUTABLE=crossword


# --------------------------------------------


all: $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm -rf *.o $(EXECUTABLE)
