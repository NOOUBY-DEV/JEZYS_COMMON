# JEZYS_COMMON
 A common library in C that cuts off the hassle of handling strings, lists, input

 
<img width="1048" height="854" alt="COMMON_CODE1" src="https://github.com/user-attachments/assets/3905b31c-c8a5-4624-a76c-3a441c0994ef" />


<br>
<br>

## What is this?

The COMMON library is made in C and for C.

It's developed with the KISS principle ("Keep it simple, stupid").

It has STRINGS, STRING_LISTS, INPUT, MATHS, MISC files.


<br>
<br>

## What does it do?

It removes the hassle to handle strings

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
