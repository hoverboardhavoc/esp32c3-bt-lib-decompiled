/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
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
      *(undefined2 *)(iVar2 + 0x44) = param_3;
      *(undefined1 *)(iVar2 + 0x46) = 2;
      memcpy((void *)(iVar2 + 0x34),param_2,5);
      uVar1 = 0;
      goto _L794;
    }
    (**(code **)(_r_plf_funcs_p + 0xc))
              (*(char *)(iVar2 + 0x46),0,"lld_con.c",0xf45,*(code **)(_r_plf_funcs_p + 0xc));
  }
  uVar1 = 0xc;
_L794:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

