# 定义相关变量 
CC=g++ #编译器类型
STD=-std=gnu++0x  #语法标准
FLAGS=-Wall  -Werror  #编译参数
OBJ=manager_view_impl.o manager_ctrl_impl.o manager_mode_impl.o manager.o service_view_impl.o service_ctrl_impl.o service_mode_impl.o department.o employee.o main.o  emis.o  tools.o     #目标文件
BIN=EMIS.bin  #编译结果

#入口编译目标 合并
all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN) && ./$(BIN)

#编译单个源文件
%.o:%.cpp
	$(CC) -c $(STD) $(FLAGS) $< -o $@

#清理编译临时文件
clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)
	rm -rf *.h.gch

