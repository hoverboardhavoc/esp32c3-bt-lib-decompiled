/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_test_end_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_test_end_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x1f) == '\0') {
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,0x201f,4);
    *puVar2 = 0xc;
    *(undefined2 *)(puVar2 + 2) = 0;
    r_hci_send_2_host();
    return 0;
  }
  iVar1 = r_lld_test_stop(param_1,param_2);
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

