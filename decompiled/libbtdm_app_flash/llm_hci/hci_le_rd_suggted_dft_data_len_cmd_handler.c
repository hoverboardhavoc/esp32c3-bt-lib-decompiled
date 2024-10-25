/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rd_suggted_dft_data_len_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_suggted_dft_data_len_cmd_handler(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0,0x2023,6);
  uVar1 = *(undefined2 *)(_p_llm_env + 0x9c);
  uVar2 = *(undefined2 *)(_p_llm_env + 0x9e);
  *puVar3 = 0;
  *(undefined2 *)(puVar3 + 2) = uVar1;
  *(undefined2 *)(puVar3 + 4) = uVar2;
  r_hci_send_2_host();
  return 0;
}

