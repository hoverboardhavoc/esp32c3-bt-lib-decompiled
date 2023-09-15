/*
 * Last changed at upstream commit e9ad3d704f1034310de8f747d503ea5443df6b67
 * https://github.com/espressif/esp32c3-bt-lib/commit/e9ad3d704f1034310de8f747d503ea5443df6b67
 * Upstream date: 2023-09-15 17:47:18 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(29996e0)
 * Source: libbtdm_app -> lld.o -> r_lld_res_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_res_list_rem(void)

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
    *(ushort *)(iVar3 + uVar2 * 0x34) = uVar1 & 0x7fff;
    memset(&lld_rpa_res_list + uVar2 * 0xd,0,0xd);
    uVar4 = 0;
  }
  else {
    uVar4 = 2;
  }
  return uVar4;
}

