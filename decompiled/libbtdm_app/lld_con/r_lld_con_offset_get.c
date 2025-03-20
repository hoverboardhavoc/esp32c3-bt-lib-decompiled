/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_offset_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_con_offset_get(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar3 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_con.c",0x10eb,*(code **)(_r_plf_funcs_p + 0xc));
    uVar2 = 0;
  }
  else {
    if ((*(ushort *)(iVar3 + 0x84) & 1) == 0) {
      uVar2 = *(uint *)(iVar3 + 0x48);
    }
    else {
      uVar2 = *(uint *)(iVar3 + 0x54);
    }
    uVar1 = *(uint *)(iVar3 + 100) >> 1;
    if (uVar1 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar2 = (uVar2 >> 1) % uVar1 & 0xffff;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

