/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llc_chmap_upd.o -> r_llc_ch_map_up_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_ch_map_up_proc_err_cb(undefined4 param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 == 0) {
    uVar1 = *param_3;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar2 == 6) {
      uVar3 = 2;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x61c);
    }
    else {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
      if (iVar2 != 6) {
        return;
      }
      uVar3 = 5;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x620);
    }
                    /* WARNING: Could not recover jumptable at 0x0001038e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,uVar3,uVar1,UNRECOVERED_JUMPTABLE);
    return;
  }
  if (2 < (param_2 - 1U & 0xff)) {
                    /* WARNING: Could not recover jumptable at 0x0001034e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(0x10000,0x172,*(code **)(_r_plf_funcs_p + 0xc));
    return;
  }
  return;
}

