/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_cbk(int param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  int iVar8;
  ushort uVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  byte bVar20;
  int iVar21;
  int iVar22;
  
  if (1 < param_2) {
    r_assert_param(0x10000,0x549);
  }
  iVar21 = _lld_init_env;
  if (param_3 == 2) {
    param_2 = param_2 & 0xff;
    if ((_lld_init_env != 0) && (iVar8 = *(int *)(param_2 * 4 + _lld_init_env), iVar8 != 0)) {
      while (iVar12 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar8 + 0x52)), iVar12 != 0) {
        bVar2 = *(byte *)(_p_lld_env + 0xd8);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        iVar12 = (uint)bVar2 * 0x14;
        bVar20 = *(byte *)(iVar8 + 0x52);
        uVar9 = *(ushort *)(iVar12 + 2 + iVar11);
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        iVar22 = iVar12 + 4;
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000,*(undefined2 *)((uint)bVar20 * 0x5a + iVar11));
        uVar4 = *(ushort *)(iVar11 + iVar12 + 6);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(ushort *)(iVar11 + iVar22);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar17 = (uint)(*(ushort *)(iVar11 + iVar12 + 6) >> 0xe);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar6 = *(undefined2 *)(iVar12 + 10 + iVar11);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar7 = *(undefined2 *)(iVar12 + 8 + iVar11);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar18 = CONCAT22(uVar6,uVar7);
        uVar15 = uVar18 * 0x271;
        uVar19 = (0x270 - (*(ushort *)(iVar12 + 0xc + iVar11) & 0x3ff) & 0xffff) + uVar15;
        uVar13 = init_rx_aux_data;
        if ((*(char *)(iVar8 + 0x3d) == '\0') && ((uVar5 & 0xf) != 8)) {
          uVar13 = (int)(uint)uVar4 >> 8;
        }
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        r_ble_log_internal_x3
                  (0x20820005,
                   ((uint)(uVar19 < uVar15) + (int)((ulonglong)uVar18 * 0x271 >> 0x20)) *
                   -0x80000000 | uVar19 >> 1,CONCAT22(*(undefined2 *)(iVar11 + iVar22),uVar9),
                   (uint)CONCAT11(bVar2,*(undefined1 *)(iVar8 + 0x52)) |
                   (uVar17 << 4 | uVar17) << 0x18 | (uVar13 & 0x3f) << 0x10);
        if (((uVar9 & 0x603d) == 0) && (*(char *)(iVar21 + 0x50) == '\0')) {
          iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar9 = *(ushort *)(iVar11 + iVar22);
          iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar6 = *(undefined2 *)(iVar12 + 0x12 + iVar11);
          *(undefined1 *)(iVar8 + 0x50) = 1;
          if ((uVar9 & 0xe) == 0) {
            r_lld_init_process_pkt_rx_adv_ind_or_direct_ind(param_2);
          }
          else {
            iVar11 = r_sdk_config_get_opts_ext();
            if (*(char *)(iVar11 + 0x18) != '\0') {
              iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
              uVar9 = uVar9 & 0xf;
              if (uVar9 == 7) {
                if ((*(ushort *)(iVar12 + 0x10 + iVar11) & 0x40) != 0) {
                  r_lld_init_process_pkt_rx_adv_ext_ind(param_2);
                }
              }
              else if (uVar9 == 8) {
                r_lld_init_process_pkt_rx_aux_connect_rsp(param_2,uVar6);
              }
            }
          }
        }
        r_lld_rxdesc_free();
      }
      if ((*(char *)(iVar8 + 0x3d) == '\x02') ||
         ((*(char *)(iVar8 + 0x50) == '\0' && (*(char *)(iVar8 + 0x3d) == '\x01')))) {
        *(undefined1 *)(iVar8 + 0x3d) = 0;
      }
      return;
    }
    r_assert_err(0,0x10000,0x3cc);
    return;
  }
  if (param_3 < 3) {
    uVar13 = param_2 & 0xff;
    bVar14 = param_3 != 0;
    g_initor_evt_end_abort = bVar14;
    if (_lld_init_env == 0) {
_L220:
      r_assert_param(uVar13,0x10000,0x4f3);
      return;
    }
    iVar21 = *(int *)(_lld_init_env + uVar13 * 4);
    if (iVar21 == 0) goto _L220;
    bVar2 = *(byte *)(iVar21 + 0x52);
    r_ble_log_internal_x1
              (0x404200fe,(uint)CONCAT12(*(undefined1 *)(iVar21 + 0x31),CONCAT11(bVar14,bVar2)));
    cVar3 = *(char *)(iVar21 + 0x31);
    *(undefined1 *)(iVar21 + 0x31) = 0;
    if (cVar3 == '\x02') {
      while (iVar21 = r_lld_rxdesc_check_hack((uint)bVar2), iVar21 != 0) {
        r_lld_rxdesc_free();
      }
r_lld_init_end:
      uVar13 = 0;
      while( true ) {
        iVar8 = uVar13 * 4;
        iVar21 = *(int *)(_lld_init_env + iVar8);
        if (iVar21 != 0) {
          r_ble_log_internal_x2
                    (0x400200fa,*(undefined4 *)(iVar21 + 0x24),
                     (uint)*(byte *)(iVar21 + 0x31) << 0x18 |
                     (uint)*(byte *)(iVar21 + 0x52) << 8 | (uint)*(byte *)(iVar21 + 0x50) << 0x10 |
                     uVar13);
          if (*(char *)(iVar21 + 0x31) == '\0') {
            r_sch_arb_remove(iVar21,0);
            r_sch_slice_bg_remove(1);
            r_ke_free(*(undefined4 *)(_lld_init_env + iVar8));
            iVar21 = _lld_init_env;
            *(undefined4 *)(iVar8 + _lld_init_env) = 0;
            *(byte *)(iVar21 + 0x2b) = ~(byte)(1 << uVar13) & *(byte *)(iVar21 + 0x2b);
          }
          else if (*(char *)(iVar21 + 0x31) == '\x01') {
            bVar2 = *(byte *)(iVar21 + 0x52);
            iVar8 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar8) = 1;
            _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
            *(undefined1 *)(iVar21 + 0x31) = 2;
          }
        }
        if (uVar13 != 0) break;
        uVar13 = 1;
      }
      if (*(char *)(_lld_init_env + 0x2b) == '\0') {
        if (*(int *)(_lld_init_env + 8) == 0) {
          puVar10 = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
          uVar1 = *(undefined1 *)(_lld_init_env + 0x2c);
          puVar10[1] = 0;
          *puVar10 = uVar1;
        }
        r_ke_msg_send();
        r_ke_free(_lld_init_env);
        _lld_init_env = 0;
      }
      return;
    }
    r_sch_arb_remove(iVar21,1);
    iVar12 = r_emi_get_mem_addr_by_offset(0x400);
    iVar8 = (uint)bVar2 * 0x5a + 0x18;
    if ((*(ushort *)(iVar12 + iVar8) >> 10 & 1) != 0) {
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      uVar9 = *(ushort *)(iVar12 + iVar8);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + iVar8) = uVar9 & 0xfbff;
      *(undefined1 *)(iVar21 + 0x3d) = 0;
    }
    r_lld_init_process_pkt_rx(uVar13);
    r_lld_init_process_pkt_tx(uVar13);
    if ((_lld_init_env == 0) || (*(int *)(_lld_init_env + uVar13 * 4) == 0)) {
      return;
    }
  }
  else {
    if (param_3 != 4) {
      r_assert_param(0x10000,0x560);
      return;
    }
    if (_lld_init_env == 0) {
      uVar16 = 0x53a;
_L261:
      r_assert_err(0,0x10000,uVar16);
      return;
    }
    iVar21 = *(int *)(_lld_init_env + (param_2 & 0xff) * 4);
    if (iVar21 == 0) {
      uVar16 = 0x53a;
      goto _L261;
    }
    param_1 = r_lld_read_clock();
    r_ble_log_internal_x2
              (0x404200ff,param_1,
               CONCAT11(*(undefined1 *)(iVar21 + 0x31),*(undefined1 *)(iVar21 + 0x52)));
    cVar3 = *(char *)(iVar21 + 0x31);
    *(undefined1 *)(iVar21 + 0x31) = 0;
    if (cVar3 == '\x02') goto r_lld_init_end;
    r_sch_arb_remove(iVar21,1);
    bVar2 = rwip_priority;
    if ((uint)*(ushort *)(iVar21 + 0x2c) << 1 <= (param_1 - *(int *)(iVar21 + 0x28) & 0xfffffffU)) {
      if (0xff < (uint)*(byte *)(iVar21 + 0x16) + (uint)rwip_priority) {
        r_assert_err(0,0x10000,0x520);
      }
      *(int *)(iVar21 + 0x28) = param_1;
      *(byte *)(iVar21 + 0x16) = bVar2 + *(char *)(iVar21 + 0x16);
    }
    if (*(char *)(iVar21 + 0x3d) != '\x01') {
      iVar21 = r_sch_arb_insert(iVar21);
      uVar16 = 0x52c;
      if (iVar21 == 0) {
        return;
      }
      goto _L261;
    }
    *(undefined1 *)(iVar21 + 0x3d) = 0;
    bVar14 = true;
  }
  iVar21 = *(int *)(_lld_init_env + (param_2 & 0xff) * 4);
  iVar8 = r_lld_read_clock();
  bVar2 = *(byte *)(iVar21 + 0x52);
  uVar13 = (iVar8 - param_1 & 0xfffffffU) + 1 >> 1;
  if (*(char *)(iVar21 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar21 + 4) = *(undefined4 *)(iVar21 + 0x40);
    *(undefined4 *)(iVar21 + 8) = *(undefined4 *)(iVar21 + 0x44);
    *(uint *)(iVar21 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar21 + 0x4d) * 2) +
         *(int *)(iVar21 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar20 = DAT_0001303e;
    if (DAT_0001303e < *(byte *)(iVar21 + 0x16)) {
      bVar20 = *(byte *)(iVar21 + 0x16);
    }
    *(byte *)(iVar21 + 0x16) = bVar20;
    *(ushort *)(iVar21 + 0x14) = DAT_0001303f & 0xf | 0x2000;
    iVar12 = r_sch_arb_insert(iVar21);
    if (iVar12 == 0) {
      uVar15 = (uint)*(byte *)(iVar21 + 0x4d);
      uVar13 = *(uint *)(iVar21 + 0x48);
      *(char *)(iVar21 + 0x3e) = (1 < uVar15) + '\x02';
      if ((uVar15 << 4 & 0xffffffcf) != 0) {
        r_assert_err(0x10000,0x1bf);
      }
      iVar12 = (uint)bVar2 * 0x5a;
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar9 = *(ushort *)(iVar8 + iVar12 + 4);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar12 + 4) = uVar9 & 0xffcf | (ushort)(uVar15 << 4);
      uVar9 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar15 * 2);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + 0x20 + iVar8) = (ushort)(((uint)uVar9 + uVar13 + 0x270) / 0x271) & 0xff;
      if (uVar13 < 0x4000) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        uVar9 = (ushort)(uVar13 + 1 >> 1);
      }
      else {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        uVar9 = (ushort)((uVar13 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      *(ushort *)(iVar8 + iVar12 + 0x1a) = uVar9;
      uVar13 = (uint)*(byte *)(iVar21 + 0x4c) << 10;
      if ((uVar13 & 0x30000) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar9 = *(ushort *)(iVar8 + iVar12 + 0x26);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar12 + 0x26) = uVar9 & 0x3ff | (ushort)uVar13;
      goto _L84;
    }
    *(undefined1 *)(iVar21 + 0x3d) = 0;
  }
  if (uVar13 < *(uint *)(iVar21 + 0x24)) {
    uVar13 = *(uint *)(iVar21 + 0x24) - uVar13;
  }
  else {
    r_sch_slice_bg_remove(1);
    uVar13 = (uint)*(ushort *)(iVar21 + 0x2e);
    uVar15 = _sch_slice_params;
    if (_sch_slice_params == 0xffffffff) {
      uVar15 = (*(ushort *)(iVar21 + 0x2c) - uVar13) * 2 + iVar8 & 0xffffffc;
    }
    *(uint *)(iVar21 + 4) = uVar15;
    *(undefined4 *)(iVar21 + 8) = 0;
  }
  uVar17 = (uint)_r_assert_param;
  *(uint *)(iVar21 + 0x24) = uVar13;
  uVar15 = uVar13 * 0x4e2;
  if (uVar17 < uVar13 * 0x4e2) {
    uVar15 = uVar17;
  }
  *(uint *)(iVar21 + 0x10) = uVar15;
  if (!bVar14) {
    *(undefined1 *)(iVar21 + 0x16) = DAT_00013042;
    *(undefined4 *)(iVar21 + 0x28) = *(undefined4 *)(iVar21 + 4);
  }
  iVar12 = (uint)bVar2 * 0x5a;
  *(ushort *)(iVar21 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar21 + 0x3e) = 1;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar12 + 0x20 + iVar8) = (short)uVar13;
  uVar13 = *(uint *)(iVar21 + 0x24);
  if ((uVar13 >> 0xf & 1) != 0) {
    r_assert_err(0,0x10000,0x4ab);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar12 + 0x1a + iVar8) = (ushort)uVar13 | 0x8000;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar12 + 0x46 + iVar8) = 0;
  iVar8 = r_sch_arb_insert(iVar21);
  if (iVar8 != 0) {
    r_assert_err(0,0x10000,0x280);
    return;
  }
_L84:
  *(undefined1 *)(iVar21 + 0x50) = 0;
  return;
}

