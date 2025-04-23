/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_start_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_init_start_hook(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == 0) {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar3 + 0x18) == '\0') {
      bVar1 = *(byte *)(param_2 + 0x13);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar3 = ((uint)bVar1 * 9 & 0xff) * 0xe + 2;
      uVar2 = *(ushort *)(iVar4 + iVar3);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar3) = uVar2 & 0xffdf;
    }
    iVar3 = llm_csa_get();
    if (iVar3 != 0) {
      bVar1 = *(byte *)(param_2 + 0x13);
      if ((iVar3 - 1U & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x162,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = (uint)bVar1 * 0x7e + 2;
      uVar2 = *(ushort *)(iVar4 + iVar5);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar5) = uVar2 & 0xffdf | (ushort)((iVar3 - 1U & 0xff) << 5);
    }
    lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x14));
    return 0;
  }
  return 0;
}

