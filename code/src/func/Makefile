CURSRCHEADDIRS += -I../../../code/inc/func/
CURLIBHEADDIRS += -I../../../lib/inc/

CFLAGS+= $(CURSRCHEADDIRS)
CFLAGS+= $(CURLIBHEADDIRS)
CFLAGS+= $(CURCMPLMACRO)

DEPEND_OBJ := fun.mk


SSSRC = $(shell for code_src in $(notdir ${SRCFILE}) ;do \
if [ -e $${code_src} ];then \
echo  "$${code_src}";  \
fi                    \
done)

SSOBJ := $(patsubst %.c,%.o,$(SSSRC)) 


# gcc -c, -c 代表只编译，不链接
all: ${SSOBJ} 
	@echo "SSSRC: ${SSSRC}"
	@echo "SSOBJ: ${SSOBJ}"
	@echo "SRCCODEDIRS: ${SRCCODEDIRS}"
	@echo "MAKEFLAGS: ${MAKEFLAGS}"
	@echo "MAKEFILES: ${MAKEFILES}"
	@echo "MAKELEVEL: ${MAKELEVEL}"
	@echo "SRCFILE:   $(notdir ${SRCFILE})"
	@echo "OBJFILE:   $(notdir ${OBJFILE})"
#@for code_src in ${SRC}; do  \
#		if [ -e $${code_src} ];then              \
#			$(CC) $(CURCMPLMACRO) $(CFLAGS) $(CURSRCHEADDIRS) \
#		     $(CURLIBHEADDIRS) -c $${code_src} ; \
#		fi                                     \
#	done		
	@echo "###################################################"	





.PHONY: all clean depend



depend: $(DEPEND_OBJ)
	

ifneq ($(MAKECMDGOALS),clean)
include fun.mk
endif


%.o : %.c
	echo "module rule ..."
	$(CC) $(CURCMPLMACRO) $(CFLAGS) $(CURSRCHEADDIRS) \
	     $(CURLIBHEADDIRS) -c $< -o $@ 
	@echo "********************"	


%.mk: %.c 
	@echo "create .mk  files begin..."
	$(CC)  $(CFLAGS) -M $< $(CURSRCHEADDIRS) $(CURLIBHEADDIRS) > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$ 
	@echo "create .mk  files finish..."
	@echo "********************"	


clean:
#@for code_obj in $(notdir ${OBJFILE}); do  \
#	if [ -e $${code_obj} ];then            \
#		$(RM)  $${code_obj} ;            \
#	fi                                     \
#done		
	@-$(RM)  *.d  *.o  *.mk
	@echo "###################################################"	
