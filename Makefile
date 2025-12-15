NAME := libftprintf.a
HEADER := ft_printf.h
BUILDDIR := .build

SRCS := ft_printf.c ft_conversion_fonction.c ft_conversion_fonction_2.c
OBJS := $(patsubst %.c,$(BUILDDIR)/%.o,$(SRCS))
DEPS := $(patsubst %.c,$(BUILDDIR)/%.d,$(SRCS))

ARFLAGS := rcs
DEPS_FLAGS := -MP -MD -MF
CFLAGS := -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(BUILDDIR):
	mkdir -p $@

$(BUILDDIR)/%.o: %.c Makefile | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(DEPS_FLAGS) $(BUILDDIR)/$*.d

test: $(NAME)
	@echo "#######+++++++++++:::::-------...-------:::::+++++++++#######"
	@echo "###########++++++++++::::::-Tester::::::++++++++++###########"
	@echo "##################++++++++++:::::++++++++++##################"
	@$(CC) main.c -L. -lftprintf -o main
	@./main
	@make fclean
# 	@rm main

clean:
	$(RM) -rf $(BUILDDIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
