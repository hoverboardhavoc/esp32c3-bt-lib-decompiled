/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_len_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx_len_update(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = (((param_3 - (uint)rwip_prog_delay) * 0x271 - 0x753 >> 1) - 0x96) -
          (uint)*(ushort *)(&fixed_tx_time + (uint)*(byte *)(iVar1 + 0x93) * 2);
  if (*(ushort *)(iVar1 + 0x88) < uVar2) {
    uVar2 = (uint)*(ushort *)(iVar1 + 0x88);
  }
  uVar2 = uVar2 - *(ushort *)(&fixed_tx_time + param_2 * 2);
  if ((*(ushort *)(iVar1 + 0x84) & 0x40) != 0) {
    uVar2 = uVar2 + (uint)*(ushort *)(&byte_tx_time + param_2 * 2) * -4;
  }
  uVar2 = uVar2 / *(ushort *)(&byte_tx_time + param_2 * 2);
  if (*(byte *)(iVar1 + 0x86) < uVar2) {
    uVar2 = (uint)*(byte *)(iVar1 + 0x86);
  }
  *(char *)(iVar1 + 0x8c) = (char)uVar2;
  return;
}

