/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined2 uVar4;
  ushort uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  int iVar15;
  int iVar16;
  
  if (1 < param_2) {
    r_assert_param(0x10000,0x521);
  }
  iVar16 = _lld_init_env;
  if (param_3 == 2) {
    param_2 = param_2 & 0xff;
    if ((_lld_init_env != 0) && (iVar7 = *(int *)(param_2 * 4 + _lld_init_env), iVar7 != 0)) {
      while (iVar8 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar7 + 0x52)), iVar8 != 0) {
        bVar2 = *(byte *)(_p_lld_env + 0xd8);
        uVar9 = (uint)bVar2;
        iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
        iVar15 = uVar9 * 0x14;
        if (((*(ushort *)(iVar15 + 2 + iVar8) & 0x603d) == 0) && (*(char *)(iVar16 + 0x50) == '\0'))
        {
          iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar5 = *(ushort *)(iVar15 + 4 + iVar8);
          iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar4 = *(undefined2 *)(iVar15 + 0x12 + iVar8);
          iVar8 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar8 + 0x28) & 0x10) != 0) &&
             (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
            r_ble_log_internal_x1
                      (0x408f000a,
                       CONCAT22(uVar5,CONCAT11(bVar2,*(undefined1 *)(iVar7 + 0x52))) & 0xfffff);
          }
          *(undefined1 *)(iVar7 + 0x50) = 1;
          if ((uVar5 & 0xe) == 0) {
            r_lld_init_process_pkt_rx_adv_ind_or_direct_ind(param_2,uVar4);
          }
          else {
            iVar8 = r_sdk_config_get_opts_ext();
            if (*(char *)(iVar8 + 0x18) != '\0') {
              iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
              if ((uVar5 & 0xf) == 7) {
                if ((*(ushort *)(iVar15 + 0x10 + iVar8) & 0x40) != 0) {
                  r_lld_init_process_pkt_rx_adv_ext_ind(param_2,uVar4);
                }
              }
              else if ((uVar5 & 0xf) == 8) {
                r_lld_init_process_pkt_rx_aux_connect_rsp(param_2,uVar4);
              }
            }
          }
        }
        else {
          iVar8 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar8 + 0x28) & 0x10) != 0) &&
             (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
            r_ble_log_internal_x2
                      (0x408f000b,
                       (uint)*(byte *)(iVar7 + 0x52) |
                       (uint)*(byte *)(iVar16 + 0x50) << 0x10 | uVar9 << 8,uVar9);
          }
        }
        r_lld_rxdesc_free();
      }
      if ((*(char *)(iVar7 + 0x3d) == '\x02') ||
         ((*(char *)(iVar7 + 0x50) == '\0' && (*(char *)(iVar7 + 0x3d) == '\x01')))) {
        *(undefined1 *)(iVar7 + 0x3d) = 0;
      }
      return;
    }
    r_assert_err(0,0x10000,0x3a4);
    return;
  }
  if (param_3 < 3) {
    uVar9 = param_2 & 0xff;
    bVar10 = param_3 != 0;
    g_initor_evt_end_abort = bVar10;
    if (_lld_init_env == 0) {
_L228:
      r_assert_param(uVar9,0x10000,0x4cb);
      return;
    }
    iVar16 = *(int *)(_lld_init_env + uVar9 * 4);
    if (iVar16 == 0) goto _L228;
    bVar2 = *(byte *)(iVar16 + 0x52);
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 0x10) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x404f0004,(uint)CONCAT12(*(undefined1 *)(iVar16 + 0x31),CONCAT11(bVar10,bVar2)));
    }
    cVar3 = *(char *)(iVar16 + 0x31);
    *(undefined1 *)(iVar16 + 0x31) = 0;
    if (cVar3 == '\x02') {
      while (iVar16 = r_lld_rxdesc_check_hack((uint)bVar2), iVar16 != 0) {
        r_lld_rxdesc_free();
      }
r_lld_init_end:
      uVar9 = 0;
      do {
        iVar7 = uVar9 * 4;
        iVar16 = *(int *)(_lld_init_env + iVar7);
        if (iVar16 != 0) {
          iVar8 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar8 + 0x28) & 0x10) != 0) &&
             (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
            r_ble_log_internal_x2
                      (0x400f0002,
                       (uint)*(byte *)(iVar16 + 0x52) << 8 |
                       (uint)*(byte *)(iVar16 + 0x31) << 0x18 |
                       (uint)*(byte *)(iVar16 + 0x50) << 0x10 | uVar9,*(undefined4 *)(iVar16 + 0x24)
                      );
          }
          if (*(char *)(iVar16 + 0x31) == '\0') {
            r_sch_arb_remove(iVar16,0);
            r_sch_slice_bg_remove(1);
            r_ke_free(*(undefined4 *)(_lld_init_env + iVar7));
            iVar16 = _lld_init_env;
            *(undefined4 *)(iVar7 + _lld_init_env) = 0;
            *(byte *)(iVar16 + 0x2b) = ~(byte)(1 << uVar9) & *(byte *)(iVar16 + 0x2b);
          }
          else if (*(char *)(iVar16 + 0x31) == '\x01') {
            bVar2 = *(byte *)(iVar16 + 0x52);
            iVar7 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar7) = 1;
            _DAT_60031000 = _DAT_60031000 | 0x1000000;
            *(undefined1 *)(iVar16 + 0x31) = 2;
          }
        }
        bVar10 = uVar9 != 1;
        uVar9 = 1;
      } while (bVar10);
      if (*(char *)(_lld_init_env + 0x2b) == '\0') {
        if (*(int *)(_lld_init_env + 8) == 0) {
          puVar6 = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
          uVar1 = *(undefined1 *)(_lld_init_env + 0x2c);
          puVar6[1] = 0;
          *puVar6 = uVar1;
        }
        r_ke_msg_send();
        r_ke_free(_lld_init_env);
        _lld_init_env = 0;
      }
      return;
    }
    r_sch_arb_remove(iVar16,1);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    iVar7 = (uint)bVar2 * 0x5a + 0x18;
    if ((*(ushort *)(iVar8 + iVar7) >> 10 & 1) != 0) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar8 + iVar7);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7) = uVar5 & 0xfbff;
      *(undefined1 *)(iVar16 + 0x3d) = 0;
    }
    r_lld_init_process_pkt_rx(uVar9);
    r_lld_init_process_pkt_tx(uVar9);
    if ((_lld_init_env == 0) || (*(int *)(_lld_init_env + uVar9 * 4) == 0)) {
      return;
    }
  }
  else {
    if (param_3 != 4) {
      r_assert_param(0x10000,0x538);
      return;
    }
    if (_lld_init_env == 0) {
      uVar11 = 0x512;
_L275:
      r_assert_err(0,0x10000,uVar11);
      return;
    }
    iVar16 = *(int *)(_lld_init_env + (param_2 & 0xff) * 4);
    if (iVar16 == 0) {
      uVar11 = 0x512;
      goto _L275;
    }
    param_1 = r_lld_read_clock();
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 0x10) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      r_ble_log_internal_x2
                (0x404f0005,CONCAT11(*(undefined1 *)(iVar16 + 0x31),*(undefined1 *)(iVar16 + 0x52)),
                 param_1);
    }
    cVar3 = *(char *)(iVar16 + 0x31);
    *(undefined1 *)(iVar16 + 0x31) = 0;
    if (cVar3 == '\x02') goto r_lld_init_end;
    r_sch_arb_remove(iVar16,1);
    bVar2 = rwip_priority;
    if ((uint)*(ushort *)(iVar16 + 0x2c) << 1 <= (param_1 - *(int *)(iVar16 + 0x28) & 0xfffffffU)) {
      if (0xff < (uint)*(byte *)(iVar16 + 0x16) + (uint)rwip_priority) {
        r_assert_err(0,0x10000,0x4f8);
      }
      *(int *)(iVar16 + 0x28) = param_1;
      *(byte *)(iVar16 + 0x16) = bVar2 + *(char *)(iVar16 + 0x16);
    }
    if (*(char *)(iVar16 + 0x3d) != '\x01') {
      iVar16 = r_sch_arb_insert(iVar16);
      uVar11 = 0x504;
      if (iVar16 == 0) {
        return;
      }
      goto _L275;
    }
    *(undefined1 *)(iVar16 + 0x3d) = 0;
    bVar10 = true;
  }
  iVar16 = *(int *)(_lld_init_env + (param_2 & 0xff) * 4);
  iVar7 = r_lld_read_clock();
  bVar2 = *(byte *)(iVar16 + 0x52);
  uVar9 = (iVar7 - param_1 & 0xfffffffU) + 1 >> 1;
  if (*(char *)(iVar16 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove();
    *(undefined4 *)(iVar16 + 4) = *(undefined4 *)(iVar16 + 0x40);
    *(undefined4 *)(iVar16 + 8) = *(undefined4 *)(iVar16 + 0x44);
    *(uint *)(iVar16 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar16 + 0x4d) * 2) +
         *(int *)(iVar16 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar14 = DAT_0001303e;
    if (DAT_0001303e < *(byte *)(iVar16 + 0x16)) {
      bVar14 = *(byte *)(iVar16 + 0x16);
    }
    *(byte *)(iVar16 + 0x16) = bVar14;
    *(ushort *)(iVar16 + 0x14) = DAT_0001303f & 0xf | 0x2000;
    iVar8 = r_sch_arb_insert(iVar16);
    if (iVar8 == 0) {
      bVar14 = *(byte *)(iVar16 + 0x4d);
      uVar9 = *(uint *)(iVar16 + 0x48);
      *(char *)(iVar16 + 0x3e) = (1 < bVar14) + '\x02';
      if ((bVar14 & 0xfc) != 0) {
        r_assert_err(0x10000,0x1bf);
      }
      iVar8 = (uint)bVar2 * 0x5a;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar7 + iVar8 + 4);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar8 + 4) = uVar5 & 0xffcf | (ushort)bVar14 << 4;
      uVar5 = *(ushort *)(&lld_init_max_aux_dur_tab + (uint)bVar14 * 2);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + 0x20 + iVar7) = (ushort)(((uint)uVar5 + uVar9 + 0x270) / 0x271) & 0xff;
      if (uVar9 < 0x4000) {
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        uVar5 = (ushort)(uVar9 + 1 >> 1);
      }
      else {
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        uVar5 = (ushort)((uVar9 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      *(ushort *)(iVar7 + iVar8 + 0x1a) = uVar5;
      bVar2 = *(byte *)(iVar16 + 0x4c);
      if ((bVar2 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar7 + iVar8 + 0x26);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar8 + 0x26) = uVar5 & 0x3ff | (ushort)bVar2 << 10;
      goto _L88;
    }
    *(undefined1 *)(iVar16 + 0x3d) = 0;
  }
  if (uVar9 < *(uint *)(iVar16 + 0x24)) {
    uVar9 = *(uint *)(iVar16 + 0x24) - uVar9;
  }
  else {
    r_sch_slice_bg_remove(1);
    uVar9 = (uint)*(ushort *)(iVar16 + 0x2e);
    uVar13 = _sch_slice_params;
    if (_sch_slice_params == 0xffffffff) {
      uVar13 = (*(ushort *)(iVar16 + 0x2c) - uVar9) * 2 + iVar7 & 0xffffffc;
    }
    *(uint *)(iVar16 + 4) = uVar13;
    *(undefined4 *)(iVar16 + 8) = 0;
  }
  uVar12 = (uint)_r_assert_param;
  *(uint *)(iVar16 + 0x24) = uVar9;
  uVar13 = uVar9 * 0x4e2;
  if (uVar12 < uVar9 * 0x4e2) {
    uVar13 = uVar12;
  }
  *(uint *)(iVar16 + 0x10) = uVar13;
  if (!bVar10) {
    *(undefined1 *)(iVar16 + 0x16) = DAT_00013042;
    *(undefined4 *)(iVar16 + 0x28) = *(undefined4 *)(iVar16 + 4);
  }
  iVar8 = (uint)bVar2 * 0x5a;
  *(ushort *)(iVar16 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar16 + 0x3e) = 1;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar8 + 0x20 + iVar7) = (short)uVar9;
  iVar7 = *(int *)(iVar16 + 0x24);
  if (iVar7 << 0x10 < 0) {
    r_assert_err(0,0x10000,0x4ab);
  }
  iVar15 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + 0x1a + iVar15) = (ushort)iVar7 | 0x8000;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar8 + 0x46 + iVar7) = 0;
  iVar7 = r_sch_arb_insert(iVar16);
  if (iVar7 != 0) {
    r_assert_err(0,0x10000,0x27b);
    return;
  }
_L88:
  *(undefined1 *)(iVar16 + 0x50) = 0;
  return;
}

