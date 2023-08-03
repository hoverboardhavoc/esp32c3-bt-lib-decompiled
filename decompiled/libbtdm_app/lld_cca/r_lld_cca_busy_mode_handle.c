/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_busy_mode_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_busy_mode_handle(int param_1)

{
  bool bVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  uVar2 = (int)(uint)*(ushort *)(p_lld_cca + 4) >> 8 & 0xf;
  if (uVar2 == 1) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x984);
  }
  else if (uVar2 == 2) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x988);
  }
  else {
    if (uVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010476. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_cca.c",0x18a);
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x97c);
    bVar1 = param_1 == 0;
    param_1 = -0x78;
    if (bVar1) {
      param_1 = 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010436. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

