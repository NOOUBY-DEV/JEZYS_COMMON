#include "STRINGS.h"







char STRING_TO_CHAR(const char* STRING)
{

        return STRING[0];

}


void CHAR_TO_STRING(char* STRING, const char CHAR)
{

        STRING[0] = CHAR;
        STRING[1] = '\0';

}


void STRING_TO_WORD_LIST(char*** WORD_LIST, char* STRING)
{

        unsigned long long WORD_LIST_INDEX = 0;


        STRING_TRIM(STRING);


        STRING_CLEAR((*WORD_LIST)[WORD_LIST_INDEX]);


        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                char CHAR = STRING[INDEX];


                if (CHAR != ' ')
                {

                        STRING_APPEND_CHAR((*WORD_LIST)[WORD_LIST_INDEX], CHAR);

                }

                else
                {

                        WORD_LIST_INDEX ++;

                        STRING_CLEAR((*WORD_LIST)[WORD_LIST_INDEX]);

                }

        }

}


void WORD_LIST_TO_STRING(char** WORD_LIST, char* STRING)
{

        STRING_CLEAR(STRING);


        for (unsigned long long INDEX = 0; WORD_LIST[INDEX] != NULL; INDEX ++)
        {

                STRING_APPEND(STRING, WORD_LIST[INDEX]);
                STRING_APPEND_CHAR(STRING, ' ');

        }


        STRING_TRIM(STRING);
}


int STRING_TO_INT(const char* INT_STRING, int* INT)
{

        short SIGN = 1;
        long INDEX = 1;



        *INT = 0;



        if (!STRING_IS_INT(INT_STRING))
        {

                return STR_FAILURE;

        }


        if (INT_STRING[0] == '-')
        {

                INDEX = 1;

                SIGN = -1;

        }


        for (INDEX = INDEX; INT_STRING[INDEX] != '\0'; INDEX ++)
        {

                *INT = (*INT) * 10 + INT_STRING[INDEX] - '0';

        }



        *INT *= SIGN;



        return STR_SUCCESS;

}


int STRING_TO_LONG_LONG(const char* INT_STRING, long long* INT)
{

        short SIGN = 0;
        long INDEX = 1;



        *INT = 0;



        if (!STRING_IS_INT(INT_STRING))
        {

                return STR_FAILURE;

        }


        if (INT_STRING[0] == '-')
        {

                INDEX = 1;

                SIGN = -1;

        }


        for (INDEX = INDEX; INT_STRING[INDEX] != '\0'; INDEX++)
        {

                *INT = (*INT) * 10 + INT_STRING[INDEX] - '0';

        }



        *INT *= SIGN;



        return STR_SUCCESS;

}


int STRING_TO_UNSIGNED_INT(const char* STRING, unsigned int* INT)
{

        *INT = 0;



        if (!STRING_IS_INT(STRING))
        {

                return STR_FAILURE;

        }


        if (STRING[0] == '-')
        {

                return STR_FAILURE;

        }


        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

               *INT = ((*INT) * 10) + (STRING[INDEX] - '0');

        }


        return STR_SUCCESS;

}


int STRING_TO_UNSIGNED_LONG_LONG(const char* STRING, unsigned long long* INT)
{

        *INT = 0;



        if (!STRING_IS_INT(STRING))
        {

                return STR_FAILURE;

        }


        if (STRING[0] == '-')
        {

                return STR_FAILURE;

        }


        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

               *INT = ((*INT) * 10) + (STRING[INDEX] - '0');

        }


        return STR_SUCCESS;

}


void INT_TO_STRING(char* STRING, long long INT)
{

        STRING_CLEAR(STRING);



        if (INT == 0)
        {

                STRING_APPEND_CHAR(STRING, '0');

                return;

        }


        while (INT > 0)
        {

                const short NUMBER = INT % 10;

                INT = (INT - NUMBER) / 10;


                STRING_APPEND_CHAR(STRING, NUMBER + '0');

        }


        if (INT < 0)
        {

                INT = -INT;


                STRING_APPEND_CHAR(STRING, '-');

        }


        STRING_FLIP(STRING);

}


void UNSIGNED_INT_TO_STRING(char* STRING, unsigned long long INT)
{

        STRING_CLEAR(STRING);



        if (INT == 0)
        {

                STRING_APPEND_CHAR(STRING, '0');

                return;

        }


        while (INT > 0)
        {

                const short NUMBER = INT % 10;

                INT = (INT - NUMBER) / 10;


                STRING_APPEND_CHAR(STRING, NUMBER + '0');

        }


        if (INT < 0)
        {

                INT = -INT;


                STRING_APPEND_CHAR(STRING, '-');

        }


        STRING_FLIP(STRING);

}


char CHAR_TO_UPPER(char CHAR)
{

        const char* LOWER = "abcdefghijklmnopqrstuvwxyz";


        if (STRING_CONTAINS_CHAR(LOWER, CHAR))
        {

                CHAR -= 32;

        }


        return CHAR;

}


char CHAR_TO_LOWER(char CHAR)
{

        const char* UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


        if (STRING_CONTAINS_CHAR(UPPER, CHAR))
        {

                CHAR += 32;

        }


        return CHAR;

}


void STRING_TO_UPPER(char* STRING)
{

        const char* LOWER = "abcdefghijklmnopqrstuvwxyz";


        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING_CONTAINS_CHAR(LOWER, STRING[INDEX]))
                {

                        STRING[INDEX] -= 32;

                }

        }

}


void STRING_TO_LOWER(char* STRING)
{

        const char* UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING_CONTAINS_CHAR(UPPER, STRING[INDEX]))
                {

                        STRING[INDEX] += 32;

                }

        }

}


void STRING_APPEND(char* STRING, const char* APPEND)
{

        unsigned long long STRING_INDEX;
	unsigned long long APPEND_INDEX;



	for (STRING_INDEX = STRING_LENGTH(STRING), APPEND_INDEX = 0; APPEND[APPEND_INDEX] != '\0'; STRING_INDEX ++, APPEND_INDEX ++)
	{

                STRING[STRING_INDEX] = APPEND[APPEND_INDEX];

	}


	STRING[STRING_INDEX] = '\0';

}


void STRING_APPEND_CHAR(char* STRING, const char CHAR)
{

        unsigned long long LENGTH = STRING_LENGTH(STRING);


        STRING[LENGTH] = CHAR;
        STRING[LENGTH + 1] = '\0';

}


int STRING_INSERT(char* STRING, const char* INSERT_STRING, const unsigned long long INSERT_INDEX)
{

        unsigned long long FULL_LENGTH = STRING_LENGTH(STRING);
        unsigned long long INSERT_LENGTH = STRING_LENGTH(INSERT_STRING);



        if (INSERT_INDEX > FULL_LENGTH)
        {

                return STR_FAILURE;

        }


        for (unsigned long long INDEX = FULL_LENGTH + INSERT_LENGTH - 1; INDEX > FULL_LENGTH - 1; INDEX --)
        {

                STRING[INDEX] = STRING[INDEX - INSERT_LENGTH];

        }


        for (unsigned long long INDEX = 0; INSERT_STRING[INDEX] != '\0'; INDEX ++)
        {

                STRING[INDEX + INSERT_INDEX] = INSERT_STRING[INDEX];

        }



        return STR_SUCCESS;

}


int STRING_INSERT_CHAR(char* STRING, const char INSERT_CHAR, const unsigned long long INSERT_INDEX)
{

        unsigned long long FULL_LENGTH = STRING_LENGTH(STRING);



        if (INSERT_INDEX > FULL_LENGTH)
        {

                return STR_FAILURE;

        }


        for (unsigned long long INDEX = FULL_LENGTH; INDEX > INSERT_INDEX; INDEX --)
        {

                STRING[INDEX] = STRING[INDEX - 1];

        }



        STRING[INSERT_INDEX] = INSERT_CHAR;


        STRING[FULL_LENGTH + 1] = '\0';



        return STR_SUCCESS;

}


void STRING_FLIP(char* STRING)
{

        unsigned long long LENGTH = STRING_LENGTH(STRING);


        for (unsigned long long INDEX = 0; INDEX < LENGTH / 2; INDEX++)
        {

                unsigned long long FLIP_INDEX = LENGTH - 1 - INDEX;
                char TEMP = STRING[INDEX];


                STRING[INDEX] = STRING[FLIP_INDEX];
                STRING[FLIP_INDEX] = TEMP;

        }

}


int SUB_STRING_SELF(char* STRING, const unsigned long long STARTING_INDEX, const unsigned long long TO_TAKE)
{

        unsigned long long FULL_LENGTH = STRING_LENGTH(STRING);
        unsigned long long SUB_INDEX;
        unsigned long long STRING_INDEX;



        if (STARTING_INDEX + TO_TAKE >= FULL_LENGTH)
        {

                return STR_FAILURE;

        }


        for (SUB_INDEX = STARTING_INDEX, STRING_INDEX = 0; STRING_INDEX < TO_TAKE; SUB_INDEX ++, STRING_INDEX ++)
        {

                STRING[STRING_INDEX] = STRING[SUB_INDEX];

        }



        STRING[STRING_INDEX] = '\0';



        return STR_SUCCESS;

}


int SUB_STRING(const char* BASE_STRING, char* SUB_STRING, const unsigned long long STARTING_INDEX, const unsigned long long TO_TAKE)
{

        unsigned long long FULL_LENGTH = STRING_LENGTH(BASE_STRING);
        unsigned long long STRING_INDEX;



        if (STARTING_INDEX + TO_TAKE >= FULL_LENGTH)
        {

                return STR_FAILURE;

        }


        for (STRING_INDEX = 0; STRING_INDEX < TO_TAKE; STRING_INDEX ++)
        {

                SUB_STRING[STRING_INDEX] = BASE_STRING[STARTING_INDEX + STRING_INDEX];

        }



        SUB_STRING[STRING_INDEX] = '\0';



        return STR_SUCCESS;

}


void STRING_COPY(char* DESTINATION, const char* STRING)
{

        unsigned long long INDEX;



        for (INDEX = 0; STRING[INDEX] != '\0'; INDEX++)
        {

                DESTINATION[INDEX] = STRING[INDEX];

        }


        DESTINATION[INDEX] = '\0';

}


void STRING_SET(char* STRING, const char* SET)
{

        unsigned long long INDEX;



        for (INDEX = 0; STRING[INDEX] != '\0'; INDEX++)
        {

                STRING[INDEX] = SET[INDEX];

        }


        STRING[INDEX] = '\0';

}


void STRING_REPLACE_CHAR(char* STRING, const char FIND_CHAR, const char REPLACE_CHAR)
{

        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0'; INDEX++)
        {

                if (STRING[INDEX] == FIND_CHAR)
                {

                        STRING[INDEX] = REPLACE_CHAR;

                }

        }

}


void STRING_REMOVE_FIRST(char* STRING)
{

        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                STRING[INDEX] = STRING[INDEX + 1];

        }

}


void STRING_REMOVE_LAST(char* STRING)
{

        unsigned long long LENGTH = STRING_LENGTH(STRING);


        if (LENGTH == 0)
        {

                return;

        }


        STRING[LENGTH - 1] = '\0';

}


int STRING_REMOVE_INDEX(char* STRING, unsigned long long INDEX)
{

        if (INDEX >= STRING_LENGTH(STRING))
        {

                return STR_FAILURE;

        }


        for (INDEX = INDEX; STRING[INDEX] != '\0'; INDEX ++)
        {

                STRING[INDEX] = STRING[INDEX + 1];

        }


        return STR_SUCCESS;

}


void STRING_REMOVE_CHAR(char* STRING, const char CHAR)
{

        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0';)
        {

                if (STRING[INDEX] == CHAR)
                {

                        STRING_REMOVE_INDEX(STRING, INDEX);

                }

                else
                {

                        INDEX ++;

                }

        }

}


void STRING_TRIM(char* STRING)
{

        unsigned long long OUTER_INDEX;
        unsigned long long STARTING;
        unsigned long long ENDING;



        STARTING = 0;
        ENDING = STRING_LENGTH(STRING) - 1;



        if (STRING_IS_EMPTY(STRING))
        {

                return;

        }


        while (STRING[STARTING] == ' ' || STRING[STARTING] == '\n')
        {

                STARTING ++;

        }

        while (ENDING >= STARTING && (STRING[ENDING] == ' ' || STRING[ENDING] == '\n'))
        {

                ENDING --;

        }

        for (OUTER_INDEX = STARTING; OUTER_INDEX <= ENDING; OUTER_INDEX ++)
        {

                STRING[OUTER_INDEX - STARTING] = STRING[OUTER_INDEX];

        }


        STRING[OUTER_INDEX - STARTING] = '\0';


        for (unsigned long long INNER_INDEX = 0; STRING[INNER_INDEX] != '\0'; INNER_INDEX ++)
        {

                if (STRING[INNER_INDEX] == ' ' || STRING[INNER_INDEX] == '\n')
                {

                        while (STRING[INNER_INDEX + 1] == ' ' || STRING[INNER_INDEX + 1] == '\n')
                        {

                                STRING_REMOVE_INDEX(STRING, INNER_INDEX + 1);

                        }

                }

        }

}


void STRING_CLEAR(char* STRING)
{

        STRING[0] = '\0';

}


int STRING_FORMAT(char* STRING, const char* FORMAT, ...)
{

        va_list VARIABLES;

        unsigned long long VARIABLE_INDEX = 0;
        unsigned long long FORMAT_MARKER_COUNT = 0;


        va_start(VARIABLES, FORMAT);


        STRING_CLEAR(STRING);



        for (unsigned long long INDEX = 0; FORMAT[INDEX] != '\0'; INDEX ++)
        {

                if (FORMAT[INDEX] == '%' && FORMAT[INDEX + 1] == 'V')
                {

                        char* VARIABLE = va_arg(VARIABLES, char*);


                        STRING_APPEND(STRING, VARIABLE);


                        INDEX ++;


                        VARIABLE_INDEX ++;


                        FORMAT_MARKER_COUNT ++;

                }
                else
                {

                        STRING_APPEND_CHAR(STRING, FORMAT[INDEX]);

                }

        }



        va_end(VARIABLES);



        if (FORMAT_MARKER_COUNT != VARIABLE_INDEX + 1)
        {

                return STR_WARNING;

        }



        return STR_SUCCESS;

}


int STRING_EQUALS(const char* STRING, const char* COMPARER)
{

        unsigned long long INDEX = 0;



        while (STRING[INDEX] != '\0' && STRING[INDEX] == COMPARER[INDEX])
        {

                INDEX ++;

        }


        return STRING[INDEX] == COMPARER[INDEX];
}


int STRING_IS_EMPTY(const char* STRING)
{

        return (STRING[0] == '\0');

}


int STRING_STARTS_WITH(const char* STRING, const char* STARTING)
{

        if (STRING_LENGTH(STRING) < STRING_LENGTH(STARTING))
        {

                return FALSE;

        }


        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING[INDEX] != STARTING[INDEX])
                {

                        return FALSE;

                }

        }


        return TRUE;

}


int STRING_ENDS_WITH(const char* STRING, const char* ENDING)
{

        unsigned long long BASE_LENGTH = STRING_LENGTH(STRING);
        unsigned long long ENDING_LENGTH = STRING_LENGTH(ENDING);



        if (BASE_LENGTH < ENDING_LENGTH)
        {

                return FALSE;

        }


        for (unsigned long long INDEX = BASE_LENGTH - ENDING_LENGTH; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING[INDEX] != ENDING[INDEX])
                {

                        return FALSE;

                }

        }


        return TRUE;

}


int STRING_CONTAINS_CHAR(const char* STRING, const char CHAR)
{

        for (unsigned long long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING[INDEX] == CHAR)
                {

                        return TRUE;


                        break;

                }

        }


        return FALSE;

}


int STRING_IS_INT(const char* STRING)
{

        unsigned long long STARTING_INDEX = 0;



        if (STRING[0] == '-')
        {

                STARTING_INDEX = 1;

        }


        if (STRING[STARTING_INDEX] == '0' && STRING[STARTING_INDEX + 1] != '\0')
        {

                return FALSE;

        }


        for (unsigned long long INDEX = STARTING_INDEX; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (!STRING_CONTAINS_CHAR("0123456789", STRING[INDEX]))
                {

                        return FALSE;

                }

        }



        return TRUE;

}


unsigned long long STRING_LENGTH(const char *STRING)
{

        unsigned long long INDEX;


	for (INDEX = 0; STRING[INDEX] != '\0'; INDEX ++);


	return INDEX;

}


unsigned long long STRING_SIZE(const char* STRING)
{

        unsigned long long INDEX;


	for (INDEX = 0; STRING[INDEX] != '\0'; INDEX ++);


	return INDEX + 1;

}
