/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_start_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_lld_init_start_hack(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = r_lld_init_start();
  r_lld_init_start_hook_part_0(param_1);
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 0x10) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x1
                (0x400f0000,
                 iVar1 << 0x18 |
                 (uint)*(byte *)(param_1 + 0x11) << 0x10 | (uint)*(byte *)(param_1 + 0x12) << 8 |
                 (uint)*(byte *)(param_1 + 0x13));
    }
  }
  return iVar1;
}

