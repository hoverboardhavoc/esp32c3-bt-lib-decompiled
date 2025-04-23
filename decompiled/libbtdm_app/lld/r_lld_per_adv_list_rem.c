/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_per_adv_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_list_rem(int param_1,undefined4 param_2,undefined4 param_3,ushort param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  
  iVar3 = _p_lld_env + param_1 * 2;
  uVar4 = *(ushort *)(iVar3 + 0xbc) & ~param_4;
  *(ushort *)(iVar3 + 0xbc) = uVar4;
  if (uVar4 == 0) {
    param_1 = param_1 * 8;
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar3 + param_1);
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar3 = _r_plf_funcs_p;
    *(ushort *)(iVar1 + param_1) = uVar4 & 0xfffe;
    iVar3 = (**(code **)(iVar3 + 0xbc))(0xc00,*(code **)(iVar3 + 0xbc));
    if ((*(ushort *)(iVar3 + param_1) >> 1 & 1) == 0) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar3 + param_1);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(param_1 + iVar3) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
    }
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x260))(param_2,param_3,*(code **)(_r_ip_funcs_p + 0x260));
    if (uVar2 < 10) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar3 + uVar2 * 0x34);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(uVar2 * 0x34 + iVar3) = uVar4 & 0xefff;
    }
    return;
  }
  return;
}

