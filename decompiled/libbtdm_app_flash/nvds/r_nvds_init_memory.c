/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> nvds.o -> r_nvds_init_memory
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_nvds_init_memory(void)

{
  (*DAT_00010680)(0,DAT_00010688,DAT_00010680);
                    /* WARNING: Could not recover jumptable at 0x00010230. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0001067c)(0,4,"NVDSNVDS MAGIC FAILED\n");
  return;
}

