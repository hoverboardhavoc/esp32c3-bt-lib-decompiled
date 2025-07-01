/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> lld.o -> r_lld_white_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_white_list_rem(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  
  if (param_3 != 0xff) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
    param_1 = param_1 * 8;
    uVar1 = *(ushort *)(iVar2 + param_1);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar4 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar2 + param_1) = uVar1 & 0xfffd;
    iVar2 = (*pcVar4)(0xc00,pcVar4);
    if ((*(ushort *)(iVar2 + param_1) & 1) == 0) {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar2 + param_1);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(param_1 + iVar2) = (ushort)(((uint)uVar1 << 0x11) >> 0x11);
    }
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x260))(param_2,param_3,*(code **)(_r_ip_funcs_p + 0x260));
    if (uVar3 < 10) {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar2 + uVar3 * 0x34);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(uVar3 * 0x34 + iVar2) = uVar1 & 0xdfff;
    }
    return;
  }
  _DAT_60031000 = _DAT_60031000 | 0x400;
  return;
}

