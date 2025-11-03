/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_sched(uint param_1,undefined4 param_2,undefined4 param_3)

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
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  
  iVar5 = *(int *)(_lld_scan_env + param_1 * 4);
  bVar1 = *(byte *)(iVar5 + 0x38);
  if (*(char *)(iVar5 + 0x3e) == '\x01') {
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
      uVar10 = *(uint *)(iVar5 + 0x50);
      uVar12 = (uint)bVar2 << 4;
      if ((uVar12 & 0xffffffcf) != 0) {
        r_assert_err("lld_scan.c",0x1bf);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar7 = (uint)bVar1 * 0x5a;
      uVar11 = *(ushort *)(iVar8 + iVar7 + 4);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 4) = uVar11 & 0xffcf | (ushort)uVar12;
      uVar11 = *(ushort *)(&lld_scan_max_aux_dur_tab + (uint)bVar2 * 2);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + 0x20 + iVar8) = (ushort)(((uint)uVar11 + uVar10 + 0x270) / 0x271) & 0xff;
      uVar11 = 0x672 - *(short *)(iVar5 + 0x36);
      if ((uVar11 & 0xf800) != 0) {
        r_assert_err(0,"lld_scan.c",0x6c0);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar8 + iVar7 + 0x28);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 0x28) = uVar11 | uVar3 & 0xf800;
      if (uVar10 < 0x4000) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar8 + iVar7 + 0x1a) = (short)(uVar10 + 1 >> 1);
      }
      else {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar8 + iVar7 + 0x1a) = (ushort)((uVar10 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar10 = (uint)*(byte *)(iVar5 + 0x54) << 10;
      if ((uVar10 & 0x30000) != 0) {
        r_assert_err(0,"lld_scan.c",0x635);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar11 = *(ushort *)(iVar8 + iVar7 + 0x26);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 0x26) = uVar11 & 0x3ff | (ushort)uVar10;
      if (*(char *)(iVar5 + 0x6f) != -1) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar7 + 0x14 + iVar8) = 0;
      }
      if ((*(char *)(iVar5 + 0x3d) == '\x03') && (*(char *)(iVar5 + 0x39) == '\x01')) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        uVar11 = *(ushort *)(iVar8 + iVar7);
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar7 + iVar8) = uVar11 & 0xffe0 | 10;
      }
      *(undefined1 *)(iVar5 + 0x43) = 0;
      iVar7 = 1;
    }
    else {
      iVar7 = 0;
      if (*(char *)(iVar5 + 0x3d) == '\x03') {
        iVar7 = r_sdk_config_get_opts_ext();
        if (*(char *)(iVar7 + 0x18) == '\0') {
          r_assert_err(0,"lld_scan.c",0x96d);
        }
        r_ble_log_internal_x1(0x404100c0,param_1);
        r_lld_scan_trunc_ind(param_1);
        iVar7 = 0;
        *(undefined1 *)(iVar5 + 0x3e) = 0;
        *(undefined1 *)(iVar5 + 0x3d) = 0;
      }
    }
    uVar12 = *(uint *)(iVar5 + 4) * 0x271;
    uVar10 = *(int *)(iVar5 + 8) + uVar12;
    r_ble_log_internal_x3
              (0x404100c1,
               uVar10 >> 1 |
               ((uint)(uVar10 < uVar12) + (int)((ulonglong)*(uint *)(iVar5 + 4) * 0x271 >> 0x20)) *
               -0x80000000,*(undefined4 *)(iVar5 + 0x10),
               iVar7 << 8 |
               (uint)*(byte *)(iVar5 + 0x3d) << 0x10 | (uint)*(byte *)(iVar5 + 0x16) << 0x18 |
               param_1);
    if (iVar7 != 0) {
      return;
    }
  }
  if ((_lld_scan_env != 0) && (iVar5 = *(int *)(_lld_scan_env + param_1 * 4), iVar5 != 0)) {
    uVar6 = r_lld_read_clock();
    lld_scan_sched_optimize(iVar5,uVar6);
  }
  uVar4 = _rwip_priority;
  _rwip_priority = 0x9c4;
  r_lld_scan_try_sched_hack(param_1,param_2,param_3);
  _rwip_priority = uVar4;
  if (_lld_scan_env != 0) {
    iVar5 = *(int *)(_lld_scan_env + param_1 * 4);
    if ((iVar5 != 0) && (*(uint *)(iVar5 + 0x24) == (uint)*(ushort *)(iVar5 + 0x32))) {
      (&scan_anchor_point)[param_1] = *(undefined4 *)(iVar5 + 4);
    }
  }
  return;
}

