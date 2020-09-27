# ft_printf

*Because putnbr and putstr aren’t enough. Made for 42 Madrid*

![114/100 score](./ftprintf_success.png)

This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future project without the fear of being flagged as a cheater.
It´s mainly to learn how to use variadic arguments

## Usage
You have to recode the libc’s printf function. The prototype of ft_printf should be int ft_printf(const char *, ...);
It must not do the buffer management like the real printf.

It will manage the following conversions: cspdiuxX%

It will manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions

#### For bonus:

Manage one or more of the following conversions: nfge

Manage one or more of the following flags: l ll h hh

Manage all the following flags: ’# +’ (yes, one of them is a space)

## 

#### Extras:

I also implemented (not in subject):
 - Unicode characters, including emojis.
 - Octals (with flags).
 - G and E uppercase options.

#### Note:
Despite having a final score of 114/115, as moulinette evaluated my '%e' as wrong, I had tested it so hard and couldn't find the bug.
If anyone want to try to find it and start and issue, well... be my guest! I will appreciate it :D

Enjoy!
