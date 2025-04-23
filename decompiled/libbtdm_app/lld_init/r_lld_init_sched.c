/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_sched(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  ushort uVar9;
  uint uVar10;
  
  iVar2 = *(int *)(_lld_init_env + param_1 * 4);
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  bVar1 = *(byte *)(iVar2 + 0x52);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x83c))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x83c));
  if (iVar4 != 0) {
    return;
  }
  if (*(char *)(iVar2 + 0x3d) == '\x01') {
    (**(code **)(_r_ip_funcs_p + 0x718))(*(code **)(_r_ip_funcs_p + 0x718));
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar2 + 0x40);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0x44);
    *(uint *)(iVar2 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar2 + 0x4d) * 2) +
         *(int *)(iVar2 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar8 = DAT_0001301e;
    if (DAT_0001301e < *(byte *)(iVar2 + 0x16)) {
      bVar8 = *(byte *)(iVar2 + 0x16);
    }
    *(byte *)(iVar2 + 0x16) = bVar8;
    *(ushort *)(iVar2 + 0x14) = DAT_0001301f & 0xf | 0x2000;
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar2,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar4 != 0) {
      *(undefined1 *)(iVar2 + 0x3d) = 0;
      goto _L40;
    }
    bVar8 = *(byte *)(iVar2 + 0x4d);
    uVar10 = *(uint *)(iVar2 + 0x48);
    *(char *)(iVar2 + 0x3e) = (1 < bVar8) + '\x02';
    if ((bVar8 & 0xfc) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x1bf,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = (uint)bVar1 * 0x5a;
    uVar9 = *(ushort *)(iVar3 + iVar4 + 4);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar3 + iVar4 + 4) = uVar9 & 0xffcf | (ushort)bVar8 << 4;
    uVar9 = *(ushort *)(&lld_init_max_aux_dur_tab + (uint)bVar8 * 2);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + 0x20 + iVar3) = (ushort)(((uint)uVar9 + uVar10 + 0x270) / 0x271) & 0xff;
    if (uVar10 < 0x4000) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
      uVar9 = (ushort)(uVar10 + 1 >> 1);
    }
    else {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
      uVar9 = (ushort)((uVar10 + 0x270) / 0x271) & 0xff | 0x8000;
    }
    *(ushort *)(iVar3 + iVar4 + 0x1a) = uVar9;
    bVar1 = *(byte *)(iVar2 + 0x4c);
    if ((bVar1 & 0xc0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x635,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar9 = *(ushort *)(iVar3 + iVar4 + 0x26);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar3 + iVar4 + 0x26) = uVar9 & 0x3ff | (ushort)bVar1 << 10;
  }
  else {
_L40:
    uVar10 = (iVar3 - param_2 & 0xfffffffU) + 1 >> 1;
    if (uVar10 < *(uint *)(iVar2 + 0x24)) {
      uVar10 = *(uint *)(iVar2 + 0x24) - uVar10;
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x718))(1,*(code **)(_r_ip_funcs_p + 0x718));
      uVar10 = (uint)*(ushort *)(iVar2 + 0x2e);
      uVar7 = _sch_slice_params;
      if (_sch_slice_params == 0xffffffff) {
        uVar7 = (*(ushort *)(iVar2 + 0x2c) - uVar10) * 2 + iVar3 & 0xffffffc;
      }
      *(uint *)(iVar2 + 4) = uVar7;
      *(undefined4 *)(iVar2 + 8) = 0;
    }
    uVar6 = (uint)_p_lld_env;
    *(uint *)(iVar2 + 0x24) = uVar10;
    uVar7 = uVar10 * 0x4e2;
    if (uVar6 < uVar10 * 0x4e2) {
      uVar7 = uVar6;
    }
    *(uint *)(iVar2 + 0x10) = uVar7;
    if (param_3 == 0) {
      *(undefined1 *)(iVar2 + 0x16) = DAT_00013022;
      *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar2 + 4);
    }
    iVar3 = _r_plf_funcs_p;
    *(ushort *)(iVar2 + 0x14) = DAT_00013023 & 0xf | 0x6000;
    *(undefined1 *)(iVar2 + 0x3e) = 1;
    iVar3 = (**(code **)(iVar3 + 0xbc))(0x400,*(code **)(iVar3 + 0xbc));
    iVar4 = (uint)bVar1 * 0x5a;
    *(short *)(iVar4 + 0x20 + iVar3) = (short)uVar10;
    iVar3 = *(int *)(iVar2 + 0x24);
    if (iVar3 << 0x10 < 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x4ab,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + 0x1a + iVar5) = (ushort)iVar3 | 0x8000;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar3 = _r_ip_funcs_p;
    *(undefined2 *)(iVar4 + 0x46 + iVar5) = 0;
    iVar3 = (**(code **)(iVar3 + 0x6b0))(iVar2,*(code **)(iVar3 + 0x6b0));
    if (iVar3 != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27b,*(code **)(_r_plf_funcs_p + 8));
      goto _L48;
    }
  }
  *(undefined1 *)(iVar2 + 0x50) = 0;
_L48:
                    /* WARNING: Could not recover jumptable at 0x00010564. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x83c))(0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x83c));
  return;
}

