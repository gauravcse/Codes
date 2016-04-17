#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    while (--argc)
    {
        long   l, index;
        double sum;

        if ((l = atol(*++argv)) > 0)
        {
            /* log(1) + ... + log(N-1) + log(N) */
            for (sum = 0, index = 1; index <= l; index++)
                sum += log10((double) index);

            /* CEILING[(log(1) + ... + log(N-1) + log(N))] */
            sum = ceil(sum);

            printf("%ld! is %.0f digits long\n",l,sum);
        }
        else printf("\"%s\" is not a valid value\n",*argv);
    }

    return EXIT_SUCCESS;
}
