/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_try_sched
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
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  code *pcVar11;
  ushort uVar12;
  uint uVar13;
  int aiStack_34 [2];
  
  iVar8 = _lld_scan_env;
  iVar4 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(iVar4 + 0x38);
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  uVar13 = (iVar6 - param_2 & 0xfffffffU) + 1 >> 1;
  uVar5 = 0;
  if (lld_scan_evt_end_reason == 1) {
    lld_scan_evt_end_reason = 0;
    iVar7 = coex_schm_phase_end_ts_get();
    if ((iVar7 - iVar6 & 0xfffffffU) < 0x8000001) {
      iVar7 = coex_schm_phase_end_ts_get();
      uVar5 = iVar7 - iVar6 >> 1 & 0x7ffffff;
    }
    else {
      iVar7 = coex_schm_phase_end_ts_get();
      uVar5 = (int)-(iVar6 - iVar7 & 0xfffffffU) / 2;
    }
    uVar5 = uVar5 & (int)~uVar5 >> 0x1f;
  }
  if (uVar5 + uVar13 < *(uint *)(iVar4 + 0x24)) {
    uVar9 = *(uint *)(iVar4 + 0x24) - (uVar5 + uVar13);
    *(uint *)(iVar4 + 4) = uVar5 * 2 + iVar6 & 0xffffffe;
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x718))(0,*(code **)(_r_ip_funcs_p + 0x718));
    uVar9 = (uint)*(ushort *)(iVar4 + 0x32);
    if (_sch_slice_params == -1) {
      iVar7 = 0;
      if (uVar13 < *(uint *)(iVar4 + 0x24)) {
        iVar7 = *(uint *)(iVar4 + 0x24) - uVar13;
      }
      *(int *)(iVar4 + 0x24) = iVar7;
      aiStack_34[0] = 0;
      *(uint *)(iVar4 + 4) = ((*(ushort *)(iVar4 + 0x30) - uVar9) + iVar7) * 2 + iVar6 & 0xffffffe;
      if (uVar5 != 0) {
        iVar6 = coex_schm_ble_scan_stop_interval_num_get(aiStack_34);
        *(uint *)(iVar4 + 4) =
             ((uint)*(ushort *)(iVar4 + 0x30) * iVar6 + aiStack_34[0]) * 2 + *(int *)(iVar4 + 4) &
             0xffffffe;
      }
      uVar9 = (uint)*(ushort *)(iVar4 + 0x32) - aiStack_34[0];
    }
    else {
      *(int *)(iVar4 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar4 + 8) = 0;
  }
  if (uVar9 < 2) {
    uVar9 = 2;
  }
  *(uint *)(iVar4 + 0x24) = uVar9;
  uVar5 = uVar9 * 0x4e2;
  if ((uint)_coex_schm_ble_scan_stop_interval_num_get < uVar9 * 0x4e2) {
    uVar5 = (uint)_coex_schm_ble_scan_stop_interval_num_get;
  }
  uVar13 = *(uint *)(iVar8 + 8);
  *(uint *)(iVar4 + 0x10) = uVar5;
  if ((uVar13 < 0x10000000) && ((*(int *)(iVar4 + 4) - uVar13 & 0xfffffff) < 0x7ffffff)) {
                    /* WARNING: Could not recover jumptable at 0x00010908. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3e4))(*(code **)(_r_ip_funcs_p + 0x3e4));
    return;
  }
  if (param_3 == 0) {
    *(undefined1 *)(iVar4 + 0x16) = rwip_priority;
    *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(iVar4 + 4);
  }
  bVar2 = *(byte *)(iVar4 + 0x3b);
  *(ushort *)(iVar4 + 0x14) = DAT_00015031 & 0xf | 0x6000;
  if ((bVar2 & 0xfc) == 0) {
    if (bVar2 < 4) goto _L144;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",399,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",400,*(code **)(_r_plf_funcs_p + 8));
_L144:
  iVar7 = (uint)bVar1 * 0x5a;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar7 + 4 + iVar6) = (ushort)bVar2 | (ushort)((int)(short)(ushort)bVar2 << 2) | 0x1000
  ;
  uVar3 = *(undefined2 *)(iVar4 + 0x24);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar7 + 0x20 + iVar6) = uVar3;
  if ((byte)(*(char *)(iVar4 + 0x3a) - 10U) < 2) {
    if ((_DAT_60031048 & 8) == 0) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
      *(undefined2 *)(iVar6 + iVar7 + 0x28) = 0x3e72;
    }
    else {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
      *(undefined2 *)(iVar6 + iVar7 + 0x28) = 0;
    }
  }
  uVar5 = *(uint *)(iVar4 + 0x24);
  if (0x3fff < uVar5) {
    uVar5 = 0x3fff;
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar7 + 0x1a) = (ushort)uVar5 | 0x8000;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar7 + 0x46 + iVar6) = 0;
  if ((*(byte *)(iVar8 + 0x14) & 2) != 0) {
    uVar3 = *(undefined2 *)(iVar8 + 0xe);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar7 + 6 + iVar6) = uVar3;
    uVar3 = *(undefined2 *)(iVar8 + 0x10);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar7 + 8 + iVar6) = uVar3;
    uVar3 = *(undefined2 *)(iVar8 + 0x12);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar7 + 10 + iVar6) = uVar3;
  }
  if (_lld_scan_sync_env == 0) {
    bVar10 = false;
    uVar5 = 0;
  }
  else {
    bVar10 = *(char *)(_lld_scan_sync_env + 1) != '\0';
    uVar5 = (uint)bVar10;
  }
  *(bool *)(iVar4 + 0x44) = bVar10;
  bVar1 = *(byte *)(iVar8 + 0x16);
  bVar2 = *(byte *)(iVar8 + 0x15);
  uVar13 = *(uint *)(iVar8 + 0x14) >> 1 & 1;
  uVar12 = (ushort)uVar13;
  if (bVar1 != 0) {
    if ((bVar1 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x2ee,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar12 = 1;
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar7 + 0x14 + iVar8) =
       (ushort)bVar2 << 8 | (ushort)bVar1 << 6 | (ushort)(uVar13 << 2) | (ushort)(uVar5 << 3) |
       uVar12;
  bVar1 = *(byte *)(iVar4 + 0x3a);
  if (0x1f < bVar1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xa6,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar12 = *(ushort *)(iVar8 + iVar7);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar11 = *(code **)(_r_ip_funcs_p + 0x6b0);
  *(ushort *)(iVar7 + iVar8) = (ushort)bVar1 | uVar12 & 0xffe0;
  iVar8 = (*pcVar11)(iVar4,pcVar11);
  if (iVar8 == 0) {
    *(undefined1 *)(iVar4 + 0x43) = 0;
    *(undefined2 *)(iVar4 + 0x36) = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010ca4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x3c6,*(code **)(_r_plf_funcs_p + 8));
  return;
}

