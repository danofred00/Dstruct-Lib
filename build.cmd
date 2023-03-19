
@echo off

mingw32-make
del *.o
mingw32-make -B test
