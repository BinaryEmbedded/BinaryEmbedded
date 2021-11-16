/*======================================================================*/
/* Includes                                                             */
/*======================================================================*/
#include <Src/MidGpio.h>


/*======================================================================*/
/* Typedefs                                                             */
/*======================================================================*/


/*======================================================================*/
/* Defines                                                              */
/*======================================================================*/


/*======================================================================*/
/* Static Function Prototype                                            */
/*======================================================================*/

/*======================================================================*/
/* Variables                                                            */
/*======================================================================*/

/*======================================================================*/
/* GlobalFunctions                                                      */
/*======================================================================*/
void MidGPIO_SetPinHigh(IfxPort_Pin ifxPort)
{
    IfxPort_setPinHigh(ifxPort.port, ifxPort.pinIndex);
}

void MidGPIO_SetPinLow(IfxPort_Pin ifxPort)
{
    IfxPort_setPinLow(ifxPort.port, ifxPort.pinIndex);
}


boolean MidGPIO_GetPinState(IfxPort_Pin ifxPort)
{
    return IfxPort_getPinState(ifxPort.port, ifxPort.pinIndex);
}

/*======================================================================*/
/* Static Functions                                                     */
/*======================================================================*/

