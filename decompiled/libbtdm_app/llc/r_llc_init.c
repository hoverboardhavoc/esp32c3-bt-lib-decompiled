/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llc.o -> r_llc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_init(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 1) {
    memset(&llc_env,0,0x28);
    return;
  }
  if (param_1 != 0) {
    if (param_1 != 2) {
      return;
    }
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    for (uVar1 = (int)((*(byte *)(iVar2 + 0xd) - 1) * 0x1000000) >> 0x18; -1 < (char)uVar1;
        uVar1 = uVar1 - 1) {
      if (*(int *)(&llc_env + uVar1 * 4) != 0) {
        (**(code **)(_r_ip_funcs_p + 0x65c))(uVar1 & 0xff,1,*(code **)(_r_ip_funcs_p + 0x65c));
      }
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010026. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x164))(1,&TASK_DESC_LLC);
  return;
}

