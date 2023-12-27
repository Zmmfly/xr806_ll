#ifndef __XR806_LL_GPIO_H__
#define __XR806_LL_GPIO_H__

#include "xr806.h"

/*
FT : 1.8v/3.3v/5.0v
+---------------+------------------+--------------+-----------+-----------+------------+---------+-----------+-----------+
|   GPIO PIN    |       Note       |     AF2      |    AF3    |    AF4    |    AF5     |   AF8   |    AF9    |   AF10    |
+---------------+------------------+--------------+-----------+-----------+------------+---------+-----------+-----------+
|      PA0      |                  |   FEMCTRL1   | AUD_PWMP  | I2C1_SCL  |   IR_RX    | KEY_Y0  | PWM5_ECT5 |           |
|      PA1      |                  |   FEMCTRL2   | AUD_PWMN  | I2C1_SDA  | FLASH_CS1  | KEY_Y1  | PWM6_ECT6 |           |
| PA10 / WKUP0  |                  |   ADC_CH0    | SPI0_MOSI |           |  UART1_RX  | KEY_Y2  |   IR_TX   |           |
| PA11 / WKUP1  |                  |   ADC_CH1    | SPI0_MISO | I2S_MCLK  |  UART1_TX  | KEY_Y3  |   IR_RX   |           |
| PA12 / WKUP2  |                  |   ADC_CH2    | PWM4_ECT4 | I2S_BCLK  |   IR_TX    | KEY_Y4  | I2C0_SCL  |           |
| PA13 / WKUP3  |                  |   ADC_CH3    | PWM5_ECT5 |  I2S_DI   |  UART2_TX  | KEY_Y5  | I2C0_SDA  |           |
| PA14 / WKUP4  |                  |   ADC_CH4    | PWM6_ECT6 |  I2S_DO   |  UART2_RX  | KEY_Y6  | I2S_MCLK  |           |
| PA15 / WKUP5  |                  |   ADC_CH5    | SPI0_CS0  | I2S_LRCLK | UART2_CTS  | KEY_Y7  | I2C1_SCL  | I2S_BCLK  |
| PA16 / WKUP6  |                  |   ADC_CH6    | SPI0_CLK  |           | UART2_RTS  | KEY_X0  | I2C1_SDA  |  I2S_DI   |
| PA17 / WKUP7  |                  |   I2C0_SCL   | AUD_PWMP  |  32KOSC0  |   IR_TX    | KEY_X1  |           |  I2S_DO   |
| PA18 / WKUP8  |                  |   I2C0_SDA   | AUD_PWMN  | FEMCTRL2  | FLASH_CS1  | KEY_X2  |           | I2S_LRCLK |
| PA19 / WKUP9  |                  |  UART2_RTS   | CARD_DATA | PWM0_ECT0 | SPI0_MOSI  | KEY_X3  | AUD_PWMP  |           |
| PA20 / WKUP10 |                  |  UART2_CTS   | CARD_CLK  | PWM1_ECT1 | SPI0_MISO  | KEY_X4  | AUD_PWMN  |           |
| PA21 / WKUP11 |                  |   UART2_RX   | CARD_RST  | PWM2_ECT2 |  SPI0_CS0  | KEY_X5  |  I2S_DO   |           |
| PA22 / WKUP12 |                  |   UART2_TX   | CARD_DET  | PWM3_ECT3 |  SPI0_CLK  | KEY_X6  | I2S_LRCLK |           |
| PA23 / WKUP13 | MustHighWhenBoot | DCXO_PUP_OUT |   IR_RX   | FEMCTRL1  |  FEMCTRL2  | KEY_X7  | I2S_MCLK  |           |
|      PB0      |        FT        |   UART0_TX   | JTAG_TMS  | PWM4_ECT4 |  SWD_TMS   | KEY_Y8  |           |           |
|      PB1      |        FT        |   UART0_RX   | JTAG_TCK  | PWM5_ECT5 |  SWD_TCK   | KEY_Y9  |           |           |
|      PB2      |                  |  UART0_CTS   | JTAG_TDO  | PWM6_ECT6 |  FLASH_WP  | KEY_Y10 |  SWD_TMS  |           |
|      PB3      |                  |  UART0_RTS   | JTAG_TDI  | PWM7_ECT7 |  FLASH_HD  | KEY_Y11 |  SWD_TCK  |           |
|      PB4      |                  |  SPI0_MOSI   | PWM0_ECT0 | UART1_RTS | FLASH_MOSI | KEY_Y12 | I2S_BCLK  |           |
|      PB5      |                  |  SPI0_MISO   | PWM1_ECT1 | UART1_CTS | FLASH_MISO | KEY_Y13 |  I2S_DI   |           |
|      PB6      |                  |   SPI0_CS0   | PWM2_ECT2 | UART1_RX  | FLASH_CS0  | KEY_Y14 |  I2S_DO   |           |
|      PB7      |                  |   SPI0_CLK   | PWM3_ECT3 | UART1_TX  | FLASH_CLK  | KEY_Y15 | I2S_LRCLK |           |
|      PB8      |                  |   FLASH_WP   |           |           |            |         |           |           |
|      PB9      |                  |   FLASH_HD   |           |           |            |         |           |           |
|     PB10      |                  |  FLASH_MOSI  | SPI0_MOSI |           |            |         |           |           |
|     PB11      |                  |  FLASH_MISO  | SPI0_MISO |           |            |         |           |           |
|     PB12      |                  |  FLASH_CS1   | SPI0_CS0  |           |            |         |           |           |
|     PB13      |                  |  FLASH_CLK   | SPI0_CLK  |           |            |         |           |           |
|     PB14      |        FT        |   UART1_TX   | UART2_TX  | I2C1_SCL  |            |         |           |           |
|     PB15      |        FT        |   UART1_RX   | UART2_TX  | I2C1_SDA  |            |         |           |           |
+---------------+------------------+--------------+-----------+-----------+------------+---------+-----------+-----------+
*/


#define LL_GPIO_REG_AF_BITS     (4U)
#define LL_GPIO_REG_DRV_BITS    (2U)
#define LL_GPIO_REG_PUL_BITS    (2U)
#define LL_GPIO_REG_INTCFG_BITS (4U)

#define LL_GPIO_AF0             (0U)
#define LL_GPIO_AF1             (1U)
#define LL_GPIO_AF2             (2U)
#define LL_GPIO_AF3             (3U)
#define LL_GPIO_AF4             (4U)
#define LL_GPIO_AF5             (5U)
#define LL_GPIO_AF6             (6U)
#define LL_GPIO_AF7             (7U)
#define LL_GPIO_AF8             (8U)
#define LL_GPIO_AF9             (9U)

#define LL_GPIO_AF_INPUT        LL_GPIO_AF0
#define LL_GPIO_AF_OUPUT        LL_GPIO_AF1
#define LL_GPIO_AF_EXTI         LL_GPIO_AF6
#define LL_GPIO_AF_DISABLE      LL_GPIO_AF7

#define LL_GPIO_DRV_LV0         (0U)
#define LL_GPIO_DRV_LV1         (1U)
#define LL_GPIO_DRV_LV2         (2U)
#define LL_GPIO_DRV_LV3         (3U)

#define LL_GPIO_PULL_NONE       (0U)
#define LL_GPIO_PULL_UP         (1U)
#define LL_GPIO_PULL_DOWN       (2U)

#endif /* __XR806_LL_GPIO_H__ */
