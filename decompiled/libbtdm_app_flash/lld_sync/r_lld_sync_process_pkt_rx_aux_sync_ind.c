/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_process_pkt_rx_aux_sync_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_process_pkt_rx_aux_sync_ind(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = *(int *)(&lld_sync_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((param_2 != 0) && ((*(ushort *)((uint)bVar1 * 0x14 + 2 + iVar6) & 1) == 0)) {
    bVar2 = *(byte *)(_p_lld_env + 0xd8);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = *(ushort *)((uint)bVar2 * 0x14 + 10 + iVar6);
    if (0xfff < uVar3) {
      r_assert_err(0,0x10000,1000);
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd8);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar8 = CONCAT22(uVar3,*(undefined2 *)((uint)bVar2 * 0x14 + 8 + iVar6));
    bVar2 = *(byte *)(_p_lld_env + 0xd8);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar4 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)*(byte *)(iVar5 + 0x58) * 2) * -2 +
            0x270) - (*(ushort *)((uint)bVar2 * 0x14 + 0xc + iVar6) & 0x3ff);
    uVar7 = uVar4 & 0xffff;
    iVar6 = (int)(uVar4 * 0x10000) >> 0x10;
    if (((co_sca2ppm & 4) != 0) && ((*(byte *)(iVar5 + 0x58) - 2 & 0xff) < 2)) {
      uVar4 = uVar7 + (uint)_DAT_0001307a * -2;
      uVar7 = uVar4 & 0xffff;
      iVar6 = (int)(uVar4 * 0x10000) >> 0x10;
    }
    uVar4 = uVar8;
    if (0x751 < (uVar7 + 0x4e1 & 0xffff)) {
      r_assert_err(0,0x10000,0x19d);
    }
    for (; iVar6 < 0; iVar6 = (iVar6 + 0x271) * 0x10000 >> 0x10) {
      uVar4 = uVar4 - 1 & 0xfffffff;
    }
    *(uint *)(iVar5 + 0x44) = uVar4;
    *(short *)(iVar5 + 0x48) = (short)iVar6;
    *(uint *)(iVar5 + 0x38) = uVar8;
    *(undefined2 *)(iVar5 + 0x52) = 0;
    *(undefined1 *)(iVar5 + 0x54) = 0;
    iVar6 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
       (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 2)) {
      r_ble_log_internal_x2
                (0x20420006,(uint)*(ushort *)(iVar5 + 0x4a) << 0x10 | (uint)bVar1 << 8 | param_1,
                 *(undefined4 *)(iVar5 + 0x38));
      return;
    }
  }
  return;
}

