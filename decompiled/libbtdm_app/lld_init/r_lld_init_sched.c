/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  byte bVar6;
  code *pcVar7;
  int iVar8;
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
    bVar6 = DAT_0001301e;
    if (DAT_0001301e < *(byte *)(iVar3 + 0x16)) {
      bVar6 = *(byte *)(iVar3 + 0x16);
    }
    *(byte *)(iVar3 + 0x16) = bVar6;
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
      (**(code **)(_r_plf_funcs_p + 8))("lld_init.c",0x1bf,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = (uint)bVar1 * 0x5a;
    uVar2 = *(ushort *)(iVar4 + iVar5 + 4);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar5 + 4) = uVar2 & 0xffcf | (ushort)(uVar10 << 4);
    uVar2 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar10 * 2);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar5 + 0x20) = (ushort)(((uint)uVar2 + uVar9 + 0x270) / 0x271) & 0xff;
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
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x635,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar4 + iVar5 + 0x26);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + 0x26 + iVar4) = uVar2 & 0x3ff | (ushort)uVar9;
  }
  else {
_L40:
    uVar9 = (iVar4 - param_2 & 0xfffffffU) + 1 >> 1;
    if (uVar9 < *(uint *)(iVar3 + 0x24)) {
      *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) - uVar9;
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x718))(1,*(code **)(_r_ip_funcs_p + 0x718));
      if (_sch_slice_params == -1) {
        *(uint *)(iVar3 + 4) =
             iVar4 + ((uint)*(ushort *)(iVar3 + 0x2c) - (uint)*(ushort *)(iVar3 + 0x2e)) * 2 &
             0xffffffc;
      }
      else {
        *(int *)(iVar3 + 4) = _sch_slice_params;
      }
      *(undefined4 *)(iVar3 + 8) = 0;
      *(uint *)(iVar3 + 0x24) = (uint)*(ushort *)(iVar3 + 0x2e);
    }
    iVar4 = *(int *)(iVar3 + 0x24);
    uVar9 = iVar4 * 0x4e2;
    if (_p_lld_env < uVar9) {
      uVar9 = (uint)_p_lld_env;
    }
    *(uint *)(iVar3 + 0x10) = uVar9;
    if (param_3 == 0) {
      *(undefined1 *)(iVar3 + 0x16) = DAT_00013022;
      *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + 4);
    }
    *(ushort *)(iVar3 + 0x14) = DAT_00013023 & 0xf | 0x6000;
    *(undefined1 *)(iVar3 + 0x3e) = 1;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar8 = (uint)bVar1 * 0x5a;
    *(short *)(iVar5 + iVar8 + 0x20) = (short)iVar4;
    iVar4 = *(int *)(iVar3 + 0x24);
    if (iVar4 << 0x10 < 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x4ab,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar5 + iVar8 + 0x1a) = (ushort)iVar4 | 0x8000;
    iVar4 = (*pcVar7)(0x400,pcVar7);
    pcVar7 = *(code **)(_r_ip_funcs_p + 0x6b0);
    *(undefined2 *)(iVar8 + 0x46 + iVar4) = 0;
    iVar4 = (*pcVar7)(iVar3,pcVar7);
    if (iVar4 != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x278,*(code **)(_r_plf_funcs_p + 8));
      goto _L48;
    }
  }
  *(undefined1 *)(iVar3 + 0x50) = 0;
_L48:
                    /* WARNING: Could not recover jumptable at 0x00010596. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x83c))(0,param_1,param_2,param_3);
  return;
}

