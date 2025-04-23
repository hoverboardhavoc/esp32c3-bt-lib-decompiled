/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_evt_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000103dc) */
/* WARNING: Removing unreachable block (ram,0x000103f0) */
/* WARNING: Removing unreachable block (ram,0x0001043c) */
/* WARNING: Removing unreachable block (ram,0x00010442) */
/* WARNING: Removing unreachable block (ram,0x00010404) */
/* WARNING: Removing unreachable block (ram,0x00010414) */
/* WARNING: Removing unreachable block (ram,0x00010432) */

void r_lld_cca_evt_cbk(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  
  iVar6 = p_lld_cca;
  if (param_2 != 0) {
    if (param_2 != 1) {
      r_assert_param("lld_cca.c",0x331);
      return;
    }
    sVar3 = *(short *)(p_lld_cca + 0x16);
    pbVar5 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
    if (sVar3 != 0) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar6) = sVar3;
      iVar6 = p_lld_cca;
      *(undefined2 *)(p_lld_cca + 0x16) = 0;
    }
    if ((*pbVar5 & 0x10) != 0) {
      r_lld_cca_force_tx(0);
      *pbVar5 = *pbVar5 & 0xef;
    }
    uVar4 = *(ushort *)(iVar6 + 4);
    if ((uVar4 & 0x10) == 0) {
      if (((uVar4 & 2) == 0) || ((*pbVar5 & 0x20) == 0)) {
        if ((*pbVar5 & 8) == 0) {
          if ((uVar4 & 1) != 0) {
            r_lld_cca_chan_rssi_cal(pbVar5);
          }
          if ((*pbVar5 & 2) != 0) {
            *pbVar5 = *pbVar5 & 0xfe | 8;
            pbVar5[8] = pbVar5[8] + 1;
          }
          if ((*(ushort *)(iVar6 + 4) & 4) != 0) {
            if (pbVar5[8] == *(byte *)(p_lld_cca + 0x1a)) {
              pbVar9 = (byte *)(*(int *)(p_lld_cca + 0x1c) + (uint)(*(byte *)(p_lld_cca + 8) >> 3));
              *pbVar9 = ~(byte)(1 << (*(byte *)(p_lld_cca + 8) & 7)) & *pbVar9;
              pbVar5[8] = 0;
              *pbVar5 = *pbVar5 | 4;
            }
            return;
          }
        }
      }
      else {
        r_lld_cca_set_thresh(0);
        *pbVar5 = *pbVar5 & 0xdf;
      }
    }
    return;
  }
  pbVar5 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
  if ((*(ushort *)(p_lld_cca + 4) & 0x10) != 0) {
    uVar4 = *(ushort *)(p_lld_cca + 4);
    pbVar5 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
    if ((uVar4 & 0xf00) == 0x200) {
      r_lld_cca_set_thresh(0);
      *pbVar5 = *pbVar5 & 0x7f;
    }
    else {
      r_lld_cca_set_thresh((int)*(char *)(p_lld_cca + 7));
    }
    if (uVar4 >> 0xc == 1) {
      sVar3 = *(short *)(iVar6 + 0x10);
      sVar2 = *(short *)(iVar6 + 0x14);
      bVar1 = *(byte *)(iVar6 + 0xd);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar6) = sVar3 - sVar2;
    }
    *(uint *)(pbVar5 + 4) = (rwip_prog_delay - 1) + param_1;
    *pbVar5 = *pbVar5 & 0xf5 | 0x41;
    return;
  }
  if ((*(ushort *)(p_lld_cca + 4) & 4) != 0) {
    r_lld_cca_chm_update_check();
  }
  bVar1 = *pbVar5;
  if ((bVar1 & 4) != 0) {
    r_lld_cca_busy_mode_handle();
    return;
  }
  if ((bVar1 & 2) == 0) {
_L174:
    if ((bVar1 & 1) == 0) {
      r_lld_cca_chan_handle(1);
      goto _L178;
    }
  }
  else {
    uVar7 = (uint)*(byte *)(p_lld_cca + 0x25) * 0x280;
    uVar8 = (uint)*(ushort *)(p_lld_cca + 0x12) << 1;
    if (uVar8 < uVar7) {
      uVar8 = uVar7;
    }
    if ((param_1 - *(int *)(pbVar5 + 4) & 0xfffffffU) < uVar8) goto _L174;
    *pbVar5 = bVar1 & 0xfd | 1;
  }
  r_lld_cca_chan_handle(0);
  *(uint *)(pbVar5 + 4) = (rwip_prog_delay - 1) + param_1;
  *pbVar5 = *pbVar5 & 0xf7;
_L178:
  if ((*(ushort *)(p_lld_cca + 4) & 2) != 0) {
    r_btdm_config_cca_sw(1,0xf,ble_2_rf_chan_tab[*(byte *)(p_lld_cca + 8)]);
    return;
  }
  return;
}

