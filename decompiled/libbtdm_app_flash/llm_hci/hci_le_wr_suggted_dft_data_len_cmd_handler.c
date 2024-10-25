/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_wr_suggted_dft_data_len_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_wr_suggted_dft_data_len_cmd_handler(short *param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _p_llm_env;
  uVar3 = 0x12;
  if ((ushort)(*param_1 - 0x1bU) < 0xe1) {
    sVar1 = param_1[1];
    uVar3 = 0x12;
    if ((ushort)(sVar1 - 0x148U) < 0x4149) {
      uVar3 = 0;
      *(short *)(_p_llm_env + 0x9c) = *param_1;
      *(short *)(iVar2 + 0x9e) = sVar1;
    }
  }
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

