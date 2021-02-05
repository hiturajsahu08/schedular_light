#include "sch_datatypes.h"
#include "Tasks.h"

/*define the task list*/
struct task_list_struct{
	uint16* task_ptr[5];
	uint8 execute_task[5];
};
struct task_list_struct Task_list;
uint8 Keep_Idle_State=0u;
uint8 nr_task=5u;

void task_man_init(void)
{
    /*initialize the task list*/
    Task_list.task_ptr[0]= &Basic_Task_5ms;
    Task_list.task_ptr[1]= &Basic_Task_10ms;
    Task_list.task_ptr[2]= &Basic_Task_20ms;
    Task_list.task_ptr[3]= &Basic_Task_40ms;
    Task_list.task_ptr[4]= &Basic_Task_80ms;
    Task_list.execute_task[0]=0u;
	Task_list.execute_task[1]=0u;
	Task_list.execute_task[2]=0u;
	Task_list.execute_task[3]=0u;
	Task_list.execute_task[4]=0u;
}

void Evaluate_task_activation(uint8 current_Sch_time)
{
	/*check and activate 5ms task*/
	Task_list.execute_task[0]=1u;
	/*check and activate 10ms task*/
	if((current_Sch_time % 10) == 0u)
		Task_list.execute_task[1]=1u;
	/*check and activate 20ms task*/
	if((current_Sch_time % 20) == 0u)
		Task_list.execute_task[2]=1u;
	/*check and activate 40ms task*/
	if((current_Sch_time % 40) == 0u)
		Task_list.execute_task[3]=1u;
	/*check and activate 80ms task*/
	if((current_Sch_time % 80) == 0u)
		Task_list.execute_task[4]=1u;
}
void Execute_tasks(void)
{
	uint8 idx=0u;
	for(idx=0u;idx<nr_task;idx++)
	{
		if( Task_list.execute_task[idx]==1)
		{
			Task_list.execute_task[idx]=1u;
			Task_list.task_ptr[idx];
		}
	}
	Update_Idle_State(1u);
}

void Enter_Idle_state(void)
{	
	/*wait for next sch timer interrupt*/
	While(Keep_Idle_State);
}
void Update_Idle_State(uint8 val)
{
	Keep_Idle_State=val;
}
