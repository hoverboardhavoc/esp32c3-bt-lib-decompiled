/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_sched(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  
  iVar5 = *(int *)(_lld_scan_env + param_1 * 4);
  if (*(char *)(iVar5 + 0x3e) == '\x01') {
    bVar1 = *(byte *)(iVar5 + 0x38);
    r_sch_slice_bg_remove(0);
    *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar5 + 0x48);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 0x4c);
    *(uint *)(iVar5 + 0x10) =
         ((uint)*(ushort *)(&lld_scan_max_aux_dur_tab + (uint)*(byte *)(iVar5 + 0x55) * 2) +
         *(int *)(iVar5 + 0x50)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar2 = DAT_0001507f;
    bVar9 = DAT_0001507e;
    if (DAT_0001507e < *(byte *)(iVar5 + 0x16)) {
      bVar9 = *(byte *)(iVar5 + 0x16);
    }
    *(byte *)(iVar5 + 0x16) = bVar9;
    *(ushort *)(iVar5 + 0x14) = bVar2 & 0xf | 0x2000;
    iVar7 = r_sch_arb_insert(iVar5);
    if (iVar7 == 0) {
      bVar2 = *(byte *)(iVar5 + 0x55);
      uVar11 = *(uint *)(iVar5 + 0x50);
      uVar12 = (uint)bVar2 << 4;
      if ((uVar12 & 0xffffffcf) != 0) {
        r_assert_err("lld_scan.c",0x1bf);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar7 = (uint)bVar1 * 0x5a;
      uVar10 = *(ushort *)(iVar8 + iVar7 + 4);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 4) = uVar10 & 0xffcf | (ushort)uVar12;
      uVar10 = *(ushort *)(&lld_scan_max_aux_dur_tab + (uint)bVar2 * 2);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 0x20) = (ushort)(((uint)uVar10 + uVar11 + 0x270) / 0x271) & 0xff;
      uVar10 = 0x672 - *(short *)(iVar5 + 0x36);
      if ((uVar10 & 0xf800) != 0) {
        r_assert_err(0,"lld_scan.c",0x6c0);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar8 + iVar7 + 0x28);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 0x28) = uVar3 & 0xf800 | uVar10;
      if (uVar11 < 0x4000) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar8 + iVar7 + 0x1a) = (short)(uVar11 + 1 >> 1);
      }
      else {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar8 + iVar7 + 0x1a) = (ushort)((uVar11 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar11 = (uint)*(byte *)(iVar5 + 0x54) << 10;
      if ((uVar11 & 0x30000) != 0) {
        r_assert_err(0,"lld_scan.c",0x635);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar10 = *(ushort *)(iVar8 + iVar7 + 0x26);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 0x26) = uVar10 & 0x3ff | (ushort)uVar11;
      if (*(char *)(iVar5 + 0x6f) != -1) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar8 + iVar7 + 0x14) = 0;
      }
      if ((*(char *)(iVar5 + 0x3d) == '\x03') && (*(char *)(iVar5 + 0x39) == '\x01')) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        uVar10 = *(ushort *)(iVar8 + iVar7);
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar8 + iVar7) = uVar10 & 0xffe0 | 10;
      }
      *(undefined1 *)(iVar5 + 0x43) = 0;
      return;
    }
    if (*(char *)(iVar5 + 0x3d) == '\x03') {
      iVar7 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar7 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0x927);
      }
      r_lld_scan_trunc_ind(param_1);
      *(undefined1 *)(iVar5 + 0x3e) = 0;
      *(undefined1 *)(iVar5 + 0x3d) = 0;
    }
  }
  if (((_lld_scan_env != 0) && (iVar5 = *(int *)(_lld_scan_env + param_1 * 4), iVar5 != 0)) &&
     (uVar6 = r_lld_read_clock(), (*(byte *)(_lld_scan_env + 0xc) & 3) == 3)) {
    lld_scan_sched_optimize_part_0(iVar5,uVar6,param_3);
  }
  uVar4 = _rwip_priority;
  _rwip_priority = 0x9c4;
  r_lld_scan_try_sched(param_1,param_2,param_3);
  _rwip_priority = uVar4;
  if (_lld_scan_env != 0) {
    iVar5 = *(int *)(_lld_scan_env + param_1 * 4);
    if ((iVar5 != 0) && (*(uint *)(iVar5 + 0x24) == (uint)*(ushort *)(iVar5 + 0x32))) {
      (&_LANCHOR0)[param_1] = *(undefined4 *)(iVar5 + 4);
    }
  }
  return;
}

