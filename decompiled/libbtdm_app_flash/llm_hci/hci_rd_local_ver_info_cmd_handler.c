/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_rd_local_ver_info_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_rd_local_ver_info_cmd_handler(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)r_ke_msg_alloc(0x1101,0,param_1,10);
  uVar1 = _sdk_cfg_priv_opts;
  puVar2[4] = 0x16;
  puVar2[1] = 0x16;
  *puVar2 = 0x900;
  puVar2[3] = uVar1;
  *(undefined1 *)(puVar2 + 2) = 9;
  r_hci_send_2_host();
  return 0;
}

