/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> r_llc_disconnect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_disconnect(int param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (*(char *)(iVar1 + 0x49) == '\0') {
    *(undefined1 *)(iVar1 + 0x46) = param_2;
    *(undefined1 *)(iVar1 + 0x47) = 0;
    r_lld_con_stop_hack(param_3);
    *(undefined1 *)(iVar1 + 0x49) = 1;
    r_llc_llcp_state_set(param_1,2,3);
    return;
  }
  return;
}

