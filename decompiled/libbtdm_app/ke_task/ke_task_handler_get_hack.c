/*
 * Last changed at upstream commit f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * https://github.com/espressif/esp32c3-bt-lib/commit/f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * Upstream date: 2021-06-21 17:00:22 +0530
 * Upstream subject: Fix MIC error issue during start_encryption procedure Update ESP32C3 and ESP32S3 libraries (a86af1e)
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
                    /* WARNING: Could not recover jumptable at 0x00010026. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar2 = (undefined *)
             (**(code **)(_r_modules_funcs_p + 0x16c))(sVar1,*(undefined2 *)(param_1 + 6));
    return puVar2;
  }
  return &lld_con_estab_ind_handler_hack;
}

