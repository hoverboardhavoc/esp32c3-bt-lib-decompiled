/*
 * Last changed at upstream commit 84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * https://github.com/espressif/esp32c3-bt-lib/commit/84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * Upstream date: 2022-12-13 21:37:30 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3 (edd93b0)
 * Source: libbtdm_app -> ke_task.o -> ke_task_handler_get_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * ke_task_handler_get_hack(int param_1)

{
  short sVar1;
  undefined *puVar2;
  
  sVar1 = *(short *)(param_1 + 4);
  if (sVar1 == 0x20d) {
    return &lld_acl_rx_ind_handler_hack;
  }
  if (sVar1 != 0x213) {
    if (sVar1 != 0x201) {
                    /* WARNING: Could not recover jumptable at 0x0001002e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar2 = (undefined *)
               (**(code **)(_r_modules_funcs_p + 0x16c))(sVar1,*(undefined2 *)(param_1 + 6));
      return puVar2;
    }
    return &lld_adv_rep_ind_handler_hack;
  }
  return &lld_con_estab_ind_handler_hack;
}

