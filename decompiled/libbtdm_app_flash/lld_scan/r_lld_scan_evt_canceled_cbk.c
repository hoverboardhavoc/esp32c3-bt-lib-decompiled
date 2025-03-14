/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  byte bVar10;
  ushort uVar11;
  uint uVar12;
  
  if (param_1 == 0) {
    uVar9 = 0xaa4;
  }
  else {
    if (*(char *)(param_1 + 0x3c) != '\0') {
      r_assert_param(*(undefined1 *)(param_1 + 0x40),"lld_scan.c",0xa9f);
      return;
    }
    iVar6 = r_lld_read_clock();
    if (*(char *)(param_1 + 0x3d) == '\x03') {
      iVar7 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar7 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0xa7c);
      }
      r_lld_scan_trunc_ind(*(undefined1 *)(param_1 + 0x40));
      *(undefined1 *)(param_1 + 0x3d) = 0;
    }
    if ((uint)*(ushort *)(param_1 + 0x30) << 1 <= (iVar6 - *(int *)(param_1 + 0x28) & 0xfffffffU)) {
      bVar1 = rwip_priority;
      if (0xff < (uint)*(byte *)(param_1 + 0x16) + (uint)rwip_priority) {
        r_assert_err(0,"lld_scan.c",0xa86);
      }
      *(int *)(param_1 + 0x28) = iVar6;
      *(byte *)(param_1 + 0x16) = bVar1 + *(char *)(param_1 + 0x16);
    }
    if (*(char *)(param_1 + 0x3e) == '\x01') {
      *(undefined1 *)(param_1 + 0x3e) = 0;
      uVar8 = (uint)*(byte *)(param_1 + 0x40);
      iVar7 = *(int *)(_lld_scan_env + uVar8 * 4);
      if (*(char *)(iVar7 + 0x3e) == '\x01') {
        bVar1 = *(byte *)(iVar7 + 0x38);
        r_sch_slice_bg_remove(0);
        *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar7 + 0x48);
        *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar7 + 0x4c);
        *(uint *)(iVar7 + 0x10) =
             ((uint)*(ushort *)(&lld_scan_max_aux_dur_tab + (uint)*(byte *)(iVar7 + 0x55) * 2) +
             *(int *)(iVar7 + 0x50)) * 2 + (uint)_sdk_cfg_priv_opts;
        bVar2 = DAT_00015077;
        bVar10 = DAT_00015076;
        if (DAT_00015076 < *(byte *)(iVar7 + 0x16)) {
          bVar10 = *(byte *)(iVar7 + 0x16);
        }
        *(byte *)(iVar7 + 0x16) = bVar10;
        *(ushort *)(iVar7 + 0x14) = bVar2 & 0xf | 0x2000;
        iVar5 = r_sch_arb_insert(iVar7);
        if (iVar5 == 0) {
          bVar2 = *(byte *)(iVar7 + 0x55);
          uVar8 = *(uint *)(iVar7 + 0x50);
          uVar12 = (uint)bVar2 << 4;
          if ((uVar12 & 0xffffffcf) != 0) {
            r_assert_err("lld_scan.c",0x1bf);
          }
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          iVar6 = (uint)bVar1 * 0x5a;
          uVar11 = *(ushort *)(iVar5 + iVar6 + 4);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar5 + iVar6 + 4) = uVar11 & 0xffcf | (ushort)uVar12;
          uVar11 = *(ushort *)(&lld_scan_max_aux_dur_tab + (uint)bVar2 * 2);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar5 + iVar6 + 0x20) =
               (ushort)(((uint)uVar11 + uVar8 + 0x270) / 0x271) & 0xff;
          uVar11 = 0x672 - *(short *)(iVar7 + 0x36);
          if ((uVar11 & 0xf800) != 0) {
            r_assert_err(0,"lld_scan.c",0x6c0);
          }
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          uVar3 = *(ushort *)(iVar5 + iVar6 + 0x28);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar5 + iVar6 + 0x28) = uVar3 & 0xf800 | uVar11;
          if (uVar8 < 0x4000) {
            iVar5 = r_emi_get_mem_addr_by_offset(0x400);
            *(short *)(iVar5 + iVar6 + 0x1a) = (short)(uVar8 + 1 >> 1);
          }
          else {
            iVar5 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar5 + iVar6 + 0x1a) = (ushort)((uVar8 + 0x270) / 0x271) & 0xff | 0x8000;
          }
          uVar8 = (uint)*(byte *)(iVar7 + 0x54) << 10;
          if ((uVar8 & 0x30000) != 0) {
            r_assert_err(0,"lld_scan.c",0x635);
          }
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          uVar11 = *(ushort *)(iVar5 + iVar6 + 0x26);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar5 + iVar6 + 0x26) = uVar11 & 0x3ff | (ushort)uVar8;
          if (*(char *)(iVar7 + 0x6f) != -1) {
            iVar5 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)(iVar5 + iVar6 + 0x14) = 0;
          }
          if ((*(char *)(iVar7 + 0x3d) == '\x03') && (*(char *)(iVar7 + 0x39) == '\x01')) {
            iVar5 = r_emi_get_mem_addr_by_offset(0x400);
            uVar11 = *(ushort *)(iVar5 + iVar6);
            iVar5 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar5 + iVar6) = uVar11 & 0xffe0 | 10;
          }
          *(undefined1 *)(iVar7 + 0x43) = 0;
          return;
        }
        if (*(char *)(iVar7 + 0x3d) == '\x03') {
          iVar5 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar5 + 0x18) == '\0') {
            r_assert_err(0,"lld_scan.c",0x91e);
          }
          r_lld_scan_trunc_ind(uVar8);
          *(undefined1 *)(iVar7 + 0x3e) = 0;
          *(undefined1 *)(iVar7 + 0x3d) = 0;
        }
      }
      if (((_lld_scan_env != 0) && (iVar7 = *(int *)(_lld_scan_env + uVar8 * 4), iVar7 != 0)) &&
         (uVar9 = r_lld_read_clock(), (*(byte *)(_lld_scan_env + 0xc) & 3) == 3)) {
        lld_scan_sched_optimize_part_0(iVar7,uVar9,1);
      }
      uVar4 = _rwip_priority;
      _rwip_priority = 0x9c4;
      r_lld_scan_try_sched(uVar8,iVar6,1);
      _rwip_priority = uVar4;
      if (_lld_scan_env != 0) {
        iVar6 = *(int *)(_lld_scan_env + uVar8 * 4);
        if ((iVar6 != 0) && (*(uint *)(iVar6 + 0x24) == (uint)*(ushort *)(iVar6 + 0x32))) {
          (&_LANCHOR0)[uVar8] = *(undefined4 *)(iVar6 + 4);
        }
      }
      return;
    }
    iVar6 = r_sch_arb_insert(param_1);
    if (iVar6 == 0) {
      return;
    }
    uVar9 = 0xa92;
  }
  r_assert_err(0,"lld_scan.c",uVar9);
  return;
}

