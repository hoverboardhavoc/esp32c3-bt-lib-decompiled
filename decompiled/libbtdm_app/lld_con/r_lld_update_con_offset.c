/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_con.o -> r_lld_update_con_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_update_con_offset(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  for (uVar1 = 0; iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      (int)uVar1 < (int)(uint)*(byte *)(iVar2 + 0xd); uVar1 = uVar1 + 1) {
    if (*(int *)(&lld_con_env + uVar1 * 4) != 0) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x4f0))(uVar1 & 0xff,*(code **)(_r_ip_funcs_p + 0x4f0));
      if (iVar2 != 0) {
        uVar3 = (**(code **)(_r_ip_funcs_p + 0x374))(uVar1 & 0xff,*(code **)(_r_ip_funcs_p + 0x374))
        ;
        *(undefined4 *)(iVar2 + 8) = uVar3;
      }
    }
  }
  return;
}

