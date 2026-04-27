/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_skip_isr(int param_1)

{
  bool bVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = *(int *)(&lld_sync_env + param_1 * 4);
  if (iVar2 != 0) {
    (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,1,*(code **)(_r_ip_funcs_p + 0x6b8));
    if (*(char *)(iVar2 + 99) == '\x01') {
      (**(code **)(_r_ip_funcs_p + 0x178))(param_1,*(code **)(_r_ip_funcs_p + 0x178));
      *(undefined1 *)(iVar2 + 99) = 0;
    }
    bVar1 = *(char *)(iVar2 + 0x5b) != '\x02';
    if (bVar1) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x16c);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x13c);
    }
                    /* WARNING: Could not recover jumptable at 0x00011356. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*(undefined1 *)(iVar2 + 0x55),bVar1,UNRECOVERED_JUMPTABLE);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00011382. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x48c,*(code **)(_r_plf_funcs_p + 8));
  return;
}

