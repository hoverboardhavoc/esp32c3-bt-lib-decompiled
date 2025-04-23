/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_eof_isr(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  ushort uVar6;
  undefined2 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  int iVar11;
  byte bVar12;
  int iVar13;
  uint uVar14;
  ushort uVar15;
  
  if ((_lld_scan_env == 0) || (iVar8 = *(int *)(param_1 * 4 + _lld_scan_env), iVar8 == 0)) {
    r_assert_param(param_1,"lld_scan.c",0x9a6);
    return;
  }
  cVar4 = *(char *)(iVar8 + 0x3c);
  *(undefined1 *)(iVar8 + 0x3c) = 0;
  bVar5 = *(byte *)(iVar8 + 0x38);
  if (cVar4 == '\x02') {
    while (iVar8 = r_lld_rxdesc_check_hack((uint)bVar5), iVar8 != 0) {
      r_lld_rxdesc_free();
    }
    uVar14 = 0;
    do {
      iVar11 = uVar14 * 4;
      iVar8 = *(int *)(_lld_scan_env + iVar11);
      if (iVar8 != 0) {
        iVar13 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar13 + 0x28) & 8) != 0) &&
           (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x40010002,(uint)*(byte *)(iVar8 + 0x3c) << 8 | uVar14,
                     *(undefined4 *)(iVar8 + 0x24));
        }
        r_lld_ext_scan_dynamic_pti_process_eco(iVar8,1);
        if (*(char *)(iVar8 + 0x3c) == '\0') {
          r_sch_arb_remove(iVar8,0);
          r_sch_slice_bg_remove(0);
          if (*(char *)(iVar8 + 0x3d) == '\x03') {
            iVar8 = r_sdk_config_get_opts_ext();
            if (*(char *)(iVar8 + 0x18) == '\0') {
              r_assert_err(0,"lld_scan.c",0x4aa);
            }
            r_lld_scan_trunc_ind(uVar14);
          }
          r_ke_free(*(undefined4 *)(_lld_scan_env + iVar11));
          iVar8 = _lld_scan_env;
          *(undefined4 *)(iVar11 + _lld_scan_env) = 0;
          *(byte *)(iVar8 + 0xc) = ~(byte)(1 << uVar14) & *(byte *)(iVar8 + 0xc);
        }
        else if (*(char *)(iVar8 + 0x3c) == '\x01') {
          bVar5 = *(byte *)(iVar8 + 0x38);
          iVar11 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)((uint)bVar5 * 0x5a + 0x20 + iVar11) = 1;
          _DAT_60031000 = _DAT_60031000 | 0x1000000;
          *(undefined1 *)(iVar8 + 0x3c) = 2;
        }
      }
      bVar1 = uVar14 != 1;
      uVar14 = 1;
    } while (bVar1);
    if (*(char *)(_lld_scan_env + 0xc) == '\0') {
      puVar9 = (undefined1 *)r_ke_msg_alloc(0x206,0,0xff,2);
      uVar2 = *(undefined1 *)(_lld_scan_env + 0xd);
      *puVar9 = 0;
      puVar9[1] = uVar2;
      r_ke_msg_send();
      r_ke_free(_lld_scan_env);
      _lld_scan_env = 0;
    }
    return;
  }
  r_sch_arb_remove(iVar8,1);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  iVar13 = (uint)bVar5 * 0x5a + 0x18;
  if ((*(ushort *)(iVar11 + iVar13) >> 10 & 1) != 0) {
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar15 = *(ushort *)(iVar11 + iVar13);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar11 + iVar13) = uVar15 & 0xfbff;
    if (*(char *)(iVar8 + 0x3d) == '\x03') {
      iVar11 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar11 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x97c);
      }
      r_lld_scan_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar8 + 0x3e) = 0;
    *(undefined1 *)(iVar8 + 0x3d) = 0;
  }
  r_lld_scan_process_pkt_rx(param_1);
  if ((*(char *)(iVar8 + 0x3e) == '\x02') ||
     ((*(char *)(iVar8 + 0x43) == '\0' && (*(char *)(iVar8 + 0x3e) == '\x01')))) {
    if (*(char *)(iVar8 + 0x3d) == '\x03') {
      iVar11 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar11 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x990);
      }
      r_lld_scan_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar8 + 0x3e) = 0;
  }
  else if (*(char *)(iVar8 + 0x3d) != '\x02') goto _L625;
  *(undefined1 *)(iVar8 + 0x3d) = 0;
_L625:
  iVar8 = *(int *)(_lld_scan_env + param_1 * 4);
  if (*(char *)(iVar8 + 0x3e) == '\x01') {
    bVar5 = *(byte *)(iVar8 + 0x38);
    r_sch_slice_bg_remove(0);
    *(undefined4 *)(iVar8 + 4) = *(undefined4 *)(iVar8 + 0x48);
    *(undefined4 *)(iVar8 + 8) = *(undefined4 *)(iVar8 + 0x4c);
    *(uint *)(iVar8 + 0x10) =
         ((uint)*(ushort *)(&lld_scan_max_aux_dur_tab + (uint)*(byte *)(iVar8 + 0x55) * 2) +
         *(int *)(iVar8 + 0x50)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar3 = DAT_0001507f;
    bVar12 = DAT_0001507e;
    if (DAT_0001507e < *(byte *)(iVar8 + 0x16)) {
      bVar12 = *(byte *)(iVar8 + 0x16);
    }
    *(byte *)(iVar8 + 0x16) = bVar12;
    *(ushort *)(iVar8 + 0x14) = bVar3 & 0xf | 0x2000;
    iVar11 = r_sch_arb_insert(iVar8);
    if (iVar11 == 0) {
      bVar3 = *(byte *)(iVar8 + 0x55);
      uVar14 = *(uint *)(iVar8 + 0x50);
      if ((bVar3 & 0xfc) != 0) {
        r_assert_err("lld_scan.c",0x1bf);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      iVar11 = (uint)bVar5 * 0x5a;
      uVar15 = *(ushort *)(iVar13 + iVar11 + 4);
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + iVar11 + 4) = uVar15 & 0xffcf | (ushort)bVar3 << 4;
      uVar15 = *(ushort *)(&lld_scan_max_aux_dur_tab + (uint)bVar3 * 2);
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + 0x20 + iVar13) = (ushort)(((uint)uVar15 + uVar14 + 0x270) / 0x271) & 0xff
      ;
      uVar15 = 0x672 - *(short *)(iVar8 + 0x36);
      if (0x7ff < uVar15) {
        r_assert_err(0,"lld_scan.c",0x6c0);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      uVar6 = *(ushort *)(iVar13 + iVar11 + 0x28);
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + iVar11 + 0x28) = uVar15 | uVar6 & 0xf800;
      if (uVar14 < 0x4000) {
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar13 + iVar11 + 0x1a) = (short)(uVar14 + 1 >> 1);
      }
      else {
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar13 + iVar11 + 0x1a) = (ushort)((uVar14 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      bVar5 = *(byte *)(iVar8 + 0x54);
      if ((bVar5 & 0xc0) != 0) {
        r_assert_err(0,"lld_scan.c",0x635);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      uVar15 = *(ushort *)(iVar13 + iVar11 + 0x26);
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + iVar11 + 0x26) = uVar15 & 0x3ff | (ushort)bVar5 << 10;
      if (*(char *)(iVar8 + 0x6f) != -1) {
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar11 + 0x14 + iVar13) = 0;
      }
      if ((*(char *)(iVar8 + 0x3d) == '\x03') && (*(char *)(iVar8 + 0x39) == '\x01')) {
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        uVar15 = *(ushort *)(iVar13 + iVar11);
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar11 + iVar13) = uVar15 & 0xffe0 | 10;
      }
      *(undefined1 *)(iVar8 + 0x43) = 0;
      return;
    }
    if (*(char *)(iVar8 + 0x3d) == '\x03') {
      iVar11 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar11 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x936);
      }
      r_lld_scan_trunc_ind(param_1);
      *(undefined1 *)(iVar8 + 0x3e) = 0;
      *(undefined1 *)(iVar8 + 0x3d) = 0;
    }
  }
  if ((_lld_scan_env != 0) && (iVar8 = *(int *)(_lld_scan_env + param_1 * 4), iVar8 != 0)) {
    uVar10 = r_lld_read_clock();
    lld_scan_sched_optimize(iVar8,uVar10);
  }
  uVar7 = _rwip_priority;
  _rwip_priority = 0x9c4;
  r_lld_scan_try_sched(param_1,param_2,param_3);
  _rwip_priority = uVar7;
  if (_lld_scan_env != 0) {
    iVar8 = *(int *)(_lld_scan_env + param_1 * 4);
    if ((iVar8 != 0) && (*(uint *)(iVar8 + 0x24) == (uint)*(ushort *)(iVar8 + 0x32))) {
      (&scan_anchor_point)[param_1] = *(undefined4 *)(iVar8 + 4);
    }
  }
  return;
}

