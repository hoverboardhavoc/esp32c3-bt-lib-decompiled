/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_init(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 1) {
    if (param_1 != 2) {
      return;
    }
    r_ble_log_internal_x0(0x60030120);
    iVar2 = r_sdk_config_get_opts();
    for (uVar1 = (int)((*(byte *)(iVar2 + 0xd) - 1) * 0x1000000) >> 0x18; -1 < (char)uVar1;
        uVar1 = uVar1 - 1) {
      if (*(int *)(&lld_con_env + uVar1 * 4) != 0) {
        r_lld_con_cleanup(uVar1 & 0xff,0,0x16);
      }
    }
  }
  memset(&lld_con_env,0,0x28);
  return;
}

