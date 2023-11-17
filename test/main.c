#include "sogi.h"
#include <math.h>
#include <stdio.h>
int main()
{
    float s;
    signal_PLL *si;
    for(int i = 0; i < 360; i++)
    {
        s = (float)sin(i);
        si->u_0 = s;
        sogi(si);
        printf("%f", s);
        printf("%f", si->d_0);
        printf("%f", si->q_0);
    }
    return 0;
}