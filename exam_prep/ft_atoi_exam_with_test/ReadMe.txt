1. What is this for?
2. How does it work?
3. Warning


--------------------
1. What is this for?
--------------------

SHORT: 
  One testing idea that might help to satisfy Moulinette during the exam.

MORE DETAILED:
  In the exam one might need to recode own version of already existing functions,
like e.g.

   atoi,   (short for: ASCII to Integer),
   strcpy, ...

Often one might have coded something that looks ok, but did not pass Moulinette;
One reason might be that there is a slight difference on the result of the 
original function  and  your own one
(which Moulinette will probably often compare).

In order to prevent or to deal with such issues during the exam it might be 
a good idea to write a main which 
tests if the result of the original function and  your own one is the same.

The file  test_ft_atoi.c  serves as an example for how this can be done.


--------------------
2. How does it work?
--------------------

a) Replace the sample  ft_atoi  (no guarantee, see Section 3) in ft_atoi.c
   by your own ft_atoi (exam version)
b) Compile the test via:
     -----------------------------------------------------------------
     cc -Wall -Wextra -Werror -o test_ft_atoi test_ft_atoi.c ft_atoi.c
	 -----------------------------------------------------------------
c) Compare if ft_atoi and atoi do the same thing for sample integers, e.g.
   ./test_ft_atoi 0
   ./test_ft_atoi -1
   ./test_ft_atoi 1
   ./test_ft_atoi 123
   ./test_ft_atoi -123

   Tests for INT_MAX == 2^31 - 1  and  INT_MIN == -2^31
   ./test_ft_atoi 2147483647
   ./test_ft_atoi -2147483648

   Sample Tests for special, non-recognized or even nonsense input
   ./test_ft_atoi  "   -123"
   ./test_ft_atoi  "   --123"
   ./test_ft_atoi -123abc
   ./test_ft_atoi -123abc
   ./test_ft_atoi -abc123

   Note that for very large input - way beyond INT_MAX - 
   ft_atoi and  atoi might differ, but that is likely to be ok. :-)
   ./test_ft_atoi 12345678123456781234


----------
3. Warning
----------

   My below  ft_atoi  has been coded on the Rush00 Weekend.
   I can give no warranty that it will work during the exam!
   E.g. I do not know  if  Moulinette expects a NULL check or not...

   Anyway the more important thing is to illustrate a (hopefully) 
   testing principle that might help to fix things during the exam.