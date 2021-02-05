#include "sch_datatypes.h"
#include "Task_Man.h"
uint8 Sch_time=0u;
Sch_timer_Isr()
{
	if(Sch_time >=0u && Sch_time <=80u)
		Sch_time = Sch_time + 5u;
	else if(Sch_time > 80u)
		Sch_time = 5u;
	else{}
	Update_Idle_State(0u);
}

uint8 Get_Sch_time(void)
{
	return Sch_time;
}