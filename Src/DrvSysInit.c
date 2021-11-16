/*======================================================================*/
/* Includes                                                             */
/*======================================================================*/
#include <Src/DrvCcu6.h>
#include <Src/DrvPinCfg.h>
#include <Src/DrvSysInit.h>


/*======================================================================*/
/* Typedefs                                                             */
/*======================================================================*/



/*======================================================================*/
/* Defines                                                              */
/*======================================================================*/


/*======================================================================*/
/* Static Function Prototype                                            */
/*======================================================================*/
static void GetClockInfo(void);


/*======================================================================*/
/* Variables                                                            */
/*======================================================================*/
ClockInfo stClockInfo;

/*======================================================================*/
/* Functions                                                            */
/*======================================================================*/
void DrvSys_Init(void)
{
    /* 0. Clock Info */
    GetClockInfo();

    /* 1. PinConfig Module */
    DrvPinCfg_Init();

    /* 2. CCU6 Module */
    DrvCcu6_Init();
}

static void GetClockInfo(void)
{
    stClockInfo.fPll0Freq = IfxScuCcu_getPllFrequency();
    stClockInfo.fSourceFreq = IfxScuCcu_getSourceFrequency();
    stClockInfo.fSriFreq = IfxScuCcu_getSriFrequency();
    stClockInfo.fSpbFreq = IfxScuCcu_getSpbFrequency();
    stClockInfo.fCpu0Freq = IfxScuCcu_getCpuFrequency(0);
    stClockInfo.fFsiFreq = IfxScuCcu_getFsiFrequency();
    stClockInfo.fFsi2Freq = IfxScuCcu_getFsi2Frequency();
    stClockInfo.fStmFreq = IfxScuCcu_getStmFrequency();
    stClockInfo.fGtmFreq = IfxScuCcu_getGtmFrequency();
    stClockInfo.fCanFreq = IfxScuCcu_getCanFrequency();
}


