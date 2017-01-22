SRCS := $(wildcard *.c)
EXECUTABLES := $(patsubst %.c,%,$(SRCS))
OBJSECTS := $(patsubst %.c,%.o,$(SRCS))

all :
	for compiled_scheme_file in $(EXECUTABLES); do \
		gcc -c "$$compiled_scheme_file".c -o "$$compiled_scheme_file".o ; \
		gcc "$$compiled_scheme_file".o -o "$$compiled_scheme_file"; \
	done; \
	rm $(OBJSECTS) 
	
clean:
	rm $(EXECUTABLES)
