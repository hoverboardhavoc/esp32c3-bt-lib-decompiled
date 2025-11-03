/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  
  iVar3 = *(int *)(_lld_init_env + param_1 * 4);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  bVar1 = *(byte *)(iVar3 + 0x52);
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x83c))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x83c));
  if (iVar5 != 0) {
    return;
  }
  if (*(char *)(iVar3 + 0x3d) == '\x01') {
    (**(code **)(_r_ip_funcs_p + 0x718))(1,*(code **)(_r_ip_funcs_p + 0x718));
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 0x40);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x44);
    *(uint *)(iVar3 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar3 + 0x4d) * 2) +
         *(int *)(iVar3 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar8 = DAT_0001301e;
    if (DAT_0001301e < *(byte *)(iVar3 + 0x16)) {
      bVar8 = *(byte *)(iVar3 + 0x16);
    }
    *(byte *)(iVar3 + 0x16) = bVar8;
    *(ushort *)(iVar3 + 0x14) = DAT_0001301f & 0xf | 0x2000;
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar3,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar5 != 0) {
      *(undefined1 *)(iVar3 + 0x3d) = 0;
      goto _L40;
    }
    uVar10 = (uint)*(byte *)(iVar3 + 0x4d);
    uVar9 = *(uint *)(iVar3 + 0x48);
    *(char *)(iVar3 + 0x3e) = (1 < uVar10) + '\x02';
    if ((uVar10 << 4 & 0xffffffcf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x1bf,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = (uint)bVar1 * 0x5a;
    uVar2 = *(ushort *)(iVar4 + iVar5 + 4);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar5 + 4) = uVar2 & 0xffcf | (ushort)(uVar10 << 4);
    uVar2 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar10 * 2);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + 0x20 + iVar4) = (ushort)(((uint)uVar2 + uVar9 + 0x270) / 0x271) & 0xff;
    if (uVar9 < 0x4000) {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar4 + iVar5 + 0x1a) = (short)(uVar9 + 1 >> 1);
    }
    else {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar5 + 0x1a) = (ushort)((uVar9 + 0x270) / 0x271) & 0xff | 0x8000;
    }
    uVar9 = (uint)*(byte *)(iVar3 + 0x4c) << 10;
    if ((uVar9 & 0x30000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x635,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar4 + iVar5 + 0x26);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar5 + 0x26) = uVar2 & 0x3ff | (ushort)uVar9;
  }
  else {
_L40:
    uVar9 = (iVar4 - param_2 & 0xfffffffU) + 1 >> 1;
    if (uVar9 < *(uint *)(iVar3 + 0x24)) {
      uVar9 = *(uint *)(iVar3 + 0x24) - uVar9;
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x718))(1,*(code **)(_r_ip_funcs_p + 0x718));
      uVar9 = (uint)*(ushort *)(iVar3 + 0x2e);
      uVar10 = _sch_slice_params;
      if (_sch_slice_params == 0xffffffff) {
        uVar10 = (*(ushort *)(iVar3 + 0x2c) - uVar9) * 2 + iVar4 & 0xffffffc;
      }
      *(uint *)(iVar3 + 4) = uVar10;
      *(undefined4 *)(iVar3 + 8) = 0;
    }
    uVar7 = (uint)_p_lld_env;
    *(uint *)(iVar3 + 0x24) = uVar9;
    uVar10 = uVar9 * 0x4e2;
    if (uVar7 < uVar9 * 0x4e2) {
      uVar10 = uVar7;
    }
    *(uint *)(iVar3 + 0x10) = uVar10;
    if (param_3 == 0) {
      *(undefined1 *)(iVar3 + 0x16) = DAT_00013022;
      *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + 4);
    }
    iVar4 = _r_plf_funcs_p;
    *(ushort *)(iVar3 + 0x14) = DAT_00013023 & 0xf | 0x6000;
    *(undefined1 *)(iVar3 + 0x3e) = 1;
    iVar4 = (**(code **)(iVar4 + 0xbc))(0x400,*(code **)(iVar4 + 0xbc));
    iVar5 = (uint)bVar1 * 0x5a;
    *(short *)(iVar5 + 0x20 + iVar4) = (short)uVar9;
    uVar9 = *(uint *)(iVar3 + 0x24);
    if ((uVar9 >> 0xf & 1) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x4ab,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + 0x1a + iVar4) = (ushort)uVar9 | 0x8000;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = _r_ip_funcs_p;
    *(undefined2 *)(iVar5 + 0x46 + iVar6) = 0;
    iVar4 = (**(code **)(iVar4 + 0x6b0))(iVar3,*(code **)(iVar4 + 0x6b0));
    if (iVar4 != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x280,*(code **)(_r_plf_funcs_p + 8));
      goto _L48;
    }
  }
  *(undefined1 *)(iVar3 + 0x50) = 0;
_L48:
                    /* WARNING: Could not recover jumptable at 0x00010598. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x83c))(0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x83c));
  return;
}

