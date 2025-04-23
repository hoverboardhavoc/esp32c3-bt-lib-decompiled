/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_start_eco(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_21 [9];
  
  auStack_21[0] = 0xc;
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  *(undefined4 *)(iVar1 + 0x50) = uVar2;
  iVar3 = _r_ip_funcs_p;
  *(undefined2 *)(iVar1 + (param_1 + 0x10) * 2 + 8) = 0;
  (**(code **)(iVar3 + 0x7d8))(param_1,*(code **)(iVar3 + 0x7d8));
  (**(code **)(_r_ip_funcs_p + 0x7d4))(param_1,*(code **)(_r_ip_funcs_p + 0x7d4));
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x828))
                    (1,auStack_21,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x828));
  if (iVar3 == 0) {
    iVar3 = r_lld_con_start(param_1,param_2);
    auStack_21[0] = (undefined1)iVar3;
    if ((iVar3 == 0) && (*(int *)(&lld_con_env + param_1 * 4) != 0)) {
      *(undefined2 *)(*(int *)(&lld_con_env + param_1 * 4) + 0x98) = 0xffff;
    }
    (**(code **)(_r_ip_funcs_p + 0x828))
              (0,auStack_21,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x828));
  }
  return auStack_21[0];
}

