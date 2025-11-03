/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  byte bVar11;
  uint uVar12;
  ushort uVar13;
  uint uVar14;
  
  if (param_1 == 0) {
    uVar10 = 0xafd;
  }
  else {
    r_ble_log_internal_x1
              (0x404100c5,
               (uint)*(byte *)(param_1 + 0x40) |
               (uint)*(byte *)(param_1 + 0x3c) << 8 | (uint)*(byte *)(param_1 + 0x3d) << 0x10);
    if (*(char *)(param_1 + 0x3c) != '\0') {
      r_assert_param(*(undefined1 *)(param_1 + 0x40),"lld_scan.c",0xaf8);
      return;
    }
    iVar7 = r_lld_read_clock();
    if (*(char *)(param_1 + 0x3d) == '\x03') {
      iVar8 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar8 + 0x18) == '\0') {
        r_assert_err(0,"lld_scan.c",0xad4);
      }
      r_ble_log_internal_x1(0x404100c6,*(undefined1 *)(param_1 + 0x40));
      r_lld_scan_trunc_ind(*(undefined1 *)(param_1 + 0x40));
      *(undefined1 *)(param_1 + 0x3d) = 0;
    }
    if ((uint)*(ushort *)(param_1 + 0x30) << 1 <= (iVar7 - *(int *)(param_1 + 0x28) & 0xfffffffU)) {
      bVar1 = rwip_priority;
      if (0xff < (uint)*(byte *)(param_1 + 0x16) + (uint)rwip_priority) {
        r_assert_err(0,"lld_scan.c",0xadf);
      }
      *(int *)(param_1 + 0x28) = iVar7;
      *(byte *)(param_1 + 0x16) = bVar1 + *(char *)(param_1 + 0x16);
    }
    if (*(char *)(param_1 + 0x3e) == '\x01') {
      *(undefined1 *)(param_1 + 0x3e) = 0;
      uVar9 = (uint)*(byte *)(param_1 + 0x40);
      iVar8 = *(int *)(_lld_scan_env + uVar9 * 4);
      bVar1 = *(byte *)(iVar8 + 0x38);
      if (*(char *)(iVar8 + 0x3e) == '\x01') {
        r_sch_slice_bg_remove(0);
        *(undefined4 *)(iVar8 + 4) = *(undefined4 *)(iVar8 + 0x48);
        *(undefined4 *)(iVar8 + 8) = *(undefined4 *)(iVar8 + 0x4c);
        *(uint *)(iVar8 + 0x10) =
             ((uint)*(ushort *)(&lld_scan_max_aux_dur_tab + (uint)*(byte *)(iVar8 + 0x55) * 2) +
             *(int *)(iVar8 + 0x50)) * 2 + (uint)_sdk_cfg_priv_opts;
        bVar2 = DAT_0001507f;
        bVar11 = DAT_0001507e;
        if (DAT_0001507e < *(byte *)(iVar8 + 0x16)) {
          bVar11 = *(byte *)(iVar8 + 0x16);
        }
        *(byte *)(iVar8 + 0x16) = bVar11;
        *(ushort *)(iVar8 + 0x14) = bVar2 & 0xf | 0x2000;
        iVar5 = r_sch_arb_insert(iVar8);
        if (iVar5 == 0) {
          bVar2 = *(byte *)(iVar8 + 0x55);
          uVar12 = *(uint *)(iVar8 + 0x50);
          uVar14 = (uint)bVar2 << 4;
          if ((uVar14 & 0xffffffcf) != 0) {
            r_assert_err("lld_scan.c",0x1bf);
          }
          iVar6 = r_emi_get_mem_addr_by_offset(0x400);
          iVar5 = (uint)bVar1 * 0x5a;
          uVar13 = *(ushort *)(iVar6 + iVar5 + 4);
          iVar6 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar6 + iVar5 + 4) = uVar13 & 0xffcf | (ushort)uVar14;
          uVar13 = *(ushort *)(&lld_scan_max_aux_dur_tab + (uint)bVar2 * 2);
          iVar6 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar5 + 0x20 + iVar6) =
               (ushort)(((uint)uVar13 + uVar12 + 0x270) / 0x271) & 0xff;
          uVar13 = 0x672 - *(short *)(iVar8 + 0x36);
          if ((uVar13 & 0xf800) != 0) {
            r_assert_err(0,"lld_scan.c",0x6c0);
          }
          iVar6 = r_emi_get_mem_addr_by_offset(0x400);
          uVar3 = *(ushort *)(iVar6 + iVar5 + 0x28);
          iVar6 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar6 + iVar5 + 0x28) = uVar13 | uVar3 & 0xf800;
          if (uVar12 < 0x4000) {
            iVar6 = r_emi_get_mem_addr_by_offset(0x400);
            *(short *)(iVar6 + iVar5 + 0x1a) = (short)(uVar12 + 1 >> 1);
          }
          else {
            iVar6 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar6 + iVar5 + 0x1a) = (ushort)((uVar12 + 0x270) / 0x271) & 0xff | 0x8000;
          }
          uVar12 = (uint)*(byte *)(iVar8 + 0x54) << 10;
          if ((uVar12 & 0x30000) != 0) {
            r_assert_err(0,"lld_scan.c",0x635);
          }
          iVar6 = r_emi_get_mem_addr_by_offset(0x400);
          uVar13 = *(ushort *)(iVar6 + iVar5 + 0x26);
          iVar6 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar6 + iVar5 + 0x26) = uVar13 & 0x3ff | (ushort)uVar12;
          if (*(char *)(iVar8 + 0x6f) != -1) {
            iVar6 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)(iVar5 + 0x14 + iVar6) = 0;
          }
          if ((*(char *)(iVar8 + 0x3d) == '\x03') && (*(char *)(iVar8 + 0x39) == '\x01')) {
            iVar6 = r_emi_get_mem_addr_by_offset(0x400);
            uVar13 = *(ushort *)(iVar6 + iVar5);
            iVar6 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar5 + iVar6) = uVar13 & 0xffe0 | 10;
          }
          *(undefined1 *)(iVar8 + 0x43) = 0;
          iVar5 = 1;
        }
        else {
          iVar5 = 0;
          if (*(char *)(iVar8 + 0x3d) == '\x03') {
            iVar5 = r_sdk_config_get_opts_ext();
            if (*(char *)(iVar5 + 0x18) == '\0') {
              r_assert_err(0,"lld_scan.c",0x96d);
            }
            r_ble_log_internal_x1(0x404100c0,uVar9);
            r_lld_scan_trunc_ind(uVar9);
            iVar5 = 0;
            *(undefined1 *)(iVar8 + 0x3e) = 0;
            *(undefined1 *)(iVar8 + 0x3d) = 0;
          }
        }
        uVar14 = *(uint *)(iVar8 + 4) * 0x271;
        uVar12 = *(int *)(iVar8 + 8) + uVar14;
        r_ble_log_internal_x3
                  (0x404100c1,
                   uVar12 >> 1 |
                   ((uint)(uVar12 < uVar14) + (int)((ulonglong)*(uint *)(iVar8 + 4) * 0x271 >> 0x20)
                   ) * -0x80000000,*(undefined4 *)(iVar8 + 0x10),
                   iVar5 << 8 |
                   (uint)*(byte *)(iVar8 + 0x3d) << 0x10 | (uint)*(byte *)(iVar8 + 0x16) << 0x18 |
                   uVar9);
        if (iVar5 != 0) {
          return;
        }
      }
      if ((_lld_scan_env != 0) && (iVar8 = *(int *)(_lld_scan_env + uVar9 * 4), iVar8 != 0)) {
        uVar10 = r_lld_read_clock();
        lld_scan_sched_optimize(iVar8,uVar10);
      }
      uVar4 = _rwip_priority;
      _rwip_priority = 0x9c4;
      r_lld_scan_try_sched_hack(uVar9,iVar7,1);
      _rwip_priority = uVar4;
      if (_lld_scan_env != 0) {
        iVar7 = *(int *)(_lld_scan_env + uVar9 * 4);
        if ((iVar7 != 0) && (*(uint *)(iVar7 + 0x24) == (uint)*(ushort *)(iVar7 + 0x32))) {
          (&scan_anchor_point)[uVar9] = *(undefined4 *)(iVar7 + 4);
        }
      }
      return;
    }
    iVar7 = r_sch_arb_insert(param_1);
    if (iVar7 == 0) {
      return;
    }
    uVar10 = 0xaeb;
  }
  r_assert_err(0,"lld_scan.c",uVar10);
  return;
}

