#include "STRING_LISTS.h"
#include "STRINGS.h"
#include <stdio.h>
#include <stdlib.h>



#define STRLIST_SUCCESS 1
#define STRLIST_FAILURE 0




int STRING_LIST_SETUP(char*** STRING_LIST, const unsigned long long LIST_SIZE, const unsigned long long STRING_SIZE)
{

        *STRING_LIST = malloc((LIST_SIZE + 1) * sizeof(char*));



        if (*STRING_LIST == NULL)
        {

                return STRLIST_FAILURE;

        }


        for (unsigned long long INDEX = 0; INDEX < LIST_SIZE; INDEX ++)
        {

                (*STRING_LIST)[INDEX] = malloc(STRING_SIZE);


                if ((*STRING_LIST)[INDEX] == NULL)
                {

                        for (unsigned long long COUNTER = 0; COUNTER < INDEX; COUNTER ++)
                        {

                                free((*STRING_LIST)[COUNTER]);

                        }


                        free(*STRING_LIST);


                        *STRING_LIST = NULL;


                        return STRLIST_FAILURE;

                }


                STRING_CLEAR((*STRING_LIST)[INDEX]);

        }



        (*STRING_LIST)[LIST_SIZE] = NULL;



        return STR_SUCCESS;

}


void FREE_STRING_LIST(char*** STRING_LIST)
{

        const unsigned long long LIST_SIZE = STRING_LIST_SIZE(STRING_LIST);


        for (unsigned long long INDEX = 0; INDEX < LIST_SIZE; INDEX ++)
        {

                free((*STRING_LIST)[INDEX]);

        }


        free(*STRING_LIST);

}


void STRING_LIST_APPEND(char*** STRING_LIST, const char* APPEND_STRING)
{

        unsigned long long LIST_SIZE = STRING_LIST_SIZE(STRING_LIST);
        unsigned long long INDEX = LIST_SIZE - 1;



        while (STRING_EQUALS((*STRING_LIST)[INDEX], EMPTY) && INDEX > 0)
        {

                INDEX --;

        }


        if (INDEX == LIST_SIZE - 1)
        {

                return;

        }

        if (INDEX == 0 && STRING_EQUALS((*STRING_LIST)[0], EMPTY))
        {

                STRING_COPY((*STRING_LIST)[0], APPEND_STRING);

                return;

        }


        STRING_COPY((*STRING_LIST)[INDEX + 1], APPEND_STRING);

}


unsigned long long STRING_LIST_SIZE(char*** STRING_LIST)
{

        unsigned long long INDEX = 0;


        while ((*STRING_LIST)[INDEX] != NULL)
        {

                INDEX ++;

        }


        return INDEX;

}
