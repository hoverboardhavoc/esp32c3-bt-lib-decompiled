/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_offset_get
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
    r_assert_param(0,"lld_con.c",0x1245);
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
      r_assert_err(0,"lld_con.c",0x94);
    }
    uVar2 = (uVar2 >> 1) % uVar1 & 0xffff;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

