/*
 * Copyright (c) 2016, Devan Lai
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose with or without fee is hereby granted, provided
 * that the above copyright notice and this permission notice
 * appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "DFU/DFU.h"
#include "backup.h"

#include <libopencm3/cm3/scb.h>

/* Boot command for DAPBoot bootloader */
static const uint16_t CMD_BOOT_VIA_DAPBOOT = 0x424C;

/* Writes a DFU command to the backup register and resets */
void DFU_reset_and_jump_to_bootloader(void) {
    backup_write_io16(4, CMD_BOOT_VIA_DAPBOOT);
    scb_reset_system();
    while (1);
}

void DFU_maybe_jump_to_bootloader(void) {

}
