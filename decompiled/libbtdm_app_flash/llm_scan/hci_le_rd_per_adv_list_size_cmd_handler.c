/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_rd_per_adv_list_size_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_per_adv_list_size_cmd_handler(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x18) == '\0') {
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,2);
    *puVar2 = 0xc;
    puVar2[1] = 0;
    r_hci_send_2_host();
    return 0;
  }
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,2);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    *puVar2 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    *puVar2 = 0;
  }
  puVar2[1] = 0xc;
  r_hci_send_2_host();
  return 0;
}

