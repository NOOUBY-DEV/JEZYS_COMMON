#include "COMMON/STRINGS.h"
#include "COMMON/INPUT.h"
#include "COMMON/STRING_LISTS.h"
#include <stdio.h>



void TEST();




int main()
{

        TEST();


        return 0;

}


void TEST()
{

        printf("==================== CONVERSION ====================\n\n");



        // [CONVERSION]
        {

                // [STRING TO CHAR]
                {

                        char* STRING__T__CHAR = "A";


                        printf("STRING_TO_CHAR : %c \n\n", STRING_TO_CHAR(STRING__T__CHAR));

                }


                // [CHAR TO STRING]
                {

                        char CHAR__T__STRING[2];

                        CHAR_TO_STRING(CHAR__T__STRING, 'A');


                        printf("CHAR_TO_STRING : %s \n\n", CHAR__T__STRING);

                }


                // [STRING TO INT]
                {

                        char* STRING__T__INT = "-12314";
                        int INT__F__STRING;


                        STRING_TO_INT(STRING__T__INT, &INT__F__STRING);


                        printf("STRING_TO_INT : %d \n\n", INT__F__STRING);

                }


                // [STRING]

        }


        // [MODIFICATION]
        {

                printf("==================== EDIT ====================\n\n");



                // [STRING APPEND]
                {

                        char STRING[64] = EMPTY;


                        STRING_APPEND(STRING, "HELLO WORLD");


                        printf("STRING_APPEND : %s \n\n", STRING);

                }

                // [STRING PREPEND]
                {

                        char STRING[64] = "DEFG";


                        STRING_PREPEND(STRING, "ABC|");


                        printf("STRING_PREPEND : %s \n\n", STRING);

                }


                // [STRING PREPEND CHAR]
                {

                        char STRING[64] = "|BCDEF";


                        STRING_PREPEND_CHAR(STRING, 'A');


                        printf("STRING_PREPEND_CHAR : %s \n\n", STRING);

                }


                // [STRING INSERT CHAR]
                {

                        char STRING__INSERT__CHAR[64] = "ABC[]EF";



                        STRING_INSERT_CHAR(STRING__INSERT__CHAR, 'D', 4);



                        printf("STRING_INSERT_CHAR : %s \n\n", STRING__INSERT__CHAR);

                }


                // [STRING INSERT]
                {

                        char STRING__INSERT__CHAR[64] = "ABF";



                        STRING_INSERT(STRING__INSERT__CHAR, "[CDE]", 2);



                        printf("STRING_INSERT : %s \n\n", STRING__INSERT__CHAR);

                }


                // [SUB STRING SELF]
                {

                        char STRING[64] = "HELLO WORLD";


                        SUB_STRING_SELF(STRING, 6, 5);


                        printf("SUB_STRING_SELF : |%s| \n\n", STRING);

                }


                // [STRING TRIM]
                {

                        char STRING[] = "              HELLO MY NAME IS NOOUBY     AND I LOVE C        ";


                        STRING_TRIM(STRING);


                        printf("STRING_TRIM : |%s|\n\n", STRING);

                }


                // [STRING FORMAT]
                {

                        char STRING[256];
                        char FORMAT[] = "HELLO MY NAME IS [%V] AND I LOVE [%V]";
                        char NAME[] = "NOOUBY-DEV";
                        char LANGUAGE[] = "C";


                        int RUN = STRING_FORMAT(STRING, FORMAT, NAME, LANGUAGE);


                        printf("STRING_FORMAT : |%s|\n\n", STRING);

                }


                // [STRING REPLACE AT INDEX]
                {

                        char STRING[64] = "HELLO XXXXXXX";


                        STRING_REPLACE_SEQUENCE(STRING, "[WORLD]", 6);


                        printf("STRING_REPLACE_SEQUENCE : %s \n\n", STRING);

                }

        }


        // [CONDITIONS]
        {

                printf("==================== CONDITIONS ====================\n\n");



                // [STRING ENDS WITH]
                {

                        char STRING[] = "ABCDEFG";
                        char ENDING[] = "EFG";


                        printf("STRING ENDS WITH : ABCDEFG, EFG : %d\n\n", STRING_ENDS_WITH(STRING, ENDING));

                }

        }


        // [STRING LISTS]
        {

                printf("==================== STRING LISTS ====================\n\n");




                // [FREE STRING LIST]
                {

                        char** LIST;



                        STRING_LIST_SETUP(&LIST, 8, 32);

                        STRING_LIST_APPEND(&LIST, "HELLO WORLD");

                        int RUN = FREE_STRING_LIST(&LIST);



                        printf("STRING_LIST_SETUP : STRLIST STATUS => %d \n\n", RUN);

                }

        }


        // [INPUT]
        {

                printf("==================== INPUT ====================\n\n");


                char STRING[256] = EMPTY;



                printf("[$] INPUT ->  ");

                INPUT_TO_STRING(STRING, "ABCDEFGHIJKLMNOPQRSTUVWXYZ ", 255);



                printf("INPUT_TO_STRING : %s \n\n", STRING);

        }

}
