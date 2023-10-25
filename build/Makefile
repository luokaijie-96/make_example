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

export COMPILEMACRO

#循环获取源文件和中间件
export SRCFILE := $(foreach dirpath,$(SRCCODEDIRS),$(wildcard $(addprefix $(dirpath)/*,.c)))
export OBJFILE := $(patsubst %.c,%.o,$(SRCFILE))

#宏定义,源文件路径，头文件路径
export CURCMPLMACRO   := $(addprefix -D ,$(COMPILEMACRO))
export CURSRCHEADDIRS := $(addprefix -I ,$(SRCHEADDIRS))
export CURLIBHEADDIRS := $(addprefix -I ,$(LIBHEADDIRS))

#程序输出路径
OUTPUTDIR := ../output

#编译器及选项
export CC := gcc
export CFLAGS := -Wall -c

RM := rm
RMFLAGS := -rf

#目标文件    
TARGETNAME = app


all:$(TARGETNAME)  



#$(TARGETNAME):$(OBJFILE) 
$(TARGETNAME): libs subsystem 
	@mkdir -p $(OUTPUTDIR)
	@echo "MAKEFLAGS: ${MAKEFLAGS}"
	@echo "MAKEFILES: ${MAKEFILES}"
	@echo "MAKELEVEL: ${MAKELEVEL}"
	@echo "OBJFILE: ${OBJFILE}"
#@echo "top pid : $$$$"
#@echo "$$< : $<"
#@echo "$$@ : $@"
#@echo "$$^ : $^"
#@echo "${SHELL}"
#@echo "CURDIR: ${CURDIR}"
	@echo ""
	@echo "all files have been compiled , now begin to link every obj for excutable file"
	@echo ""
	@echo "linking............"
	$(CC)  -o $(OUTPUTDIR)/$(TARGETNAME).$(APPVERSION) $(OBJFILE) -L$(LIBFILEDIRS) $(LIBFILE)
	@echo ""
	@echo "linked ok," $(TARGETNAME) "has been created"
	@echo ""
	@echo $(TMPBUILDTM)
	@echo $(MAKEFILE_LIST)
#@echo $(MAKE)
#@echo $(SRCFILE)
#@echo $(OBJFILE)
#@echo "ldd $(OUTPUTDIR)/$(TARGETNAME).$(APPVERSION):"
#@ldd $(OUTPUTDIR)/$(TARGETNAME).$(APPVERSION)




#%.o: %.c
#	@echo ""
#	@echo "MAKEFLAGS: ${MAKEFLAGS}"
#	@echo "MAKEFILES: ${MAKEFILES}"
#	@echo "MAKELEVEL: ${MAKELEVEL}"
##@echo "$(SRCFILE_PRINT)"
##@echo "CURDIR: ${CURDIR}"
##@echo "${SHELL}"
##@echo "%.o:%.c pid : $$$$"
##@echo "$$< : $<"
##@echo "$$@ : $@"
##@echo "$$^ : $^"
#	@echo "start " $< "......compiling"
#	@$(CC) $(CURCMPLMACRO) $(CFLAGS) $(CURSRCHEADDIRS) $(CURLIBHEADDIRS) $< -o $@
#	@echo "created " $@
#	@echo "end   " $< "......compiled ok"
#	@echo ""






.PHONY: all arm clean help libs cleanlibs subsystem  cleansubsystem


# Makefile 中符号“$”有特殊的含义（表示变量或者函数的引用），在规则中需
#要使用符号“$”的地方，需要书写两个连续的（“$$”）。
#for循环的循环体要使用; 
subsystem :
	@for dir in $(SRCCODEDIRS);do \
	${MAKE} all -C $${dir};           \
	done
	


arm:$(TARGETNAME)  


	

#语句等效
libs :
	@$(MAKE) -C $(LIBFILEDIRS)
#@cd  $(LIBFILEDIRS); $(MAKE) 
#@cd  $(LIBFILEDIRS) && $(MAKE) 



clean: cleanlibs  cleansubsystem
	@-$(RM) $(RMFLAGS) $(TARGETNAME) $(OBJFILE) $(OUTPUTDIR)

cleanlibs :
	$(MAKE) clean -C  $(LIBFILEDIRS)	
	
cleansubsystem :
	@for code_obj in ${SRCCODEDIRS}; do  \
		if [ -e $${code_obj} ];then            \
			$(MAKE) clean -C  $${code_obj};    \
		fi                                     \
	done		


help:
	@echo "Usage:" 
	@echo "       make" 
	@echo "       make arm"  
	@echo "       make libs" 
	@echo "       make all"  
#@echo -n "Usage:" ;           echo "    $$$$" \
#echo -n "       make" ;      echo "    $$$$" \
#echo -n "       make arm"  ; echo "    $$$$" \
#echo -n "       make libs" ; echo "    $$$$" \
#echo -n "       make all"  ; echo "    $$$$" 
