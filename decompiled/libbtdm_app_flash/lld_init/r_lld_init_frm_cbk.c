/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  undefined4 uVar12;
  byte bVar13;
  uint uVar14;
  ushort uVar15;
  
  if (1 < param_2) {
    r_assert_param(param_2,param_3,"lld_init.c",0x515);
  }
  iVar5 = _lld_init_env;
  if (param_3 == 1) {
    bVar11 = true;
_L267:
    uVar10 = param_2 & 0xff;
    g_initor_evt_end_abort = bVar11;
    if (_lld_init_env == 0) {
_L215:
      r_assert_param(_lld_init_env,"lld_init.c",0x4c0);
      return;
    }
    iVar5 = *(int *)(_lld_init_env + uVar10 * 4);
    if (iVar5 == 0) goto _L215;
    cVar3 = *(char *)(iVar5 + 0x31);
    *(undefined1 *)(iVar5 + 0x31) = 0;
    bVar2 = *(byte *)(iVar5 + 0x52);
    if (cVar3 == '\x02') {
      while (iVar5 = r_lld_rxdesc_check_hack((uint)bVar2), iVar5 != 0) {
        r_lld_rxdesc_free();
      }
r_lld_init_end:
      iVar5 = 0;
      while( true ) {
        iVar6 = iVar5 * 4;
        iVar8 = *(int *)(_lld_init_env + iVar6);
        if (iVar8 != 0) {
          if (*(char *)(iVar8 + 0x31) == '\0') {
            r_sch_arb_remove(iVar8,0);
            r_sch_slice_bg_remove(1);
            r_ke_free(*(undefined4 *)(_lld_init_env + iVar6));
            iVar8 = _lld_init_env;
            *(undefined4 *)(iVar6 + _lld_init_env) = 0;
            *(byte *)(iVar8 + 0x2b) = ~(byte)(1 << iVar5) & *(byte *)(iVar8 + 0x2b);
          }
          else if (*(char *)(iVar8 + 0x31) == '\x01') {
            bVar2 = *(byte *)(iVar8 + 0x52);
            iVar6 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)(iVar6 + (uint)bVar2 * 0x5a + 0x20) = 1;
            _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
            *(undefined1 *)(iVar8 + 0x31) = 2;
          }
        }
        if (iVar5 != 0) break;
        iVar5 = 1;
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
    r_sch_arb_remove(iVar5,1);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    iVar6 = (uint)bVar2 * 0x5a + 0x18;
    if ((*(ushort *)(iVar8 + iVar6) >> 10 & 1) != 0) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar15 = *(ushort *)(iVar8 + iVar6);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar8) = uVar15 & 0xfbff;
      *(undefined1 *)(iVar5 + 0x3d) = 0;
    }
    r_lld_init_process_pkt_rx(uVar10);
    r_lld_init_process_pkt_tx(uVar10);
    if ((_lld_init_env == 0) || (*(int *)(uVar10 * 4 + _lld_init_env) == 0)) {
      return;
    }
  }
  else {
    if (param_3 == 0) {
      bVar11 = false;
      goto _L267;
    }
    if (param_3 == 2) {
      param_2 = param_2 & 0xff;
      if ((_lld_init_env != 0) && (iVar6 = *(int *)(param_2 * 4 + _lld_init_env), iVar6 != 0)) {
        while (iVar8 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar6 + 0x52)), iVar8 != 0) {
          bVar2 = *(byte *)(_p_lld_env + 0xd8);
          iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
          iVar8 = (uint)bVar2 * 0x14;
          if (((*(ushort *)(iVar9 + iVar8 + 2) & 0x603d) == 0) && (*(char *)(iVar5 + 0x50) == '\0'))
          {
            iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar15 = *(ushort *)(iVar9 + iVar8 + 4);
            iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar4 = *(undefined2 *)(iVar9 + iVar8 + 0x12);
            *(undefined1 *)(iVar6 + 0x50) = 1;
            if ((uVar15 & 0xe) == 0) {
              r_lld_init_process_pkt_rx_adv_ind_or_direct_ind(param_2);
            }
            else {
              iVar9 = r_sdk_config_get_opts_ext();
              if (*(char *)(iVar9 + 0x18) != '\0') {
                iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
                uVar15 = uVar15 & 0xf;
                if (uVar15 == 7) {
                  if ((*(ushort *)(iVar8 + 0x10 + iVar9) & 0x40) != 0) {
                    r_lld_init_process_pkt_rx_adv_ext_ind(param_2);
                  }
                }
                else if (uVar15 == 8) {
                  r_lld_init_process_pkt_rx_aux_connect_rsp(param_2,uVar4);
                }
              }
            }
          }
          r_lld_rxdesc_free();
        }
        if ((*(char *)(iVar6 + 0x3d) == '\x02') ||
           ((*(char *)(iVar6 + 0x50) == '\0' && (*(char *)(iVar6 + 0x3d) == '\x01')))) {
          *(undefined1 *)(iVar6 + 0x3d) = 0;
        }
        return;
      }
      r_assert_err(0,"lld_init.c",0x39a);
      return;
    }
    if (param_3 != 4) {
      r_assert_param(param_2,param_3,"lld_init.c",0x52c);
      return;
    }
    if (_lld_init_env == 0) {
      uVar12 = 0x506;
_L256:
      r_assert_err(0,"lld_init.c",uVar12);
      return;
    }
    iVar5 = *(int *)(_lld_init_env + (param_2 & 0xff) * 4);
    if (iVar5 == 0) {
      uVar12 = 0x506;
      goto _L256;
    }
    param_1 = r_lld_read_clock();
    cVar3 = *(char *)(iVar5 + 0x31);
    *(undefined1 *)(iVar5 + 0x31) = 0;
    if (cVar3 == '\x02') goto r_lld_init_end;
    r_sch_arb_remove(iVar5,1);
    bVar2 = rwip_priority;
    if ((uint)*(ushort *)(iVar5 + 0x2c) << 1 <= (param_1 - *(int *)(iVar5 + 0x28) & 0xfffffffU)) {
      if (0xff < (uint)*(byte *)(iVar5 + 0x16) + (uint)rwip_priority) {
        r_assert_err(0,"lld_init.c",0x4ec);
      }
      *(int *)(iVar5 + 0x28) = param_1;
      *(byte *)(iVar5 + 0x16) = bVar2 + *(char *)(iVar5 + 0x16);
    }
    if (*(char *)(iVar5 + 0x3d) != '\x01') {
      iVar5 = r_sch_arb_insert(iVar5);
      uVar12 = 0x4f8;
      if (iVar5 == 0) {
        return;
      }
      goto _L256;
    }
    *(undefined1 *)(iVar5 + 0x3d) = 0;
    bVar11 = true;
  }
  iVar5 = *(int *)(_lld_init_env + (param_2 & 0xff) * 4);
  iVar6 = r_lld_read_clock();
  uVar10 = (iVar6 - param_1 & 0xfffffffU) + 1 >> 1;
  bVar2 = *(byte *)(iVar5 + 0x52);
  if (*(char *)(iVar5 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar5 + 0x40);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 0x44);
    *(uint *)(iVar5 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar5 + 0x4d) * 2) +
         *(int *)(iVar5 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar13 = DAT_00013036;
    if (DAT_00013036 < *(byte *)(iVar5 + 0x16)) {
      bVar13 = *(byte *)(iVar5 + 0x16);
    }
    *(byte *)(iVar5 + 0x16) = bVar13;
    *(ushort *)(iVar5 + 0x14) = DAT_00013037 & 0xf | 0x2000;
    iVar8 = r_sch_arb_insert(iVar5);
    if (iVar8 == 0) {
      uVar14 = (uint)*(byte *)(iVar5 + 0x4d);
      uVar10 = *(uint *)(iVar5 + 0x48);
      *(char *)(iVar5 + 0x3e) = (1 < uVar14) + '\x02';
      if ((uVar14 << 4 & 0xffffffcf) != 0) {
        r_assert_err("lld_init.c",0x1bf);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar6 = (uint)bVar2 * 0x5a;
      uVar15 = *(ushort *)(iVar8 + iVar6 + 4);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar6 + 4) = uVar15 & 0xffcf | (ushort)(uVar14 << 4);
      uVar15 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar14 * 2);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar6 + 0x20) = (ushort)(((uint)uVar15 + uVar10 + 0x270) / 0x271) & 0xff;
      if (uVar10 < 0x4000) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar8 + iVar6 + 0x1a) = (short)(uVar10 + 1 >> 1);
      }
      else {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar8 + iVar6 + 0x1a) = (ushort)((uVar10 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar10 = (uint)*(byte *)(iVar5 + 0x4c) << 10;
      if ((uVar10 & 0x30000) != 0) {
        r_assert_err(0,"lld_init.c",0x635);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar15 = *(ushort *)(iVar8 + iVar6 + 0x26);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + 0x26 + iVar8) = uVar15 & 0x3ff | (ushort)uVar10;
      goto _L81;
    }
    *(undefined1 *)(iVar5 + 0x3d) = 0;
  }
  if (uVar10 < *(uint *)(iVar5 + 0x24)) {
    *(uint *)(iVar5 + 0x24) = *(uint *)(iVar5 + 0x24) - uVar10;
  }
  else {
    r_sch_slice_bg_remove(1);
    if (_sch_slice_params == -1) {
      *(uint *)(iVar5 + 4) =
           ((uint)*(ushort *)(iVar5 + 0x2c) - (uint)*(ushort *)(iVar5 + 0x2e)) * 2 + iVar6 &
           0xffffffc;
    }
    else {
      *(int *)(iVar5 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar5 + 8) = 0;
    *(uint *)(iVar5 + 0x24) = (uint)*(ushort *)(iVar5 + 0x2e);
  }
  iVar6 = *(int *)(iVar5 + 0x24);
  uVar10 = iVar6 * 0x4e2;
  if (_r_assert_param < uVar10) {
    uVar10 = (uint)_r_assert_param;
  }
  *(uint *)(iVar5 + 0x10) = uVar10;
  if (!bVar11) {
    *(undefined1 *)(iVar5 + 0x16) = DAT_0001303a;
    *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(iVar5 + 4);
  }
  *(ushort *)(iVar5 + 0x14) = DAT_0001303b & 0xf | 0x6000;
  *(undefined1 *)(iVar5 + 0x3e) = 1;
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  iVar8 = (uint)bVar2 * 0x5a;
  *(short *)(iVar9 + iVar8 + 0x20) = (short)iVar6;
  iVar6 = *(int *)(iVar5 + 0x24);
  if (iVar6 << 0x10 < 0) {
    r_assert_err(0,"lld_init.c",0x4ab);
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar9 + iVar8 + 0x1a) = (ushort)iVar6 | 0x8000;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar8 + 0x46 + iVar6) = 0;
  iVar6 = r_sch_arb_insert(iVar5);
  if (iVar6 != 0) {
    r_assert_err(0,"lld_init.c",0x278);
    return;
  }
_L81:
  *(undefined1 *)(iVar5 + 0x50) = 0;
  return;
}

