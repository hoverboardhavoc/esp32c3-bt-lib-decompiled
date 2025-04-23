/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_process_pkt_tx_cal_con_timestamp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_init_process_pkt_tx_cal_con_timestamp(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  iVar4 = _lld_init_env;
  bVar1 = (&co_rate_to_phy)[*(byte *)(_lld_init_env + 0x4e)];
  bVar2 = *(byte *)(*(int *)(param_1 * 4 + _lld_init_env) + 0x52);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  iVar7 = *(int *)(iVar4 + 0x54);
  uVar8 = (uint)*(ushort *)((uint)bVar2 * 0x5a + 0x44 + iVar5) * 4;
  if (sdk_cfg_priv_opts == '\0') {
    iVar4 = iVar4 + (uint)bVar1 * 10;
    uVar3 = *(ushort *)(iVar4 + 4);
    uVar6 = (uint)*(ushort *)(iVar4 + 2) * 4;
    if (*(ushort *)(iVar4 + 2) == 0) {
      r_assert_err(0,0x10000,0x94);
    }
    uVar6 = (uVar6 + iVar7) - (iVar7 + (uint)uVar3 * -2 & 0xfffffff) % uVar6 & 0xfffffff;
    if ((uVar6 - iVar7 & 0xfffffff) < uVar8) {
      uVar6 = uVar6 + (uint)*(ushort *)(iVar4 + 2) * 4 & 0xfffffff;
    }
  }
  else {
    iVar5 = 1;
    if (*(char *)(iVar4 + 0x59) != '\0') {
      iVar5 = (1 < *(byte *)(iVar4 + 0x4e)) + 2;
    }
    uVar6 = iVar5 * 4 + iVar7 + uVar8 & 0xfffffff;
  }
  return uVar6;
}

