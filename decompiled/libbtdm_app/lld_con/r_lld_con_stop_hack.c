/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_stop_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_stop_hack(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  uVar1 = 0xc;
  if (iVar2 == 0) goto _L175;
  if (*(char *)(iVar2 + 0x8f) == '\0') {
    if (param_2 != 0) {
      (**(code **)(_r_ip_funcs_p + 0x6b8))(0,*(code **)(_r_ip_funcs_p + 0x6b8));
      (**(code **)(_r_ip_funcs_p + 800))(param_1,1,0x16,*(code **)(_r_ip_funcs_p + 800));
      uVar1 = 0;
      goto _L175;
    }
_L177:
    *(undefined1 *)(iVar2 + 0x8f) = 2;
  }
  else if (*(char *)(iVar2 + 0x8f) == '\x01') goto _L177;
  uVar1 = 0;
_L175:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

