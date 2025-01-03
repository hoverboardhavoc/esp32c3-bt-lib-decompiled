/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  ushort uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  uint uVar12;
  uint uVar13;
  int aiStack_34 [2];
  
  iVar10 = _lld_scan_env;
  iVar4 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(iVar4 + 0x38);
  iVar7 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  uVar12 = (iVar7 - param_2 & 0xfffffffU) + 1 >> 1;
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
  if (uVar6 + uVar12 < *(uint *)(iVar4 + 0x24)) {
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) - (uVar6 + uVar12);
    *(uint *)(iVar4 + 4) = iVar7 + uVar6 * 2 & 0xffffffe;
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x718))(0,*(code **)(_r_ip_funcs_p + 0x718));
    if (_sch_slice_params == -1) {
      iVar8 = 0;
      if (uVar12 < *(uint *)(iVar4 + 0x24)) {
        iVar8 = *(uint *)(iVar4 + 0x24) - uVar12;
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
  uVar12 = uVar6 * 0x4e2;
  if ((uint)_coex_schm_ble_scan_stop_interval_num_get < uVar6 * 0x4e2) {
    uVar12 = (uint)_coex_schm_ble_scan_stop_interval_num_get;
  }
  uVar6 = *(uint *)(iVar10 + 8);
  *(uint *)(iVar4 + 0x10) = uVar12;
  if ((uVar6 < 0x10000000) && ((*(int *)(iVar4 + 4) - uVar6 & 0xfffffff) < 0x7ffffff)) {
    (**(code **)(_r_ip_funcs_p + 0x3e4))(*(code **)(_r_ip_funcs_p + 0x3e4));
  }
  else {
    if (param_3 == 0) {
      *(undefined1 *)(iVar4 + 0x16) = rwip_priority;
      *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(iVar4 + 4);
    }
    bVar2 = *(byte *)(iVar4 + 0x3b);
    *(ushort *)(iVar4 + 0x14) = DAT_00015031 & 0xf | 0x6000;
    if (((uint)bVar2 << 2 & 0xfffffff3) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",399,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar2 & 0xfc) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",400,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar8 = (uint)bVar1 * 0x5a;
    *(ushort *)(iVar7 + iVar8 + 4) = (ushort)((uint)bVar2 << 2) | (ushort)bVar2 | 0x1000;
    uVar3 = *(undefined2 *)(iVar4 + 0x24);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar7 + iVar8 + 0x20) = uVar3;
    if ((byte)(*(char *)(iVar4 + 0x3a) - 10U) < 2) {
      if ((_DAT_60031048 >> 3 & 1) == 0) {
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
        *(undefined2 *)(iVar7 + iVar8 + 0x28) = 0x3e72;
      }
      else {
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
        *(undefined2 *)(iVar7 + iVar8 + 0x28) = 0;
      }
    }
    uVar6 = *(uint *)(iVar4 + 0x24);
    if (0x3fff < uVar6) {
      uVar6 = 0x3fff;
    }
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = _r_plf_funcs_p;
    *(ushort *)(iVar9 + iVar8 + 0x1a) = (ushort)uVar6 | 0x8000;
    iVar7 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
    *(undefined2 *)(iVar7 + iVar8 + 0x46) = 0;
    if ((*(byte *)(iVar10 + 0x14) & 2) != 0) {
      uVar3 = *(undefined2 *)(iVar10 + 0xe);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar8 + 6) = uVar3;
      uVar3 = *(undefined2 *)(iVar10 + 0x10);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar8 + 8) = uVar3;
      uVar3 = *(undefined2 *)(iVar10 + 0x12);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar8 + 10) = uVar3;
    }
    uVar6 = 0;
    if (_lld_scan_sync_env != 0) {
      uVar6 = (uint)(*(char *)(_lld_scan_sync_env + 1) != '\0');
    }
    *(char *)(iVar4 + 0x44) = (char)uVar6;
    bVar1 = *(byte *)(iVar10 + 0x15);
    uVar12 = *(byte *)(iVar10 + 0x14) >> 1 & 1;
    uVar5 = (ushort)uVar12;
    if (*(byte *)(iVar10 + 0x16) != 0) {
      uVar5 = 1;
    }
    uVar13 = (uint)*(byte *)(iVar10 + 0x16) << 6;
    if ((uVar13 & 0xffffffbf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x2ee,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar10 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar10 + iVar8 + 0x14) =
         (ushort)(uVar12 << 2) | (ushort)bVar1 << 8 | (ushort)uVar13 | (ushort)(uVar6 << 3) | uVar5;
    bVar1 = *(byte *)(iVar4 + 0x3a);
    if ((bVar1 & 0xe0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xa6,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar10 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar5 = *(ushort *)(iVar10 + iVar8);
    iVar10 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar11 = *(code **)(_r_ip_funcs_p + 0x6b0);
    *(ushort *)(iVar10 + iVar8) = uVar5 & 0xffe0 | (ushort)bVar1;
    iVar10 = (*pcVar11)(iVar4,pcVar11);
    if (iVar10 == 0) {
      *(undefined1 *)(iVar4 + 0x43) = 0;
      *(undefined2 *)(iVar4 + 0x36) = 0;
    }
    else {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x3af,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  return;
}

