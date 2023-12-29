#ifndef __XR806_H__
#define __XR806_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define __CM33_REV          0x0000U
#define __FPU_PRESENT       1
#define __DSP_PRESENT       1
#define __SAUREGION_PRESENT 1

#define __MPU_PRESENT           0
#define __NVIC_PRIO_BITS        3
#define __Vendor_SysTickConfig  0

typedef enum IRQn_Type
{
    Reset_IRQn            = -15,    /* Reset interrupt */
    NMI_IRQn              = -14,    /* Non maskable interrupt */
    HardFault_IRQn        = -13,    /* Hardfault interrupt */
    MemoryManagement_IRQn = -12,    /* Memory management interrupt */
    BusFault_IRQn         = -11,    /* Bus fault interrupt */
    UsageFault_IRQn       = -10,    /* Usage fault interrupt */
    SecureFault_IRQn      = -9,     /* Secure fault interrupt */
    SVCall_IRQn           = -5,     /* SV Call interrupt */
    DebugMonitor_IRQn     = -4,     /* Debug Monitor interrupt */
    PendSV_IRQn           = -2,     /* Pend SV interrupt */
    SysTick_IRQn          = -1,     /* System Tick interrupt */

    /* Specific Interrupt Numbers */
    DMA_IRQn            = 0,
    GPIOA_IRQn          = 1,
    UART0_IRQn          = 4,
    UART1_IRQn          = 5,
    SPI0_IRQn           = 6,
    I2C0_IRQn           = 8,
    I2C1_IRQn           = 9,
    WDT_IRQn            = 10,
    TIM0_IRQn           = 11,
    TIM1_IRQn           = 12,
    RTC_SEC_ALARM_IRQn  = 13,
    RTC_WDAY_ALARM_IRQn = 14,
    I2S_IRQn            = 16,
    PWM_ECT_IRQn        = 17,
    CRYPTENG_IRQn       = 18,
    GPADC_IRQn          = 19,
    GPIOB_IRQn          = 20,
    IRRX_IRQn           = 22,
    IRTX_IRQn           = 23,
    A_WAKEUP_IRQn       = 25,
    FLASHC_IRQn         = 26,
    UART2_IRQn          = 27,
    WIFIC_IRQn          = 29,
    CODEC_DAC_IRQn      = 30,
    CODEC_ADC_IRQn      = 31,
    AVS_IRQn            = 32,   /* AVS psensor */
    BLE_LL_IRQn         = 35,
    BTCOEX_IRQn         = 36,
    KEYSCAN_IRQn        = 37,
    SMCARD_IRQn         = 38,
    DMA_SEC_IRQn        = 39,
    CAPSEN_IRQn         = 40,
    LPUART0_IRQn        = 41,
    LPUART1_IRQn        = 42,
    TZASC_IRQn          = 43,
}IRQn_Type;

#include <core_cm33.h>
#include <cmsis_compiler.h>

#define PERIPH_BASE         (0x4000000U)
#define DMA_BASE            (PERIPH_BASE + 0x00001000)
#define SDC0_BASE           (PERIPH_BASE + 0x00002000)
#define SDC1_BASE           (PERIPH_BASE + 0x00003000)
#define CRYPTENG_BASE       (PERIPH_BASE + 0x00004000)
#define SPI0_BASE           (PERIPH_BASE + 0x00005000)
#define SPI1_BASE           (PERIPH_BASE + 0x00006000)
#define CSI_BASE            (PERIPH_BASE + 0x00007000)
#define JPEG_BASE           (PERIPH_BASE + 0x00007400)
#define DCACHE_BASE         (PERIPH_BASE + 0x00009000)
#define SYSCTL_BASE         (PERIPH_BASE + 0x0000a000)
#define FLASHC_BASE         (PERIPH_BASE + 0x0000b000)
#define ICACHE_BASE         (PERIPH_BASE + 0x0000c000)
#define PSRAM_CTRL_BASE     (FLASHC_BASE + 0x00000800)
#define WIFIC_BASE          (PERIPH_BASE + 0x0000d000)
#define PRCM_BASE           (PERIPH_BASE + 0x00040000)
#define CCM_BASE            (PERIPH_BASE + 0x00040400)
#define TIM_BASE            (PERIPH_BASE + 0x00040800)
#define UART0_BASE          (PERIPH_BASE + 0x00040c00)
#define UART1_BASE          (PERIPH_BASE + 0x00041000)
#define UART2_BASE          (PERIPH_BASE + 0x00041400)
#define RTC_BASE            (PERIPH_BASE + 0x00041800)
#define I2C0_BASE           (PERIPH_BASE + 0x00041c00)
#define I2C1_BASE           (PERIPH_BASE + 0x00042000)
#define PWM_BASE            (PERIPH_BASE + 0x00042800)
#define I2S_BASE            (PERIPH_BASE + 0x00042c00)
#define ADC_BASE            (PERIPH_BASE + 0x00043000)
#define IRTX_BASE           (PERIPH_BASE + 0x00043400)
#define IRRX_BASE           (PERIPH_BASE + 0x00043800)
#define EFUSE_BASE          (PERIPH_BASE + 0x00043c00)
#define CODEC_BASE          (PERIPH_BASE + 0x00044000)
#define TRNG_BASE           (PERIPH_BASE + 0x00044400)
#define GPIOA_BASE          (PERIPH_BASE + 0x00050000)
#define GPIOB_BASE          (PERIPH_BASE + 0x00050024)
#define GPIOA_IRQ_BASE      (PERIPH_BASE + 0x00050200)
#define GPIOB_IRQ_BASE      (PERIPH_BASE + 0x00050220)
#define KEYSCAN_BASE        (PERIPH_BASE + 0x00044800)
#define ISO7816_BASE        (PERIPH_BASE + 0x00044c00)
#define FLASH_CRYPT_BASE    (PERIPH_BASE + 0x00045000)
#define CAPSENSE_BASE       (PERIPH_BASE + 0x00045400)
#define LPUART0_BASE        (PERIPH_BASE + 0x00045800)
#define LPUART1_BASE        (PERIPH_BASE + 0x00045c00)
#define RCOSC_CALI_BASE     (PERIPH_BASE + 0x00046000) 
#define TZ_BASE             (PERIPH_BASE + 0x00080000)
#define DMA_SEC_BASE        (PERIPH_BASE + 0x00081000)
#define TZASC_BASE          (PERIPH_BASE + 0x000A1000)

/**
 * @brief define bit value
 * 
 * @param b bit pos, begin from zero
 * 
 */
#define BIT(b)              (1U<<(b))

/**
 * @brief Set register bit(s)
 * 
 * @param reg register
 * @param msk bit(s) mask
 * 
 */
#define BIT_SET(reg, msk)   ((reg) | (msk))

/**
 * @brief Clear register bit(s)
 * 
 * @param reg register
 * @param msk bit(s) mask
 */
#define BIT_CLR(reg, msk)   ((reg) &= (~(msk)))

/**
 * @brief define unsigned integer
 * 
 * @param width
 * 
 */
#define u(width)    uint##width##_t

/**
 * @brief Edit register bit(s)
 * 
 * @param reg register
 * @param width register width, could be 8, 16, 32, 64
 * @param msb edit value msb
 * @param lsb edit value lsb, NOTE: val will left shit lsb bits
 * @param val new bit(s) value
 */
#define BITS_EDIT(reg, width, msb, lsb, val) do { \
    u(width) _reg_old  = (reg);                              /* get old register value */ \
    u(64)    _mask     = ~((u(64))(0));                      /* build full mask */ \
    u(64)    _reg_mask = (_mask << ((msb)+1))                /* left mask */ \
                        |(_mask >> ((width) - (lsb)));       /* right mask */ \
    u(width) _reg_new  = (_reg_old & _reg_mask)              /* reset old register bit(s) */ \
                        |(((val) << (lsb)) & (~_reg_mask));  /* shift value, and AND NOT(reg_mask) for safe */ \
    (reg) = _reg_new;                                        /* assign new register value */ \
}while(0)

/**
 * @brief Clock Control Module registers
 * 
 */
typedef struct
{
    __IO u(32) BUS_CLKCFG;              /* CPU Bus clock configure register */
    __IO u(32) BUS_PERIPH_CLK_CTRL;     /* Bus device clock gating control register */
    __IO u(32) BUS_PERIPH_RST_CTRL;     /* Bus device reset control register */
    __IO u(32) RESERVED1[5];
    __IO u(32) SPI0_MCLK_CTRL;          /* SPI0 clock control register */
    __IO u(32) RESERVED2[2];
    __IO u(32) CRYPTENG_MCLK_CTRL;      /* Crypto Engine clock control register */
    __IO u(32) RESERVED3;
    __IO u(32) I2S_MCLK_CTRL;           /* I2S digital audio clock control register */
    __IO u(32) IRRX_MCLK_CTRL;          /* IR RX clock control register */
    __IO u(32) IRTX_MCLK_CTRL;          /* IR TX clock control register */
    __IO u(32) SYSTICK_REFCLK_CTRL;     /* System Tick reference clock register */
    __IO u(32) SYSTICK_CALIB_CTRL;      /* System Tick clock calibration register */
    __IO u(32) RESERVED4[3];
    __IO u(32) FLASHC_MCLK_CTRL;        /* Flash controller clock control register */
    __IO u(32)  RESERVED5;
    __IO u(32) APBSPC_CLKCFG;           /* Special APB peripheral(UART/PRCM/RTC) clock configure register */
    __IO u(32) PSRAM_MCLK_CTRL;         /* PSRAM controller clock control register */
    __IO u(32) KEYSCAN_MCLK_CTRL;       /* KEYSCAN clock control register */
}CCM_TypeDef;
#define CCM ((CCM_TypeDef*)CCM_BASE)

typedef struct
{
    __IO u(32) TLDO_CTRL;               /* offset: 0x0000, TOP_LDO and SMPS control register */
    __IO u(32) LDO_MISC;                /* offset: 0x0004, LDO and switch control register */
    __IO u(32) LFCLK_CTRL;              /* offset: 0x0008, Low speed clock control register */
    __IO u(32) HSE_CTRL;                /* offset: 0x000C, High speed clock crystal selector register */
    __IO u(32) LSI_CALIB_CTRL;          /* offset: 0x0010, RC oscillator calibration control register */
    __IO u(32) RESERVED0[3];            /* offset: 0x0014, ~ 0x001C */
    __IO u(32) PLL_CTRL;                /* offset: 0x0020, PLL control register */
    __IO u(32) SYS_CLK1_CTRL;           /* offset: 0x0024, System clock 1 control register */
    __IO u(32) SYS_CLK3_CTRL;           /* offset: 0x002C, System clock 3 control register */
    __IO u(32) RESERVED1;               /* offset: 0x0030  */
    __IO u(32) CODEC_CLK_CTRL;          /* offset: 0x0034, Audio clock control register */
    __IO u(32) RESERVED2[8];            /* offset: 0x0038, ~ 0x0054 */
    __IO u(32) DCXO_CTRL;               /* offset: 0x0058, DCXO control register */
    __IO u(32) RESERVED4[5];            /* offset: 0x005c, ~ 0x006C */
    __IO u(32) CONNBOOT_FLAG;           /* offset: 0x0070, Connect boot flag */
    __IO u(32) PWR_CTRL;                /* offset: 0x0074, power control register */
    __IO u(32) RESERVED5[2];            /* offset: 0x0078, ~ 0x007C */
    __IO u(32) SYS1_RST_ST;             /* offset: 0x0080, system 1 reset status */
    __IO u(32) SYS1_CTRL;               /* offset: 0x0084, system 1 control register */
    __IO u(32) RESERVED6[2];
    __IO u(32) SYS3_CTRL;               /* offset: 0x0090, system 3 control register */
    __IO u(32) SYS3_ST;                 /* offset: 0x0094, system 3 status */
    __IO u(32) SYS1_WKUP_CTRL;          /* offset: 0x0098, system 1 wakeup control register */
    __IO u(32) RESERVED7;
    __IO u(32) SYS1_SLP_CTRL;           /* offset: 0x00a0, system 1 sleep control register */
    __IO u(32) RESERVED8;
    __IO u(32) DCXO_STA_REF_TIME;       /* offset: 0x00a8, DCXO stable reference time register */
    __IO u(32) DPLL_STA_REF_TIME;       /* offset: 0x00ac, PLL stable reference time register*/
    __IO u(32) LDO_STA_REF_TIME;        /* offset: 0x00b0, LDO stable reference timer register */
    __IO u(32) DIG_SW_REF_TIME;         /* offset: 0x00B4, Digital switch reference time register */
    __IO u(32) RTC_LDO_VOLT_CTRL;       /* offset: 0x00B8, RTC LDO voltage control register */
    __IO u(32) BANDGAP_STA_REF_TIME;    /* offset: 0x00BC, Band gap stable reference time register */
    __IO u(32) DCDC_STA_REF_TIME;       /* offset: 0x00C0, DCDC stable reference time register */
    __IO u(32) RESERVED9[3];
    __IO u(32) BLE_RTC_RST_CTRL;        /* offset: 0x00D0, BLE RTC Reset control register */
    __IO u(32) BLE_RTC_CLK_CTRL;        /* offset: 0x00D4, BLE RTC Clk control register */
    __IO u(32) RFAS_CTRL_REG;           /* offset: 0x00D8, RFAS Reset control register */
    __IO u(32) RESERVEDa[9];
    __IO u(32) CPUA_BOOT_FLAG;          /* offset: 0x0100, CPUA boot flag register */
    __IO u(32) CPUA_BOOT_ADDR;          /* offset: 0x0104, CPUA boot address register */
    __IO u(32) CPUA_BOOT_ARG;           /* offset: 0x0108, CPUA boot argument register */
    __IO u(32) CPUA_PRIV_REG_0T3[4];    /* offset: 0x010C~0x0118, CPUA private register 0 to 3 */
    __IO u(32) WDG_NORST_PERIPH;        /* offset: 0x011C, watchdog no reset peripherals */
    __IO u(32) CPU_WK_TIMER_CNT;        /* offset: 0x0120, CPUA wakeup timer counter register */
    __IO u(32) CPU_WK_TIMER_CMP;        /* offset: 0x0124, CPUA wakeup timer value register */
    __IO u(32) CPUA_PRIV_TIME_L;        /* offset: 0x0128, CPUA private time register */
    __IO u(32) CPUA_PRIV_TIME_H;        /* offset: 0x012C, CPUA private time register */
    __IO u(32) CPUA_WK_IO_EN;           /* offset: 0x0130, CPUA IO wakeup enable register */
    __IO u(32) CPUA_WK_IO_DEB_CLK;      /* offset: 0x0134, CPUA IO wakeup debounce clk register */
    __IO u(32) CPUA_WK_IO_ST;           /* offset: 0x0138, CPUA IO wakeup status register */
    __IO u(32) CPUA_WK_IO_HLD;          /* offset: 0x013C, CPUA IO hold control register */
    __IO u(32) CPUA_WK_IO_GLB_EN;       /* offset: 0x0140, CPUA IO wakeup global enable register */
    __IO u(32) CPUA_WK_IO_DEB_CYCLES0;  /* offset: 0x0144, CPUA IO wakeup debounce cycles register */
    __IO u(32) CPUA_WK_IO_DEB_CYCLES1;  /* offset: 0x0148, CPUA IO wakeup debounce cycles register */
    __IO u(32) RESERVEDb;
    __IO u(32) LDO_MODE_SW_SEL;         /* offset: 0x0150, LDO mode software select */
    __IO u(32) RESERVEDc[43];
    __IO u(32) DCDC_PARAM_CTRL;         /* offset: 0x0200, DCDC parameter control register */
    __IO u(32) ANA_BANDGAP;             /* offset: 0x0204, Analog band gap control register */
    __IO u(32) CLK_LDO_PARAM;           /* offset: 0x0208, Clock LDO parameter register */
    __IO u(32) DIG_LDO_PARAM;           /* offset: 0x020C, Digital LDO parameter register */
    __IO u(32) DPLL_ST;                 /* offset: 0x0210, DPLL status register */
    __IO u(32) BONDING_IO;              /* offset: 0x0214, Bonding IO status register */
    __IO u(32) CPU_RST_SRC;             /* offset: 0x0218, CPU reset source register */
    __IO u(32) WLAN_HIF_OVERRIDE_CTRL;  /* offset: 0x021C, WLAN HIF override control register */
    __IO u(32) SRAM_BIST_CTRL;          /* offset: 0x0220, SRAM bist control register */
    __IO u(32) WLAN_SRAM_SHARE_CTRL;    /* offset: 0x0224, wlan sram share control register */
    __IO u(32) BLE_16L_SRAM_SHARE_CTRL; /* offset: 0x0228, ble 16K sram share control register */
    __IO u(32) RESERVEDd;
    __IO u(32) LPUART0_WK_CTRL;         /* offset: 0x0230, lpuart0 wakeup control register */
    __IO u(32) LPUART1_WK_CTRL;         /* offset: 0x0234, lpuart1 wakeup control register */
    __IO u(32) ADC_CLK_CTRL;            /* offset: 0x0238, gpadc clock control register */
    __IO u(32) CLK_32K_CTRL;            /* offset: 0x023C, 32k clock control register */
    __IO u(32) WKUP_SRC_BUS_CLK_CTRL;   /* offset: 0x0240, wakeup source reset control register */
    __IO u(32) WKUP_SRC_RST_CTRL;       /* offset: 0x0244, wakeup source reset control register */
    __IO u(32) RESERVEDe[2];
    __IO u(32) FLASH_ENC_AES_NONCE0;    /* offset: 0x0250, wakeup source reset control register */
    __IO u(32) FLASH_ENC_AES_NONCE1;    /* offset: 0x0254, wakeup source reset control register */
    __IO u(32) RESERVEDf[2];
    __IO u(32) BLE_LSI_CALIB_CTRL0;     /* offset: 0x0260, ble RCOSC calibration control register0 */
    __IO u(32) BLE_LSI_CALIB_CTRL1;     /* offset: 0x0264, ble RCOSC calibration control register1 */
    __IO u(32) BLE_CLK32K_SW0;          /* offset: 0x0268, ble clk 32k switch register0 */
    __IO u(32) BLE_CLK32K_SW1;          /* offset: 0x026C, ble clk 32k switch register1 */
}PRCM_TypeDef;
#define PRCM ((PRCM_TypeDef*)PRCM_BASE)

typedef struct 
{
    __IO u(32) MODE[4];                 /* offset: 0x00, GPIO mode configuration register */
    __IO u(32) DAT;                     /* offset: 0x10, GPIO data register */
    __IO u(32) DRV[2];                  /* offset: 0x14, GPIO driving level register */
    __IO u(32) PULL[2];                 /* offset: 0x1c, GPIO pull type register */
}GPIO_TypeDef;
#define GPIOA ((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef*)GPIOB_BASE)

typedef struct
{
    __IO u(32) MODE[4];                 /* offset: 0x00, GPIO itnerrupt configuration register */
    __IO u(32) ENABLE;                  /* offset: 0x10, GPIO interrupt enable register  */
    __IO u(32) STATUS;                  /* offset: 0x14, GPIO interrupt status register */
    __IO u(32) DEBOUNCE;                /* offset: 0x18, GPIO interrupt debounce register */
}GPIO_IRQ_TypeDef;
#define GPIOA_IRQ ((GPIO_IRQ_TypeDef*)GPIOA_IRQ_BASE)
#define GPIOB_IRQ ((GPIO_IRQ_TypeDef*)GPIOB_IRQ_BASE)

#ifdef __cplusplus
}
#endif

#endif /* __XR806_LL_DEF_H__ */
