/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  int iVar11;
  byte bVar12;
  ushort uVar13;
  uint uVar14;
  uint uVar15;
  
  if ((_lld_scan_env == 0) || (iVar7 = *(int *)(param_1 * 4 + _lld_scan_env), iVar7 == 0)) {
    r_assert_param(_lld_scan_env,"lld_scan.c",0x98e);
    return;
  }
  cVar3 = *(char *)(iVar7 + 0x3c);
  *(undefined1 *)(iVar7 + 0x3c) = 0;
  bVar4 = *(byte *)(iVar7 + 0x38);
  if (cVar3 == '\x02') {
    while (iVar7 = r_lld_rxdesc_check_hack((uint)bVar4), iVar7 != 0) {
      r_lld_rxdesc_free();
    }
    iVar7 = 0;
    while( true ) {
      iVar11 = iVar7 * 4;
      iVar8 = *(int *)(_lld_scan_env + iVar11);
      if (iVar8 != 0) {
        r_lld_ext_scan_dynamic_pti_process_eco(iVar8,1);
        if (*(char *)(iVar8 + 0x3c) == '\0') {
          r_sch_arb_remove(iVar8,0);
          r_sch_slice_bg_remove(0);
          if (*(char *)(iVar8 + 0x3d) == '\x03') {
            iVar8 = r_sdk_config_get_opts_ext();
            if (*(char *)(iVar8 + 0x18) == '\0') {
              r_assert_err(0,"lld_scan.c",0x492);
            }
            r_lld_scan_trunc_ind(iVar7);
          }
          r_ke_free(*(undefined4 *)(_lld_scan_env + iVar11));
          iVar8 = _lld_scan_env;
          *(undefined4 *)(iVar11 + _lld_scan_env) = 0;
          *(byte *)(iVar8 + 0xc) = ~(byte)(1 << iVar7) & *(byte *)(iVar8 + 0xc);
        }
        else if (*(char *)(iVar8 + 0x3c) == '\x01') {
          bVar4 = *(byte *)(iVar8 + 0x38);
          iVar11 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar11 + (uint)bVar4 * 0x5a + 0x20) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar8 + 0x3c) = 2;
        }
      }
      if (iVar7 != 0) break;
      iVar7 = 1;
    }
    if (*(char *)(_lld_scan_env + 0xc) == '\0') {
      puVar9 = (undefined1 *)r_ke_msg_alloc(0x206,0,0xff,2);
      uVar1 = *(undefined1 *)(_lld_scan_env + 0xd);
      *puVar9 = 0;
      puVar9[1] = uVar1;
      r_ke_msg_send();
      r_ke_free(_lld_scan_env);
      _lld_scan_env = 0;
    }
    return;
  }
  r_sch_arb_remove(iVar7,1);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  iVar8 = (uint)bVar4 * 0x5a + 0x18;
  if ((*(ushort *)(iVar11 + iVar8) >> 10 & 1) != 0) {
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar13 = *(ushort *)(iVar11 + iVar8);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar8 + iVar11) = uVar13 & 0xfbff;
    if (*(char *)(iVar7 + 0x3d) == '\x03') {
      iVar8 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar8 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x964);
      }
      r_lld_scan_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar7 + 0x3e) = 0;
    *(undefined1 *)(iVar7 + 0x3d) = 0;
  }
  r_lld_scan_process_pkt_rx(param_1);
  if ((*(char *)(iVar7 + 0x3e) == '\x02') ||
     ((*(char *)(iVar7 + 0x43) == '\0' && (*(char *)(iVar7 + 0x3e) == '\x01')))) {
    if (*(char *)(iVar7 + 0x3d) == '\x03') {
      iVar8 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar8 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x978);
      }
      r_lld_scan_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar7 + 0x3e) = 0;
  }
  else if (*(char *)(iVar7 + 0x3d) != '\x02') goto _L634;
  *(undefined1 *)(iVar7 + 0x3d) = 0;
_L634:
  iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
  if (*(char *)(iVar7 + 0x3e) == '\x01') {
    bVar4 = *(byte *)(iVar7 + 0x38);
    r_sch_slice_bg_remove(0);
    *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar7 + 0x48);
    *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar7 + 0x4c);
    *(uint *)(iVar7 + 0x10) =
         ((uint)*(ushort *)(&lld_scan_max_aux_dur_tab + (uint)*(byte *)(iVar7 + 0x55) * 2) +
         *(int *)(iVar7 + 0x50)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar2 = DAT_00015077;
    bVar12 = DAT_00015076;
    if (DAT_00015076 < *(byte *)(iVar7 + 0x16)) {
      bVar12 = *(byte *)(iVar7 + 0x16);
    }
    *(byte *)(iVar7 + 0x16) = bVar12;
    *(ushort *)(iVar7 + 0x14) = bVar2 & 0xf | 0x2000;
    iVar8 = r_sch_arb_insert(iVar7);
    if (iVar8 == 0) {
      bVar2 = *(byte *)(iVar7 + 0x55);
      uVar14 = *(uint *)(iVar7 + 0x50);
      uVar15 = (uint)bVar2 << 4;
      if ((uVar15 & 0xffffffcf) != 0) {
        r_assert_err("lld_scan.c",0x1bf);
      }
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      iVar8 = (uint)bVar4 * 0x5a;
      uVar13 = *(ushort *)(iVar11 + iVar8 + 4);
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + iVar8 + 4) = uVar13 & 0xffcf | (ushort)uVar15;
      uVar13 = *(ushort *)(&lld_scan_max_aux_dur_tab + (uint)bVar2 * 2);
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + iVar8 + 0x20) = (ushort)(((uint)uVar13 + uVar14 + 0x270) / 0x271) & 0xff;
      uVar13 = 0x672 - *(short *)(iVar7 + 0x36);
      if ((uVar13 & 0xf800) != 0) {
        r_assert_err(0,"lld_scan.c",0x6c0);
      }
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar11 + iVar8 + 0x28);
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + iVar8 + 0x28) = uVar5 & 0xf800 | uVar13;
      if (uVar14 < 0x4000) {
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar11 + iVar8 + 0x1a) = (short)(uVar14 + 1 >> 1);
      }
      else {
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar11 + iVar8 + 0x1a) = (ushort)((uVar14 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar14 = (uint)*(byte *)(iVar7 + 0x54) << 10;
      if ((uVar14 & 0x30000) != 0) {
        r_assert_err(0,"lld_scan.c",0x635);
      }
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      uVar13 = *(ushort *)(iVar11 + iVar8 + 0x26);
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + iVar8 + 0x26) = uVar13 & 0x3ff | (ushort)uVar14;
      if (*(char *)(iVar7 + 0x6f) != -1) {
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar11 + iVar8 + 0x14) = 0;
      }
      if ((*(char *)(iVar7 + 0x3d) == '\x03') && (*(char *)(iVar7 + 0x39) == '\x01')) {
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        uVar13 = *(ushort *)(iVar11 + iVar8);
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar11 + iVar8) = uVar13 & 0xffe0 | 10;
      }
      *(undefined1 *)(iVar7 + 0x43) = 0;
      return;
    }
    if (*(char *)(iVar7 + 0x3d) == '\x03') {
      iVar8 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar8 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x91e);
      }
      r_lld_scan_trunc_ind(param_1);
      *(undefined1 *)(iVar7 + 0x3e) = 0;
      *(undefined1 *)(iVar7 + 0x3d) = 0;
    }
  }
  if (((_lld_scan_env != 0) && (iVar7 = *(int *)(_lld_scan_env + param_1 * 4), iVar7 != 0)) &&
     (uVar10 = r_lld_read_clock(), (*(byte *)(_lld_scan_env + 0xc) & 3) == 3)) {
    lld_scan_sched_optimize_part_0(iVar7,uVar10,param_3);
  }
  uVar6 = _rwip_priority;
  _rwip_priority = 0x9c4;
  r_lld_scan_try_sched(param_1,param_2,param_3);
  _rwip_priority = uVar6;
  if (_lld_scan_env != 0) {
    iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
    if ((iVar7 != 0) && (*(uint *)(iVar7 + 0x24) == (uint)*(ushort *)(iVar7 + 0x32))) {
      (&_LANCHOR0)[param_1] = *(undefined4 *)(iVar7 + 4);
    }
  }
  return;
}

