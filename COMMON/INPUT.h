#ifndef INPUT
#define INPUT

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>




char PRESSED_KEY();

void WAIT_FOR_KEY(const char TARGET_KEY);




#endif
