/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_evt_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000103da) */
/* WARNING: Removing unreachable block (ram,0x000103ee) */
/* WARNING: Removing unreachable block (ram,0x0001043a) */
/* WARNING: Removing unreachable block (ram,0x00010440) */
/* WARNING: Removing unreachable block (ram,0x00010402) */
/* WARNING: Removing unreachable block (ram,0x00010412) */
/* WARNING: Removing unreachable block (ram,0x00010430) */

void r_lld_cca_evt_cbk(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  
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
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      iVar6 = p_lld_cca;
      *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar7) = sVar3;
      *(undefined2 *)(iVar6 + 0x16) = 0;
    }
    if ((*pbVar5 & 0x10) != 0) {
      r_lld_cca_force_tx(0);
      *pbVar5 = *pbVar5 & 0xef;
    }
    iVar6 = p_lld_cca;
    uVar4 = *(ushort *)(p_lld_cca + 4);
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
              pbVar10 = (byte *)(*(int *)(p_lld_cca + 0x1c) + (uint)(*(byte *)(p_lld_cca + 8) >> 3))
              ;
              *pbVar10 = ~(byte)(1 << (*(byte *)(p_lld_cca + 8) & 7)) & *pbVar10;
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
    if (((int)(uint)uVar4 >> 8 & 0xfU) == 2) {
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
  if ((bVar1 & 4) == 0) {
    if ((bVar1 & 2) != 0) {
      uVar8 = (uint)*(byte *)(p_lld_cca + 0x25) * 0x280;
      uVar9 = (uint)*(ushort *)(p_lld_cca + 0x12) << 1;
      if (uVar9 < uVar8) {
        uVar9 = uVar8;
      }
      if (uVar9 <= (param_1 - *(int *)(pbVar5 + 4) & 0xfffffffU)) {
        *pbVar5 = bVar1 & 0xfd | 1;
      }
    }
    if ((*pbVar5 & 1) == 0) {
      r_lld_cca_chan_handle(1);
    }
    else {
      r_lld_cca_chan_handle(0);
      *(uint *)(pbVar5 + 4) = (rwip_prog_delay - 1) + param_1;
      *pbVar5 = *pbVar5 & 0xf7;
    }
    if ((*(ushort *)(p_lld_cca + 4) & 2) != 0) {
      r_btdm_config_cca_sw(1,0xf,ble_2_rf_chan_tab[*(byte *)(p_lld_cca + 8)]);
      return;
    }
    return;
  }
  r_lld_cca_busy_mode_handle();
  return;
}

