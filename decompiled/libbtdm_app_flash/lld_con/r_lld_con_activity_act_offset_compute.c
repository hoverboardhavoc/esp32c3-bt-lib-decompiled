/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_activity_act_offset_compute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_con_activity_act_offset_compute
               (int param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar1 == 0) {
    uVar5 = 0;
    uVar2 = 0;
    iVar4 = 0;
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(iVar1 + 100);
    iVar4 = *(int *)(iVar1 + 0x48);
    uVar5 = (uint)*(ushort *)(iVar1 + 0x6e);
    uVar2 = (uint)*(ushort *)(iVar1 + 0x7c) + (uint)*(ushort *)(iVar1 + 0x7e) & 0xffff;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar1 = uVar2 - param_2;
  if (iVar1 < 0x8001) {
    iVar1 = param_2 - uVar2;
  }
  uVar3 = (iVar1 * 0x10000 >> 0x10) * iVar6 + iVar4 & 0xfffffff;
  uVar2 = (*param_4 * 2 + uVar5) / 0x271 + uVar3;
  if (param_3 == 0) {
    r_assert_err(0,"lld_con.c",0x94);
  }
  iVar1 = ((uVar2 & 0xffffffe) - uVar3 & 0xfffffff) * 0x271 - uVar5;
  if (iVar1 < 1) {
    iVar1 = (iVar1 + -1) / 2;
  }
  else {
    iVar1 = iVar1 + 1 >> 1;
  }
  *param_4 = *param_4 - iVar1;
  *param_5 = *param_5 - iVar1;
  return (uVar2 * 0x10 >> 5) % (uint)(param_3 << 1) & 0xffff;
}

