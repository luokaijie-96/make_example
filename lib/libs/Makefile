LIB_TYPE ?= dynamic

ifeq (dynamic,$(LIB_TYPE))
#参数：-fpic创建与地址无关的编译程序(pic, position independent code), 目的就是为了能够在多个应用程序间共享.
CFLAGS += -fpic
CURCMPLMACRO += -DLIB_TYPE_DYNAMIC
else
CURCMPLMACRO += -DLIB_TYPE_STATIC
endif
CFLAGS += -c


objs := mylib.o  mylib_test1.o  mylib_test2.o


ifeq ($(MAKELEVEL),0)
all : msg
else
ifeq (dynamic,$(LIB_TYPE))
all : $(objs) 
	@#2 使用gcc将.o文件编译成库文件
	gcc -shared $^  -o libmylib.so
#gcc -shared $?  -o libmylib.so
	sudo cp  libmylib.so  /usr/lib	
	@echo "###################################################"	
else
all : $(objs) 
	$(AR)  rcs  libmylib.a  $^
	@echo "###################################################"	
endif
endif




msg:
	@echo "Can not make in this directory!"


.PHONY : clean  


 
# 使用最终万用规则，最后缺省规则.当一个目标找不到可用规则时，将使用此规则
#% ::
#	touch $@
#	@echo "$@ "

%.o : %.c
	@#1 将.c文件编译成.o文件
	$(CC) $(CFLAGS) $(CURCMPLMACRO) $<  -I../inc
	


clean :
	@-sudo $(RM) $(objs) libmylib.so  /usr/lib/libmylib.so  libmylib.a
	@echo "###################################################"	
