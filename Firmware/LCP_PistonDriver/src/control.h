#ifndef CONTROL_H
#define CONTROL_H
//void CTRL_Write(

#include "config.h"

#define CTRL_VOLUME_DIFF_MAX    (SYS_VOLUME_DIFF_MAX)

void CTRL_Init(void);
void CTRL_Check_Write(void);

#endif // CONTROL_H
