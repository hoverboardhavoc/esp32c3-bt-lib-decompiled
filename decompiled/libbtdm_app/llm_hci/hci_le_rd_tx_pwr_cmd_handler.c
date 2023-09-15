/*
 * Last changed at upstream commit e9ad3d704f1034310de8f747d503ea5443df6b67
 * https://github.com/espressif/esp32c3-bt-lib/commit/e9ad3d704f1034310de8f747d503ea5443df6b67
 * Upstream date: 2023-09-15 17:47:18 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(29996e0)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rd_tx_pwr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_tx_pwr_cmd_handler(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,0,0x204b,3,*(code **)(_r_modules_funcs_p + 200));
  *puVar2 = 0;
  uVar1 = (*_rw_rf_le_exit_test_mode)(btdm_controller_on_reset,1,_rw_rf_le_exit_test_mode);
  puVar2[1] = uVar1;
  uVar1 = (*_rw_rf_le_exit_test_mode)(DAT_00012045,1,_rw_rf_le_exit_test_mode);
  puVar2[2] = uVar1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar2,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

