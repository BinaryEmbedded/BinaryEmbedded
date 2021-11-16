/*======================================================================*/
/* Includes                                                             */
/*======================================================================*/
#include <Src/DrvPinCfg.h>

/*======================================================================*/
/* Typedefs                                                             */
/*======================================================================*/


/*======================================================================*/
/* Defines                                                              */
/*======================================================================*/


/*======================================================================*/
/* Static Function Prototype                                            */
/*======================================================================*/
static void gpio_init_pins(void);


/*======================================================================*/
/* Variables                                                            */
/*======================================================================*/

/* GPIO pin configuration */
static const IfxPort_Io_ConfigPin gpio_pin_table[] =
{
    IFXCFG_P00_5_IO_CONFIG,
    IFXCFG_P00_6_IO_CONFIG
};

static const IfxPort_Io_Config gpio_io_config_table =
{
    sizeof(gpio_pin_table)/sizeof(IfxPort_Io_ConfigPin),
    (IfxPort_Io_ConfigPin*)gpio_pin_table
};

/*======================================================================*/
/* Functions                                                            */
/*======================================================================*/

/***************************** Driver API Functions********************************/


/************************* Driver Initialization Function**************************/
void DrvPinCfg_Init(void)
{
    /*GPIO Init*/
    gpio_init_pins();

    /*GPO Init Value*/
    IfxPort_setPinLow(IFXCFG_PORT_LED1_P00_5.port, IFXCFG_PORT_LED1_P00_5.pinIndex);
    IfxPort_setPinLow(IFXCFG_PORT_LED2_P00_6.port, IFXCFG_PORT_LED2_P00_6.pinIndex);

}

static void gpio_init_pins(void)
{
    IfxPort_Io_initModule(&gpio_io_config_table);
}


