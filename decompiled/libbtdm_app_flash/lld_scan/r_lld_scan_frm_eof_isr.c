/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_eof_isr(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  int iVar10;
  byte bVar11;
  int iVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  
  if ((_lld_scan_env == 0) || (iVar7 = *(int *)(param_1 * 4 + _lld_scan_env), iVar7 == 0)) {
    r_assert_param(param_1,"lld_scan.c",0x9a6);
    return;
  }
  cVar3 = *(char *)(iVar7 + 0x3c);
  *(undefined1 *)(iVar7 + 0x3c) = 0;
  bVar4 = *(byte *)(iVar7 + 0x38);
  if (cVar3 == '\x02') {
    while (iVar7 = r_lld_rxdesc_check_hack((uint)bVar4), iVar7 != 0) {
      r_lld_rxdesc_free();
    }
    uVar13 = 0;
    while( true ) {
      iVar10 = uVar13 * 4;
      iVar7 = *(int *)(_lld_scan_env + iVar10);
      if (iVar7 != 0) {
        iVar12 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar12 + 0x28) & 8) != 0) &&
           (iVar12 = r_sdk_config_get_opts_ext(), *(byte *)(iVar12 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x40010002,(uint)*(byte *)(iVar7 + 0x3c) << 8 | uVar13,
                     *(undefined4 *)(iVar7 + 0x24));
        }
        r_lld_ext_scan_dynamic_pti_process_eco(iVar7,1);
        if (*(char *)(iVar7 + 0x3c) == '\0') {
          r_sch_arb_remove(iVar7,0);
          r_sch_slice_bg_remove(0);
          if (*(char *)(iVar7 + 0x3d) == '\x03') {
            iVar7 = r_sdk_config_get_opts_ext();
            if (*(char *)(iVar7 + 0x18) == '\0') {
              r_assert_err(0,"lld_scan.c",0x4aa);
            }
            r_lld_scan_trunc_ind(uVar13);
          }
          r_ke_free(*(undefined4 *)(_lld_scan_env + iVar10));
          iVar7 = _lld_scan_env;
          *(undefined4 *)(iVar10 + _lld_scan_env) = 0;
          *(byte *)(iVar7 + 0xc) = ~(byte)(1 << uVar13) & *(byte *)(iVar7 + 0xc);
        }
        else if (*(char *)(iVar7 + 0x3c) == '\x01') {
          bVar4 = *(byte *)(iVar7 + 0x38);
          iVar10 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)((uint)bVar4 * 0x5a + 0x20 + iVar10) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar7 + 0x3c) = 2;
        }
      }
      if (uVar13 != 0) break;
      uVar13 = 1;
    }
    if (*(char *)(_lld_scan_env + 0xc) == '\0') {
      puVar8 = (undefined1 *)r_ke_msg_alloc(0x206,0,0xff,2);
      uVar1 = *(undefined1 *)(_lld_scan_env + 0xd);
      *puVar8 = 0;
      puVar8[1] = uVar1;
      r_ke_msg_send();
      r_ke_free(_lld_scan_env);
      _lld_scan_env = 0;
    }
    return;
  }
  r_sch_arb_remove(iVar7,1);
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  iVar12 = (uint)bVar4 * 0x5a + 0x18;
  if ((*(ushort *)(iVar10 + iVar12) >> 10 & 1) != 0) {
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar14 = *(ushort *)(iVar10 + iVar12);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar10 + iVar12) = uVar14 & 0xfbff;
    if (*(char *)(iVar7 + 0x3d) == '\x03') {
      iVar10 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar10 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x97c);
      }
      r_lld_scan_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar7 + 0x3e) = 0;
    *(undefined1 *)(iVar7 + 0x3d) = 0;
  }
  r_lld_scan_process_pkt_rx_hack(param_1);
  if ((*(char *)(iVar7 + 0x3e) == '\x02') ||
     ((*(char *)(iVar7 + 0x43) == '\0' && (*(char *)(iVar7 + 0x3e) == '\x01')))) {
    if (*(char *)(iVar7 + 0x3d) == '\x03') {
      iVar10 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar10 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x990);
      }
      r_lld_scan_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar7 + 0x3e) = 0;
  }
  else if (*(char *)(iVar7 + 0x3d) != '\x02') goto _L647;
  *(undefined1 *)(iVar7 + 0x3d) = 0;
_L647:
  iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
  bVar4 = *(byte *)(iVar7 + 0x38);
  if (*(char *)(iVar7 + 0x3e) == '\x01') {
    r_sch_slice_bg_remove(0);
    *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar7 + 0x48);
    *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar7 + 0x4c);
    *(uint *)(iVar7 + 0x10) =
         ((uint)*(ushort *)(&lld_scan_max_aux_dur_tab + (uint)*(byte *)(iVar7 + 0x55) * 2) +
         *(int *)(iVar7 + 0x50)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar2 = DAT_0001507f;
    bVar11 = DAT_0001507e;
    if (DAT_0001507e < *(byte *)(iVar7 + 0x16)) {
      bVar11 = *(byte *)(iVar7 + 0x16);
    }
    *(byte *)(iVar7 + 0x16) = bVar11;
    *(ushort *)(iVar7 + 0x14) = bVar2 & 0xf | 0x2000;
    iVar10 = r_sch_arb_insert(iVar7);
    if (iVar10 == 0) {
      bVar2 = *(byte *)(iVar7 + 0x55);
      uVar13 = *(uint *)(iVar7 + 0x50);
      uVar15 = (uint)bVar2 << 4;
      if ((uVar15 & 0xffffffcf) != 0) {
        r_assert_err("lld_scan.c",0x1bf);
      }
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      iVar10 = (uint)bVar4 * 0x5a;
      uVar14 = *(ushort *)(iVar12 + iVar10 + 4);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + iVar10 + 4) = uVar14 & 0xffcf | (ushort)uVar15;
      uVar14 = *(ushort *)(&lld_scan_max_aux_dur_tab + (uint)bVar2 * 2);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar10 + 0x20 + iVar12) = (ushort)(((uint)uVar14 + uVar13 + 0x270) / 0x271) & 0xff
      ;
      uVar14 = 0x672 - *(short *)(iVar7 + 0x36);
      if ((uVar14 & 0xf800) != 0) {
        r_assert_err(0,"lld_scan.c",0x6c0);
      }
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar12 + iVar10 + 0x28);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + iVar10 + 0x28) = uVar14 | uVar5 & 0xf800;
      if (uVar13 < 0x4000) {
        iVar12 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar10 + 0x1a + iVar12) = (short)(uVar13 + 1 >> 1);
      }
      else {
        iVar12 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar12 + iVar10 + 0x1a) = (ushort)((uVar13 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar13 = (uint)*(byte *)(iVar7 + 0x54) << 10;
      if ((uVar13 & 0x30000) != 0) {
        r_assert_err(0,"lld_scan.c",0x635);
      }
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      uVar14 = *(ushort *)(iVar12 + iVar10 + 0x26);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + iVar10 + 0x26) = uVar14 & 0x3ff | (ushort)uVar13;
      if (*(char *)(iVar7 + 0x6f) != -1) {
        iVar12 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar10 + 0x14 + iVar12) = 0;
      }
      if ((*(char *)(iVar7 + 0x3d) == '\x03') && (*(char *)(iVar7 + 0x39) == '\x01')) {
        iVar12 = r_emi_get_mem_addr_by_offset(0x400);
        uVar14 = *(ushort *)(iVar12 + iVar10);
        iVar12 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar10 + iVar12) = uVar14 & 0xffe0 | 10;
      }
      *(undefined1 *)(iVar7 + 0x43) = 0;
      return;
    }
    if (*(char *)(iVar7 + 0x3d) == '\x03') {
      iVar10 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar10 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x936);
      }
      r_lld_scan_trunc_ind(param_1);
      *(undefined1 *)(iVar7 + 0x3e) = 0;
      *(undefined1 *)(iVar7 + 0x3d) = 0;
    }
  }
  if ((_lld_scan_env != 0) && (iVar7 = *(int *)(_lld_scan_env + param_1 * 4), iVar7 != 0)) {
    uVar9 = r_lld_read_clock();
    lld_scan_sched_optimize(iVar7,uVar9);
  }
  uVar6 = _rwip_priority;
  _rwip_priority = 0x9c4;
  r_lld_scan_try_sched_hack(param_1,param_2,param_3);
  _rwip_priority = uVar6;
  if (_lld_scan_env != 0) {
    iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
    if ((iVar7 != 0) && (*(uint *)(iVar7 + 0x24) == (uint)*(ushort *)(iVar7 + 0x32))) {
      (&scan_anchor_point)[param_1] = *(undefined4 *)(iVar7 + 4);
    }
  }
  return;
}

