/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_busy_mode_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_busy_mode_handle(int param_1)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = (int)(uint)*(ushort *)(p_lld_cca + 4) >> 8 & 0xf;
  if (uVar1 == 1) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x984);
  }
  else {
    if (uVar1 != 2) {
      if (uVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010448. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x97c))
                  ((-(uint)(param_1 == 0) & 0x78) - 0x78,*(code **)(_r_ip_funcs_p + 0x97c));
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x00010486. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_cca.c",0x18a,*(code **)(_r_plf_funcs_p + 8));
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x988);
  }
                    /* WARNING: Could not recover jumptable at 0x0001045a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
  return;
}

