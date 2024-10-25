/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_chmap_upd.o -> r_llc_ch_map_up_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_ch_map_up_proc_err_cb(undefined4 param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 uVar3;
  
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
                    /* WARNING: Could not recover jumptable at 0x0001035a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,uVar3,uVar1);
    return;
  }
  if (param_2 < 4) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010396. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))("llc_chmap_upd.c",0x166);
  return;
}

