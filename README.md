# ft_printf
## About this project
This project was carried out as part of the core curriculum at 42 school.
It is not intended to be perfect, but rather to illustrate my level and progress at this stage of my journey at 42 school.

## About ft_printf

The goal of the **ft_printf** project is to reproduce the behavior of the libc ft_printf function.
It consists of managing formatted output from a character string, interpreting different conversion specifiers, and displaying the corresponding arguments. However, it does not handle as many cases here; we handle ‘**csduixXp%**’: 
- %c : character
- %s : string
- %d / %i : signed decimal integer
- %u : unsigned decimal integer
- %x / %X : hexadecimal integer (lowercase / uppercase)
- %p : pointer adress
- %% : percent sign

As part of the core curriculum at 42 school, this project allows us to work on:
 - variadic functions (va_list, va_start, va_arg, va_end)
 - code organization and clarity

## Important information

This implementation does not support the subject's bonuses.

In order to comply with the 42 Norm, I chose to use a structure to group several variables together.
This avoids having too many parameters in the functions and keeps the code readable and compliant with the constraints imposed by the school.

## How to use
To use this ft_printf, you must first download the project and compile it using make.
This will generate an .a library that you can then integrate into your projects.
(That said, you'd have to be slightly crazy to use my ft_printf rather than the real one.)
The use of ft_printf looks like this: 
```python
>>> ft_printf(“This is a test: %s”, “Hello world!”)
This is a test: Hello world!

# Another example
>>> ft_printf(“This is another test: %s %d %%”, “Hello world!”, 10)
This is another test: Hello World! 10 %
```

<small>*This readme was created outside of the 42 curriculum. I made it to make the project cleaner, which is why it is not presented in the same way as the following projects.*</small>