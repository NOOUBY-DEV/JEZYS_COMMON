long long INT_DIGITS(long long INT)
{

        unsigned long long DIGITS = 0;


        if (INT < 0)
        {

                INT = -INT;

        }


        if (INT == 0)
        {

                DIGITS = 1;

        }


        while (INT > 0)
        {

                INT -= INT % 10;
                INT /= 10;

                DIGITS ++;

        }

        return DIGITS;

}
