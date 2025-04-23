/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_terminate_max_evt_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_terminate_max_evt_update(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  if ((iVar3 != 0) && (iVar2 = iVar2 + param_1 * 4, *(char *)(iVar2 + 2) != '\0')) {
    if (param_2 == 0) {
      cVar1 = *(char *)(iVar2 + 3);
      *(char *)(iVar2 + 3) = cVar1 + '\x01';
      if ((5 < (byte)(cVar1 + 1U)) && (*(char *)(iVar3 + 0x8f) != '\x02')) {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,1,*(code **)(_r_ip_funcs_p + 0x6b8));
        (**(code **)(_r_ip_funcs_p + 800))(param_1,1,0x16,*(code **)(_r_ip_funcs_p + 800));
        return 1;
      }
    }
    else {
      *(undefined1 *)(iVar2 + 3) = 0;
    }
  }
  return 0;
}

