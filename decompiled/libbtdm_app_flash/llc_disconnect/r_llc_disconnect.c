/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    r_lld_con_stop(param_3);
    *(undefined1 *)(iVar1 + 0x49) = 1;
    r_llc_llcp_state_set(param_1,2,3);
    return;
  }
  return;
}

