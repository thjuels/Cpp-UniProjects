# Remove the '#' in line 3 if you want to check for memory leaks
CPPFLAGS = -std=c++11 
# CPPFLAGS = -std=c++11 -g -fsanitize=address,leak,undefined
SRCS = main.cpp queuecontainer.cpp lifoqueue.cpp fifoqueue.cpp sortedqueue.cpp queuesystem.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

ifeq (Windows_NT, $(OS))
RM_CMD := del /F
else
RM_CMD := rm -vf
endif

ZIP_CMD := zip

all: lab5.exe

lab5.exe: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

# Use make zinc to create the zip file for submission
zinc: queuecontainer.cpp lifoqueue.cpp fifoqueue.cpp sortedqueue.cpp queuesystem.cpp
	$(ZIP_CMD) lab5.zip $^ 

clean:
	$(RM_CMD) *.o lab5.exe *.d lab5.zip

