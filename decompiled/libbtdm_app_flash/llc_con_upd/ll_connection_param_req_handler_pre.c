/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> ll_connection_param_req_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_connection_param_req_handler_pre(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (*(ushort *)(param_2 + 2) < 0xb) {
    uVar2 = r_lld_con_count_get();
    if (1 < uVar2) {
      return 0x23;
    }
    if (*(char *)(iVar1 + 0x1c) == '\x03') {
      return 0x23;
    }
    if (*(char *)(iVar1 + 0x1d) == '\x03') {
      return 0x23;
    }
  }
  return 0;
}

