/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
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
  uint uVar5;
  
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
      uVar5 = (iVar3 - 1U & 0xff) << 5;
      bVar1 = *(byte *)(param_2 + 0x13);
      if ((uVar5 & 0xffffffdf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x162,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = (uint)bVar1 * 0x7e + 2;
      uVar2 = *(ushort *)(iVar3 + iVar4);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar3 + iVar4) = uVar2 & 0xffdf | (ushort)uVar5;
    }
    lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x14));
    return 0;
  }
  return 0;
}

