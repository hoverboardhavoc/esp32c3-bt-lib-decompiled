/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == 0) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar4 + 0x18) == '\0') {
      bVar1 = *(byte *)(param_2 + 0x13);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = ((uint)bVar1 * 9 & 0xff) * 0xe + 2;
      uVar2 = *(ushort *)(iVar5 + iVar4);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar4) = uVar2 & 0xffdf;
    }
    iVar4 = llm_csa_get();
    if (iVar4 != 0) {
      uVar3 = (iVar4 - 1U & 0xff) << 5;
      bVar1 = *(byte *)(param_2 + 0x13);
      if ((uVar3 & 0xffffffdf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x162,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = (uint)bVar1 * 0x7e + 2;
      uVar2 = *(ushort *)(iVar4 + iVar5);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar5) = uVar2 & 0xffdf | (ushort)uVar3;
    }
    lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x14));
    return 0;
  }
  return 0;
}

