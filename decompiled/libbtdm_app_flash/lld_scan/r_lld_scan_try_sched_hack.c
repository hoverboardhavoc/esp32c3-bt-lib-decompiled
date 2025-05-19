/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_try_sched_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_try_sched_hack(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iStack_34;
  
  iVar11 = _lld_scan_env;
  iVar5 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar2 = *(byte *)(iVar5 + 0x38);
  iVar9 = r_lld_read_clock();
  uVar12 = (iVar9 - param_2 & 0xfffffffU) + 1 >> 1;
  uVar7 = 0;
  if (lld_scan_evt_end_reason == 1) {
    lld_scan_evt_end_reason = 0;
    iVar10 = coex_schm_phase_end_ts_get();
    if ((iVar10 - iVar9 & 0xfffffffU) < 0x8000001) {
      iVar10 = coex_schm_phase_end_ts_get();
      uVar7 = iVar10 - iVar9 >> 1 & 0x7ffffff;
    }
    else {
      iVar10 = coex_schm_phase_end_ts_get();
      uVar7 = (int)-(iVar9 - iVar10 & 0xfffffffU) / 2;
    }
    if ((int)uVar7 < 0) {
      uVar7 = 0;
    }
  }
  if (uVar7 + uVar12 < *(uint *)(iVar5 + 0x24)) {
    *(uint *)(iVar5 + 0x24) = *(uint *)(iVar5 + 0x24) - (uVar7 + uVar12);
    *(uint *)(iVar5 + 4) = uVar7 * 2 + iVar9 & 0xffffffe;
  }
  else {
    r_sch_slice_bg_remove(0);
    if (_sch_slice_params == -1) {
      iVar10 = 0;
      if (uVar12 < *(uint *)(iVar5 + 0x24)) {
        iVar10 = *(uint *)(iVar5 + 0x24) - uVar12;
      }
      *(int *)(iVar5 + 0x24) = iVar10;
      *(uint *)(iVar5 + 4) =
           (((uint)*(ushort *)(iVar5 + 0x30) - (uint)*(ushort *)(iVar5 + 0x32)) + iVar10) * 2 +
           iVar9 & 0xffffffe;
      iStack_34 = 0;
      if (uVar7 != 0) {
        iVar9 = coex_schm_ble_scan_stop_interval_num_get(&iStack_34);
        *(uint *)(iVar5 + 4) =
             ((uint)*(ushort *)(iVar5 + 0x30) * iVar9 + iStack_34) * 2 + *(int *)(iVar5 + 4) &
             0xffffffe;
      }
      *(uint *)(iVar5 + 0x24) = (uint)*(ushort *)(iVar5 + 0x32) - iStack_34;
    }
    else {
      *(int *)(iVar5 + 4) = _sch_slice_params;
      *(uint *)(iVar5 + 0x24) = (uint)*(ushort *)(iVar5 + 0x32);
    }
    *(undefined4 *)(iVar5 + 8) = 0;
  }
  uVar7 = *(uint *)(iVar5 + 0x24);
  if (uVar7 < 2) {
    uVar7 = 2;
  }
  *(uint *)(iVar5 + 0x24) = uVar7;
  uVar12 = uVar7 * 0x4e2;
  if ((uint)_rwip_priority < uVar7 * 0x4e2) {
    uVar12 = (uint)_rwip_priority;
  }
  uVar7 = *(uint *)(iVar11 + 8);
  *(uint *)(iVar5 + 0x10) = uVar12;
  if ((uVar7 < 0x10000000) && ((*(int *)(iVar5 + 4) - uVar7 & 0xfffffff) < 0x7ffffff)) {
    uVar7 = 0;
    while( true ) {
      iVar5 = uVar7 * 4;
      iVar11 = *(int *)(_lld_scan_env + iVar5);
      if (iVar11 != 0) {
        iVar9 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar9 + 0x28) & 8) != 0) &&
           (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x40010002,(uint)*(byte *)(iVar11 + 0x3c) << 8 | uVar7,
                     *(undefined4 *)(iVar11 + 0x24));
        }
        r_lld_ext_scan_dynamic_pti_process_eco(iVar11,1);
        if (*(char *)(iVar11 + 0x3c) == '\0') {
          r_sch_arb_remove(iVar11,0);
          r_sch_slice_bg_remove(0);
          if (*(char *)(iVar11 + 0x3d) == '\x03') {
            iVar11 = r_sdk_config_get_opts_ext();
            if (*(char *)(iVar11 + 0x18) == '\0') {
              r_assert_err(0,"lld_scan.c",0x4aa);
            }
            r_lld_scan_trunc_ind(uVar7);
          }
          r_ke_free(*(undefined4 *)(_lld_scan_env + iVar5));
          iVar11 = _lld_scan_env;
          *(undefined4 *)(iVar5 + _lld_scan_env) = 0;
          *(byte *)(iVar11 + 0xc) = ~(byte)(1 << uVar7) & *(byte *)(iVar11 + 0xc);
        }
        else if (*(char *)(iVar11 + 0x3c) == '\x01') {
          bVar2 = *(byte *)(iVar11 + 0x38);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar5) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar11 + 0x3c) = 2;
        }
      }
      if (uVar7 != 0) break;
      uVar7 = 1;
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
  if (param_3 == 0) {
    *(undefined1 *)(iVar5 + 0x16) = rwip_priority;
    *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(iVar5 + 4);
  }
  bVar3 = *(byte *)(iVar5 + 0x3b);
  *(ushort *)(iVar5 + 0x14) = _rwip_priority >> 8 & 0xf | 0x6000;
  if (((uint)bVar3 << 2 & 0xfffffff3) != 0) {
    r_assert_err(0,"lld_scan.c",399);
  }
  if ((bVar3 & 0xfc) != 0) {
    r_assert_err(0,"lld_scan.c",400);
  }
  iVar10 = (uint)bVar2 * 0x5a;
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar9 + iVar10 + 4) = (ushort)((uint)bVar3 << 2) | (ushort)bVar3 | 0x1000;
  uVar4 = *(undefined2 *)(iVar5 + 0x24);
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar10 + 0x20 + iVar9) = uVar4;
  if ((byte)(*(char *)(iVar5 + 0x3a) - 10U) < 2) {
    if ((_DAT_60031048 >> 3 & 1) == 0) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar9 + iVar10 + 0x28) = 0x3e72;
    }
    else {
      iVar9 = r_emi_get_mem_addr_by_offset();
      *(undefined2 *)(iVar9 + iVar10 + 0x28) = 0;
    }
  }
  uVar7 = *(uint *)(iVar5 + 0x24);
  if (0x3fff < uVar7) {
    uVar7 = 0x3fff;
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar9 + iVar10 + 0x1a) = (ushort)uVar7 | 0x8000;
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar10 + 0x46 + iVar9) = 0;
  if ((*(byte *)(iVar11 + 0x14) & 2) != 0) {
    uVar4 = *(undefined2 *)(iVar11 + 0xe);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar10 + 6 + iVar9) = uVar4;
    uVar4 = *(undefined2 *)(iVar11 + 0x10);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar10 + 8 + iVar9) = uVar4;
    uVar4 = *(undefined2 *)(iVar11 + 0x12);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar10 + 10 + iVar9) = uVar4;
  }
  uVar7 = 0;
  if (_lld_scan_sync_env != 0) {
    uVar7 = (uint)(*(char *)(_lld_scan_sync_env + 1) != '\0');
  }
  *(char *)(iVar5 + 0x44) = (char)uVar7;
  bVar2 = *(byte *)(iVar11 + 0x15);
  uVar12 = *(byte *)(iVar11 + 0x14) >> 1 & 1;
  uVar6 = (ushort)uVar12;
  if (*(byte *)(iVar11 + 0x16) != 0) {
    uVar6 = 1;
  }
  uVar13 = (uint)*(byte *)(iVar11 + 0x16) << 6;
  if ((uVar13 & 0xffffffbf) != 0) {
    r_assert_err(0,"lld_scan.c",0x2ee);
  }
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar10 + 0x14 + iVar11) =
       (ushort)(uVar12 << 2) | (ushort)bVar2 << 8 | (ushort)uVar13 | (ushort)(uVar7 << 3) | uVar6;
  bVar2 = *(byte *)(iVar5 + 0x3a);
  if ((bVar2 & 0xe0) != 0) {
    r_assert_err(0,"lld_scan.c",0xa6);
  }
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uVar6 = *(ushort *)(iVar11 + iVar10);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar10 + iVar11) = uVar6 & 0xffe0 | (ushort)bVar2;
  iVar11 = r_sch_arb_insert(iVar5);
  if (iVar11 != 0) {
    r_assert_err(0,"lld_scan.c",0x3c6);
    return;
  }
  *(undefined1 *)(iVar5 + 0x43) = 0;
  *(undefined2 *)(iVar5 + 0x36) = 0;
  return;
}

