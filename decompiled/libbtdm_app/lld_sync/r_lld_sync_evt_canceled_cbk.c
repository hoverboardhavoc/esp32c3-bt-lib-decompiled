/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_evt_canceled_cbk(int param_1)

{
  bool bVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x5b) != '\0') {
      (**(code **)(_r_plf_funcs_p + 0xc))(0,0x10000,0x4d9,*(code **)(_r_plf_funcs_p + 0xc));
    }
    if (*(char *)(param_1 + 99) == '\x01') {
      (**(code **)(_r_ip_funcs_p + 0x178))
                (*(undefined1 *)(param_1 + 0x55),*(code **)(_r_ip_funcs_p + 0x178));
      *(undefined1 *)(param_1 + 99) = 0;
    }
    bVar1 = *(char *)(param_1 + 0x5b) != '\x02';
    if (bVar1) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x16c);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x13c);
    }
                    /* WARNING: Could not recover jumptable at 0x0001169c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*(undefined1 *)(param_1 + 0x55),bVar1,UNRECOVERED_JUMPTABLE);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000116bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x4ee,*(code **)(_r_plf_funcs_p + 8));
  return;
}

