/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_adv_data_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_adv_data_update(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    ets_printf("adv_adv_free\n");
  }
  else if (*(char *)(iVar1 + 0x89) == '\0') {
    r_lld_adv_adv_data_set(1,0);
  }
  else {
    if (*(short *)(iVar1 + 0x24) != 0) {
      r_ble_util_buf_adv_tx_free();
    }
    iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
    *(undefined2 *)(iVar1 + 0x28) = param_2;
    *(undefined2 *)(iVar1 + 0x24) = param_3;
  }
                    /* WARNING: Could not recover jumptable at 0x000154b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

