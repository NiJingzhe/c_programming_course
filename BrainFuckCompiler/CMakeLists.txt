cmake_minimum_required(VERSION 2.8)

Project(BrainFuckCompiler)

add_executable(bf BF.c paraser.c compiler.c)

