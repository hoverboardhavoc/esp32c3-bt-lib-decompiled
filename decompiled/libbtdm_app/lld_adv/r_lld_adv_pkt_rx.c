/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  while (iVar2 = (**(code **)(_r_ip_funcs_p + 0x2a4))(param_1,*(code **)(_r_ip_funcs_p + 0x2a4)),
        iVar2 != 0) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar2 = (uint)bVar1 * 0x14;
    if ((*(ushort *)(iVar2 + 2 + iVar3) & 0x603d) == 0) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar2 + 4 + iVar3) & 0xf;
      if (uVar4 == 5) {
        uVar5 = (**(code **)(_r_ip_funcs_p + 0x1c8))(param_1,*(code **)(_r_ip_funcs_p + 0x1c8));
      }
      else if ((*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8a) != '\0') && (uVar4 == 3)) {
        (**(code **)(_r_ip_funcs_p + 0x1cc))(param_1,*(code **)(_r_ip_funcs_p + 0x1cc));
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  }
  return uVar5;
}

