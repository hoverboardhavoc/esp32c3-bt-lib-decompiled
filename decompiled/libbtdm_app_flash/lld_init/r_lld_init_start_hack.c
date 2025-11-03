/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_start_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_lld_init_start_hack(int param_1)

{
  int iVar1;
  
  iVar1 = r_lld_init_start();
  r_lld_init_start_hook_part_0(param_1);
  r_ble_log_internal_x2
            (0x40020097,*(undefined1 *)(param_1 + 0x12),
             iVar1 << 0x10 |
             (uint)CONCAT11(*(undefined1 *)(param_1 + 0x11),*(undefined1 *)(param_1 + 0x13)));
  return iVar1;
}

