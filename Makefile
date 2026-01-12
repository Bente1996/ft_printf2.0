NAME := libftprintf.a
EXEC_NAME := ft_printf
HEADERFILES := libft.h ft_printf.h
SRCFILES := ft_printf.c
OBJFILES := $(SRCFILES:.c=.o)
DEPDIR := dep/
DEPFILES := $(addprefix $(DEPDIR),$(SRCFILES:.c=.d))
CPPFLAGS ?=
DEPFLAG = -MM -MF $@ -MT $@ -MT $(addsuffix .o,$(basename $<))
CFLAGS ?= -Wall -Wextra -Werror -Ilibft/
.DEFAULT_GOAL := all

-include $(DEPFILES)

all : $(NAME)

run: $(NAME) $(EXEC_NAME)
	./$(EXEC_NAME)

$(NAME) : $(OBJFILES) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) -rcs $(NAME) $(OBJFILES)

$(EXEC_NAME) : $(NAME) main.c
	$(CC) main.c -L./ -lftprintf $(CFLAGS) -o $(EXEC_NAME)

$(LIBFT_A) :
	$(MAKE) -C libft

%.o: %.c $(HEADERFILES)
	$(CC) $(CFLAGS) -c $<

$(DEPDIR)%.d: %.c | $(DEPDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAG) $<

clean:
	$(RM) $(OBJFILES)
	$(MAKE) -C libft clean
fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(DEPDIR)
	$(MAKE) -C libft clean

re:
	$(MAKE) fclean
	$(MAKE) all

%/:
	mkdir -p $@

test:
	echo "$(CC) $(RM) $(AR) $(ARFLAGS)"

.PHONY: all clean fclean re
.PRECIOUS: $(DEPDIR)
