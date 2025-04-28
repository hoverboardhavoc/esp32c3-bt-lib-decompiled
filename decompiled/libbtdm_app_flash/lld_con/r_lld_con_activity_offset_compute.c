/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_activity_offset_compute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_con_activity_offset_compute(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar3 == 0) {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = 0;
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(iVar3 + 100);
    iVar1 = *(int *)(iVar3 + 0x48);
    uVar4 = (uint)*(ushort *)(iVar3 + 0x7c) + (uint)*(ushort *)(iVar3 + 0x7e) & 0xffff;
    uVar5 = 0;
    if (param_5 != 0) {
      uVar5 = (uint)*(ushort *)(iVar3 + 0x6e);
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar3 = uVar4 - param_2;
  if (iVar3 < 0x8001) {
    iVar3 = param_2 - uVar4;
  }
  uVar4 = (uint)(param_3 << 0x12) >> 0x10;
  if (uVar4 == 0) {
    r_assert_err(0,"lld_con.c",0x94);
  }
  uVar2 = uVar4 - (iVar1 + param_4 * -2 + (iVar3 * 0x10000 >> 0x10) * iVar6 & 0xfffffffU) % uVar4;
  if (uVar4 == uVar2) {
    uVar2 = 0;
  }
  iVar3 = uVar2 * 0x271 - uVar5;
  if (iVar3 < 0) {
    iVar3 = iVar3 + -1;
  }
  else {
    iVar3 = iVar3 + 1;
  }
  return iVar3 >> 1;
}

