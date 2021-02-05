#include "sch_datatypes.h"
#include "Task_Man.h"
uint8 init_seq=1u;
main()
{
    uint8 current_Sch_time=0u;
    if(init_seq==1u)
    {
        task_man_init();
        init_seq=0u;
    }
    /*get current schedular time*/
    current_Sch_time = Get_Sch_Time();
    /*Evaluate if task needs to be activated*/
    Evaluate_task_activation(current_Sch_time);
    /*execute the activated task*/
    Execute_tasks();
    /*Let's enter idle Task*/
    Enter_Idle_state();
}