/*
 * Last changed at upstream commit 29d5555ca1febeb132f5a13556893f3419d2d640
 * https://github.com/espressif/esp32c3-bt-lib/commit/29d5555ca1febeb132f5a13556893f3419d2d640
 * Upstream date: 2024-06-03 11:12:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(0738a61)
 * Source: libbtdm_app -> lld.o -> r_lld_res_list_priv_mode_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_res_list_priv_mode_update(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x260))(*(code **)(_r_ip_funcs_p + 0x260));
  if (uVar2 < 10) {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar3 + uVar2 * 0x34);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar3 + uVar2 * 0x34) = (ushort)(param_1 == 1) << 0xb | uVar1 & 0xf7ff;
    uVar4 = 0;
  }
  else {
    uVar4 = 2;
  }
  return uVar4;
}

