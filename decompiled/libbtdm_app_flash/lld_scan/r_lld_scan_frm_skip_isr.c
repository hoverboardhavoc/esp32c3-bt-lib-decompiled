/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_skip_isr(uint param_1)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  byte bVar13;
  uint uVar14;
  ushort uVar15;
  uint uVar16;
  
  if (_lld_scan_env == 0) {
    uVar12 = 0xa4e;
  }
  else {
    iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
    if (iVar7 == 0) {
      uVar12 = 0xa4e;
    }
    else {
      iVar10 = r_lld_read_clock();
      cVar4 = *(char *)(iVar7 + 0x3c);
      *(undefined1 *)(iVar7 + 0x3c) = 0;
      if (cVar4 == '\x02') {
        uVar14 = 0;
        while( true ) {
          iVar10 = uVar14 * 4;
          iVar7 = *(int *)(_lld_scan_env + iVar10);
          if (iVar7 != 0) {
            r_ble_log_internal_x2
                      (0x400100ba,*(undefined4 *)(iVar7 + 0x24),
                       (uint)*(byte *)(iVar7 + 0x3c) << 8 | uVar14);
            r_lld_ext_scan_dynamic_pti_process_eco(iVar7,1);
            if (*(char *)(iVar7 + 0x3c) == '\0') {
              r_sch_arb_remove(iVar7,0);
              r_sch_slice_bg_remove(0);
              if (*(char *)(iVar7 + 0x3d) == '\x03') {
                iVar7 = r_sdk_config_get_opts_ext();
                if (*(char *)(iVar7 + 0x18) == '\0') {
                  r_assert_err(0,"lld_scan.c",0x4d7);
                }
                r_ble_log_internal_x1(0x404100bb,uVar14);
                r_lld_scan_trunc_ind(uVar14);
              }
              r_ke_free(*(undefined4 *)(_lld_scan_env + iVar10));
              iVar7 = _lld_scan_env;
              *(undefined4 *)(iVar10 + _lld_scan_env) = 0;
              *(byte *)(iVar7 + 0xc) = ~(byte)(1 << uVar14) & *(byte *)(iVar7 + 0xc);
            }
            else if (*(char *)(iVar7 + 0x3c) == '\x01') {
              bVar2 = *(byte *)(iVar7 + 0x38);
              iVar10 = r_emi_get_mem_addr_by_offset(0x400);
              *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar10) = 1;
              _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
              *(undefined1 *)(iVar7 + 0x3c) = 2;
            }
          }
          if (uVar14 != 0) break;
          uVar14 = 1;
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
      if (*(char *)(iVar7 + 0x3d) == '\x03') {
        iVar11 = r_sdk_config_get_opts_ext();
        if (*(char *)(iVar11 + 0x18) == '\0') {
          r_assert_err(0,"lld_scan.c",0xa29);
        }
        r_ble_log_internal_x1(0x404100c4,param_1);
        r_lld_scan_trunc_ind(param_1);
        *(undefined1 *)(iVar7 + 0x3d) = 0;
      }
      if ((uint)*(ushort *)(iVar7 + 0x30) << 1 <= (iVar10 - *(int *)(iVar7 + 0x28) & 0xfffffffU)) {
        bVar2 = rwip_priority;
        if (0xff < (uint)*(byte *)(iVar7 + 0x16) + (uint)rwip_priority) {
          r_assert_err(0,"lld_scan.c",0xa34);
        }
        *(int *)(iVar7 + 0x28) = iVar10;
        *(byte *)(iVar7 + 0x16) = bVar2 + *(char *)(iVar7 + 0x16);
      }
      if (*(char *)(iVar7 + 0x3e) == '\x01') {
        *(undefined1 *)(iVar7 + 0x3e) = 0;
        iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
        bVar2 = *(byte *)(iVar7 + 0x38);
        if (*(char *)(iVar7 + 0x3e) == '\x01') {
          r_sch_slice_bg_remove(0);
          *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar7 + 0x48);
          *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar7 + 0x4c);
          *(uint *)(iVar7 + 0x10) =
               ((uint)*(ushort *)(&lld_scan_max_aux_dur_tab + (uint)*(byte *)(iVar7 + 0x55) * 2) +
               *(int *)(iVar7 + 0x50)) * 2 + (uint)_sdk_cfg_priv_opts;
          bVar3 = DAT_0001507f;
          bVar13 = DAT_0001507e;
          if (DAT_0001507e < *(byte *)(iVar7 + 0x16)) {
            bVar13 = *(byte *)(iVar7 + 0x16);
          }
          *(byte *)(iVar7 + 0x16) = bVar13;
          *(ushort *)(iVar7 + 0x14) = bVar3 & 0xf | 0x2000;
          iVar11 = r_sch_arb_insert(iVar7);
          if (iVar11 == 0) {
            bVar3 = *(byte *)(iVar7 + 0x55);
            uVar14 = *(uint *)(iVar7 + 0x50);
            uVar16 = (uint)bVar3 << 4;
            if ((uVar16 & 0xffffffcf) != 0) {
              r_assert_err("lld_scan.c",0x1bf);
            }
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            iVar11 = (uint)bVar2 * 0x5a;
            uVar15 = *(ushort *)(iVar9 + iVar11 + 4);
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar9 + iVar11 + 4) = uVar15 & 0xffcf | (ushort)uVar16;
            uVar15 = *(ushort *)(&lld_scan_max_aux_dur_tab + (uint)bVar3 * 2);
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar11 + 0x20 + iVar9) =
                 (ushort)(((uint)uVar15 + uVar14 + 0x270) / 0x271) & 0xff;
            uVar15 = 0x672 - *(short *)(iVar7 + 0x36);
            if ((uVar15 & 0xf800) != 0) {
              r_assert_err(0,"lld_scan.c",0x6c0);
            }
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            uVar5 = *(ushort *)(iVar9 + iVar11 + 0x28);
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar9 + iVar11 + 0x28) = uVar15 | uVar5 & 0xf800;
            if (uVar14 < 0x4000) {
              iVar9 = r_emi_get_mem_addr_by_offset(0x400);
              *(short *)(iVar9 + iVar11 + 0x1a) = (short)(uVar14 + 1 >> 1);
            }
            else {
              iVar9 = r_emi_get_mem_addr_by_offset(0x400);
              *(ushort *)(iVar9 + iVar11 + 0x1a) =
                   (ushort)((uVar14 + 0x270) / 0x271) & 0xff | 0x8000;
            }
            uVar14 = (uint)*(byte *)(iVar7 + 0x54) << 10;
            if ((uVar14 & 0x30000) != 0) {
              r_assert_err(0,"lld_scan.c",0x635);
            }
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            uVar15 = *(ushort *)(iVar9 + iVar11 + 0x26);
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar9 + iVar11 + 0x26) = uVar15 & 0x3ff | (ushort)uVar14;
            if (*(char *)(iVar7 + 0x6f) != -1) {
              iVar9 = r_emi_get_mem_addr_by_offset(0x400);
              *(undefined2 *)(iVar11 + 0x14 + iVar9) = 0;
            }
            if ((*(char *)(iVar7 + 0x3d) == '\x03') && (*(char *)(iVar7 + 0x39) == '\x01')) {
              iVar9 = r_emi_get_mem_addr_by_offset(0x400);
              uVar15 = *(ushort *)(iVar9 + iVar11);
              iVar9 = r_emi_get_mem_addr_by_offset(0x400);
              *(ushort *)(iVar11 + iVar9) = uVar15 & 0xffe0 | 10;
            }
            *(undefined1 *)(iVar7 + 0x43) = 0;
            iVar11 = 1;
          }
          else {
            iVar11 = 0;
            if (*(char *)(iVar7 + 0x3d) == '\x03') {
              iVar11 = r_sdk_config_get_opts_ext();
              if (*(char *)(iVar11 + 0x18) == '\0') {
                r_assert_err(0,"lld_scan.c",0x96d);
              }
              r_ble_log_internal_x1(0x404100c0,param_1);
              r_lld_scan_trunc_ind(param_1);
              iVar11 = 0;
              *(undefined1 *)(iVar7 + 0x3e) = 0;
              *(undefined1 *)(iVar7 + 0x3d) = 0;
            }
          }
          uVar16 = *(uint *)(iVar7 + 4) * 0x271;
          uVar14 = *(int *)(iVar7 + 8) + uVar16;
          r_ble_log_internal_x3
                    (0x404100c1,
                     uVar14 >> 1 |
                     ((uint)(uVar14 < uVar16) +
                     (int)((ulonglong)*(uint *)(iVar7 + 4) * 0x271 >> 0x20)) * -0x80000000,
                     *(undefined4 *)(iVar7 + 0x10),
                     iVar11 << 8 |
                     (uint)*(byte *)(iVar7 + 0x3d) << 0x10 | (uint)*(byte *)(iVar7 + 0x16) << 0x18 |
                     param_1);
          if (iVar11 != 0) {
            return;
          }
        }
        if ((_lld_scan_env != 0) && (iVar7 = *(int *)(_lld_scan_env + param_1 * 4), iVar7 != 0)) {
          uVar12 = r_lld_read_clock();
          lld_scan_sched_optimize(iVar7,uVar12);
        }
        uVar6 = _rwip_priority;
        _rwip_priority = 0x9c4;
        r_lld_scan_try_sched_hack(param_1,iVar10,1);
        _rwip_priority = uVar6;
        if (_lld_scan_env != 0) {
          iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
          if ((iVar7 != 0) && (*(uint *)(iVar7 + 0x24) == (uint)*(ushort *)(iVar7 + 0x32))) {
            (&scan_anchor_point)[param_1] = *(undefined4 *)(iVar7 + 4);
          }
        }
        return;
      }
      iVar7 = r_sch_arb_insert(iVar7);
      if (iVar7 == 0) {
        return;
      }
      uVar12 = 0xa40;
    }
  }
  r_assert_err(0,"lld_scan.c",uVar12);
  return;
}

