/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_rd_max_adv_data_len_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_max_adv_data_len_cmd_handler(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x18) == '\0') {
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,4);
    *puVar2 = 0xc;
    *(undefined2 *)(puVar2 + 2) = 0x1f;
    r_hci_send_2_host();
    return 0;
  }
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,4);
  uVar3 = 0xc;
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar3 = 0;
  }
  *puVar2 = uVar3;
  *(undefined2 *)(puVar2 + 2) = 0x672;
  r_hci_send_2_host();
  return 0;
}

