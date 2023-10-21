


srcs := mylib.c
objs := mylib.o

all : 
#@echo "CURDIR: ${CURDIR}"
	@#1 将.c文件编译成.o文件
	gcc -fpic -c ${srcs}  -I../inc
	@#参数：-fpic创建与地址无关的编译程序(pic, position independent code), 目的就是为了能够在多个应用程序间共享.
	@#2 使用gcc将.o文件编译成库文件
	gcc -shared $(objs)  -o libmylib.so
	sudo cp  libmylib.so  /usr/lib	
	@echo "###################################################"	


.PHONY : clean


clean :
	@-sudo $(RM) $(objs) libmylib.so  /usr/lib/libmylib.so
	@echo "###################################################"	
