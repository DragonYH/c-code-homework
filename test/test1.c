#include <stdio.h>
#define COUNT 400
int main()
{
    const double Pi=3.14159265358979323846;
    int spwm_value[COUNT]={0};
    for(int i=0; i<COUNT; i++)
    {
        spwm_value[i] = 8400*sin(180.0*(i+1)/COUNT*Pi/180);
        printf("%d\n",spwm_value[i]);
    }
}