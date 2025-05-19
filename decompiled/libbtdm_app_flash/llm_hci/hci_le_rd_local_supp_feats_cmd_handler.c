/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rd_local_supp_feats_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_rd_local_supp_feats_cmd_handler(void)

{
  undefined1 *puVar1;
  void *__src;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1101,0,0x2003,9);
  __src = (void *)r_llm_le_features_get_hack();
  memcpy(puVar1 + 1,__src,8);
  *puVar1 = 0;
  r_hci_send_2_host(puVar1);
  return 0;
}

