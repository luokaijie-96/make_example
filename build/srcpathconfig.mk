#源文件目录
export SRCCODEDIRS   :=../code/src/com \
               		   ../code/src/func \


#头文件目录
export SRCHEADDIRS   :=../code/inc/func \
				../code/inc/com \

#lib文件目录
export LIBFILEDIRS := ../lib/libs

#lib头文件目录
export LIBHEADDIRS := ../lib/inc/

#lib文件
export LIBFILE := -lmylib


unexport SRCCODEDIRS
export SRCCODEDIRS
