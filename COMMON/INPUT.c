#include "INPUT.h"



char PRESSED_KEY()
{

        struct termios OLD_T, NEW_T;

        char CHAR;



        tcgetattr(STDIN_FILENO, &OLD_T);

        NEW_T = OLD_T;

        NEW_T.c_lflag &= ~(ICANON | ECHO);

        tcsetattr(STDIN_FILENO, TCSANOW, &NEW_T);

        CHAR = (char)getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &OLD_T);



        return CHAR;

}


void WAIT_FOR_KEY(const char TARGET_KEY)
{

        char TYPED_KEY = '\0';


        while (TYPED_KEY != TARGET_KEY)
        {

                TYPED_KEY = PRESSED_KEY();

        }

}
