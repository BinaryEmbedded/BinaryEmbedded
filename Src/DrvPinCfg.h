#ifndef DRVPINCFG_H
#define DRVPINCFG_H

/*======================================================================*/
/* Includes                                                             */
/*======================================================================*/
#include "Ifx_Types.h"
#include <Port/Io/IfxPort_Io.h>
#include <_PinMap/IfxPort_PinMap.h>


/*======================================================================*/
/* Defines                                                              */
/*======================================================================*/

// p00_5
#define IFXCFG_PORT_LED1_P00_5                           IfxPort_P00_5
#define IFXCFG_PORT_LED1_P00_5_MODE                      IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_LED1_P00_5_PAD_DRIVER                IfxPort_PadDriver_cmosAutomotiveSpeed4

// p00_6
#define IFXCFG_PORT_LED2_P00_6                           IfxPort_P00_6
#define IFXCFG_PORT_LED2_P00_6_MODE                      IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_LED2_P00_6_PAD_DRIVER                IfxPort_PadDriver_cmosAutomotiveSpeed4

#define IFXCFG_P00_5_IO_CONFIG                  { &IFXCFG_PORT_LED1_P00_5, IFXCFG_PORT_LED1_P00_5_MODE, IFXCFG_PORT_LED1_P00_5_PAD_DRIVER }
#define IFXCFG_P00_6_IO_CONFIG                  { &IFXCFG_PORT_LED2_P00_6, IFXCFG_PORT_LED2_P00_6_MODE, IFXCFG_PORT_LED2_P00_6_PAD_DRIVER }


/*======================================================================*/
/* Typedefs                                                             */
/*======================================================================*/



/*======================================================================*/
/* Variables                                                            */
/*======================================================================*/


/*======================================================================*/
/* Global Function Prototypes                                           */
/*======================================================================*/

extern void DrvPinCfg_Init(void);


#endif

