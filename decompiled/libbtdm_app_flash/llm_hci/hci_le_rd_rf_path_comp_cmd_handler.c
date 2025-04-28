/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rd_rf_path_comp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_rf_path_comp_cmd_handler(void)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 uVar4;
  
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,0x204c,6);
  uVar1 = *(undefined2 *)(_p_llm_env + 0xca);
  *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(_p_llm_env + 200);
  *(undefined2 *)(puVar2 + 2) = uVar1;
  iVar3 = r_sdk_config_get_opts_ext();
  uVar4 = 0xc;
  if (*(char *)(iVar3 + 0x18) != '\0') {
    uVar4 = 0;
  }
  *puVar2 = uVar4;
  r_hci_send_2_host(puVar2);
  return 0;
}

