/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_evt_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000103c8) */
/* WARNING: Removing unreachable block (ram,0x000103dc) */
/* WARNING: Removing unreachable block (ram,0x00010428) */
/* WARNING: Removing unreachable block (ram,0x0001042e) */
/* WARNING: Removing unreachable block (ram,0x000103f0) */
/* WARNING: Removing unreachable block (ram,0x00010400) */
/* WARNING: Removing unreachable block (ram,0x0001041e) */

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
  byte *pbVar9;
  uint uVar10;
  
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
      *(short *)(iVar7 + (uint)bVar1 * 0x5a + 0x20) = sVar3;
      *(undefined2 *)(iVar6 + 0x16) = 0;
    }
    if ((*pbVar5 & 0x10) != 0) {
      r_lld_cca_force_tx(0);
      *pbVar5 = *pbVar5 & 0xef;
    }
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
          if ((*(ushort *)(p_lld_cca + 4) & 4) != 0) {
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
    pbVar5 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
    if (((int)(uint)*(ushort *)(p_lld_cca + 4) >> 8 & 0xfU) == 2) {
      r_lld_cca_set_thresh(0);
      *pbVar5 = *pbVar5 & 0x7f;
    }
    else {
      r_lld_cca_set_thresh((int)*(char *)(p_lld_cca + 7));
    }
    if (*(ushort *)(p_lld_cca + 4) >> 0xc == 1) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      sVar3 = *(short *)(p_lld_cca + 0x10);
      sVar2 = *(short *)(p_lld_cca + 0x14);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar6 + (uint)bVar1 * 0x5a + 0x20) = sVar3 - sVar2;
    }
    uVar10 = (uint)rwip_prog_delay;
    *pbVar5 = *pbVar5 & 0xf5 | 0x41;
    *(uint *)(pbVar5 + 4) = (uVar10 - 1) + param_1;
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
_L176:
    if ((bVar1 & 1) == 0) {
      r_lld_cca_chan_handle(1);
      goto _L180;
    }
  }
  else {
    uVar10 = (uint)*(ushort *)(p_lld_cca + 0x12) << 1;
    uVar8 = (uint)*(byte *)(p_lld_cca + 0x25) * 0x280;
    if (uVar10 < uVar8) {
      uVar10 = uVar8;
    }
    if ((param_1 - *(int *)(pbVar5 + 4) & 0xfffffffU) < uVar10) goto _L176;
    *pbVar5 = bVar1 & 0xfd | 1;
  }
  r_lld_cca_chan_handle(0);
  *(uint *)(pbVar5 + 4) = (rwip_prog_delay - 1) + param_1;
  *pbVar5 = *pbVar5 & 0xf7;
_L180:
  if ((*(ushort *)(p_lld_cca + 4) & 2) != 0) {
    r_btdm_config_cca_sw(1,0xf,ble_2_rf_chan_tab[*(byte *)(p_lld_cca + 8)]);
    return;
  }
  return;
}

