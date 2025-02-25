/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_cbk(int param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  byte bVar13;
  int iVar14;
  
  if (1 < param_2) {
    r_assert_param(param_2,param_3,"lld_init.c",0x521);
  }
  iVar12 = _lld_init_env;
  if (param_3 == 1) {
    iVar12 = 1;
_L289:
    uVar10 = param_2 & 0xff;
    g_initor_evt_end_abort = (undefined1)iVar12;
    if (_lld_init_env == 0) {
_L231:
      r_assert_param(_lld_init_env,"lld_init.c",0x4cb);
      return;
    }
    iVar9 = *(int *)(_lld_init_env + uVar10 * 4);
    if (iVar9 == 0) goto _L231;
    uVar6 = (uint)*(byte *)(iVar9 + 0x52);
    iVar8 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar8 + 0x28) & 0x10) != 0) &&
       (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
      r_ble_log_internal_x1(0x404f0004,(uint)*(byte *)(iVar9 + 0x31) << 0x10 | iVar12 << 8 | uVar6);
    }
    cVar3 = *(char *)(iVar9 + 0x31);
    *(undefined1 *)(iVar9 + 0x31) = 0;
    if (cVar3 == '\x02') {
      while (iVar12 = r_lld_rxdesc_check_hack(uVar6), iVar12 != 0) {
        r_lld_rxdesc_free();
      }
r_lld_init_end:
      uVar10 = 0;
      while( true ) {
        iVar9 = uVar10 * 4;
        iVar12 = *(int *)(_lld_init_env + iVar9);
        if (iVar12 != 0) {
          iVar8 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar8 + 0x28) & 0x10) != 0) &&
             (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
            r_ble_log_internal_x2
                      (0x400f0002,
                       (uint)*(byte *)(iVar12 + 0x52) << 8 |
                       (uint)*(byte *)(iVar12 + 0x31) << 0x18 |
                       (uint)*(byte *)(iVar12 + 0x50) << 0x10 | uVar10,
                       *(undefined4 *)(iVar12 + 0x24));
          }
          if (*(char *)(iVar12 + 0x31) == '\0') {
            r_sch_arb_remove(iVar12,0);
            r_sch_slice_bg_remove(1);
            r_ke_free(*(undefined4 *)(_lld_init_env + iVar9));
            iVar12 = _lld_init_env;
            *(undefined4 *)(iVar9 + _lld_init_env) = 0;
            *(byte *)(iVar12 + 0x2b) = ~(byte)(1 << uVar10) & *(byte *)(iVar12 + 0x2b);
          }
          else if (*(char *)(iVar12 + 0x31) == '\x01') {
            bVar2 = *(byte *)(iVar12 + 0x52);
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)(iVar9 + (uint)bVar2 * 0x5a + 0x20) = 1;
            _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
            *(undefined1 *)(iVar12 + 0x31) = 2;
          }
        }
        if (uVar10 != 0) break;
        uVar10 = 1;
      }
      if (*(char *)(_lld_init_env + 0x2b) == '\0') {
        if (*(int *)(_lld_init_env + 8) == 0) {
          puVar7 = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
          uVar1 = *(undefined1 *)(_lld_init_env + 0x2c);
          puVar7[1] = 0;
          *puVar7 = uVar1;
        }
        r_ke_msg_send();
        r_ke_free(_lld_init_env);
        _lld_init_env = 0;
      }
      return;
    }
    r_sch_arb_remove(iVar9,1);
    iVar14 = r_emi_get_mem_addr_by_offset(0x400);
    iVar8 = uVar6 * 0x5a + 0x18;
    if ((*(ushort *)(iVar14 + iVar8) >> 10 & 1) != 0) {
      iVar14 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar14 + iVar8);
      iVar14 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar14) = uVar4 & 0xfbff;
      *(undefined1 *)(iVar9 + 0x3d) = 0;
    }
    r_lld_init_process_pkt_rx(uVar10);
    r_lld_init_process_pkt_tx(uVar10);
    if ((_lld_init_env == 0) || (*(int *)(uVar10 * 4 + _lld_init_env) == 0)) {
      return;
    }
  }
  else {
    if (param_3 == 0) {
      iVar12 = 0;
      goto _L289;
    }
    if (param_3 == 2) {
      param_2 = param_2 & 0xff;
      if ((_lld_init_env != 0) && (iVar9 = *(int *)(param_2 * 4 + _lld_init_env), iVar9 != 0)) {
        while (iVar8 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar9 + 0x52)), iVar8 != 0) {
          bVar2 = *(byte *)(_p_lld_env + 0xd8);
          uVar10 = (uint)bVar2;
          iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
          iVar14 = uVar10 * 0x14;
          if (((*(ushort *)(iVar8 + iVar14 + 2) & 0x603d) == 0) &&
             (*(char *)(iVar12 + 0x50) == '\0')) {
            iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar4 = *(ushort *)(iVar8 + iVar14 + 4);
            iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar5 = *(undefined2 *)(iVar8 + iVar14 + 0x12);
            iVar8 = r_sdk_config_get_opts_ext();
            if (((*(uint *)(iVar8 + 0x28) & 0x10) != 0) &&
               (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
              r_ble_log_internal_x1
                        (0x408f000a,
                         CONCAT22(uVar4,CONCAT11(bVar2,*(undefined1 *)(iVar9 + 0x52))) & 0xfffff);
            }
            *(undefined1 *)(iVar9 + 0x50) = 1;
            if ((uVar4 & 0xe) == 0) {
              r_lld_init_process_pkt_rx_adv_ind_or_direct_ind(param_2,uVar5);
            }
            else {
              iVar8 = r_sdk_config_get_opts_ext();
              if (*(char *)(iVar8 + 0x18) != '\0') {
                iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
                if ((uVar4 & 0xf) == 7) {
                  if ((*(ushort *)(iVar14 + 0x10 + iVar8) & 0x40) != 0) {
                    r_lld_init_process_pkt_rx_adv_ext_ind(param_2,uVar5);
                  }
                }
                else if ((uVar4 & 0xf) == 8) {
                  r_lld_init_process_pkt_rx_aux_connect_rsp(param_2,uVar5);
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
                         (uint)*(byte *)(iVar9 + 0x52) |
                         (uint)*(byte *)(iVar12 + 0x50) << 0x10 | uVar10 << 8,uVar10);
            }
          }
          r_lld_rxdesc_free();
        }
        if ((*(char *)(iVar9 + 0x3d) == '\x02') ||
           ((*(char *)(iVar9 + 0x50) == '\0' && (*(char *)(iVar9 + 0x3d) == '\x01')))) {
          *(undefined1 *)(iVar9 + 0x3d) = 0;
        }
        return;
      }
      r_assert_err(0,"lld_init.c",0x3a4);
      return;
    }
    if (param_3 != 4) {
      r_assert_param(param_2,param_3,"lld_init.c",0x538);
      return;
    }
    if (_lld_init_env == 0) {
      uVar11 = 0x512;
_L278:
      r_assert_err(0,"lld_init.c",uVar11);
      return;
    }
    iVar12 = *(int *)(_lld_init_env + (param_2 & 0xff) * 4);
    if (iVar12 == 0) {
      uVar11 = 0x512;
      goto _L278;
    }
    param_1 = r_lld_read_clock();
    iVar9 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar9 + 0x28) & 0x10) != 0) &&
       (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
      r_ble_log_internal_x2
                (0x404f0005,CONCAT11(*(undefined1 *)(iVar12 + 0x31),*(undefined1 *)(iVar12 + 0x52)),
                 param_1);
    }
    cVar3 = *(char *)(iVar12 + 0x31);
    *(undefined1 *)(iVar12 + 0x31) = 0;
    if (cVar3 == '\x02') goto r_lld_init_end;
    r_sch_arb_remove(iVar12,1);
    bVar2 = rwip_priority;
    if ((uint)*(ushort *)(iVar12 + 0x2c) << 1 <= (param_1 - *(int *)(iVar12 + 0x28) & 0xfffffffU)) {
      if (0xff < (uint)*(byte *)(iVar12 + 0x16) + (uint)rwip_priority) {
        r_assert_err(0,"lld_init.c",0x4f8);
      }
      *(int *)(iVar12 + 0x28) = param_1;
      *(byte *)(iVar12 + 0x16) = bVar2 + *(char *)(iVar12 + 0x16);
    }
    if (*(char *)(iVar12 + 0x3d) != '\x01') {
      iVar12 = r_sch_arb_insert(iVar12);
      uVar11 = 0x504;
      if (iVar12 == 0) {
        return;
      }
      goto _L278;
    }
    *(undefined1 *)(iVar12 + 0x3d) = 0;
    iVar12 = 1;
  }
  iVar9 = *(int *)(_lld_init_env + (param_2 & 0xff) * 4);
  iVar8 = r_lld_read_clock();
  uVar10 = (iVar8 - param_1 & 0xfffffffU) + 1 >> 1;
  bVar2 = *(byte *)(iVar9 + 0x52);
  if (*(char *)(iVar9 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iVar9 + 0x40);
    *(undefined4 *)(iVar9 + 8) = *(undefined4 *)(iVar9 + 0x44);
    *(uint *)(iVar9 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar9 + 0x4d) * 2) +
         *(int *)(iVar9 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar13 = DAT_0001303e;
    if (DAT_0001303e < *(byte *)(iVar9 + 0x16)) {
      bVar13 = *(byte *)(iVar9 + 0x16);
    }
    *(byte *)(iVar9 + 0x16) = bVar13;
    *(ushort *)(iVar9 + 0x14) = DAT_0001303f & 0xf | 0x2000;
    iVar14 = r_sch_arb_insert(iVar9);
    if (iVar14 == 0) {
      uVar6 = (uint)*(byte *)(iVar9 + 0x4d);
      uVar10 = *(uint *)(iVar9 + 0x48);
      *(char *)(iVar9 + 0x3e) = (1 < uVar6) + '\x02';
      if ((uVar6 << 4 & 0xffffffcf) != 0) {
        r_assert_err("lld_init.c",0x1bf);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar12 = (uint)bVar2 * 0x5a;
      uVar4 = *(ushort *)(iVar8 + iVar12 + 4);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar12 + 4) = uVar4 & 0xffcf | (ushort)(uVar6 << 4);
      uVar4 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar6 * 2);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar12 + 0x20) = (ushort)(((uint)uVar4 + uVar10 + 0x270) / 0x271) & 0xff;
      if (uVar10 < 0x4000) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar8 + iVar12 + 0x1a) = (short)(uVar10 + 1 >> 1);
      }
      else {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar8 + iVar12 + 0x1a) = (ushort)((uVar10 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar10 = (uint)*(byte *)(iVar9 + 0x4c) << 10;
      if ((uVar10 & 0x30000) != 0) {
        r_assert_err(0,"lld_init.c",0x635);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar8 + iVar12 + 0x26);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + 0x26 + iVar8) = uVar4 & 0x3ff | (ushort)uVar10;
      goto _L87;
    }
    *(undefined1 *)(iVar9 + 0x3d) = 0;
  }
  if (uVar10 < *(uint *)(iVar9 + 0x24)) {
    *(uint *)(iVar9 + 0x24) = *(uint *)(iVar9 + 0x24) - uVar10;
  }
  else {
    r_sch_slice_bg_remove(1);
    if (_sch_slice_params == -1) {
      *(uint *)(iVar9 + 4) =
           ((uint)*(ushort *)(iVar9 + 0x2c) - (uint)*(ushort *)(iVar9 + 0x2e)) * 2 + iVar8 &
           0xffffffc;
    }
    else {
      *(int *)(iVar9 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar9 + 8) = 0;
    *(uint *)(iVar9 + 0x24) = (uint)*(ushort *)(iVar9 + 0x2e);
  }
  iVar8 = *(int *)(iVar9 + 0x24);
  uVar10 = iVar8 * 0x4e2;
  if (_r_assert_param < uVar10) {
    uVar10 = (uint)_r_assert_param;
  }
  *(uint *)(iVar9 + 0x10) = uVar10;
  if (iVar12 == 0) {
    *(undefined1 *)(iVar9 + 0x16) = DAT_00013042;
    *(undefined4 *)(iVar9 + 0x28) = *(undefined4 *)(iVar9 + 4);
  }
  *(ushort *)(iVar9 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar9 + 0x3e) = 1;
  iVar14 = r_emi_get_mem_addr_by_offset(0x400);
  iVar12 = (uint)bVar2 * 0x5a;
  *(short *)(iVar14 + iVar12 + 0x20) = (short)iVar8;
  iVar8 = *(int *)(iVar9 + 0x24);
  if (iVar8 << 0x10 < 0) {
    r_assert_err(0,"lld_init.c",0x4ab);
  }
  iVar14 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar14 + iVar12 + 0x1a) = (ushort)iVar8 | 0x8000;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar12 + 0x46 + iVar8) = 0;
  iVar12 = r_sch_arb_insert(iVar9);
  if (iVar12 != 0) {
    r_assert_err(0,"lld_init.c",0x27b);
    return;
  }
_L87:
  *(undefined1 *)(iVar9 + 0x50) = 0;
  return;
}

