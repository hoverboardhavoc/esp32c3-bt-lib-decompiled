/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_data_rx_buf_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_data_rx_buf_reset(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = (uint)*(byte *)(_p_ble_util_buf_env + 0x1ba);
  while (uVar2 = uVar3 - 1, uVar2 != 0xffffffff) {
    uVar1 = *(ushort *)(_p_ble_util_buf_env + 0x1b8);
    uVar5 = uVar2 * 0x400 + 0x7805;
    *(short *)((uVar3 + 0x17) * 8 + _p_ble_util_buf_env + 4) = (short)(uVar5 * 0x10000 >> 0x10);
    iVar4 = r_emi_overwrite_em_mapping_by_offset((uVar5 & 0xffff) - 5,uVar1 + 0xd);
    uVar3 = uVar2;
    if (iVar4 != 0) {
      r_assert_err(0,"ble_util_buf.c",0xfc);
    }
  }
  r_co_list_pool_init(_p_ble_util_buf_env + 8,_p_ble_util_buf_env + 0xc0,8,
                      *(undefined1 *)(_p_ble_util_buf_env + 0x1ba));
  return;
}

