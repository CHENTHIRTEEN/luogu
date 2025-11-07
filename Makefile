# 通用 Makefile: 将 `name.cpp` 编译为同名可执行文件 `name`
# 用法示例：
#   make P605      # 编译 P605.cpp -> 可执行文件 ./P605
#   make           # 编译目录下所有以 P*.cpp 或 *.cpp 为目标匹配的文件（可选）
#   make clean     # 删除可执行文件

CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra

# 模式规则：target : target.cpp
# % 匹配文件名（例如 P605）
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# 可选：生成当前目录下所有以 .cpp 结尾的可执行文件（解除注释以启用）
# ALL := $(patsubst %.cpp,%,$(wildcard *.cpp))
# all: $(ALL)

.PHONY: clean
clean:
	rm -f */*.o *.o $(patsubst %.cpp,%,$(wildcard *.cpp))
