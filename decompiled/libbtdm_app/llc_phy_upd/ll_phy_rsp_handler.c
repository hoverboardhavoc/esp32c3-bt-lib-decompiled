/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> ll_phy_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte ll_phy_rsp_handler(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar4 + 0x18) == '\0') {
    return 0x24;
  }
  bVar3 = 0x1e;
  if (*(char *)(param_2 + 2) != '\0') {
    bVar3 = -(*(char *)(param_2 + 1) == '\0') & 0x1e;
  }
  if (((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) ||
     (iVar4 = (**(code **)(_r_ip_funcs_p + 0x678))
                        (param_1,0,param_3,*(code **)(_r_ip_funcs_p + 0x678)), iVar4 != 9)) {
    bVar3 = 0x24;
  }
  else {
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,0,*(code **)(_r_ip_funcs_p + 0x674));
    bVar1 = *(byte *)(param_2 + 2);
    *(byte *)(iVar4 + 10) = *(byte *)(iVar4 + 10) & bVar1;
    bVar2 = *(byte *)(param_2 + 1);
    *(byte *)(iVar4 + 0xb) = *(byte *)(iVar4 + 0xb) & bVar2;
    bVar5 = 0;
    if ((uint)bVar1 == (uint)bVar2) {
      bVar5 = (&one_bits)[bVar1] & -((&one_bits)[bVar1] == 1);
    }
    *(byte *)(iVar4 + 0xf) = bVar5 & 1;
    (**(code **)(_r_ip_funcs_p + 0x648))(param_1,2,bVar3,*(code **)(_r_ip_funcs_p + 0x648));
  }
  return bVar3;
}

