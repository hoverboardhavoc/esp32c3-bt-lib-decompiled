/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_ch_map_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_ch_map_update(int param_1,void *param_2,undefined2 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x46) == '\0') {
      *(undefined1 *)(iVar2 + 0x46) = 2;
      *(undefined2 *)(iVar2 + 0x44) = param_3;
      memcpy((void *)(iVar2 + 0x34),param_2,5);
      uVar1 = 0;
      goto _L778;
    }
    (**(code **)(_r_plf_funcs_p + 0xc))
              (*(char *)(iVar2 + 0x46),0,"lld_con.c",0xf8a,*(code **)(_r_plf_funcs_p + 0xc));
  }
  uVar1 = 0xc;
_L778:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

