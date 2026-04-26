
# JEZYS_COMMON
 A common library in C that cuts off the hassle of handling strings, lists, input

<img width="1820" height="640" alt="JEZYS_COMMON_BANNER" src="https://github.com/user-attachments/assets/32337f7b-a580-4540-b00d-62565338f569" />

<br>

<img width="1048" height="730" alt="COMMON_CODE1" src="https://github.com/user-attachments/assets/7107c4f8-fd49-4e69-b50e-2cee3a4840f9" />

<br>
<br>

## What is this?

The COMMON library is made in C and for C.

It's developed with the KISS principle ("Keep it simple, stupid").

It has STRINGS, STRING_LISTS, INPUT, MATHS, MISC files.


<br>
<br>

## What does it do?

It removes the hassle to handle strings and string lists

Example:

<br>

instead of :

<img width="599" height="145" alt="COMMON_CODE_SNIP1" src="https://github.com/user-attachments/assets/8d5b3cbf-bfa6-4c71-8540-3e53278075cd" />

<br>

you could just :

<img width="527" height="53" alt="image" src="https://github.com/user-attachments/assets/1c51bde2-21bc-46ec-988c-26ea8d789295" />

<br>

Clean, clear, mess-free way of just adding a char to a string.

<br>
<br>

## Doesn't string.h exist?

Well, yes, although it's given by libc, its lacking:

- some regular functions like SUB_STRING, STRING_INSERT, and type conversion functions like INT_TO_STRING
- clear naming : strcat vs STRING_APPEND
- and much more

<br>
<br>

## Ok, what else?

String lists are hard to make, use, control in C, especially for beginners

<br>

a string list = a list of list of chars

to make, edit, free, theres a lot of addition and subtraction and one-offs involved

most programmers just want to have a string list, add some items to a string list, free a string list

<br>

Example:

<br>

instead of :

<img width="804" height="527" alt="image" src="https://github.com/user-attachments/assets/9dba83f3-d29d-498d-83e5-81b9ea9876fd" />

<br>

You could just :

<img width="541" height="157" alt="image" src="https://github.com/user-attachments/assets/de470ed1-c769-4e04-9b35-f166de7b60d2" />

<br>

clean, mess-free, and simplified

<br>

Full flow:

<img width="641" height="233" alt="image" src="https://github.com/user-attachments/assets/be549677-b2e9-44a8-babf-43e895f247f3" />

<br>
<br>

## I have suggestions

It's totally fine to give suggestions, in fact, i encourage it

If this library could grow, I'd love to get more countributors to suggest, improve, and add to this library

<br>

The README goes to here for now, thanks for reading.
