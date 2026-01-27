𝑇ℎ𝑖𝑠 𝑝𝑟𝑜𝑗𝑒𝑐𝑡 ℎ𝑎𝑠 𝑏𝑒𝑒𝑛 𝑐𝑟𝑒𝑎𝑡𝑒𝑑 𝑎𝑠 𝑝𝑎𝑟𝑡 𝑜𝑓 𝑡ℎ𝑒 42 𝑐𝑢𝑟𝑟𝑖𝑐𝑢𝑙𝑢𝑚 𝑏𝑦 𝑏𝑒𝑑𝑒-𝑘𝑜𝑛.

Description:

The ft_printf project asks you to recode a simplified version of the C standard library (libc) function: printf (which can also be used as a shell command in Linux).
This function formats text and writes it to the standard output.
Ft_printf only handles the following conversions: c, s, p, d, i, u, x, X and %.
Ft_printf doesn't handle buffer management and undefined behaviour in the same way as the original printf.


Instructions:

The project includes a makefile, so you can just compile it by typing 'make' in the command line.
If you want to compile and run the program including the main.c file, type 'make run' instead.


Resources:
- I had done this project already a year ago, so I relied a lot on my memories from past experience.
- The printf Wikipedia page.
- No AI was used.


Algorithm and data structure:
- I used a recursive algorithm to format integers. I did this because it was a very concise approach and because I thought it was good to practise the use of recursion.
- Just like the original printf, my function takes a va_list type (internally a struct) as a parameter. For the rest I only used basic arithmetic data types (int and char) because that was sufficient.
