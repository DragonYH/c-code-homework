#include "sogi.h"
/*
SOGI变换
调用频繁，使用内联函数增加效率
*/
float k = 1.0f;
void sogi(signal_PLL *signal)
{
    signal->temp->lamda = 0.5f * signal->omiga * signal->Ts;
    signal->temp->x = 2 * k * signal->omiga * signal->Ts;
    signal->temp->y = signal->omiga * signal->Ts * signal->omiga * signal->Ts;

    signal->temp->b0 = signal->temp->x / (signal->temp->x + signal->temp->y +4);
    signal->temp->a1 = (8-2 * signal->temp->y) / (signal->temp->x + signal->temp->y + 4);
    signal->temp->a2 = (signal->temp->x - signal->temp->y - 4) / (signal->temp->x + signal->temp->y + 4);

    signal->d_0 = signal->temp->b0 * signal->u_0 - signal->temp->b0 * signal->u_2 + signal->temp->a1 * signal->d_1 + signal->temp->a2 * signal->d_2;
    signal->q_0 = signal->temp->b0 * signal->u_0 +2 * signal->temp->b0 * signal->u_1 + signal->temp->b0 * signal->u_2 + signal->temp->a1 * signal->q_1 + signal->temp->a2 * signal->q_2;

    signal->u_2 = signal->u_1;
    signal->u_1 = signal->u_0;
    signal->d_2 = signal->d_1;
    signal->d_1 = signal->d_0;
    signal->q_2 = signal->q_1;
    signal->q_1 = signal->q_0;
}
