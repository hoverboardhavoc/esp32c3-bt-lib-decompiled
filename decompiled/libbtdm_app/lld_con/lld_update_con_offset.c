/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> lld_con.o -> lld_update_con_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_update_con_offset(void)

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

