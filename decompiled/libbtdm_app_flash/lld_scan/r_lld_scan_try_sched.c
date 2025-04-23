/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_try_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_try_sched(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  ushort uVar13;
  uint uVar14;
  int aiStack_34 [3];
  
  iVar10 = _lld_scan_env;
  iVar5 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar2 = *(byte *)(iVar5 + 0x38);
  iVar8 = r_lld_read_clock();
  uVar14 = (iVar8 - param_2 & 0xfffffffU) + 1 >> 1;
  uVar6 = 0;
  if (lld_scan_evt_end_reason == 1) {
    lld_scan_evt_end_reason = 0;
    iVar9 = coex_schm_phase_end_ts_get();
    if ((iVar9 - iVar8 & 0xfffffffU) < 0x8000001) {
      iVar9 = coex_schm_phase_end_ts_get();
      uVar6 = iVar9 - iVar8 >> 1 & 0x7ffffff;
    }
    else {
      iVar9 = coex_schm_phase_end_ts_get();
      uVar6 = (int)-(iVar8 - iVar9 & 0xfffffffU) / 2;
    }
    uVar6 = uVar6 & (int)~uVar6 >> 0x1f;
  }
  if (uVar6 + uVar14 < *(uint *)(iVar5 + 0x24)) {
    uVar11 = *(uint *)(iVar5 + 0x24) - (uVar6 + uVar14);
    *(uint *)(iVar5 + 4) = uVar6 * 2 + iVar8 & 0xffffffe;
  }
  else {
    r_sch_slice_bg_remove(0);
    uVar11 = (uint)*(ushort *)(iVar5 + 0x32);
    if (_sch_slice_params == -1) {
      iVar9 = 0;
      if (uVar14 < *(uint *)(iVar5 + 0x24)) {
        iVar9 = *(uint *)(iVar5 + 0x24) - uVar14;
      }
      *(int *)(iVar5 + 0x24) = iVar9;
      aiStack_34[0] = 0;
      *(uint *)(iVar5 + 4) = ((*(ushort *)(iVar5 + 0x30) - uVar11) + iVar9) * 2 + iVar8 & 0xffffffe;
      if (uVar6 != 0) {
        iVar8 = coex_schm_ble_scan_stop_interval_num_get(aiStack_34);
        *(uint *)(iVar5 + 4) =
             ((uint)*(ushort *)(iVar5 + 0x30) * iVar8 + aiStack_34[0]) * 2 + *(int *)(iVar5 + 4) &
             0xffffffe;
      }
      uVar11 = (uint)*(ushort *)(iVar5 + 0x32) - aiStack_34[0];
    }
    else {
      *(int *)(iVar5 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar5 + 8) = 0;
  }
  if (uVar11 < 2) {
    uVar11 = 2;
  }
  *(uint *)(iVar5 + 0x24) = uVar11;
  uVar6 = uVar11 * 0x4e2;
  if ((uint)_rwip_priority < uVar11 * 0x4e2) {
    uVar6 = (uint)_rwip_priority;
  }
  uVar14 = *(uint *)(iVar10 + 8);
  *(uint *)(iVar5 + 0x10) = uVar6;
  if ((uVar14 < 0x10000000) && ((*(int *)(iVar5 + 4) - uVar14 & 0xfffffff) < 0x7ffffff)) {
    uVar6 = 0;
    do {
      iVar5 = uVar6 * 4;
      iVar10 = *(int *)(_lld_scan_env + iVar5);
      if (iVar10 != 0) {
        iVar8 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar8 + 0x28) & 8) != 0) &&
           (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x40010002,(uint)*(byte *)(iVar10 + 0x3c) << 8 | uVar6,
                     *(undefined4 *)(iVar10 + 0x24));
        }
        r_lld_ext_scan_dynamic_pti_process_eco(iVar10,1);
        if (*(char *)(iVar10 + 0x3c) == '\0') {
          r_sch_arb_remove(iVar10,0);
          r_sch_slice_bg_remove(0);
          if (*(char *)(iVar10 + 0x3d) == '\x03') {
            iVar10 = r_sdk_config_get_opts_ext();
            if (*(char *)(iVar10 + 0x18) == '\0') {
              r_assert_err(0,"lld_scan.c",0x4aa);
            }
            r_lld_scan_trunc_ind(uVar6);
          }
          r_ke_free(*(undefined4 *)(_lld_scan_env + iVar5));
          iVar10 = _lld_scan_env;
          *(undefined4 *)(iVar5 + _lld_scan_env) = 0;
          *(byte *)(iVar10 + 0xc) = ~(byte)(1 << uVar6) & *(byte *)(iVar10 + 0xc);
        }
        else if (*(char *)(iVar10 + 0x3c) == '\x01') {
          bVar2 = *(byte *)(iVar10 + 0x38);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar5) = 1;
          _DAT_60031000 = _DAT_60031000 | 0x1000000;
          *(undefined1 *)(iVar10 + 0x3c) = 2;
        }
      }
      bVar12 = uVar6 != 1;
      uVar6 = 1;
    } while (bVar12);
    if (*(char *)(_lld_scan_env + 0xc) == '\0') {
      puVar7 = (undefined1 *)r_ke_msg_alloc(0x206,0,0xff,2);
      uVar1 = *(undefined1 *)(_lld_scan_env + 0xd);
      *puVar7 = 0;
      puVar7[1] = uVar1;
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
  if ((bVar3 & 0xfc) == 0) {
    if (bVar3 < 4) goto _L357;
  }
  else {
    r_assert_err(0,"lld_scan.c",399);
  }
  r_assert_err(0,"lld_scan.c",400);
_L357:
  iVar8 = (uint)bVar2 * 0x5a;
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + 4 + iVar9) = (ushort)bVar3 | (ushort)((int)(short)(ushort)bVar3 << 2) | 0x1000
  ;
  uVar4 = *(undefined2 *)(iVar5 + 0x24);
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar8 + 0x20 + iVar9) = uVar4;
  if ((byte)(*(char *)(iVar5 + 0x3a) - 10U) < 2) {
    if ((_DAT_60031048 & 8) == 0) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar9 + iVar8 + 0x28) = 0x3e72;
    }
    else {
      iVar9 = r_emi_get_mem_addr_by_offset();
      *(undefined2 *)(iVar9 + iVar8 + 0x28) = 0;
    }
  }
  uVar6 = *(uint *)(iVar5 + 0x24);
  if (0x3fff < uVar6) {
    uVar6 = 0x3fff;
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar9 + iVar8 + 0x1a) = (ushort)uVar6 | 0x8000;
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar8 + 0x46 + iVar9) = 0;
  if ((*(byte *)(iVar10 + 0x14) & 2) != 0) {
    uVar4 = *(undefined2 *)(iVar10 + 0xe);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar8 + 6 + iVar9) = uVar4;
    uVar4 = *(undefined2 *)(iVar10 + 0x10);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar8 + 8 + iVar9) = uVar4;
    uVar4 = *(undefined2 *)(iVar10 + 0x12);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar8 + 10 + iVar9) = uVar4;
  }
  if (_lld_scan_sync_env == 0) {
    bVar12 = false;
    uVar6 = 0;
  }
  else {
    bVar12 = *(char *)(_lld_scan_sync_env + 1) != '\0';
    uVar6 = (uint)bVar12;
  }
  *(bool *)(iVar5 + 0x44) = bVar12;
  bVar2 = *(byte *)(iVar10 + 0x16);
  bVar3 = *(byte *)(iVar10 + 0x15);
  uVar14 = *(uint *)(iVar10 + 0x14) >> 1 & 1;
  uVar13 = (ushort)uVar14;
  if (bVar2 != 0) {
    if ((bVar2 & 0xfe) != 0) {
      r_assert_err(0,"lld_scan.c",0x2ee);
    }
    uVar13 = 1;
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + 0x14 + iVar10) =
       (ushort)bVar3 << 8 | (ushort)bVar2 << 6 | (ushort)(uVar14 << 2) | (ushort)(uVar6 << 3) |
       uVar13;
  bVar2 = *(byte *)(iVar5 + 0x3a);
  if (0x1f < bVar2) {
    r_assert_err(0,"lld_scan.c",0xa6);
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  uVar13 = *(ushort *)(iVar10 + iVar8);
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + iVar10) = (ushort)bVar2 | uVar13 & 0xffe0;
  iVar10 = r_sch_arb_insert(iVar5);
  if (iVar10 != 0) {
    r_assert_err(0,"lld_scan.c",0x3c6);
    return;
  }
  *(undefined1 *)(iVar5 + 0x43) = 0;
  *(undefined2 *)(iVar5 + 0x36) = 0;
  return;
}

