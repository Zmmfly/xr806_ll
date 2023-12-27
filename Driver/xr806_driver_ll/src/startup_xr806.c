#include "xr806.h"

typedef void(*VectorTable_Type)(void);

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN 
void Reset_Handler(void);
void Default_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak));
void MemManage_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SecureFault_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));

void DMA_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOA_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SDC0_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void MBOX_A_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI0_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void WDT_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM0_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void ALARM0_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void ALARM1_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void CSI_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void I2S_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM_ECT_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void CRYPTENG_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void GPADC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOB_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void DMIC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void IRRX_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void IRTX_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void MBOX_B_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void APP_WKUP_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void FLASHC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SDC1_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void WIFIC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void CODEC_DAC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void CODEC_ADC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void AVS_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void PSRAMC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void KEYSCAN_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void SMCARD_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SEC_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void LPUART0_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void LPUART1_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void RCCAL_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VectorTable_Type __VECTOR_TABLE[];

__VECTOR_TABLE_ATTRIBUTE
const VectorTable_Type __VECTOR_TABLE[] = {
    (VectorTable_Type)(&__INITIAL_SP),  /* offset: 0x00, Initial Stack Pointer */
    Reset_Handler,                      /* offset: 0x04, Reset Handler */
    NMI_Handler,                        /* offset: 0x08, -14 NMI Handler */
    HardFault_Handler,                  /* offset: 0x0c, -13 Hard Fault Handler */
    MemManage_Handler,                  /* offset: 0x10, -12 MPU Fault Handler */
    BusFault_Handler,                   /* offset: 0x14, -11 Bus Fault Handler */
    UsageFault_Handler,                 /* 0ffset: 0x18, -10 Usage Fault Handler */
    0,                                  /* offset: 0x1c, Reserved */
    0,                                  /* offset: 0x20, Reserved */
    0,                                  /* offset: 0x24, Reserved */
    0,                                  /* offset: 0x28, Reserved */
    SVC_Handler,                        /* offset: 0x2c, -5 SVCall Handler */
    DebugMon_Handler,                   /* offset: 0x30, -4 Debug Monitor Handler */
    0,                                  /* offset: 0x34, Reserved */
    PendSV_Handler,                     /* offset: 0x38, PendSV Handler */
    SysTick_Handler,                    /* offset: 0x3c, SysTick Handler */

    DMA_IRQHandler,                     /* offset: 0x40, DMA Handler */
    GPIOA_IRQHandler,                   /* offset: 0x44, GPIOA Handler */
    SDC0_IRQHandler,                    /* offset: 0x48, SDC0 Handler */
    MBOX_A_IRQHandler,                  /* offset: 0x4c, MessageBox A Handler */
    UART0_IRQHandler,                   /* offset: 0x50, UART0 Handler */
    UART1_IRQHandler,                   /* offset: 0x54, UART1 Handler */
    SPI0_IRQHandler,                    /* offset: 0x58, SPI0 Handler */
    SPI1_IRQHandler,                    /* offset: 0x5c, SPI1 Handler */
    I2C0_IRQHandler,                    /* offset: 0x60, I2C0 Handler */
    I2C1_IRQHandler,                    /* offset: 0x64, I2C1 Handler */
    WDT_IRQHandler,                     /* offset: 0x68, WDT Handler  */
    TIM0_IRQHandler,                    /* offset: 0x6c, TIM0 Handler */
    TIM1_IRQHandler,                    /* offset: 0x70, TIM1 Handler */
    ALARM0_IRQHandler,                  /* offset: 0x74, Alarm0 Handler */
    ALARM1_IRQHandler,                  /* offset: 0x78, Alarm1 Handler */
    CSI_IRQHandler,                     /* offset: 0x7c, CSI Handler */
    I2S_IRQHandler,                     /* offset: 0x80, I2S Digital Audio Handler */
    PWM_ECT_IRQHandler,                 /* offset: 0x84, PWM/ECT Handler */
    CRYPTENG_IRQHandler,                /* offset: 0x88, Crypto Engine Handler */
    GPADC_IRQHandler,                   /* offset: 0x8c, GPADC Handler */
    GPIOB_IRQHandler,                   /* offset: 0x90, GPION Handler */
    DMIC_IRQHandler,                    /* offset: 0x94, DMIC Handler */
    IRRX_IRQHandler,                    /* offset: 0x98, IR Receiver Handler */
    IRTX_IRQHandler,                    /* offset: 0x9c, IR Transmitter Handler */
    MBOX_B_IRQHandler,                  /* offset: 0xa0, MessageBox B Handler */
    APP_WKUP_IRQHandler,                /* offset: 0xa4, App Wakeup Handler */
    FLASHC_IRQHandler,                  /* offset: 0xa8, Flash Handler */
    UART2_IRQHandler,                   /* offset: 0xac, UART2 Handler */
    SDC1_IRQHandler,                    /* offset: 0xb0, SDC1 Handler */
    WIFIC_IRQHandler,                   /* offset: 0xb4, WLAN Handler */
    CODEC_DAC_IRQHandler,               /* offset: 0xb8, Codec DAC Handler */
    CODEC_ADC_IRQHandler,               /* offset: 0xbc, Codec ADC Handler */
    AVS_IRQHandler,                     /* offset: 0xc0, AVS psensor Handler */
    GPIOC_IRQHandler,                   /* offset: 0xc4, GPIOC Handler */
    PSRAMC_IRQHandler,                  /* offset: 0xc8, PSRAM Handler */
    0,                                  /* offset: 0xcc, Reserved for BLE LL Handler */
    0,                                  /* offset: 0xd0, Reserved for BTCOEX Handler */
    KEYSCAN_IRQHandler,                 /* offset: 0xd4, KEYSCAN Handler */
    SMCARD_IRQHandler,                  /* offset: 0xd8, SmartCard Handler */
    DMA_SEC_IRQHandler,                 /* offset: 0xdc, Secure DMA Handler */
    0,                                  /* offset: 0xe0, Reserved */
    LPUART0_IRQHandler,                 /* offset: 0xe4, LPUART0 Handler */
    LPUART1_IRQHandler,                 /* offset: 0xe8, LPUART1 Handler */
    SecureFault_Handler,                /* offset: 0xec, SecureFault Handler */
    RCCAL_IRQHandler,                   /* offset: 0xf0, RCOSC Calibration Handler */
};

#if defined ( __GNUC__ )
    #pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();                             /* CMSIS System Initialization */
    __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*----------------------------------------------------------------------------
  Hard Fault Handler
 *----------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
  while(1);
}

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif
