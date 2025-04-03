/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_try_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_try_sched(int param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int aiStack_34 [3];
  
  iVar9 = _lld_scan_env;
  iVar4 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(iVar4 + 0x38);
  iVar7 = r_lld_read_clock();
  uVar10 = (iVar7 - param_2 & 0xfffffffU) + 1 >> 1;
  uVar6 = 0;
  if (_LANCHOR2 == 1) {
    _LANCHOR2 = 0;
    iVar8 = coex_schm_phase_end_ts_get();
    if ((iVar8 - iVar7 & 0xfffffffU) < 0x8000001) {
      iVar8 = coex_schm_phase_end_ts_get();
      uVar6 = iVar8 - iVar7 >> 1 & 0x7ffffff;
    }
    else {
      iVar8 = coex_schm_phase_end_ts_get();
      uVar6 = (int)-(iVar7 - iVar8 & 0xfffffffU) / 2;
    }
    if ((int)uVar6 < 0) {
      uVar6 = 0;
    }
  }
  if (uVar6 + uVar10 < *(uint *)(iVar4 + 0x24)) {
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) - (uVar6 + uVar10);
    *(uint *)(iVar4 + 4) = iVar7 + uVar6 * 2 & 0xffffffe;
  }
  else {
    r_sch_slice_bg_remove(0);
    if (_sch_slice_params == -1) {
      iVar8 = 0;
      if (uVar10 < *(uint *)(iVar4 + 0x24)) {
        iVar8 = *(uint *)(iVar4 + 0x24) - uVar10;
      }
      *(int *)(iVar4 + 0x24) = iVar8;
      aiStack_34[0] = 0;
      *(uint *)(iVar4 + 4) =
           (((uint)*(ushort *)(iVar4 + 0x30) - (uint)*(ushort *)(iVar4 + 0x32)) + iVar8) * 2 + iVar7
           & 0xffffffe;
      if (uVar6 != 0) {
        iVar7 = coex_schm_ble_scan_stop_interval_num_get(aiStack_34);
        *(uint *)(iVar4 + 4) =
             ((uint)*(ushort *)(iVar4 + 0x30) * iVar7 + aiStack_34[0]) * 2 + *(int *)(iVar4 + 4) &
             0xffffffe;
      }
      *(uint *)(iVar4 + 0x24) = (uint)*(ushort *)(iVar4 + 0x32) - aiStack_34[0];
    }
    else {
      *(int *)(iVar4 + 4) = _sch_slice_params;
      *(uint *)(iVar4 + 0x24) = (uint)*(ushort *)(iVar4 + 0x32);
    }
    *(undefined4 *)(iVar4 + 8) = 0;
  }
  uVar6 = *(uint *)(iVar4 + 0x24);
  if (uVar6 < 2) {
    uVar6 = 2;
  }
  *(uint *)(iVar4 + 0x24) = uVar6;
  uVar10 = uVar6 * 0x4e2;
  if ((uint)_rwip_priority < uVar6 * 0x4e2) {
    uVar10 = (uint)_rwip_priority;
  }
  uVar6 = *(uint *)(iVar9 + 8);
  *(uint *)(iVar4 + 0x10) = uVar10;
  if ((uVar6 < 0x10000000) && ((*(int *)(iVar4 + 4) - uVar6 & 0xfffffff) < 0x7ffffff)) {
    r_lld_scan_end();
  }
  else {
    if (param_3 == 0) {
      *(undefined1 *)(iVar4 + 0x16) = rwip_priority;
      *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(iVar4 + 4);
    }
    bVar2 = *(byte *)(iVar4 + 0x3b);
    *(ushort *)(iVar4 + 0x14) = _rwip_priority >> 8 & 0xf | 0x6000;
    if (((uint)bVar2 << 2 & 0xfffffff3) != 0) {
      r_assert_err(0,"lld_scan.c",399);
    }
    if ((bVar2 & 0xfc) != 0) {
      r_assert_err(0,"lld_scan.c",400);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    iVar8 = (uint)bVar1 * 0x5a;
    *(ushort *)(iVar7 + iVar8 + 4) = (ushort)((uint)bVar2 << 2) | (ushort)bVar2 | 0x1000;
    uVar3 = *(undefined2 *)(iVar4 + 0x24);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + iVar8 + 0x20) = uVar3;
    if ((byte)(*(char *)(iVar4 + 0x3a) - 10U) < 2) {
      if ((_DAT_60031048 >> 3 & 1) == 0) {
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar7 + iVar8 + 0x28) = 0x3e72;
      }
      else {
        iVar7 = r_emi_get_mem_addr_by_offset();
        *(undefined2 *)(iVar7 + iVar8 + 0x28) = 0;
      }
    }
    uVar6 = *(uint *)(iVar4 + 0x24);
    if (0x3fff < uVar6) {
      uVar6 = 0x3fff;
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar7 + iVar8 + 0x1a) = (ushort)uVar6 | 0x8000;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + iVar8 + 0x46) = 0;
    if ((*(byte *)(iVar9 + 0x14) & 2) != 0) {
      uVar3 = *(undefined2 *)(iVar9 + 0xe);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar8 + 6) = uVar3;
      uVar3 = *(undefined2 *)(iVar9 + 0x10);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar8 + 8) = uVar3;
      uVar3 = *(undefined2 *)(iVar9 + 0x12);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar8 + 10) = uVar3;
    }
    uVar6 = 0;
    if (_lld_scan_sync_env != 0) {
      uVar6 = (uint)(*(char *)(_lld_scan_sync_env + 1) != '\0');
    }
    *(char *)(iVar4 + 0x44) = (char)uVar6;
    bVar1 = *(byte *)(iVar9 + 0x15);
    uVar10 = *(byte *)(iVar9 + 0x14) >> 1 & 1;
    uVar5 = (ushort)uVar10;
    if (*(byte *)(iVar9 + 0x16) != 0) {
      uVar5 = 1;
    }
    uVar11 = (uint)*(byte *)(iVar9 + 0x16) << 6;
    if ((uVar11 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_scan.c",0x2ee);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar9 + iVar8 + 0x14) =
         (ushort)(uVar10 << 2) | (ushort)bVar1 << 8 | (ushort)uVar11 | (ushort)(uVar6 << 3) | uVar5;
    bVar1 = *(byte *)(iVar4 + 0x3a);
    if ((bVar1 & 0xe0) != 0) {
      r_assert_err(0,"lld_scan.c",0xa6);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = *(ushort *)(iVar9 + iVar8);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar9 + iVar8) = uVar5 & 0xffe0 | (ushort)bVar1;
    iVar9 = r_sch_arb_insert(iVar4);
    if (iVar9 == 0) {
      *(undefined1 *)(iVar4 + 0x43) = 0;
      *(undefined2 *)(iVar4 + 0x36) = 0;
    }
    else {
      r_assert_err(0,"lld_scan.c",0x3c6);
    }
  }
  return;
}

