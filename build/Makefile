#引用其他文件
include srcpathconfig.mk  ../include_flag.mk

#时间信息
tmpbuildtm := `date |sed 's/ /_/g'`
TMPBUILDTM = $(tmpbuildtm)

#软件版本
APPVERSION = 1.0.0.0


#不同的目标采用不同的宏定义
ifeq ($(MAKECMDGOALS),arm)
COMPILEMACRO += COMPILER_IS_ARM_LINUX_GCC
else
COMPILEMACRO += COMPILER_IS_LINUX_GCC MACRO_DEF
endif

ifeq ($(INCLUDE_FLAG),1)
COMPILEMACRO += INCLUDE_FLAG
endif	

#循环获取源文件和中间件
SRCFILE := $(foreach dirpath,$(SRCCODEDIRS),$(wildcard $(addprefix $(dirpath)/*,.c)))
OBJFILE := $(patsubst %.c,%.o,$(SRCFILE))

#宏定义,源文件路径，头文件路径
CURCMPLMACRO   := $(addprefix -D ,$(COMPILEMACRO))
CURSRCHEADDIRS := $(addprefix -I ,$(SRCHEADDIRS))
CURLIBHEADDIRS := $(addprefix -I ,$(LIBHEADDIRS))

#程序输出路径
OUTPUTDIR := ../output

#编译器及选项
CC := gcc
CFLAGS := -Wall -c

RM := rm
RMFLAGS := -rf

#目标文件    
TARGETNAME = app

$(TARGETNAME):$(OBJFILE)
	@mkdir -p $(OUTPUTDIR)
	@echo ""
	@echo "all files have been compiled , now begin to link every obj for excutable file"
	@echo ""
	@echo "linking............"
	@echo $(OBJFILE)
	@$(CC)  -o $(OUTPUTDIR)/$(TARGETNAME).$(APPVERSION) $(OBJFILE) -L$(LIBFILEDIRS) $(LIBFILE)
	@echo ""
	@echo "linked ok," $(TARGETNAME) "has been created"
	@echo ""
	@echo $(TMPBUILDTM)
	@echo $(MAKEFILE_LIST)
#@echo $(SRCFILE)
#@echo $(OBJFILE)
#@echo "ldd $(OUTPUTDIR)/$(TARGETNAME).$(APPVERSION):"
#@ldd $(OUTPUTDIR)/$(TARGETNAME).$(APPVERSION)

%.o: %.c
	@echo ""
	@echo "start " $< "......compiling"
	@$(CC) $(CURCMPLMACRO) $(CFLAGS) $(CURSRCHEADDIRS) $(CURLIBHEADDIRS) $< -o $@
	@echo "created " $@
	@echo "end   " $< "......compiled ok"
	@echo ""

.PHONY: all arm clean help libs

arm:$(TARGETNAME)
all:$(TARGETNAME)


libs :
	@cd  $(LIBFILEDIRS); make; cd -	


clean:
	@-$(RM) $(RMFLAGS) $(TARGETNAME) $(OBJFILE) $(OUTPUTDIR)
	@cd  $(LIBFILEDIRS);  make clean; cd -	


help:
	@echo "Usage:"
	@echo "       make"
	@echo "       make arm"
	@echo "       make libs"
	@echo "       make all"
