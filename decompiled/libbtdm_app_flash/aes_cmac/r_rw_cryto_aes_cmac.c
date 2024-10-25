/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes_cmac.o -> r_rw_cryto_aes_cmac
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_rw_cryto_aes_cmac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined4 param_5)

{
  r_aes_alloc(0x34,0x10000,param_4,param_5);
  r_aes_cmac_start(param_1,param_2,param_3);
  return;
}

