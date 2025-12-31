/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_stop_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_stop_hack(uint param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
    r_ble_log_internal_x1(0x800300e4);
    uVar1 = 0xc;
    goto _L250;
  }
  r_ble_log_internal_x1(0x400300e3,param_2 << 8 | param_1 | (uint)*(byte *)(iVar2 + 0x8f) << 0x10);
  if (*(char *)(iVar2 + 0x8f) == '\0') {
    if (param_2 != 0) {
      r_sch_arb_remove(iVar2,0);
      r_lld_con_cleanup(param_1,1,0x16);
      uVar1 = 0;
      goto _L250;
    }
_L249:
    *(undefined1 *)(iVar2 + 0x8f) = 2;
  }
  else if (*(char *)(iVar2 + 0x8f) == '\x01') goto _L249;
  uVar1 = 0;
_L250:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

