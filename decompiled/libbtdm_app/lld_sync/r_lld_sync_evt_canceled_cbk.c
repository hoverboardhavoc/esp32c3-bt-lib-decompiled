/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
      (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_sync.c",0x4d9,*(code **)(_r_plf_funcs_p + 0xc));
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
                    /* WARNING: Could not recover jumptable at 0x000116a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*(undefined1 *)(param_1 + 0x55),bVar1);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000116c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))("lld_sync.c",0x4ee);
  return;
}

