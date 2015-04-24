MAKEFLAGS+=-rR -j$(shell nproc)
CC:=$(shell basename `which clang 2>/dev/null  || which gcc`)
CFLAGS:=-std=c11 -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 -Werror -Wall -Wno-parentheses -Wno-missing-prototypes

all: nato
%: %.c Makefile
	@echo CC $< $@
	@${CC} ${CFLAGS} $< -o $@
