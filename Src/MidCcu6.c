/*======================================================================*/
/* Includes                                                             */
/*======================================================================*/
#include <Src/DrvCcu6.h>
#include <Src/MidCcu6.h>

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
/* Functions                                                            */
/*======================================================================*/
void MidCcu6_Reg1msTaskCallbackFn(void (*fpCallback)(void))
{
    DrvCcu6_Reg1msTaskCallbackFn(fpCallback);
}


