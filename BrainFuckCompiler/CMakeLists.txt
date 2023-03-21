# CMakeList.txt: BrainFuckCompiler 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.

project ("BrainFuckCompiler")

aux_source_directory(src SRC_LIST)
aux_source_directory(src/headers HEAD_LIST)

# 将源代码添加到此项目的可执行文件。
add_executable (BF ${SRC_LIST} ${HEAD_LIST})

# TODO: 如有需要，请添加测试并安装目标。
