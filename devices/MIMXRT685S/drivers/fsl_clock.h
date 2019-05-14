/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright (c) 2016 - 2018 , NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_device_registers.h"
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "fsl_reset.h"
#include "fsl_common.h"

/*! @addtogroup clock */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Definitions
 *****************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 2.0.4. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(2, 0, 4))
/*@}*/
/*! @brief External XTAL (SYSOSC) clock frequency.
 *
 * The XTAL (SYSOSC) clock frequency in Hz, when the clock is setup, use the
 * function CLOCK_SetXtalFreq to set the value in to clock driver. For example,
 * if XTAL is 16MHz,
 * @code
 * CLOCK_SetXtalFreq(160000000); // Set the XTALIN value to clock driver.
 * @endcode
 */
extern volatile uint32_t g_xtalFreq;
/*! @brief External XTAL (SYSOSC) clock frequency.
 *
 * The MCLK in (mclk_in) PIN clock frequency in Hz, when the clock is setup, use the
 * function CLOCK_SetMclkInFreq to set the value in to clock driver. For example,
 * if mclk_In is 16MHz,
 * @code
 * CLOCK_SetMclkInFreq(160000000); // Set the MCLK_IN value to clock driver.
 * @endcode
 */
extern volatile uint32_t g_MclkInFreq;


/*! @brief Clock ip name array for ACMP. */
#define CMP_CLOCKS   \
    {                \
        kCLOCK_Acmp0 \
    }
/*! @brief Clock ip name array for FLEXCOMM. */
#define FLEXCOMM_CLOCKS                                                                                             \
    {                                                                                                               \
        kCLOCK_FlexComm0, kCLOCK_FlexComm1, kCLOCK_FlexComm2, kCLOCK_FlexComm3, kCLOCK_FlexComm4, kCLOCK_FlexComm5, \
            kCLOCK_FlexComm14, kCLOCK_FlexComm15                                                                    \
    }
/*! @brief Clock ip name array for LPUART. */
#define USART_CLOCKS                                                                                             \
    {                                                                                                            \
        kCLOCK_Usart0, kCLOCK_Usart1, kCLOCK_Usart2, kCLOCK_Usart3, kCLOCK_Usart4, kCLOCK_Usart5                 \
    }

/*! @brief Clock ip name array for I2C. */
#define I2C_CLOCKS                                                                                              \
    {                                                                                                           \
        kCLOCK_I2c0, kCLOCK_I2c1, kCLOCK_I2c2, kCLOCK_I2c3, kCLOCK_I2c4, kCLOCK_I2c5, kCLOCK_I2c15              \
    }
/*! @brief Clock ip name array for I3C. */
#define I3C_CLOCKS \
    {              \
        kCLOCK_I3c \
    }
/*! @brief Clock ip name array for SPI. */
#define SPI_CLOCKS                                                                                              \
    {                                                                                                           \
        kCLOCK_Spi0, kCLOCK_Spi1, kCLOCK_Spi2, kCLOCK_Spi3, kCLOCK_Spi4, kCLOCK_Spi5, kCLOCK_Spi14              \
    }
/*! @brief Clock ip name array for FLEXI2S. */
#define FLEXI2S_CLOCKS                                                                                        \
    {                                                                                                         \
        kCLOCK_FlexI2s0, kCLOCK_FlexI2s1, kCLOCK_FlexI2s2, kCLOCK_FlexI2s3, kCLOCK_FlexI2s4, kCLOCK_FlexI2s5  \
    }
/*! @brief Clock ip name array for UTICK. */
#define UTICK_CLOCKS  \
    {                 \
        kCLOCK_Utick0 \
    }
/*! @brief Clock ip name array for DMIC. */
#define DMIC_CLOCKS  \
    {                \
        kCLOCK_Dmic0 \
    }
/*! @brief Clock ip name array for CT32B. */
#define CTIMER_CLOCKS                                                             \
    {                                                                             \
        kCLOCK_Ct32b0, kCLOCK_Ct32b1, kCLOCK_Ct32b2, kCLOCK_Ct32b3, kCLOCK_Ct32b4 \
    }

/*! @brief Clock ip name array for GPIO. */
#define GPIO_CLOCKS                                                                                     \
    {                                                                                                   \
        kCLOCK_HsGpio0, kCLOCK_HsGpio1, kCLOCK_HsGpio2, kCLOCK_HsGpio3, kCLOCK_HsGpio4, kCLOCK_HsGpio5, \
            kCLOCK_HsGpio6, kCLOCK_HsGpio7                                                              \
    }
/*! @brief Clock ip name array for ADC. */
#define LPADC_CLOCKS \
    {                \
        kCLOCK_Adc0  \
    }
/*! @brief Clock ip name array for MRT. */
#define MRT_CLOCKS  \
    {               \
        kCLOCK_Mrt0 \
    }
/*! @brief Clock ip name array for SCT. */
#define SCT_CLOCKS \
    {              \
        kCLOCK_Sct \
    }
/*! @brief Clock ip name array for RTC. */
#define RTC_CLOCKS \
    {              \
        kCLOCK_Rtc \
    }
/*! @brief Clock ip name array for WWDT. */
#define WWDT_CLOCKS                \
    {                              \
        kCLOCK_Wwdt0, kCLOCK_Wwdt1 \
    }
/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS \
    {              \
        kCLOCK_Crc \
    }
/*! @brief Clock ip name array for USBD. */
#define USBD_CLOCKS        \
    {                      \
        kCLOCK_UsbhsDevice \
    }
/*! @brief Clock ip name array for DMA. */
#define DMA_CLOCKS                 \
    {                              \
        kCLOCK_Dmac0, kCLOCK_Dmac1 \
    }
/*! @brief Clock ip name array for PINT. */
#define PINT_CLOCKS \
    {               \
        kCLOCK_Pint \
    }
/*! @brief Clock ip name array for QSPI */
#define QSPI_CLOCKS         \
    {                       \
        kCLOCK_OtfadQuadspi \
    }
/*! @brief Clock ip name array for MUA */
#define MU_CLOCKS \
    {             \
        kCLOCK_Mu \
    }
/*! @brief Clock ip name array for SEMA */
#define SEMA42_CLOCKS \
    {                 \
        kCLOCK_Sema   \
    }
/*! @brief Clock ip name array for RNG */
#define TRNG_CLOCKS \
    {               \
        kCLOCK_Rng  \
    }
/*! @brief Clock ip name array for uSDHC */
#define USDHC_CLOCKS \
    {                \
        kCLOCK_Sdio0 \
    }
/*! @brief Clock ip name array for OSTimer */
#define OSTIMER_CLOCKS      \
    {                       \
        kCLOCK_OsEventTimer \
    }

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
/*------------------------------------------------------------------------------
 clock_ip_name_t definition:
------------------------------------------------------------------------------*/

#define CLK_GATE_REG_OFFSET_SHIFT 8U
#define CLK_GATE_REG_OFFSET_MASK 0xFF00U
#define CLK_GATE_BIT_SHIFT_SHIFT 0U
#define CLK_GATE_BIT_SHIFT_MASK 0x000000FFU

#define CLK_GATE_DEFINE(reg_offset, bit_shift)                                  \
    ((((reg_offset) << CLK_GATE_REG_OFFSET_SHIFT) & CLK_GATE_REG_OFFSET_MASK) | \
     (((bit_shift) << CLK_GATE_BIT_SHIFT_SHIFT) & CLK_GATE_BIT_SHIFT_MASK))

#define CLK_GATE_ABSTRACT_REG_OFFSET(x) (((uint32_t)(x)&CLK_GATE_REG_OFFSET_MASK) >> CLK_GATE_REG_OFFSET_SHIFT)
#define CLK_GATE_ABSTRACT_BITS_SHIFT(x) (((uint32_t)(x)&CLK_GATE_BIT_SHIFT_MASK) >> CLK_GATE_BIT_SHIFT_SHIFT)

#define CLK_CTL0_PSCCTL0 0
#define CLK_CTL0_PSCCTL1 1
#define CLK_CTL0_PSCCTL2 2
#define CLK_CTL1_PSCCTL0 3
#define CLK_CTL1_PSCCTL1 4
#define CLK_CTL1_PSCCTL2 5

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
typedef enum _clock_ip_name
{
    kCLOCK_IpInvalid = 0U,
    kCLOCK_Dsp = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 1),
    kCLOCK_PowerQuad = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 8),
    kCLOCK_Casper = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 9),
    kCLOCK_HashCrypt = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 10),
    kCLOCK_Puf = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 11),
    kCLOCK_Rng = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 12),
    kCLOCK_OtfadQuadspi = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 16),
    kCLOCK_Otpc = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 17),
    kCLOCK_UsbhsPhy = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 20),
    kCLOCK_UsbhsDevice = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 21),
    kCLOCK_UsbhsHost = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 22),
    kCLOCK_UsbhsSram = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 23),
    kCLOCK_Sct = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL0, 24),

    kCLOCK_Sdio0 = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL1, 2),
    kCLOCK_Acmp0 = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL1, 15),
    kCLOCK_Adc0 = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL1, 16),
    kCLOCK_ShsGpio0 = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL1, 24),

    kCLOCK_Utick0 = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL2, 0),
    kCLOCK_Wwdt0 = CLK_GATE_DEFINE(CLK_CTL0_PSCCTL2, 1),

    kCLOCK_FlexComm0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 8),
    kCLOCK_FlexComm1 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 9),
    kCLOCK_FlexComm2 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 10),
    kCLOCK_FlexComm3 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 11),
    kCLOCK_FlexComm4 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 12),
    kCLOCK_FlexComm5 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 13),
    kCLOCK_FlexComm14 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 22),
    kCLOCK_FlexComm15 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 23),
    kCLOCK_Usart0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 8),
    kCLOCK_Usart1 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 9),
    kCLOCK_Usart2 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 10),
    kCLOCK_Usart3 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 11),
    kCLOCK_Usart4 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 12),
    kCLOCK_Usart5 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 13),
    kCLOCK_I2s0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 8),
    kCLOCK_I2s1 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 9),
    kCLOCK_I2s2 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 10),
    kCLOCK_I2s3 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 11),
    kCLOCK_I2s4 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 12),
    kCLOCK_I2s5 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 13),
    kCLOCK_I2c0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 8),
    kCLOCK_I2c1 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 9),
    kCLOCK_I2c2 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 10),
    kCLOCK_I2c3 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 11),
    kCLOCK_I2c4 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 12),
    kCLOCK_I2c5 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 13),
    kCLOCK_I2c15 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 23),
    kCLOCK_Spi0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 8),
    kCLOCK_Spi1 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 9),
    kCLOCK_Spi2 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 10),
    kCLOCK_Spi3 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 11),
    kCLOCK_Spi4 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 12),
    kCLOCK_Spi5 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 13),
    kCLOCK_Spi14 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 22),
    kCLOCK_Dmic0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 24),
    kCLOCK_OsEventTimer = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL0, 27),

    kCLOCK_HsGpio0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 0),
    kCLOCK_HsGpio1 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 1),
    kCLOCK_HsGpio2 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 2),
    kCLOCK_HsGpio3 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 3),
    kCLOCK_HsGpio4 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 4),
    kCLOCK_HsGpio5 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 5),
    kCLOCK_HsGpio6 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 6),
    kCLOCK_HsGpio7 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 7),
    kCLOCK_Crc = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 16),
    kCLOCK_Dmac0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 23),
    kCLOCK_Dmac1 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 24),
    kCLOCK_Mu = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 28),
    kCLOCK_Sema = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 29),
    kCLOCK_Freqme = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL1, 31),

    kCLOCK_Ct32b0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 0),
    kCLOCK_Ct32b1 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 1),
    kCLOCK_Ct32b2 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 2),
    kCLOCK_Ct32b3 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 3),
    kCLOCK_Ct32b4 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 4),
    kCLOCK_Rtc = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 7),
    kCLOCK_Mrt0 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 8),
    kCLOCK_Wwdt1 = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 10),
    kCLOCK_I3c = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 16),
    kCLOCK_Pint = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 30),
    kCLOCK_InputMux = CLK_GATE_DEFINE(CLK_CTL1_PSCCTL2, 31)
} clock_ip_name_t;

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
    kCLOCK_CoreSysClk, /*!< Core clock  (aka HCLK)                                 */
    kCLOCK_BusClk,     /*!< Bus clock (AHB/APB clock, aka HCLK)                    */
    kCLOCK_Mclk,       /*!< MCLK, to MCLK pin                                      */
    kCLOCK_ClockOut,   /*!< CLOCKOUT                                               */
    kCLOCK_AdcClk,     /*!< ADC                                                    */
    kCLOCK_QspiClk,    /*!< QSPI                                                   */
    kCLOCK_SctClk,     /*!< SCT                                                    */
    kCLOCK_WdtOsc,     /*!< Watchdog Oscillator                                    */
    kCLOCK_SystickClk, /*!< Systick                                                */
    kCLOCK_Sdio0Clk,   /*!< SDIO0                                                  */
    kCLOCK_I3cClk,     /*!< I3C                                                    */
    kCLOCK_Usb,        /*!< USB0                                                   */
    kCLOCK_Dmic,       /*!< Digital Mic clock                                      */
    kCLOCK_DspCpuClk,  /*!< DSP  clock                                             */
    kCLOCK_AcmpClk,    /*!< Acmp clock                                             */
    kCLOCK_FlexI2S,    /*!< FlexI2S clock                                          */
    kCLOCK_Flexcomm0,  /*!< Flexcomm0Clock                                         */
    kCLOCK_Flexcomm1,  /*!< Flexcomm1Clock                                         */
    kCLOCK_Flexcomm2,  /*!< Flexcomm2Clock                                         */
    kCLOCK_Flexcomm3,  /*!< Flexcomm3Clock                                         */
    kCLOCK_Flexcomm4,  /*!< Flexcomm4Clock                                         */
    kCLOCK_Flexcomm5,  /*!< Flexcomm5Clock                                         */
    kCLOCK_Flexcomm14, /*!< Flexcomm14Clock                                        */
    kCLOCK_Flexcomm15, /*!< Flexcomm15Clock                                        */
} clock_name_t;

/**
 * PLL PFD clock name
 */
typedef enum _clock_pfd
{
    kCLOCK_Pfd0 = 0U, /*!< PLL PFD0 */
    kCLOCK_Pfd1 = 1U, /*!< PLL PFD1 */
    kCLOCK_Pfd2 = 2U, /*!< PLL PFD2 */
    kCLOCK_Pfd3 = 3U, /*!< PLL PFD3 */
} clock_pfd_t;

/**
 * Clock range selections for the FFRO clock
 */
typedef enum _ffro_clock_range
{
    kCLOCK_FFro48Mhz = 0, /*!< 48MHz FRO */
    kCLOCK_FFro52Mhz,     /*!< 52MHz FRO */
    kCLOCK_FFro56Mhz,     /*!< 56MHz FRO */
    kCLOCK_FFro60Mhz,     /*!< 60MHz FRO */
} ffro_clock_range_t;

/*! @brief Clock Mux Switches
*  The encoding is as follows each connection identified is 32bits wide
*  starting from LSB upwards
*
*  [12 bits for reg offset, 0 means end of descriptor, 4 bits for choice] [bit 31 define CLKCTL0 or CLKCTL1]*
*
*/
#define SYSPLL0CLKSEL_OFFSET 0x200
#define MAINCLKSELA_OFFSET 0x430
#define MAINCLKSELB_OFFSET 0x434
#define OSPIFFCLKSEL_OFFSET 0x620
#define SCTFCLKSEL_OFFSET 0x640
#define USBHSFCLKSEL_OFFSET 0x660
#define SDIO0FCLKSEL_OFFSET 0x680
#define SDIO1FCLKSEL_OFFSET 0x690
#define ADC0FCLKSEL0_OFFSET 0x6D0
#define ADC0FCLKSEL1_OFFSET 0x6D4
#define UTICKFCLKSEL_OFFSET 0x700
#define WDT0FCLKSEL_OFFSET 0x720
#define SYSTICKFCLKSEL_OFFSET 0x760
#define AUDIOPLL0CLKSEL_OFFSET 0x200
#define DSPCPUCLKSELA_OFFSET 0x430
#define DSPCPUCLKSELB_OFFSET 0x434
#define OSEVENTTFCLKSEL_OFFSET 0x480
#define FC0FCLKSEL_OFFSET 0x508
#define FC1FCLKSEL_OFFSET 0x528
#define FC2FCLKSEL_OFFSET 0x548
#define FC3FCLKSEL_OFFSET 0x568
#define FC4FCLKSEL_OFFSET 0x588
#define FC5FCLKSEL_OFFSET 0x5A8
#define FC6FCLKSEL_OFFSET 0x5C8
#define FC7FCLKSEL_OFFSET 0x5E8
#define FC14FCLKSEL_OFFSET 0x6C8
#define FC15FCLKSEL_OFFSET 0x6E8
#define DMIC0FCLKSEL_OFFSET 0x700
#define CT32BIT0FCLKSEL_OFFSET 0x720
#define CT32BIT1FCLKSEL_OFFSET 0x724
#define CT32BIT2FCLKSEL_OFFSET 0x728
#define CT32BIT3FCLKSEL_OFFSET 0x72C
#define CT32BIT4FCLKSEL_OFFSET 0x730
#define AUDIOMCLKSEL_OFFSET 0x740
#define CLKOUTSEL0_OFFSET 0x760
#define CLKOUTSEL1_OFFSET 0x764
#define I3C0FCLKSEL_OFFSET 0x780
#define I3C0FCLKSTCSEL_OFFSET 0x784
#define ACMP0FCLKSEL_OFFSET 0x7C0

#define SYSCPUAHBCLKDIV_OFFSET 0x400
#define ADC0FCLKDIV_OFFSET 0x6D8
#define OSPIFCLKDIV_OFFSET 0x624
#define SCTFCLKDIV_OFFSET 0x644
#define SDIO0FCLKDIV_OFFSET 0x684
#define SDIO1FCLKDIV_OFFSET 0x694
#define SYSTICKFCLKDIV_OFFSET 0x764
#define USBHSFCLKDIV_OFFSET 0x664
#define AUDIOMCLKDIV_OFFSET 0x744
#define AUDIOPLLCLKDIV_OFFSET 0x240
#define ACMP0FCLKDIV_OFFSET 0x7C4
#define CLKOUTDIV_OFFSET 0x768
#define DMIC0FCLKDIV_OFFSET 0x704
#define DSPCPUCLKDIV_OFFSET 0x400
#define DSPMAINRAMCLKDIV_OFFSET 0x404
#define FRGPLLCLKDIV_OFFSET 0x6FC
#define I3C0FCLKDIV_OFFSET 0x790
#define I3C0FCLKSTCDIV_OFFSET 0x788
#define I3C0FCLKSDIV_OFFSET 0x78C

#define CLKCTL0_TUPLE_MUXA(reg, choice) ((reg & 0xFFFU) | ((choice) << 12U))
#define CLKCTL0_TUPLE_MUXB(reg, choice) (((reg & 0xFFFU) << 16) | ((choice) << 28U))
#define CLKCTL1_TUPLE_MUXA(reg, choice) (0x80000000U | ((reg & 0xFFFU) | ((choice) << 12U)))
#define CLKCTL1_TUPLE_MUXB(reg, choice) (0x80000000U | (((reg & 0xFFFU) << 16) | ((choice) << 28U)))
#define CLKCTL_TUPLE_REG(base, tuple) ((volatile uint32_t *)(((uint32_t)(base)) + ((tuple)&0xFFFU)))
#define CLKCTL_TUPLE_SEL(tuple) (((tuple) >> 12U) & 0x7U)

typedef enum _clock_attach_id
{
    kSFRO_to_SYS_PLL = CLKCTL0_TUPLE_MUXA(SYSPLL0CLKSEL_OFFSET, 0),
    kXTALIN_CLK_to_SYS_PLL = CLKCTL0_TUPLE_MUXA(SYSPLL0CLKSEL_OFFSET, 1),
    kFFRO_DIV2_to_SYS_PLL = CLKCTL0_TUPLE_MUXA(SYSPLL0CLKSEL_OFFSET, 2),
    kNONE_to_SYS_PLL = CLKCTL0_TUPLE_MUXA(SYSPLL0CLKSEL_OFFSET, 7),

    kSFRO_to_AUDIO_PLL = CLKCTL1_TUPLE_MUXA(AUDIOPLL0CLKSEL_OFFSET, 0),
    kXTALIN_CLK_to_AUDIO_PLL = CLKCTL1_TUPLE_MUXA(AUDIOPLL0CLKSEL_OFFSET, 1),
    kFFRO_DIV2_to_AUDIO_PLL = CLKCTL1_TUPLE_MUXA(AUDIOPLL0CLKSEL_OFFSET, 2),
    kNONE_to_AUDIO_PLL = CLKCTL1_TUPLE_MUXA(AUDIOPLL0CLKSEL_OFFSET, 7),

    kFFRO_DIV4_to_MAIN_CLK = CLKCTL0_TUPLE_MUXA(MAINCLKSELA_OFFSET, 0) | CLKCTL0_TUPLE_MUXB(MAINCLKSELB_OFFSET, 0),
    kXTALIN_CLK_to_MAIN_CLK = CLKCTL0_TUPLE_MUXA(MAINCLKSELA_OFFSET, 1) | CLKCTL0_TUPLE_MUXB(MAINCLKSELB_OFFSET, 0),
    kLPOSC_to_MAIN_CLK = CLKCTL0_TUPLE_MUXA(MAINCLKSELA_OFFSET, 2) | CLKCTL0_TUPLE_MUXB(MAINCLKSELB_OFFSET, 0),
    kFFRO_to_MAIN_CLK = CLKCTL0_TUPLE_MUXA(MAINCLKSELA_OFFSET, 3) | CLKCTL0_TUPLE_MUXB(MAINCLKSELB_OFFSET, 0),
    kSFRO_to_MAIN_CLK = CLKCTL0_TUPLE_MUXA(MAINCLKSELB_OFFSET, 1),
    kMAIN_PLL_to_MAIN_CLK = CLKCTL0_TUPLE_MUXA(MAINCLKSELB_OFFSET, 2),
    kOSC32K_to_MAIN_CLK = CLKCTL0_TUPLE_MUXA(MAINCLKSELB_OFFSET, 3),

    kFFRO_to_DSP_MAIN_CLK = CLKCTL1_TUPLE_MUXA(DSPCPUCLKSELA_OFFSET, 0) | CLKCTL1_TUPLE_MUXB(DSPCPUCLKSELB_OFFSET, 0),
    kXTALIN_CLK_to_DSP_MAIN_CLK =
        CLKCTL1_TUPLE_MUXA(DSPCPUCLKSELA_OFFSET, 1) | CLKCTL1_TUPLE_MUXB(DSPCPUCLKSELB_OFFSET, 0),
    kLPOSC_to_DSP_MAIN_CLK = CLKCTL1_TUPLE_MUXA(DSPCPUCLKSELA_OFFSET, 2) | CLKCTL1_TUPLE_MUXB(DSPCPUCLKSELB_OFFSET, 0),
    kSFRO_to_DSP_MAIN_CLK = CLKCTL1_TUPLE_MUXA(DSPCPUCLKSELA_OFFSET, 3) | CLKCTL1_TUPLE_MUXB(DSPCPUCLKSELB_OFFSET, 0),
    kMAIN_PLL_to_DSP_MAIN_CLK = CLKCTL1_TUPLE_MUXA(DSPCPUCLKSELB_OFFSET, 1),
    kDSP_PLL_to_DSP_MAIN_CLK = CLKCTL1_TUPLE_MUXA(DSPCPUCLKSELB_OFFSET, 2),
    kOSC32K_to_DSP_MAIN_CLK = CLKCTL1_TUPLE_MUXA(DSPCPUCLKSELB_OFFSET, 3),

    kFFRO_to_MCLK = CLKCTL1_TUPLE_MUXA(AUDIOMCLKSEL_OFFSET, 0),
    kAUDIO_PLL_to_MCLK = CLKCTL1_TUPLE_MUXA(AUDIOMCLKSEL_OFFSET, 1),
    kNONE_to_MCLK = CLKCTL1_TUPLE_MUXA(AUDIOMCLKSEL_OFFSET, 7),

    kSFRO_to_ADC_CLK = CLKCTL0_TUPLE_MUXA(ADC0FCLKSEL0_OFFSET, 0) | CLKCTL0_TUPLE_MUXB(ADC0FCLKSEL1_OFFSET, 0),
    kXTALIN_CLK_to_ADC_CLK = CLKCTL0_TUPLE_MUXA(ADC0FCLKSEL0_OFFSET, 1) | CLKCTL0_TUPLE_MUXB(ADC0FCLKSEL1_OFFSET, 0),
    kLPOSC_to_ADC_CLK = CLKCTL0_TUPLE_MUXA(ADC0FCLKSEL0_OFFSET, 2) | CLKCTL0_TUPLE_MUXB(ADC0FCLKSEL1_OFFSET, 0),
    kFFRO_to_ADC_CLK = CLKCTL0_TUPLE_MUXA(ADC0FCLKSEL0_OFFSET, 3) | CLKCTL0_TUPLE_MUXB(ADC0FCLKSEL1_OFFSET, 0),
    kMAIN_PLL_to_ADC_CLK = CLKCTL0_TUPLE_MUXA(ADC0FCLKSEL1_OFFSET, 1),
    kAUX0_PLL_to_ADC_CLK = CLKCTL0_TUPLE_MUXA(ADC0FCLKSEL1_OFFSET, 3),
    kAUX1_PLL_to_ADC_CLK = CLKCTL0_TUPLE_MUXA(ADC0FCLKSEL1_OFFSET, 5),

    kSFRO_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL0_OFFSET, 0) | CLKCTL1_TUPLE_MUXB(CLKOUTSEL1_OFFSET, 0),
    kXTALIN_CLK_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL0_OFFSET, 1) | CLKCTL1_TUPLE_MUXB(CLKOUTSEL1_OFFSET, 0),
    kLPOSC_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL0_OFFSET, 2) | CLKCTL1_TUPLE_MUXB(CLKOUTSEL1_OFFSET, 0),
    kFFRO_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL0_OFFSET, 3) | CLKCTL1_TUPLE_MUXB(CLKOUTSEL1_OFFSET, 0),
    kMAIN_CLK_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL0_OFFSET, 4) | CLKCTL1_TUPLE_MUXB(CLKOUTSEL1_OFFSET, 0),
    kDSP_MAIN_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL0_OFFSET, 6) | CLKCTL1_TUPLE_MUXB(CLKOUTSEL1_OFFSET, 0),
    kMAIN_PLL_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL1_OFFSET, 1),
    kAUX0_PLL_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL1_OFFSET, 2),
    kDSP_PLL_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL1_OFFSET, 3),
    kAUX1_PLL_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL1_OFFSET, 4),
    kAUDIO_PLL_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL1_OFFSET, 5),
    kOSC32K_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL1_OFFSET, 6),
    kNONE_to_CLKOUT = CLKCTL1_TUPLE_MUXA(CLKOUTSEL1_OFFSET, 7),

    kMAIN_CLK_to_I3C_CLK = CLKCTL1_TUPLE_MUXA(I3C0FCLKSEL_OFFSET, 0),
    kFFRO_to_I3C_CLK = CLKCTL1_TUPLE_MUXA(I3C0FCLKSEL_OFFSET, 1),
    kNONE_to_I3C_CLK = CLKCTL1_TUPLE_MUXA(I3C0FCLKSEL_OFFSET, 7),

    kI3C_CLK_to_I3C_TC_CLK = CLKCTL1_TUPLE_MUXA(I3C0FCLKSTCSEL_OFFSET, 0),
    kLPOSC_to_I3C_TC_CLK = CLKCTL1_TUPLE_MUXA(I3C0FCLKSTCSEL_OFFSET, 1),
    kNONE_to_I3C_TC_CLK = CLKCTL1_TUPLE_MUXA(I3C0FCLKSTCSEL_OFFSET, 7),

    kLPOSC_to_OSTIMER_CLK = CLKCTL1_TUPLE_MUXA(OSEVENTTFCLKSEL_OFFSET, 0),
    kOSC32K_to_OSTIMER_CLK = CLKCTL1_TUPLE_MUXA(OSEVENTTFCLKSEL_OFFSET, 1),
    kNONE_to_OSTIMER_CLK = CLKCTL1_TUPLE_MUXA(OSEVENTTFCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_QSPI_CLK = CLKCTL0_TUPLE_MUXA(OSPIFFCLKSEL_OFFSET, 0),
    kMAIN_PLL_to_QSPI_CLK = CLKCTL0_TUPLE_MUXA(OSPIFFCLKSEL_OFFSET, 1),
    kAUX0_PLL_to_QSPI_CLK = CLKCTL0_TUPLE_MUXA(OSPIFFCLKSEL_OFFSET, 2),
    kFFRO_to_QSPI_CLK = CLKCTL0_TUPLE_MUXA(OSPIFFCLKSEL_OFFSET, 3),
    kAUX1_PLL_to_QSPI_CLK = CLKCTL0_TUPLE_MUXA(OSPIFFCLKSEL_OFFSET, 4),
    kNONE_to_QSPI_CLK = CLKCTL0_TUPLE_MUXA(OSPIFFCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_SCT_CLK = CLKCTL0_TUPLE_MUXA(SCTFCLKSEL_OFFSET, 0),
    kMAIN_PLL_to_SCT_CLK = CLKCTL0_TUPLE_MUXA(SCTFCLKSEL_OFFSET, 1),
    kAUX0_PLL_to_SCT_CLK = CLKCTL0_TUPLE_MUXA(SCTFCLKSEL_OFFSET, 2),
    kFFRO_to_SCT_CLK = CLKCTL0_TUPLE_MUXA(SCTFCLKSEL_OFFSET, 3),
    kAUX1_PLL_to_SCT_CLK = CLKCTL0_TUPLE_MUXA(SCTFCLKSEL_OFFSET, 4),
    kAUDIO_PLL_to_SCT_CLK = CLKCTL0_TUPLE_MUXA(SCTFCLKSEL_OFFSET, 5),
    kNONE_to_SCT_CLK = CLKCTL0_TUPLE_MUXA(SCTFCLKSEL_OFFSET, 7),

    kLPOSC_to_UTICK_CLK = CLKCTL0_TUPLE_MUXA(UTICKFCLKSEL_OFFSET, 0),
    kNONE_to_UTICK_CLK = CLKCTL0_TUPLE_MUXA(UTICKFCLKSEL_OFFSET, 7),

    kLPOSC_to_WDT0_CLK = CLKCTL0_TUPLE_MUXA(WDT0FCLKSEL_OFFSET, 0),
    kNONE_to_WDT0_CLK = CLKCTL0_TUPLE_MUXA(WDT0FCLKSEL_OFFSET, 7),

    kMAIN_CLK_DIV_to_SYSTICK_CLK = CLKCTL0_TUPLE_MUXA(SYSTICKFCLKSEL_OFFSET, 0),
    kLPOSC_to_SYSTICK_CLK = CLKCTL0_TUPLE_MUXA(SYSTICKFCLKSEL_OFFSET, 1),
    kOSC32K_to_SYSTICK_CLK = CLKCTL0_TUPLE_MUXA(SYSTICKFCLKSEL_OFFSET, 2),
    kSFRO_to_SYSTICK_CLK = CLKCTL0_TUPLE_MUXA(SYSTICKFCLKSEL_OFFSET, 3),
    kNONE_to_SYSTICK_CLK = CLKCTL0_TUPLE_MUXA(SYSTICKFCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_SDIO0_CLK = CLKCTL0_TUPLE_MUXA(SDIO0FCLKSEL_OFFSET, 0),
    kMAIN_PLL_to_SDIO0_CLK = CLKCTL0_TUPLE_MUXA(SDIO0FCLKSEL_OFFSET, 1),
    kAUX0_PLL_to_SDIO0_CLK = CLKCTL0_TUPLE_MUXA(SDIO0FCLKSEL_OFFSET, 2),
    kFFRO_to_SDIO0_CLK = CLKCTL0_TUPLE_MUXA(SDIO0FCLKSEL_OFFSET, 3),
    kAUX1_PLL_to_SDIO0_CLK = CLKCTL0_TUPLE_MUXA(SDIO0FCLKSEL_OFFSET, 4),
    kNONE_to_SDIO0_CLK = CLKCTL0_TUPLE_MUXA(SDIO0FCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_SDIO1_CLK = CLKCTL0_TUPLE_MUXA(SDIO1FCLKSEL_OFFSET, 0),
    kMAIN_PLL_to_SDIO1_CLK = CLKCTL0_TUPLE_MUXA(SDIO1FCLKSEL_OFFSET, 1),
    kAUX0_PLL_to_SDIO1_CLK = CLKCTL0_TUPLE_MUXA(SDIO1FCLKSEL_OFFSET, 2),
    kFFRO_to_SDIO1_CLK = CLKCTL0_TUPLE_MUXA(SDIO1FCLKSEL_OFFSET, 3),
    kAUX1_PLL_to_SDIO1_CLK = CLKCTL0_TUPLE_MUXA(SDIO1FCLKSEL_OFFSET, 4),
    kNONE_to_SDIO1_CLK = CLKCTL0_TUPLE_MUXA(SDIO1FCLKSEL_OFFSET, 7),

    kXTALIN_CLK_to_USB_CLK = CLKCTL0_TUPLE_MUXA(USBHSFCLKSEL_OFFSET, 0),
    kMAIN_CLK_to_USB_CLK = CLKCTL0_TUPLE_MUXA(USBHSFCLKSEL_OFFSET, 1),
    kNONE_to_USB_CLK = CLKCTL0_TUPLE_MUXA(USBHSFCLKSEL_OFFSET, 7),

    kFFRO_to_MCLK_CLK = CLKCTL1_TUPLE_MUXA(AUDIOMCLKSEL_OFFSET, 0),
    kAUDIO_PLL_to_MCLK_CLK = CLKCTL1_TUPLE_MUXA(AUDIOMCLKSEL_OFFSET, 1),
    kNONE_to_MCLK_CLK = CLKCTL1_TUPLE_MUXA(AUDIOMCLKSEL_OFFSET, 7),

    kSFRO_to_DMIC = CLKCTL1_TUPLE_MUXA(DMIC0FCLKSEL_OFFSET, 0),
    kFFRO_to_DMIC = CLKCTL1_TUPLE_MUXA(DMIC0FCLKSEL_OFFSET, 1),
    kAUDIO_PLL_to_DMIC = CLKCTL1_TUPLE_MUXA(DMIC0FCLKSEL_OFFSET, 2),
    kMASTER_CLK_to_DMIC = CLKCTL1_TUPLE_MUXA(DMIC0FCLKSEL_OFFSET, 3),
    kLPOSC_to_DMIC = CLKCTL1_TUPLE_MUXA(DMIC0FCLKSEL_OFFSET, 4),
    k32K_WAKE_CLK_to_DMIC = CLKCTL1_TUPLE_MUXA(DMIC0FCLKSEL_OFFSET, 5),
    kMAIN_CLK_DMIC = CLKCTL1_TUPLE_MUXA(DMIC0FCLKSEL_OFFSET, 6),
    kNONE_to_DMIC = CLKCTL1_TUPLE_MUXA(DMIC0FCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_ACMP_CLK = CLKCTL1_TUPLE_MUXA(ACMP0FCLKSEL_OFFSET, 0),
    kSFRO_to_ACMP_CLK = CLKCTL1_TUPLE_MUXA(ACMP0FCLKSEL_OFFSET, 1),
    kFFRO_to_ACMP_CLK = CLKCTL1_TUPLE_MUXA(ACMP0FCLKSEL_OFFSET, 2),
    kAUX0_PLL_to_ACMP_CLK = CLKCTL1_TUPLE_MUXA(ACMP0FCLKSEL_OFFSET, 3),
    kAUX1_PLL_to_ACMP_CLK = CLKCTL1_TUPLE_MUXA(ACMP0FCLKSEL_OFFSET, 4),
    kNONE_to_ACMP_CLK = CLKCTL1_TUPLE_MUXA(ACMP0FCLKSEL_OFFSET, 7),

    kSFRO_to_FLEXCOMM0 = CLKCTL1_TUPLE_MUXA(FC0FCLKSEL_OFFSET, 0),
    kFFRO_to_FLEXCOMM0 = CLKCTL1_TUPLE_MUXA(FC0FCLKSEL_OFFSET, 1),
    kAUDIO_PLL_to_FLEXCOMM0 = CLKCTL1_TUPLE_MUXA(FC0FCLKSEL_OFFSET, 2),
    kMASTER_CLK_to_FLEXCOMM0 = CLKCTL1_TUPLE_MUXA(FC0FCLKSEL_OFFSET, 3),
    kFRG_to_FLEXCOMM0 = CLKCTL1_TUPLE_MUXA(FC0FCLKSEL_OFFSET, 4),
    kNONE_to_FLEXCOMM0 = CLKCTL1_TUPLE_MUXA(FC0FCLKSEL_OFFSET, 7),

    kSFRO_to_FLEXCOMM1 = CLKCTL1_TUPLE_MUXA(FC1FCLKSEL_OFFSET, 0),
    kFFRO_to_FLEXCOMM1 = CLKCTL1_TUPLE_MUXA(FC1FCLKSEL_OFFSET, 1),
    kAUDIO_PLL_to_FLEXCOMM1 = CLKCTL1_TUPLE_MUXA(FC1FCLKSEL_OFFSET, 2),
    kMASTER_CLK_to_FLEXCOMM1 = CLKCTL1_TUPLE_MUXA(FC1FCLKSEL_OFFSET, 3),
    kFRG_to_FLEXCOMM1 = CLKCTL1_TUPLE_MUXA(FC1FCLKSEL_OFFSET, 4),
    kNONE_to_FLEXCOMM1 = CLKCTL1_TUPLE_MUXA(FC1FCLKSEL_OFFSET, 7),

    kSFRO_to_FLEXCOMM2 = CLKCTL1_TUPLE_MUXA(FC2FCLKSEL_OFFSET, 0),
    kFFRO_to_FLEXCOMM2 = CLKCTL1_TUPLE_MUXA(FC2FCLKSEL_OFFSET, 1),
    kAUDIO_PLL_to_FLEXCOMM2 = CLKCTL1_TUPLE_MUXA(FC2FCLKSEL_OFFSET, 2),
    kMASTER_CLK_to_FLEXCOMM2 = CLKCTL1_TUPLE_MUXA(FC2FCLKSEL_OFFSET, 3),
    kFRG_to_FLEXCOMM2 = CLKCTL1_TUPLE_MUXA(FC2FCLKSEL_OFFSET, 4),
    kNONE_to_FLEXCOMM2 = CLKCTL1_TUPLE_MUXA(FC2FCLKSEL_OFFSET, 7),

    kSFRO_to_FLEXCOMM3 = CLKCTL1_TUPLE_MUXA(FC3FCLKSEL_OFFSET, 0),
    kFFRO_to_FLEXCOMM3 = CLKCTL1_TUPLE_MUXA(FC3FCLKSEL_OFFSET, 1),
    kAUDIO_PLL_to_FLEXCOMM3 = CLKCTL1_TUPLE_MUXA(FC3FCLKSEL_OFFSET, 2),
    kMASTER_CLK_to_FLEXCOMM3 = CLKCTL1_TUPLE_MUXA(FC3FCLKSEL_OFFSET, 3),
    kFRG_to_FLEXCOMM3 = CLKCTL1_TUPLE_MUXA(FC3FCLKSEL_OFFSET, 4),
    kNONE_to_FLEXCOMM3 = CLKCTL1_TUPLE_MUXA(FC3FCLKSEL_OFFSET, 7),

    kSFRO_to_FLEXCOMM4 = CLKCTL1_TUPLE_MUXA(FC4FCLKSEL_OFFSET, 0),
    kFFRO_to_FLEXCOMM4 = CLKCTL1_TUPLE_MUXA(FC4FCLKSEL_OFFSET, 1),
    kAUDIO_PLL_to_FLEXCOMM4 = CLKCTL1_TUPLE_MUXA(FC4FCLKSEL_OFFSET, 2),
    kMASTER_CLK_to_FLEXCOMM4 = CLKCTL1_TUPLE_MUXA(FC4FCLKSEL_OFFSET, 3),
    kFRG_to_FLEXCOMM4 = CLKCTL1_TUPLE_MUXA(FC4FCLKSEL_OFFSET, 4),
    kNONE_to_FLEXCOMM4 = CLKCTL1_TUPLE_MUXA(FC4FCLKSEL_OFFSET, 7),

    kSFRO_to_FLEXCOMM5 = CLKCTL1_TUPLE_MUXA(FC5FCLKSEL_OFFSET, 0),
    kFFRO_to_FLEXCOMM5 = CLKCTL1_TUPLE_MUXA(FC5FCLKSEL_OFFSET, 1),
    kAUDIO_PLL_to_FLEXCOMM5 = CLKCTL1_TUPLE_MUXA(FC5FCLKSEL_OFFSET, 2),
    kMASTER_CLK_to_FLEXCOMM5 = CLKCTL1_TUPLE_MUXA(FC5FCLKSEL_OFFSET, 3),
    kFRG_to_FLEXCOMM5 = CLKCTL1_TUPLE_MUXA(FC5FCLKSEL_OFFSET, 4),
    kNONE_to_FLEXCOMM5 = CLKCTL1_TUPLE_MUXA(FC5FCLKSEL_OFFSET, 7),

    kSFRO_to_FLEXCOMM14 = CLKCTL1_TUPLE_MUXA(FC14FCLKSEL_OFFSET, 0),
    kFFRO_to_FLEXCOMM14 = CLKCTL1_TUPLE_MUXA(FC14FCLKSEL_OFFSET, 1),
    kAUDIO_PLL_to_FLEXCOMM14 = CLKCTL1_TUPLE_MUXA(FC14FCLKSEL_OFFSET, 2),
    kMASTER_CLK_to_FLEXCOMM14 = CLKCTL1_TUPLE_MUXA(FC14FCLKSEL_OFFSET, 3),
    kFRG_to_FLEXCOMM14 = CLKCTL1_TUPLE_MUXA(FC14FCLKSEL_OFFSET, 4),
    kNONE_to_FLEXCOMM14 = CLKCTL1_TUPLE_MUXA(FC14FCLKSEL_OFFSET, 7),

    kSFRO_to_FLEXCOMM15 = CLKCTL1_TUPLE_MUXA(FC15FCLKSEL_OFFSET, 0),
    kFFRO_to_FLEXCOMM15 = CLKCTL1_TUPLE_MUXA(FC15FCLKSEL_OFFSET, 1),
    kAUDIO_PLL_to_FLEXCOMM15 = CLKCTL1_TUPLE_MUXA(FC15FCLKSEL_OFFSET, 2),
    kMASTER_CLK_to_FLEXCOMM15 = CLKCTL1_TUPLE_MUXA(FC15FCLKSEL_OFFSET, 3),
    kFRG_to_FLEXCOMM15 = CLKCTL1_TUPLE_MUXA(FC15FCLKSEL_OFFSET, 4),
    kNONE_to_FLEXCOMM15 = CLKCTL1_TUPLE_MUXA(FC15FCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_CTIMER0 = CLKCTL1_TUPLE_MUXA(CT32BIT0FCLKSEL_OFFSET, 0),
    kSFRO_to_CTIMER0 = CLKCTL1_TUPLE_MUXA(CT32BIT0FCLKSEL_OFFSET, 1),
    kFFRO_PLL_to_CTIMER0 = CLKCTL1_TUPLE_MUXA(CT32BIT0FCLKSEL_OFFSET, 2),
    kAUDIO_PLL_to_CTIMER0 = CLKCTL1_TUPLE_MUXA(CT32BIT0FCLKSEL_OFFSET, 3),
    kMASTER_CLK_to_CTIMER0 = CLKCTL1_TUPLE_MUXA(CT32BIT0FCLKSEL_OFFSET, 4),
    kLPOSC_to_CTIMER0 = CLKCTL1_TUPLE_MUXA(CT32BIT0FCLKSEL_OFFSET, 5),
    kNONE_to_CTIMER0 = CLKCTL1_TUPLE_MUXA(CT32BIT0FCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_CTIMER1 = CLKCTL1_TUPLE_MUXA(CT32BIT1FCLKSEL_OFFSET, 0),
    kSFRO_to_CTIMER1 = CLKCTL1_TUPLE_MUXA(CT32BIT1FCLKSEL_OFFSET, 1),
    kFFRO_PLL_to_CTIMER1 = CLKCTL1_TUPLE_MUXA(CT32BIT1FCLKSEL_OFFSET, 2),
    kAUDIO_PLL_to_CTIMER1 = CLKCTL1_TUPLE_MUXA(CT32BIT1FCLKSEL_OFFSET, 3),
    kMASTER_CLK_to_CTIMER1 = CLKCTL1_TUPLE_MUXA(CT32BIT1FCLKSEL_OFFSET, 4),
    kLPOSC_to_CTIMER1 = CLKCTL1_TUPLE_MUXA(CT32BIT1FCLKSEL_OFFSET, 5),
    kNONE_to_CTIMER1 = CLKCTL1_TUPLE_MUXA(CT32BIT1FCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_CTIMER2 = CLKCTL1_TUPLE_MUXA(CT32BIT2FCLKSEL_OFFSET, 0),
    kSFRO_to_CTIMER2 = CLKCTL1_TUPLE_MUXA(CT32BIT2FCLKSEL_OFFSET, 1),
    kFFRO_PLL_to_CTIMER2 = CLKCTL1_TUPLE_MUXA(CT32BIT2FCLKSEL_OFFSET, 2),
    kAUDIO_PLL_to_CTIMER2 = CLKCTL1_TUPLE_MUXA(CT32BIT2FCLKSEL_OFFSET, 3),
    kMASTER_CLK_to_CTIMER2 = CLKCTL1_TUPLE_MUXA(CT32BIT2FCLKSEL_OFFSET, 4),
    kLPOSC_to_CTIMER2 = CLKCTL1_TUPLE_MUXA(CT32BIT2FCLKSEL_OFFSET, 5),
    kNONE_to_CTIMER2 = CLKCTL1_TUPLE_MUXA(CT32BIT2FCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_CTIMER3 = CLKCTL1_TUPLE_MUXA(CT32BIT3FCLKSEL_OFFSET, 0),
    kSFRO_to_CTIMER3 = CLKCTL1_TUPLE_MUXA(CT32BIT3FCLKSEL_OFFSET, 1),
    kFFRO_PLL_to_CTIMER3 = CLKCTL1_TUPLE_MUXA(CT32BIT3FCLKSEL_OFFSET, 2),
    kAUDIO_PLL_to_CTIMER3 = CLKCTL1_TUPLE_MUXA(CT32BIT3FCLKSEL_OFFSET, 3),
    kMASTER_CLK_to_CTIMER3 = CLKCTL1_TUPLE_MUXA(CT32BIT3FCLKSEL_OFFSET, 4),
    kLPOSC_to_CTIMER3 = CLKCTL1_TUPLE_MUXA(CT32BIT3FCLKSEL_OFFSET, 5),
    kNONE_to_CTIMER3 = CLKCTL1_TUPLE_MUXA(CT32BIT3FCLKSEL_OFFSET, 7),

    kMAIN_CLK_to_CTIMER4 = CLKCTL1_TUPLE_MUXA(CT32BIT4FCLKSEL_OFFSET, 0),
    kSFRO_to_CTIMER4 = CLKCTL1_TUPLE_MUXA(CT32BIT4FCLKSEL_OFFSET, 1),
    kFFRO_PLL_to_CTIMER4 = CLKCTL1_TUPLE_MUXA(CT32BIT4FCLKSEL_OFFSET, 2),
    kAUDIO_PLL_to_CTIMER4 = CLKCTL1_TUPLE_MUXA(CT32BIT4FCLKSEL_OFFSET, 3),
    kMASTER_CLK_to_CTIMER4 = CLKCTL1_TUPLE_MUXA(CT32BIT4FCLKSEL_OFFSET, 4),
    kLPOSC_to_CTIMER4 = CLKCTL1_TUPLE_MUXA(CT32BIT4FCLKSEL_OFFSET, 5),
    kNONE_to_CTIMER4 = CLKCTL1_TUPLE_MUXA(CT32BIT4FCLKSEL_OFFSET, 7),

} clock_attach_id_t;

/*  Clock dividers */
typedef enum _clock_div_name
{
    kCLOCK_DivSysCpuAhbClk = CLKCTL0_TUPLE_MUXA(SYSCPUAHBCLKDIV_OFFSET, 0),
    kCLOCK_DivAdcClk = CLKCTL0_TUPLE_MUXA(ADC0FCLKDIV_OFFSET, 0),
    kCLOCK_DivQspiClk = CLKCTL0_TUPLE_MUXA(OSPIFCLKDIV_OFFSET, 0),
    kCLOCK_DivSctClk = CLKCTL0_TUPLE_MUXA(SCTFCLKDIV_OFFSET, 0),
    kCLOCK_DivSdio0Clk = CLKCTL0_TUPLE_MUXA(SDIO0FCLKDIV_OFFSET, 0),
    kCLOCK_DivSystickClk = CLKCTL0_TUPLE_MUXA(SYSTICKFCLKDIV_OFFSET, 0),
    kCLOCK_DivUsbHsFclk = CLKCTL0_TUPLE_MUXA(USBHSFCLKDIV_OFFSET, 0),
    kCLOCK_DivAudioPllClk = CLKCTL1_TUPLE_MUXA(AUDIOPLLCLKDIV_OFFSET, 0),
    kCLOCK_DivAcmpClk = CLKCTL1_TUPLE_MUXA(ACMP0FCLKDIV_OFFSET, 0),
    kCLOCK_DivClockOut = CLKCTL1_TUPLE_MUXA(CLKOUTDIV_OFFSET, 0),
    kCLOCK_DivDmicClk = CLKCTL1_TUPLE_MUXA(DMIC0FCLKDIV_OFFSET, 0),
    kCLOCK_DivDspCpuClk = CLKCTL1_TUPLE_MUXA(DSPCPUCLKDIV_OFFSET, 0),
    kCLOCK_DivDspRamClk = CLKCTL1_TUPLE_MUXA(DSPMAINRAMCLKDIV_OFFSET, 0),
    kCLOCK_DivMclkClk = CLKCTL1_TUPLE_MUXA(AUDIOMCLKDIV_OFFSET, 0),
    kCLOCK_DivPLLFRGClk = CLKCTL1_TUPLE_MUXA(FRGPLLCLKDIV_OFFSET, 0),
    kCLOCK_DivI3cClk = CLKCTL1_TUPLE_MUXA(I3C0FCLKDIV_OFFSET, 0),
    kCLOCK_DivI3cTcClk = CLKCTL1_TUPLE_MUXA(I3C0FCLKSTCDIV_OFFSET, 0),
    kCLOCK_DivI3cSlowClk = CLKCTL1_TUPLE_MUXA(I3C0FCLKSDIV_OFFSET, 0),
} clock_div_name_t;

/*! @brief PLL configuration for SYSPLL */
typedef struct _clock_sys_pll_config
{
    enum
    {
        kCLOCK_SysPllSFroClk = 0, /*!< 16MHz FRO clock */
        kCLOCK_SysPllXtalIn,      /*!< OSC clock */
        kCLOCK_SysPllFFroDiv2,    /*!< FRO48/60 clock */
    } sys_pll_src;
    uint32_t numerator;   /*!< 30 bit numerator of fractional loop divider. */
    uint32_t denominator; /*!< 30 bit numerator of fractional loop divider. */
    enum
    {
        kCLOCK_SysPllMult16 = 0,
        kCLOCK_SysPllMult17,
        kCLOCK_SysPllMult20,
        kCLOCK_SysPllMult22,
        kCLOCK_SysPllMult27,
        kCLOCK_SysPllMult33,
    } sys_pll_mult;
} clock_sys_pll_config_t;
/*! @brief PLL configuration for SYSPLL */
typedef struct _clock_audio_pll_config
{
    enum
    {
        kCLOCK_AudioPllSFroClk = 0, /*!< 16MHz FRO clock */
        kCLOCK_AudioPllXtalIn,      /*!< OSC clock */
        kCLOCK_AudioPllFFroDiv2,    /*!< FRO48/60 clock */
    } audio_pll_src;
    uint32_t numerator;   /*!< 30 bit numerator of fractional loop divider. */
    uint32_t denominator; /*!< 30 bit numerator of fractional loop divider. */
    uint8_t mult;         /*!< PLL loop divider. */
} clock_audio_pll_config_t;
/*! @brief PLL configuration for FRG */
typedef struct _clock_frg_clk_config
{
    uint8_t num; /*!< FRG clock */
    enum
    {
        kCLOCK_FrgMainClk = 0, /*!< Main System clock */
        kCLOCK_FrgPllDiv,      /*!< Main pll clock divider*/
        kCLOCK_FrgSFro,        /*!< 16MHz FRO */
        kCLOCK_FrgFFro,        /*!< FRO48/60 */
    } sfg_clock_src;
    uint8_t divider; /*!< PLL loop divider. */
    uint8_t mult;    /*!< PLL loop divider. */
} clock_frg_clk_config_t;
/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

static inline void CLOCK_EnableClock(clock_ip_name_t clk)
{
    uint32_t index = CLK_GATE_ABSTRACT_REG_OFFSET(clk);

    switch (index)
    {
        case CLK_CTL0_PSCCTL0:
            CLKCTL0->PSCCTL0_SET = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL0_PSCCTL1:
            CLKCTL0->PSCCTL1_SET = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL0_PSCCTL2:
            CLKCTL0->PSCCTL2_SET = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL1_PSCCTL0:
            CLKCTL1->PSCCTL0_SET = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL1_PSCCTL1:
            CLKCTL1->PSCCTL1_SET = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL1_PSCCTL2:
            CLKCTL1->PSCCTL2_SET = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        default:
            break;
    }
}

static inline void CLOCK_DisableClock(clock_ip_name_t clk)
{
    uint32_t index = CLK_GATE_ABSTRACT_REG_OFFSET(clk);
    switch (index)
    {
        case CLK_CTL0_PSCCTL0:
            CLKCTL0->PSCCTL0_CLR = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL0_PSCCTL1:
            CLKCTL0->PSCCTL1_CLR = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL0_PSCCTL2:
            CLKCTL0->PSCCTL2_CLR = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL1_PSCCTL0:
            CLKCTL1->PSCCTL0_CLR = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL1_PSCCTL1:
            CLKCTL1->PSCCTL1_CLR = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        case CLK_CTL1_PSCCTL2:
            CLKCTL1->PSCCTL2_CLR = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
            break;
        default:
            break;
    }
}
/**
 * @brief   Configure the clock selection muxes.
 * @param   connection  : Clock to be configured.
 * @return  Nothing
 */
void CLOCK_AttachClk(clock_attach_id_t connection);
/**
 * @brief   Setup peripheral clock dividers.
 * @param   div_name    : Clock divider name
 * @param   divider     : Value to be divided.
 * @return  Nothing
 */
void CLOCK_SetClkDiv(clock_div_name_t div_name, uint32_t divider);
/*! @brief  Return Frequency of selected clock
 *  @return Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);

/*! @brief  Return Input frequency for the Fractional baud rate generator
 *  @return Input Frequency for FRG
 */
uint32_t CLOCK_GetFRGClock(uint32_t id);

/*! @brief  Set output of the Fractional baud rate generator
 * @param   config    : Configuration to set to FRGn clock.
 */
void CLOCK_SetFRGClock(const clock_frg_clk_config_t *config);

/*! @brief  Return Frequency of FRO 16MHz
 *  @return Frequency of FRO 12MHz
 */
static inline uint32_t CLOCK_GetSFroFreq(void)
{
    return CLK_FRO_16MHZ;
}
/*! @brief  Return Frequency of SYSPLL
 *  @return Frequency of SYSPLL
 */
uint32_t CLOCK_GetSysPllFreq(void);
/*! @brief  Get current output frequency of specific System PLL PFD.
 *  @param   pfd    : pfd name to get frequency.
 *  @return  Frequency of SYSPLL PFD.
 */
uint32_t CLOCK_GetSysPfdFreq(clock_pfd_t pfd);
/*! @brief  Return Frequency of AUDIO PLL
 *  @return Frequency of AUDIO PLL
 */
uint32_t CLOCK_GetAudioPllFreq(void);
/*! @brief  Get current output frequency of specific Audio PLL PFD.
 *  @param   pfd    : pfd name to get frequency.
 *  @return  Frequency of AUDIO PLL PFD.
 */
uint32_t CLOCK_GetAudioPfdFreq(clock_pfd_t pfd);
/*! @brief  Return Frequency of High-Freq output of FRO
 *  @return Frequency of High-Freq output of FRO
 */
static inline uint32_t CLOCK_GetFFroFreq(void)
{
    return CLK_FRO_48MHZ;
}
/*! @brief  Return Frequency of main clk
 *  @return Frequency of main clk
 */
uint32_t CLOCK_GetMainClkFreq(void);
/*! @brief  Return Frequency of DSP main clk
 *  @return Frequency of DSP main clk
 */
uint32_t CLOCK_GetDspMainClkFreq(void);
/*! @brief  Return Frequency of ACMP clk
 *  @return Frequency of ACMP clk
 */
uint32_t CLOCK_GetAcmpClkFreq(void);
/*! @brief  Return Frequency of DMIC clk
 *  @return Frequency of DMIC clk
 */
uint32_t CLOCK_GetDmicClkFreq(void);
/*! @brief  Return Frequency of USB clk
 *  @return Frequency of USB clk
 */
uint32_t CLOCK_GetUsbClkFreq(void);
/*! @brief  Return Frequency of SDIO clk
 *  @param  sel : clock source select
 *  @param  divider : clock divider
 *  @return Frequency of SDIO clk
 */
uint32_t CLOCK_GetSdioClkFreq(uint32_t sel, uint32_t divider);
/*! @brief  Return Frequency of systick clk
 *  @return Frequency of systick clk
 */
uint32_t CLOCK_GetSystickClkFreq(void);
/*! @brief  Return Frequency of wdt clk
 *  @return Frequency of wdt clk
 */
uint32_t CLOCK_GetWdt0ClkFreq(void);
/*! @brief  Return Frequency of mclk
 *  @return Frequency of mclk clk
 */
uint32_t CLOCK_GetMclkClkFreq(void);
/*! @brief  Return Frequency of sct
 *  @return Frequency of sct clk
 */
uint32_t CLOCK_GetSctClkFreq(void);

/*! @brief  Return Frequency of sys osc Clock
 *  @return Frequency of sys osc Clock. If no external clock is used returns 0.
 */
static inline uint32_t CLOCK_GetXtalInClkFreq(void)
{
    return (CLKCTL0->SYSOSCBYPASS == 0U) ? g_xtalFreq : 0U;
}
/*! @brief  Enable sys osc clock from external crystal clock.
 *  @param  enable : true to enable system osc clock, false to bypass system osc.
 */
static inline void CLOCK_EnableSysOscClk(bool enable)
{
    if (enable)
    {
        CLKCTL0->SYSOSCCTL0 = CLKCTL0_SYSOSCCTL0_LP_ENABLE_MASK;
        CLKCTL0->SYSOSCBYPASS = 0;
    }
    else
    {
        CLKCTL0->SYSOSCCTL0 |= CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE_MASK;
    }
}
/*! @brief  Return Frequency of Lower power osc
 *  @return Frequency of LPOSC
 */
static inline uint32_t CLOCK_GetLpOscFreq(void)
{
    return CLK_LPOSC_1MHZ;
}
/*! @brief  Return Frequency of 32kHz osc
 *  @return Frequency of 32kHz osc
 */
static inline uint32_t CLOCK_GetOsc32KFreq(void)
{
    return (CLKCTL0->OSC32KHZCTL0 & CLKCTL0_OSC32KHZCTL0_ENA32KHZ_MASK) ? CLK_RTC_32K_CLK : 0U;
}
/*! @brief  Enables and disables 32kHz osc
 *  @param  enable : true to enable 32k osc clock, false to disable clock
 */
static inline void CLOCK_EnableOsc32K(bool enable)
{
    if (enable)
    {
        CLKCTL0->OSC32KHZCTL0 |= CLKCTL0_OSC32KHZCTL0_ENA32KHZ_MASK;
    }
    else
    {
        CLKCTL0->OSC32KHZCTL0 &= ~CLKCTL0_OSC32KHZCTL0_ENA32KHZ_MASK;
    }
}

/*! @brief  Return Frequency of 32khz wake clk
 *  @return Frequency of 32kHz wake clk
 */
static inline uint32_t CLOCK_GetWakeClk32KFreq(void)
{
    return (CLKCTL0->WAKECLK32KHZSEL & CLKCTL0_WAKECLK32KHZSEL_SEL_MASK) ?
               CLOCK_GetLpOscFreq() / ((CLKCTL0->WAKECLK32KHZDIV & 0xffU) + 1U) :
               CLK_RTC_32K_CLK;
}
/*!
 * @brief Set the XTALIN (system OSC) frequency based on board setting.
 *
 * @param freq : The XTAL input clock frequency in Hz.
 */
static inline void CLOCK_SetXtalFreq(uint32_t freq)
{
    g_xtalFreq = freq;
}
/*!
 * @brief Set the MCLK in (mclk_in) clock frequency based on pin drive.
 *
 * @param freq : The MCLK input clock frequency in Hz.
 */
static inline void CLOCK_SetMclkInFreq(uint32_t freq)
{
    g_MclkInFreq = freq;
}
/*! brief  Return Frequency of mclk_in
 *  return Frequency of mclk clk
 *  Note The pin need associated with MCLK function.
 */
uint32_t CLOCK_GetMclkInClkFreq(void);
/*! @brief  Return Frequency of Flexcomm functional Clock
 *  @param   id    : flexcomm index to get frequency.
 *  @return Frequency of Flexcomm functional Clock
 */
uint32_t CLOCK_GetFlexCommClkFreq(uint32_t id);
/*! @brief  Return Frequency of Ctimer Clock
 *  @param   id    : ctimer index to get frequency.
 *  @return Frequency of Ctimer Clock
 */
uint32_t CLOCK_GetCtimerClkFreq(uint32_t id);
/*! @brief  Return Frequency of ClockOut
 *  @return Frequency of ClockOut
 */
uint32_t CLOCK_GetClockOutClkFreq(void);
/*! @brief  Return Frequency of Adc Clock
 *  @return Frequency of Adc Clock.
 */
uint32_t CLOCK_GetAdcClkFreq(void);
/*! @brief  Return Frequency of QSPI Clock
 *  @return Frequency of Qspi.
 */
uint32_t CLOCK_GetQspiClkFreq(void);
/*! @brief  Initialize the System PLL.
 *  @param  config    : Configuration to set to PLL.
 */
void CLOCK_InitSysPll(const clock_sys_pll_config_t *config);
/*! @brief Initialize the System PLL PFD.
 *  @param pfd    : Which PFD clock to enable.
 *  @param divider    : The PFD divider value.
 *  @note It is recommended that PFD settings are kept between 12-35.
 */
void CLOCK_InitSysPfd(clock_pfd_t pfd, uint8_t divider);
/*! @brief  Initialize the audio PLL.
 *  @param  config    : Configuration to set to PLL.
 */
void CLOCK_InitAudioPll(const clock_audio_pll_config_t *config);
/*! @brief Initialize the audio PLL PFD.
 *  @param pfd    : Which PFD clock to enable.
 *  @param divider    : The PFD divider value.
 *  @note It is recommended that PFD settings are kept between 12-35.
 */
void CLOCK_InitAudioPfd(clock_pfd_t pfd, uint8_t divider);
/*! @brief Enable USB HS device PLL clock.
 *
 * This function enables USB HS device PLL clock.
 */
void CLOCK_EnableUsbhsDeviceClock(void);
/*! @brief Enable USB HS host PLL clock.
 *
 * This function enables USB HS host PLL clock.
 */
void CLOCK_EnableUsbhsHostClock(void);
/*! @brief Enable USB HS PHY PLL clock.
 *
 * This function enables USB HS PHY PLL clock.
 */
void CLOCK_EnableUsbhsPhyClock(void);
#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */
