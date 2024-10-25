/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_scan_rsp_data_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_scan_rsp_data_update(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    ets_printf("adv_rsp_free\n");
  }
  else if (*(char *)(iVar1 + 0x89) == '\0') {
    r_lld_adv_scan_rsp_data_set(1,0);
  }
  else {
    if (*(short *)(iVar1 + 0x26) != 0) {
      r_ble_util_buf_adv_tx_free();
    }
    iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
    *(undefined2 *)(iVar1 + 0x2a) = param_2;
    *(undefined2 *)(iVar1 + 0x26) = param_3;
  }
                    /* WARNING: Could not recover jumptable at 0x0001541c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

