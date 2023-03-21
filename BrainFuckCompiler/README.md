<!--
 * @Author: ni-jingzhe 1448976235@qq.com
 * @Date: 2023-03-21 15:20:31
 * @LastEditors: ni-jingzhe 1448976235@qq.com
 * @LastEditTime: 2023-03-21 15:24:50
 * @FilePath: \undefinedg:\StudyProject\c_programming\BrainFuckCompiler\README.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
# 项目说明
---
进入项目文件夹后首先需要删除`CMakeCache.txt`然后`cmake .`重新生成`Makefile`文件
在`build_control.h`中，修改`LINUX`或`WIN`控制编译为适用于`bash(包括powershell)`或`DOS`的编译器。

目前`Release`文件夹中包括一个适用于`DOS`的编译器(.exe后缀的)和一个适用于`bash(包括powershell)`的编译器