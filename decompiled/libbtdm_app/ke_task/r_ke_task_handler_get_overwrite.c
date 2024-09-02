/*
 * Last changed at upstream commit d874f55e1132416fe18293ae1aa9ac73c40b3261
 * https://github.com/espressif/esp32c3-bt-lib/commit/d874f55e1132416fe18293ae1aa9ac73c40b3261
 * Upstream date: 2024-09-02 19:56:58 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(8ce789b)
 * Source: libbtdm_app -> ke_task.o -> r_ke_task_handler_get_overwrite
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * r_ke_task_handler_get_overwrite(int param_1)

{
  ushort uVar1;
  undefined *puVar2;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if (uVar1 == 0x206) {
    return &lld_scan_end_ind_handler_hack;
  }
  if (uVar1 < 0x207) {
    if (uVar1 == 6) {
      return &llm_rpa_renew_to_handler_hack;
    }
    if (uVar1 == 0x201) {
      return &lld_adv_rep_ind_handler_hack;
    }
    if (uVar1 == 3) {
      return &llm_scan_period_to_handler_hack;
    }
  }
  else {
    if (uVar1 == 0x20d) {
      return &lld_acl_rx_ind_handler_hack;
    }
    if (uVar1 == 0x213) {
      return &lld_con_estab_ind_handler_hack;
    }
    if (uVar1 == 0x207) {
      return &lld_adv_end_ind_handler_hack;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010058. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar2 = (undefined *)
           (**(code **)(_r_modules_funcs_p + 0x16c))(uVar1,*(undefined2 *)(param_1 + 6));
  return puVar2;
}

