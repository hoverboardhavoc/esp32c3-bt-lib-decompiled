/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> f_hci_le_test_end_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_hci_le_test_end_cmd_handler(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = r_lld_test_stop();
  if (iVar1 == 0) {
    rw_rf_le_exit_test_mode();
  }
  else {
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,0x201f,4);
    *puVar2 = (char)iVar1;
    *(undefined2 *)(puVar2 + 2) = 0;
    r_hci_send_2_host();
  }
  return 0;
}

