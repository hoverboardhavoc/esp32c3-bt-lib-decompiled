/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> hci_le_con_upd_cmd_pre_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_con_upd_cmd_pre_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = *param_1;
  iVar2 = *(int *)(&llc_env + (uint)bVar1 * 4);
  if (((iVar2 != 0) && (*(ushort *)(param_1 + 2) < 0xb)) &&
     ((uVar3 = r_lld_con_count_get(), 1 < uVar3 ||
      ((*(char *)(iVar2 + 0x1c) == '\x03' || (*(char *)(iVar2 + 0x1d) == '\x03')))))) {
    r_llc_cmd_stat_send((uint)bVar1,param_2,0x12);
    return 1;
  }
  return 0;
}

