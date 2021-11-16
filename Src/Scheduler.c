/*======================================================================*/
/* Includes                                                             */
/*======================================================================*/
#include <Src/MidCcu6.h>
#include <Src/MidGpio.h>
#include <Src/Scheduler.h>

/*======================================================================*/
/* Typedefs                                                             */
/*======================================================================*/


/*======================================================================*/
/* Defines                                                              */
/*======================================================================*/
#define ON  (1u)
#define OFF (0u)

/*Task Cycle Define*/
#define TASK_TIMING_5MS                     5u
#define TASK_TIMING_10MS                    10u
#define TASK_TIMING_40MS                    40u
#define TASK_TIMING_50MS                    50u
#define TASK_TIMING_100MS                   100u
#define TASK_TIMING_200MS                   200u
#define TASK_TIMING_300MS                   300u
#define TASK_TIMING_450MS                   450u
#define TASK_TIMING_500MS                   500u
#define TASK_TIMING_1S                      1000u
#define TASK_TIMING_MAX                     3000u


/*Task Timing Offset Define*/
#define TASK_TIMING_OFFSET_1MS                1u
#define TASK_TIMING_OFFSET_2MS                2u
#define TASK_TIMING_OFFSET_3MS                3u
#define TASK_TIMING_OFFSET_4MS                4u
#define TASK_TIMING_OFFSET_5MS                5u
#define TASK_TIMING_OFFSET_6MS                6u
#define TASK_TIMING_OFFSET_7MS                7u
#define TASK_TIMING_OFFSET_8MS                8u
#define TASK_TIMING_OFFSET_9MS                9u


/*======================================================================*/
/* Static Function Prototype                                            */
/*======================================================================*/
static void Timing1ms_Task(void);
static void Timing5ms_Task(void);
static void Timing10ms_Task(void);
static void Timing40ms_Task1(void);
static void Timing40ms_Task2(void);
static void Timing50ms_Task(void);
static void Timing100ms_Task1(void);
static void Timing100ms_Task2(void);
static void Timing100ms_Task3(void);
static void Timing300ms_Task1(void);
static void Timing300ms_Task2(void);
static void Timing1s_Task1(void);
static void Timing1s_Task2(void);
static void Timing1s_Task3(void);
static void Timing1s_Task4(void);



/*======================================================================*/
/* Variables                                                            */
/*======================================================================*/
volatile TaskFlag gstTaskFlag = {0u,};
uint32 gulTiming1msCounter = 0u;
TaskCnt gstTaskCnt = {0u,};
uint8 testFlag = 0u;

/*======================================================================*/
/* Functions                                                            */
/*======================================================================*/

/***************************** ISR Declaration***************************/


/***************************** ISR Functions*****************************/


/*************************** Driver API Functions************************/

/*Task Cycle 1ms*/
static void Timing1ms_Task(void)
{
    gstTaskCnt.ulTiming1msTaskCnt++;

}

/*Task Cycle 5ms  (Starting task after 1ms)*/
static void Timing5ms_Task(void)
{


}

/*Task Cycle 10ms  (Starting task after 2ms)*/
static void Timing10ms_Task(void)
{

}

/*Task Cycle 40ms  (Starting task after 3ms)*/
static void Timing40ms_Task1(void)
{

}

/*Task Cycle 40ms  (Starting task after 4ms)*/
static void Timing40ms_Task2(void)
{

}

/*Task Cycle 50ms  (Starting task after 5ms)*/
static void Timing50ms_Task(void)
{

}

/*Task Cycle 100ms  (Starting task after 6ms)*/
static void Timing100ms_Task1(void)
{

}

/*Task Cycle 100ms  (Starting task after 7ms)*/
static void Timing100ms_Task2(void)
{

}

/*Task Cycle 100ms  (Starting task after 8ms)*/
static void Timing100ms_Task3(void)
{

}

/*Task Cycle 200ms  (Starting task after 9ms)*/
static void Timing200ms_Task(void)
{

}

/*Task Cycle 300ms  (Starting task after 1ms)*/
static void Timing300ms_Task1(void)
{

}

/*Task Cycle 300ms  (Starting task after 2ms)*/
static void Timing300ms_Task2(void)
{

}

/*Task Cycle 450ms  (Starting task after 3ms)*/
static void Timing450ms_Task(void)
{

}

/*Task Cycle 500ms  (Starting task after 4ms)*/
static void Timing500ms_Task(void)
{

    if (testFlag == 1)
    {
        MidGPIO_SetPinHigh(IFXCFG_PORT_LED1_P00_5);
        MidGPIO_SetPinLow(IFXCFG_PORT_LED2_P00_6);
        testFlag = 0;
    }
    else
    {
        MidGPIO_SetPinLow(IFXCFG_PORT_LED1_P00_5);
        MidGPIO_SetPinHigh(IFXCFG_PORT_LED2_P00_6);
        testFlag = 1;
    }

}

/*Task Cycle 1s  (Starting task after 5ms)*/
static void Timing1s_Task1(void)
{

}

/*Task Cycle 1s  (Starting task after 6ms)*/
static void Timing1s_Task2(void)
{

}

/*Task Cycle 1s  (Starting task after 7ms)*/
static void Timing1s_Task3(void)
{

}


/*Task Cycle 1s  (Starting task after 8ms)*/
static void Timing1s_Task4(void)
{

}

/*1ms  Timer Callback Function*/
void Timing1ms_Callback(void)
{
    gulTiming1msCounter++;

    gstTaskFlag.ucTiming1msTaskFlag = ON;

    /*Set 5ms TaskFlag (Starting task after 1ms)*/
    if((gulTiming1msCounter % TASK_TIMING_5MS) == TASK_TIMING_OFFSET_1MS)
    {
        gstTaskFlag.ucTiming5msTaskFlag = ON;
    }

    /*Set 10ms TaskFlag (Starting task after 2ms)*/
    if((gulTiming1msCounter % TASK_TIMING_10MS) == TASK_TIMING_OFFSET_2MS)
    {
        gstTaskFlag.ucTiming10msTaskFlag = ON;
    }

    /*Set 40ms TaskFlag (Starting task after 3ms)*/
    if((gulTiming1msCounter % TASK_TIMING_40MS) == TASK_TIMING_OFFSET_3MS)
    {
        gstTaskFlag.ucTiming40msTask1Flag = ON;
    }

    /*Set 40ms TaskFlag (Starting task after 4ms)*/
    if((gulTiming1msCounter % TASK_TIMING_40MS) == TASK_TIMING_OFFSET_4MS)
    {
        gstTaskFlag.ucTiming40msTask2Flag = ON;
    }

    /*Set 50ms TaskFlag (Starting task after 5ms)*/
    if((gulTiming1msCounter % TASK_TIMING_50MS) == TASK_TIMING_OFFSET_5MS)
    {
        gstTaskFlag.ucTiming50msTaskFlag = ON;
    }

    /*Set 100ms TaskFlag (Starting task after 6ms)*/
    if((gulTiming1msCounter % TASK_TIMING_100MS) == TASK_TIMING_OFFSET_6MS)
    {
        gstTaskFlag.ucTiming100msTask1Flag = ON;
    }

    /*Set 100ms TaskFlag (Starting task after 7ms)*/
    if((gulTiming1msCounter % TASK_TIMING_100MS) == TASK_TIMING_OFFSET_7MS)
    {
        gstTaskFlag.ucTiming100msTask2Flag = ON;
    }

    /*Set 100ms TaskFlag (Starting task after 8ms)*/
    if((gulTiming1msCounter % TASK_TIMING_100MS) == TASK_TIMING_OFFSET_8MS)
    {
        gstTaskFlag.ucTiming100msTask3Flag = ON;
    }

    /*Set 200ms TaskFlag (Starting task after 9ms)*/
    if((gulTiming1msCounter % TASK_TIMING_200MS) == TASK_TIMING_OFFSET_9MS)
    {
        gstTaskFlag.ucTiming200msTaskFlag = ON;
    }

    /*Set 300ms TaskFlag (Starting task after 1ms)*/
    if((gulTiming1msCounter % TASK_TIMING_300MS) == TASK_TIMING_OFFSET_1MS)
    {
        gstTaskFlag.ucTiming300msTask1Flag = ON;
    }

    /*Set 300ms TaskFlag (Starting task after 2ms)*/
    if((gulTiming1msCounter % TASK_TIMING_300MS) == TASK_TIMING_OFFSET_2MS)
    {
        gstTaskFlag.ucTiming300msTask2Flag = ON;
    }

    /*Set 450ms TaskFlag (Starting task after 4ms)*/
    if((gulTiming1msCounter % TASK_TIMING_450MS) == TASK_TIMING_OFFSET_4MS)
    {
        gstTaskFlag.ucTiming450msTaskFlag = ON;
    }

    /*Set 500ms TaskFlag (Starting task after 3ms)*/
    if((gulTiming1msCounter % TASK_TIMING_500MS) == TASK_TIMING_OFFSET_3MS)
    {
        gstTaskFlag.ucTiming500msTaskFlag = ON;
    }

    /*Set 1s TaskFlag (Starting task after 5ms)*/
    if((gulTiming1msCounter % TASK_TIMING_1S) == TASK_TIMING_OFFSET_5MS)
    {
        gstTaskFlag.ucTiming1sTask1Flag = ON;
    }

    /*Set 1s TaskFlag (Starting task after 6ms)*/
    if((gulTiming1msCounter % TASK_TIMING_1S) == TASK_TIMING_OFFSET_6MS)
    {
        gstTaskFlag.ucTiming1sTask2Flag = ON;
    }

    /*Set 1s TaskFlag (Starting task after 7ms)*/
    if((gulTiming1msCounter % TASK_TIMING_1S) == TASK_TIMING_OFFSET_7MS)
    {
        gstTaskFlag.ucTiming1sTask3Flag = ON;
    }

    /*Set 1s TaskFlag (Starting task after 8ms)*/
    if((gulTiming1msCounter % TASK_TIMING_1S) == TASK_TIMING_OFFSET_8MS)
    {
        gstTaskFlag.ucTiming1sTask4Flag = ON;
    }

    /*1ms TimingCounter Reset at 3sec*/
    if(gulTiming1msCounter >= TASK_TIMING_MAX)
    {
        gulTiming1msCounter = 0u;
    }
}


/*Callback Function Initialization*/
void SchedulerInit(void)
{
    MidCcu6_Reg1msTaskCallbackFn(Timing1ms_Callback);
}

void Scheduler(void)
{
    if(gstTaskFlag.ucTiming1msTaskFlag == ON)
    {
        Timing1ms_Task();
        gstTaskFlag.ucTiming1msTaskFlag = OFF;

        if(gstTaskFlag.ucTiming5msTaskFlag == ON)
        {
            Timing5ms_Task();
            gstTaskFlag.ucTiming5msTaskFlag = OFF;
        }

        if(gstTaskFlag.ucTiming10msTaskFlag == ON)
        {
            Timing10ms_Task();
            gstTaskFlag.ucTiming10msTaskFlag = OFF;
        }

        if(gstTaskFlag.ucTiming40msTask1Flag == ON)
        {
            Timing40ms_Task1();
            gstTaskFlag.ucTiming40msTask1Flag = OFF;
        }

        if(gstTaskFlag.ucTiming40msTask2Flag == ON)
        {
            Timing40ms_Task2();
            gstTaskFlag.ucTiming40msTask2Flag = OFF;
        }

        if(gstTaskFlag.ucTiming50msTaskFlag == ON)
        {
            Timing50ms_Task();
            gstTaskFlag.ucTiming50msTaskFlag = OFF;
        }

        if(gstTaskFlag.ucTiming100msTask1Flag == ON)
        {
            Timing100ms_Task1();
            gstTaskFlag.ucTiming100msTask1Flag = OFF;
        }

        if(gstTaskFlag.ucTiming100msTask2Flag == ON)
        {
            Timing100ms_Task2();
            gstTaskFlag.ucTiming100msTask2Flag = OFF;
        }

        if(gstTaskFlag.ucTiming100msTask3Flag == ON)
        {
            Timing100ms_Task3();
            gstTaskFlag.ucTiming100msTask3Flag = OFF;
        }

        if(gstTaskFlag.ucTiming200msTaskFlag == ON)
        {
            Timing200ms_Task();
            gstTaskFlag.ucTiming200msTaskFlag = OFF;
        }

        if(gstTaskFlag.ucTiming300msTask1Flag == ON)
        {
            Timing300ms_Task1();
            gstTaskFlag.ucTiming300msTask1Flag = OFF;
        }

        if(gstTaskFlag.ucTiming300msTask2Flag == ON)
        {
            Timing300ms_Task2();
            gstTaskFlag.ucTiming300msTask2Flag = OFF;
        }

        if(gstTaskFlag.ucTiming450msTaskFlag == ON)
        {
            Timing450ms_Task();
            gstTaskFlag.ucTiming450msTaskFlag = OFF;
        }

        if(gstTaskFlag.ucTiming500msTaskFlag == ON)
        {
            Timing500ms_Task();
            gstTaskFlag.ucTiming500msTaskFlag = OFF;
        }

        if(gstTaskFlag.ucTiming1sTask1Flag == ON)
        {
            Timing1s_Task1();
            gstTaskFlag.ucTiming1sTask1Flag = OFF;
        }

        if(gstTaskFlag.ucTiming1sTask2Flag == ON)
        {
            Timing1s_Task2();
            gstTaskFlag.ucTiming1sTask2Flag = OFF;
        }

        if(gstTaskFlag.ucTiming1sTask3Flag == ON)
        {
            Timing1s_Task3();
            gstTaskFlag.ucTiming1sTask3Flag = OFF;
        }

        if(gstTaskFlag.ucTiming1sTask4Flag == ON)
        {
            Timing1s_Task4();
            gstTaskFlag.ucTiming1sTask4Flag = OFF;
        }
    }
}

