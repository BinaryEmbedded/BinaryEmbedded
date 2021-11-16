/*======================================================================*/
/* Includes                                                             */
/*======================================================================*/
#include <Src/DrvCcu6.h>
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
static void DrvCcu60_T12_Init(void);

/*======================================================================*/
/* Variables                                                            */
/*======================================================================*/
IfxCcu6_Timer g_timer;
void(*DrvCcu60_Timing1msCallback)(void) = NULL;


/*======================================================================*/
/* Functions                                                            */
/*======================================================================*/

/***************************** ISR Declaration********************************/
IFX_INTERRUPT(Isr_Ccu60T12, 0, ISR_PRIORITY_CCU60_T12_TIMER);


/***************************** ISR Functions**********************************/
void Isr_Ccu60T12(void)
{
    IfxCpu_enableInterrupts();

    DrvCcu60_Timing1msCallback();
}

/***************************** Driver API Functions********************************/
void DrvCcu6_Reg1msTaskCallbackFn(void(*fpCallback)(void))
{
    DrvCcu60_Timing1msCallback = fpCallback;
}

/***************************** Driver Initialization Function********************************/
void DrvCcu6_Init(void)
{
    DrvCcu60_T12_Init();    /*Core0 1ms Task Timer*/
}

static void DrvCcu60_T12_Init(void)
{
    IfxCcu6_Timer_Config timerConfig;                               /* Structure for timer configuration                        */
    IfxCcu6_Timer_initModuleConfig(&timerConfig, &MODULE_CCU60);    /* Initialize the timer module structure with default values*/

    /* The Serial Peripheral Bus has a default Frequency of Fcc6 = 100000000 Hz = 100 MHz
     * Possible frequencies for the CCU6 timer are:
     *       - 100000000 Hz = 100 MHz   (Fcc6)
     *       - 50000000 Hz  = 50 MHz    (Fcc6/2)
     *       - 25000000 Hz  = 25 MHz    (Fcc6/4)
     *       - 12500000 Hz  = 12.5 MHz  (Fcc6/8)
     *       - 6250000 Hz   = 6.25 MHz  (Fcc6/16)
     *       - 3125000 Hz   ~ 3 MHz     (Fcc6/32)
     *       - 1562500 Hz   ~ 1.5 MHz   (Fcc6/64)
     *       - 781250 Hz    ~ 780 KHz   (Fcc6/128)
     *       - 390625 Hz    ~ 390 KHz   (Fcc6/256)
     *       - 195312.5 Hz  ~ 200 KHz   (Fcc6/512)
     *       - 97656.25 Hz  ~ 100 KHz   (Fcc6/1024)
     *       - 48828.12 Hz  ~ 50 KHz    (Fcc6/2048)
     *       - 24414.06 Hz  ~ 25 KHz    (Fcc6/4096)
     *       - 12207.03 Hz  ~ 12.5 KHz  (Fcc6/8192)
     *       - 6103.51 Hz   ~ 6 KHz     (Fcc6/16384)
     *       - 3051.75 Hz   ~ 3 KHz     (Fcc6/32768)
     */
    timerConfig.base.t12Frequency = 6250000u;                                   /* Configure the frequency of the timer module, 6.25MHz */
    timerConfig.base.t12Period = 6250u;                                         /* Configure the period of the timer (16-bit)  */
    timerConfig.timer = IfxCcu6_TimerId_t12;                                    /* Select the timer to be started              */
    timerConfig.interrupt1.source = IfxCcu6_InterruptSource_t12PeriodMatch;     /* Set interrupt source                */
    timerConfig.interrupt1.serviceRequest = IfxCcu6_ServiceRequest_0;
    timerConfig.interrupt1.priority = ISR_PRIORITY_CCU60_T12_TIMER;             /* Set the priority of the ISR                 */
    timerConfig.interrupt1.typeOfService = IfxSrc_Tos_cpu0;                     /* Set the type of service for the interrupt   */
    timerConfig.trigger.t13InSyncWithT12 = FALSE;                               /* Configure timers synchronization            */

    IfxCcu6_Timer_initModule(&g_timer, &timerConfig);                           /* Initialize the CCU6 module                  */

    IfxCcu6_Timer_start(&g_timer);
}


