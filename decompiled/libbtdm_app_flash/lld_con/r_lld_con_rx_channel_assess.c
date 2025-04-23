/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar2 = r_lld_read_clock();
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar4 = (uint)*(ushort *)((uint)bVar1 * 0x14 + 6 + iVar3);
  iVar3 = (*_r_ble_log_internal_x2)(uVar4 & 0xff,_r_ble_log_internal_x2);
  if ((*(ushort *)(param_1 + 0x84) & 0x100) != 0) {
    *(char *)(param_1 + 0x95) = (char)iVar3;
  }
  uVar5 = 1;
  if (param_2 == 0) {
    if (iVar3 <= sdk_cfg_priv_opts) {
      return;
    }
    uVar5 = 0;
  }
  r_lld_channel_assess((int)uVar4 >> 8 & 0x3f,uVar5,uVar2);
  return;
}

