/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> r_llc_le_ping_restart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_le_ping_restart(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar2 + 0x1c) != '\0') && ((*(ushort *)(iVar1 + 0x42) & 0x20) != 0)) {
    r_ke_timer_set(0x102,*(undefined2 *)(iVar1 + 0x3e));
    r_ke_timer_set(0x103,param_1 << 8 | 1,*(undefined2 *)(iVar1 + 0x40));
    return;
  }
  return;
}

