/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> hci_le_set_data_len_cmd_pre_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int hci_le_set_data_len_cmd_pre_handler(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = r_sdk_config_get_opts();
  iVar2 = 0;
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    iVar1 = *(int *)(&llc_env + param_1 * 4);
    iVar2 = 0;
    if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
      iVar2 = (uint)((*(byte *)(iVar3 + 0x45) & 0x20) != 0) << 1;
    }
  }
  return iVar2;
}

