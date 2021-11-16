#ifndef SCHEDULER_H
#define SCHEDULER_H
/*============================================================================*/
/* Includes                                                                   */
/*============================================================================*/
#include "Ifx_Types.h"


/*============================================================================*/
/* Defines                                                                    */
/*============================================================================*/



/*============================================================================*/
/* Typedefs                                                                   */
/*============================================================================*/
typedef struct
{
    uint8 ucTiming1msTaskFlag;
    uint8 ucTiming5msTaskFlag;
    uint8 ucTiming10msTaskFlag;
    uint8 ucTiming40msTask1Flag;
    uint8 ucTiming40msTask2Flag;
    uint8 ucTiming50msTaskFlag;
    uint8 ucTiming100msTask1Flag;
    uint8 ucTiming100msTask2Flag;
    uint8 ucTiming100msTask3Flag;
    uint8 ucTiming200msTaskFlag;
    uint8 ucTiming300msTask1Flag;
    uint8 ucTiming300msTask2Flag;
    uint8 ucTiming450msTaskFlag;
    uint8 ucTiming500msTaskFlag;
    uint8 ucTiming1sTask1Flag;
    uint8 ucTiming1sTask2Flag;
    uint8 ucTiming1sTask3Flag;
    uint8 ucTiming1sTask4Flag;
}TaskFlag;

typedef struct
{
    uint32 ulTiming1msTaskCnt;
    uint32 ulTiming5msTaskCnt;
    uint32 ulTiming10msTaskCnt;
    uint32 ulTiming40msTask1Cnt;
    uint32 ulTiming40msTask2Cnt;
    uint32 ulTiming50msTaskCnt;
    uint32 ulTiming100msTask1Cnt;
    uint32 ulTiming100msTask2Cnt;
    uint32 ulTiming100msTask3Cnt;
    uint32 ulTiming200msTaskCnt;
    uint32 ulTiming300msTask1Cnt;
    uint32 ulTiming300msTask2Cnt;
    uint32 ulTiming450msTaskCnt;
    uint32 ulTiming500msTaskCnt;
    uint32 ulTiming1sTask1Cnt;
    uint32 ulTiming1sTask2Cnt;
    uint32 ulTiming1sTask3Cnt;
    uint32 ulTiming1sTask4Cnt;
}TaskCnt;
/*============================================================================*/
/* Variables                                                                  */
/*============================================================================*/


/*============================================================================*/
/* Global Function Prototypes                                                 */
/*============================================================================*/
extern void Scheduler(void);
extern void SchedulerInit(void);
extern void Timing1ms_Callback(void);

#endif /* SCHEDULER_H */




