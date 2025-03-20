/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_eof_isr(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  uint uVar12;
  
  g_initor_evt_end_abort = (undefined1)param_3;
  if (_lld_init_env == 0) {
_L231:
    r_assert_param(_lld_init_env,"lld_init.c",0x4cb);
    return;
  }
  iVar11 = *(int *)(_lld_init_env + param_1 * 4);
  if (iVar11 == 0) goto _L231;
  uVar5 = (uint)*(byte *)(iVar11 + 0x52);
  iVar8 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar8 + 0x28) & 0x10) != 0) &&
     (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x404f0004,(uint)*(byte *)(iVar11 + 0x31) << 0x10 | param_3 << 8 | uVar5);
  }
  cVar3 = *(char *)(iVar11 + 0x31);
  *(undefined1 *)(iVar11 + 0x31) = 0;
  if (cVar3 == '\x02') {
    while (iVar11 = r_lld_rxdesc_check_hack(uVar5), iVar11 != 0) {
      r_lld_rxdesc_free();
    }
    uVar5 = 0;
    while( true ) {
      iVar8 = uVar5 * 4;
      iVar11 = *(int *)(_lld_init_env + iVar8);
      if (iVar11 != 0) {
        iVar9 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar9 + 0x28) & 0x10) != 0) &&
           (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x400f0002,
                     (uint)*(byte *)(iVar11 + 0x52) << 8 |
                     (uint)*(byte *)(iVar11 + 0x31) << 0x18 | (uint)*(byte *)(iVar11 + 0x50) << 0x10
                     | uVar5,*(undefined4 *)(iVar11 + 0x24));
        }
        if (*(char *)(iVar11 + 0x31) == '\0') {
          r_sch_arb_remove(iVar11,0);
          r_sch_slice_bg_remove(1);
          r_ke_free(*(undefined4 *)(_lld_init_env + iVar8));
          iVar11 = _lld_init_env;
          *(undefined4 *)(iVar8 + _lld_init_env) = 0;
          *(byte *)(iVar11 + 0x2b) = ~(byte)(1 << uVar5) & *(byte *)(iVar11 + 0x2b);
        }
        else if (*(char *)(iVar11 + 0x31) == '\x01') {
          bVar2 = *(byte *)(iVar11 + 0x52);
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar8 + (uint)bVar2 * 0x5a + 0x20) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar11 + 0x31) = 2;
        }
      }
      if (uVar5 != 0) break;
      uVar5 = 1;
    }
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
  r_sch_arb_remove(iVar11,1);
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  iVar8 = uVar5 * 0x5a + 0x18;
  if ((*(ushort *)(iVar9 + iVar8) >> 10 & 1) != 0) {
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(ushort *)(iVar9 + iVar8);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar8 + iVar9) = uVar4 & 0xfbff;
    *(undefined1 *)(iVar11 + 0x3d) = 0;
  }
  r_lld_init_process_pkt_rx(param_1);
  r_lld_init_process_pkt_tx(param_1);
  if ((_lld_init_env == 0) || (*(int *)(param_1 * 4 + _lld_init_env) == 0)) {
    return;
  }
  iVar11 = *(int *)(_lld_init_env + param_1 * 4);
  iVar8 = r_lld_read_clock();
  uVar5 = (iVar8 - param_2 & 0xfffffffU) + 1 >> 1;
  bVar2 = *(byte *)(iVar11 + 0x52);
  if (*(char *)(iVar11 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar11 + 4) = *(undefined4 *)(iVar11 + 0x40);
    *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(iVar11 + 0x44);
    *(uint *)(iVar11 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar11 + 0x4d) * 2) +
         *(int *)(iVar11 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar10 = DAT_0001303e;
    if (DAT_0001303e < *(byte *)(iVar11 + 0x16)) {
      bVar10 = *(byte *)(iVar11 + 0x16);
    }
    *(byte *)(iVar11 + 0x16) = bVar10;
    *(ushort *)(iVar11 + 0x14) = DAT_0001303f & 0xf | 0x2000;
    iVar9 = r_sch_arb_insert(iVar11);
    if (iVar9 == 0) {
      uVar12 = (uint)*(byte *)(iVar11 + 0x4d);
      uVar5 = *(uint *)(iVar11 + 0x48);
      *(char *)(iVar11 + 0x3e) = (1 < uVar12) + '\x02';
      if ((uVar12 << 4 & 0xffffffcf) != 0) {
        r_assert_err("lld_init.c",0x1bf);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      iVar8 = (uint)bVar2 * 0x5a;
      uVar4 = *(ushort *)(iVar9 + iVar8 + 4);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar8 + 4) = uVar4 & 0xffcf | (ushort)(uVar12 << 4);
      uVar4 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar12 * 2);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar8 + 0x20) = (ushort)(((uint)uVar4 + uVar5 + 0x270) / 0x271) & 0xff;
      if (uVar5 < 0x4000) {
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar9 + iVar8 + 0x1a) = (short)(uVar5 + 1 >> 1);
      }
      else {
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar9 + iVar8 + 0x1a) = (ushort)((uVar5 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar5 = (uint)*(byte *)(iVar11 + 0x4c) << 10;
      if ((uVar5 & 0x30000) != 0) {
        r_assert_err(0,"lld_init.c",0x635);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar9 + iVar8 + 0x26);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + 0x26 + iVar9) = uVar4 & 0x3ff | (ushort)uVar5;
      goto _L87;
    }
    *(undefined1 *)(iVar11 + 0x3d) = 0;
  }
  if (uVar5 < *(uint *)(iVar11 + 0x24)) {
    *(uint *)(iVar11 + 0x24) = *(uint *)(iVar11 + 0x24) - uVar5;
  }
  else {
    r_sch_slice_bg_remove(1);
    if (_sch_slice_params == -1) {
      *(uint *)(iVar11 + 4) =
           ((uint)*(ushort *)(iVar11 + 0x2c) - (uint)*(ushort *)(iVar11 + 0x2e)) * 2 + iVar8 &
           0xffffffc;
    }
    else {
      *(int *)(iVar11 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar11 + 8) = 0;
    *(uint *)(iVar11 + 0x24) = (uint)*(ushort *)(iVar11 + 0x2e);
  }
  iVar8 = *(int *)(iVar11 + 0x24);
  uVar5 = iVar8 * 0x4e2;
  if (_r_assert_param < uVar5) {
    uVar5 = (uint)_r_assert_param;
  }
  *(uint *)(iVar11 + 0x10) = uVar5;
  if (param_3 == 0) {
    *(undefined1 *)(iVar11 + 0x16) = DAT_00013042;
    *(undefined4 *)(iVar11 + 0x28) = *(undefined4 *)(iVar11 + 4);
  }
  *(ushort *)(iVar11 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar11 + 0x3e) = 1;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  iVar9 = (uint)bVar2 * 0x5a;
  *(short *)(iVar7 + iVar9 + 0x20) = (short)iVar8;
  iVar8 = *(int *)(iVar11 + 0x24);
  if (iVar8 << 0x10 < 0) {
    r_assert_err(0,"lld_init.c",0x4ab);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar7 + iVar9 + 0x1a) = (ushort)iVar8 | 0x8000;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar9 + 0x46 + iVar8) = 0;
  iVar8 = r_sch_arb_insert(iVar11);
  if (iVar8 != 0) {
    r_assert_err(0,"lld_init.c",0x27b);
    return;
  }
_L87:
  *(undefined1 *)(iVar11 + 0x50) = 0;
  return;
}

