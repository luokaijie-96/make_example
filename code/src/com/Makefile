CURSRCHEADDIRS += -I../../../code/inc/func/
CURLIBHEADDIRS += -I../../../lib/inc/

CFLAGS+= $(CURSRCHEADDIRS)
CFLAGS+= $(CURLIBHEADDIRS)
CFLAGS+= $(CURCMPLMACRO)

DEPEND_OBJ := main.mk


SSSRC = $(shell for code_src in $(notdir ${SRCFILE}) ;do \
if [ -e $${code_src} ];then \
echo  "$${code_src}";  \
fi                    \
done)

SSOBJ := $(patsubst %.c,%.o,$(SSSRC)) 


define  echo_func
	echo "SSSRC: ${SSSRC}"
	echo "SSOBJ: ${SSOBJ}"
	echo "SRCCODEDIRS: ${SRCCODEDIRS}"
	echo "MAKEFLAGS: ${MAKEFLAGS}"
	echo "MAKEFILES: ${MAKEFILES}"
	echo "MAKELEVEL: ${MAKELEVEL}"
	echo "SRCFILE:   $(notdir ${SRCFILE})"
	echo "OBJFILE:   $(notdir ${OBJFILE})"
endef


# gcc -c, -c 代表只编译，不链接
all: ${SSOBJ} 
	@$(echo_func)
#@for code_src in ${SRC}; do  \
#		if [ -e $${code_src} ];then              \
#			$(CC) $(CURCMPLMACRO) $(CFLAGS) $(CURSRCHEADDIRS) \
#		     $(CURLIBHEADDIRS) -c $${code_src} ; \
#		fi                                     \
#	done		
	@echo "###################################################"	





.PHONY: all clean depend



depend: $(DEPEND_OBJ)
	


define  mk_fun
	@echo "create .mk  files begin..."
	$(CC)  $(CFLAGS) -M $< $(CURSRCHEADDIRS) $(CURLIBHEADDIRS) > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$ 
	@echo "create .mk  files finish..."
	@echo "********************"	
endef



include main.mk


%.mk: %.c 
	$(mk_fun)



clean:
#@for code_obj in $(notdir ${OBJFILE}); do  \
#		if [ -e $${code_obj} ];then            \
#			$(RM)  $${code_obj} ;            \
#		fi                                     \
#	done		
	@-$(RM)  *.d  *.o  *.mk
	@echo "###################################################"	
