

TARGET := Snake  #目标名，最终可执行文件名
CC := arm-linux-gcc # c编译器
CPP := arm-linux-g++  -std=c++11  #c++编译器

# PWD := $(shell pwd)

# 变量 CPPSRCS 保存当前工程所有的 C文件名
CPPSRCS += $(wildcard *.cpp)



# 变量OBJS 保存当前工程中所有的 中间文件名  .o
OBJS +=$(patsubst  %.cpp, %.o, $(CPPSRCS))


# 头文件的搜索路径
INC_PATH += -I ../inc


# 链接的库
LIBS += -L  ../libs -l pthread -l m 


$(TARGET): $(OBJS)
	$(CPP) $^ $(LIBS)  -o  $@
	cp $(TARGET) /home/china/tftp   

%.o : %.c
	$(CC) -c $<  $(INC_PATH) -o $@


%.o : %.cpp
	$(CPP) -c $<  $(INC_PATH) -o $@

# 清除所有的中间文件(*.o)和最终的可执行文件
clean:
	rm -rf $(OBJS)
	rm -rf $(TARGET)