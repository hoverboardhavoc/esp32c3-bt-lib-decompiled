/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_data_len_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_con_data_len_update(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = 0xc;
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 0x8a) = param_4;
    iVar1 = _r_ip_funcs_p;
    *(undefined2 *)(iVar2 + 0x86) = param_3;
    pcVar4 = *(code **)(iVar1 + 0x34c);
    *(undefined2 *)(iVar2 + 0x88) = param_2;
    (*pcVar4)(param_1,pcVar4);
    (**(code **)(_r_ip_funcs_p + 0x3c4))
              (param_1,*(undefined1 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100),
               *(code **)(_r_ip_funcs_p + 0x3c4));
    uVar3 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

