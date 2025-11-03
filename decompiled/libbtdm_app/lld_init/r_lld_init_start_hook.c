/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == 0) {
    bVar1 = *(byte *)(param_2 + 0x13);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    uVar3 = (uint)bVar1 * 9 & 0xff;
    if (*(char *)(iVar5 + 0x18) == '\0') {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = uVar3 * 0xe + 2;
      uVar2 = *(ushort *)(iVar5 + iVar6);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar6) = uVar2 & 0xffdf;
    }
    iVar5 = llm_csa_get();
    if (iVar5 != 0) {
      uVar4 = (iVar5 - 1U & 0xff) << 5;
      if ((uVar4 & 0xffffffdf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x162,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = uVar3 * 0xe + 2;
      uVar2 = *(ushort *)(iVar5 + iVar6);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar6) = uVar2 & 0xffdf | (ushort)uVar4;
    }
    lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x14));
    return 0;
  }
  return 0;
}

