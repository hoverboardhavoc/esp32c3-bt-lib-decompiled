/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx_channel_assess
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_channel_assess(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar3 = r_lld_read_clock();
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = (uint)*(ushort *)((uint)bVar1 * 0x14 + 6 + iVar4);
  iVar4 = (*_rwip_rf)(uVar2 & 0xff,_rwip_rf);
  if ((*(ushort *)(param_1 + 0x84) & 0x100) != 0) {
    *(char *)(param_1 + 0x95) = (char)iVar4;
  }
  if (param_2 == 0) {
    if (iVar4 <= sdk_cfg_priv_opts) {
      return;
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  r_lld_channel_assess((int)uVar2 >> 8 & 0x3f,uVar5,uVar3);
  return;
}

