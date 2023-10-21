CURSRCHEADDIRS += "-I../../../code/inc/func/"
CURSRCHEADDIRS += -I../../../lib/inc/

# gcc -c, -c 代表只编译，不链接
all: 
	@echo "SRCCODEDIRS: ${SRCCODEDIRS}"
	@echo "MAKEFLAGS: ${MAKEFLAGS}"
	@echo "MAKEFILES: ${MAKEFILES}"
	@echo "MAKELEVEL: ${MAKELEVEL}"
	@echo "SRCFILE:   $(notdir ${SRCFILE})"
	@echo "OBJFILE:   $(notdir ${OBJFILE})"
	@for code_src in $(notdir ${SRCFILE}); do  \
		if [ -e $${code_src} ];then              \
			$(CC) $(CURCMPLMACRO) $(CFLAGS) $(CURSRCHEADDIRS) \
		     $(CURLIBHEADDIRS) -c $${code_src} ; \
		fi                                     \
	done		
	@echo "###################################################"	



.PHONY: all clean



clean:
	@for code_obj in $(notdir ${OBJFILE}); do  \
		if [ -e $${code_obj} ];then            \
			$(RM)  $${code_obj} ;            \
		fi                                     \
	done		
	@echo "###################################################"	
