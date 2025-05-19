/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  
  iVar1 = r_lld_test_stop_hack();
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

