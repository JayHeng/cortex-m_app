/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright (c) 2016, NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_reset.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.reset"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Assert reset to peripheral.
 *
 * Asserts reset signal to specified peripheral module.
 *
 * param peripheral Assert reset to this peripheral. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_SetPeripheralReset(reset_ip_name_t peripheral)
{
    const uint32_t regIndex = ((uint32_t)peripheral & 0x0000FF00u) >> 8;
    const uint32_t bitPos = ((uint32_t)peripheral & 0x000000FFu);
    const uint32_t bitMask = 1u << bitPos;

    assert(bitPos < 32u);

    switch (regIndex)
    {
        case RST_CTRL0_PSCCTL0:
            RSTCTRL0->PRSTCTL0_SET = bitMask;
            while (0u == (RSTCTRL0->PRSTCTL0 & bitMask))
            {
            }
            break;
        case RST_CTRL0_PSCCTL1:
            RSTCTRL0->PRSTCTL1_SET = bitMask;
            while (0u == (RSTCTRL0->PRSTCTL1 & bitMask))
            {
            }
            break;
        case RST_CTRL0_PSCCTL2:
            RSTCTRL0->PRSTCTL2_SET = bitMask;
            while (0u == (RSTCTRL0->PRSTCTL2 & bitMask))
            {
            }
            break;
        case RST_CTRL1_PSCCTL0:
            RSTCTRL1->PRSTCTL0_SET = bitMask;
            while (0u == (RSTCTRL1->PRSTCTL0 & bitMask))
            {
            }
            break;
        case RST_CTRL1_PSCCTL1:
            RSTCTRL1->PRSTCTL1_SET = bitMask;
            while (0u == (RSTCTRL1->PRSTCTL1 & bitMask))
            {
            }
            break;
        case RST_CTRL1_PSCCTL2:
            RSTCTRL1->PRSTCTL2_SET = bitMask;
            while (0u == (RSTCTRL1->PRSTCTL2 & bitMask))
            {
            }
            break;
        default:
            break;
    }
}

/*!
 * brief Clear reset to peripheral.
 *
 * Clears reset signal to specified peripheral module, allows it to operate.
 *
 * param peripheral Clear reset to this peripheral. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_ClearPeripheralReset(reset_ip_name_t peripheral)
{
    const uint32_t regIndex = ((uint32_t)peripheral & 0x0000FF00u) >> 8;
    const uint32_t bitPos = ((uint32_t)peripheral & 0x000000FFu);
    const uint32_t bitMask = 1u << bitPos;

    assert(bitPos < 32u);

    switch (regIndex)
    {
        case RST_CTRL0_PSCCTL0:
            RSTCTRL0->PRSTCTL0_CLR = bitMask;
            while (bitMask == (RSTCTRL0->PRSTCTL0 & bitMask))
            {
            }
            break;
        case RST_CTRL0_PSCCTL1:
            RSTCTRL0->PRSTCTL1_CLR = bitMask;
            while (bitMask == (RSTCTRL0->PRSTCTL1 & bitMask))
            {
            }
            break;
        case RST_CTRL0_PSCCTL2:
            RSTCTRL0->PRSTCTL2_CLR = bitMask;
            while (bitMask == (RSTCTRL0->PRSTCTL2 & bitMask))
            {
            }
            break;
        case RST_CTRL1_PSCCTL0:
            RSTCTRL1->PRSTCTL0_CLR = bitMask;
            while (bitMask == (RSTCTRL1->PRSTCTL0 & bitMask))
            {
            }
            break;
        case RST_CTRL1_PSCCTL1:
            RSTCTRL1->PRSTCTL1_CLR = bitMask;
            while (bitMask == (RSTCTRL1->PRSTCTL1 & bitMask))
            {
            }
            break;
        case RST_CTRL1_PSCCTL2:
            RSTCTRL1->PRSTCTL2_CLR = bitMask;
            while (bitMask == (RSTCTRL1->PRSTCTL2 & bitMask))
            {
            }
            break;
        default:
            break;
    }
}

/*!
 * brief Reset peripheral module.
 *
 * Reset peripheral module.
 *
 * param peripheral Peripheral to reset. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_PeripheralReset(reset_ip_name_t peripheral)
{
    RESET_SetPeripheralReset(peripheral);
    RESET_ClearPeripheralReset(peripheral);
}
