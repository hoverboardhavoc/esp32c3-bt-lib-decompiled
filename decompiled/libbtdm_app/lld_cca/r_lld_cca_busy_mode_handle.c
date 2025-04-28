/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  bool bVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = (int)(uint)*(ushort *)(p_lld_cca + 4) >> 8 & 0xf;
  if (uVar2 == 1) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x984);
  }
  else if (uVar2 == 2) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x988);
  }
  else {
    if (uVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010484. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_cca.c",0x18a,*(code **)(_r_plf_funcs_p + 8));
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x97c);
    bVar1 = param_1 == 0;
    param_1 = -0x78;
    if (bVar1) {
      param_1 = 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010446. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,UNRECOVERED_JUMPTABLE);
  return;
}

