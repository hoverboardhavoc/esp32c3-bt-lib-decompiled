/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  if (uVar1 < 0x214) {
    if (uVar1 < 0x201) {
      if (uVar1 == 3) {
        return &llm_scan_period_to_handler_hack;
      }
      if (uVar1 == 6) {
        return &llm_rpa_renew_to_handler_hack;
      }
    }
    else {
      switch(uVar1) {
      case 0x201:
        return &lld_adv_rep_ind_handler_hack;
      case 0x203:
        return &lld_sync_start_req_handler_hack;
      case 0x205:
        return &lld_per_adv_rx_end_ind_handler_hack;
      case 0x206:
        return &lld_scan_end_ind_handler_hack;
      case 0x207:
        return &lld_adv_end_ind_handler_hack;
      case 0x20d:
        return &lld_acl_rx_ind_handler_hack;
      case 0x213:
        return &lld_con_estab_ind_handler_hack;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010032. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar2 = (undefined *)
           (**(code **)(_r_modules_funcs_p + 0x16c))
                     (*(undefined2 *)(param_1 + 6),*(code **)(_r_modules_funcs_p + 0x16c));
  return puVar2;
}

