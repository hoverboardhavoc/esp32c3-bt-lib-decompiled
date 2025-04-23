/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_eof_isr(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  ushort uVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte bVar13;
  int iVar14;
  
  g_initor_evt_end_abort = (undefined1)param_3;
  if (_lld_init_env == 0) {
_L228:
    r_assert_param(param_1,0x10000,0x4cb);
    return;
  }
  iVar14 = *(int *)(_lld_init_env + param_1 * 4);
  if (iVar14 == 0) goto _L228;
  uVar5 = (uint)*(byte *)(iVar14 + 0x52);
  iVar9 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar9 + 0x28) & 0x10) != 0) &&
     (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x404f0004,(uint)*(byte *)(iVar14 + 0x31) << 0x10 | param_3 << 8 | uVar5);
  }
  cVar4 = *(char *)(iVar14 + 0x31);
  *(undefined1 *)(iVar14 + 0x31) = 0;
  if (cVar4 == '\x02') {
    while (iVar14 = r_lld_rxdesc_check_hack(uVar5), iVar14 != 0) {
      r_lld_rxdesc_free();
    }
    uVar5 = 0;
    do {
      iVar9 = uVar5 * 4;
      iVar14 = *(int *)(_lld_init_env + iVar9);
      if (iVar14 != 0) {
        iVar10 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar10 + 0x28) & 0x10) != 0) &&
           (iVar10 = r_sdk_config_get_opts_ext(), *(byte *)(iVar10 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x400f0002,
                     (uint)*(byte *)(iVar14 + 0x52) << 8 |
                     (uint)*(byte *)(iVar14 + 0x31) << 0x18 | (uint)*(byte *)(iVar14 + 0x50) << 0x10
                     | uVar5,*(undefined4 *)(iVar14 + 0x24));
        }
        if (*(char *)(iVar14 + 0x31) == '\0') {
          r_sch_arb_remove(iVar14,0);
          r_sch_slice_bg_remove(1);
          r_ke_free(*(undefined4 *)(_lld_init_env + iVar9));
          iVar14 = _lld_init_env;
          *(undefined4 *)(iVar9 + _lld_init_env) = 0;
          *(byte *)(iVar14 + 0x2b) = ~(byte)(1 << uVar5) & *(byte *)(iVar14 + 0x2b);
        }
        else if (*(char *)(iVar14 + 0x31) == '\x01') {
          bVar3 = *(byte *)(iVar14 + 0x52);
          iVar9 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)((uint)bVar3 * 0x5a + 0x20 + iVar9) = 1;
          _DAT_60031000 = _DAT_60031000 | 0x1000000;
          *(undefined1 *)(iVar14 + 0x31) = 2;
        }
      }
      bVar1 = uVar5 != 1;
      uVar5 = 1;
    } while (bVar1);
    if (*(char *)(_lld_init_env + 0x2b) == '\0') {
      if (*(int *)(_lld_init_env + 8) == 0) {
        puVar7 = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
        uVar2 = *(undefined1 *)(_lld_init_env + 0x2c);
        puVar7[1] = 0;
        *puVar7 = uVar2;
      }
      r_ke_msg_send();
      r_ke_free(_lld_init_env);
      _lld_init_env = 0;
    }
    return;
  }
  r_sch_arb_remove(iVar14,1);
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  iVar9 = uVar5 * 0x5a + 0x18;
  if ((*(ushort *)(iVar10 + iVar9) >> 10 & 1) != 0) {
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar6 = *(ushort *)(iVar10 + iVar9);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar10 + iVar9) = uVar6 & 0xfbff;
    *(undefined1 *)(iVar14 + 0x3d) = 0;
  }
  r_lld_init_process_pkt_rx(param_1);
  r_lld_init_process_pkt_tx(param_1);
  if ((_lld_init_env == 0) || (*(int *)(_lld_init_env + param_1 * 4) == 0)) {
    return;
  }
  iVar14 = *(int *)(_lld_init_env + param_1 * 4);
  iVar9 = r_lld_read_clock();
  bVar3 = *(byte *)(iVar14 + 0x52);
  uVar5 = (iVar9 - param_2 & 0xfffffffU) + 1 >> 1;
  if (*(char *)(iVar14 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove();
    *(undefined4 *)(iVar14 + 4) = *(undefined4 *)(iVar14 + 0x40);
    *(undefined4 *)(iVar14 + 8) = *(undefined4 *)(iVar14 + 0x44);
    *(uint *)(iVar14 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar14 + 0x4d) * 2) +
         *(int *)(iVar14 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar13 = DAT_0001303e;
    if (DAT_0001303e < *(byte *)(iVar14 + 0x16)) {
      bVar13 = *(byte *)(iVar14 + 0x16);
    }
    *(byte *)(iVar14 + 0x16) = bVar13;
    *(ushort *)(iVar14 + 0x14) = DAT_0001303f & 0xf | 0x2000;
    iVar10 = r_sch_arb_insert(iVar14);
    if (iVar10 == 0) {
      bVar13 = *(byte *)(iVar14 + 0x4d);
      uVar5 = *(uint *)(iVar14 + 0x48);
      *(char *)(iVar14 + 0x3e) = (1 < bVar13) + '\x02';
      if ((bVar13 & 0xfc) != 0) {
        r_assert_err(0x10000,0x1bf);
      }
      iVar10 = (uint)bVar3 * 0x5a;
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      uVar6 = *(ushort *)(iVar9 + iVar10 + 4);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar10 + 4) = uVar6 & 0xffcf | (ushort)bVar13 << 4;
      uVar6 = *(ushort *)(&lld_init_max_aux_dur_tab + (uint)bVar13 * 2);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar10 + 0x20 + iVar9) = (ushort)(((uint)uVar6 + uVar5 + 0x270) / 0x271) & 0xff;
      if (uVar5 < 0x4000) {
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        uVar6 = (ushort)(uVar5 + 1 >> 1);
      }
      else {
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        uVar6 = (ushort)((uVar5 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      *(ushort *)(iVar9 + iVar10 + 0x1a) = uVar6;
      bVar3 = *(byte *)(iVar14 + 0x4c);
      if ((bVar3 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      uVar6 = *(ushort *)(iVar9 + iVar10 + 0x26);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar10 + 0x26) = uVar6 & 0x3ff | (ushort)bVar3 << 10;
      goto _L88;
    }
    *(undefined1 *)(iVar14 + 0x3d) = 0;
  }
  if (uVar5 < *(uint *)(iVar14 + 0x24)) {
    uVar5 = *(uint *)(iVar14 + 0x24) - uVar5;
  }
  else {
    r_sch_slice_bg_remove(1);
    uVar5 = (uint)*(ushort *)(iVar14 + 0x2e);
    uVar12 = _sch_slice_params;
    if (_sch_slice_params == 0xffffffff) {
      uVar12 = (*(ushort *)(iVar14 + 0x2c) - uVar5) * 2 + iVar9 & 0xffffffc;
    }
    *(uint *)(iVar14 + 4) = uVar12;
    *(undefined4 *)(iVar14 + 8) = 0;
  }
  uVar11 = (uint)_r_assert_param;
  *(uint *)(iVar14 + 0x24) = uVar5;
  uVar12 = uVar5 * 0x4e2;
  if (uVar11 < uVar5 * 0x4e2) {
    uVar12 = uVar11;
  }
  *(uint *)(iVar14 + 0x10) = uVar12;
  if (param_3 == 0) {
    *(undefined1 *)(iVar14 + 0x16) = DAT_00013042;
    *(undefined4 *)(iVar14 + 0x28) = *(undefined4 *)(iVar14 + 4);
  }
  iVar10 = (uint)bVar3 * 0x5a;
  *(ushort *)(iVar14 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar14 + 0x3e) = 1;
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar10 + 0x20 + iVar9) = (short)uVar5;
  iVar9 = *(int *)(iVar14 + 0x24);
  if (iVar9 << 0x10 < 0) {
    r_assert_err(0,0x10000,0x4ab);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar10 + 0x1a + iVar8) = (ushort)iVar9 | 0x8000;
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar10 + 0x46 + iVar9) = 0;
  iVar9 = r_sch_arb_insert(iVar14);
  if (iVar9 != 0) {
    r_assert_err(0,0x10000,0x27b);
    return;
  }
_L88:
  *(undefined1 *)(iVar14 + 0x50) = 0;
  return;
}

