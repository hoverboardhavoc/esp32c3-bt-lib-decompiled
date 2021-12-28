/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
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
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  code *pcVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  
  iVar4 = *(int *)(lld_init_env + param_1 * 4);
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  uVar10 = (iVar5 - param_2 & 0xfffffffU) + 1 >> 1;
  bVar1 = *(byte *)(iVar4 + 0x52);
  if (*(char *)(iVar4 + 0x3d) == '\x01') {
    (**(code **)(_r_ip_funcs_p + 0x718))(1,*(code **)(_r_ip_funcs_p + 0x718));
    *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 0x40);
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0x44);
    *(uint *)(iVar4 + 0x10) =
         ((uint)*(ushort *)((int)&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar4 + 0x4d) * 2) +
         *(int *)(iVar4 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar7 = DAT_0001300e;
    if (DAT_0001300e < *(byte *)(iVar4 + 0x16)) {
      bVar7 = *(byte *)(iVar4 + 0x16);
    }
    *(byte *)(iVar4 + 0x16) = bVar7;
    *(ushort *)(iVar4 + 0x14) = DAT_0001300f & 0xf | 0x2000;
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar4,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar6 == 0) {
      uVar11 = (uint)*(byte *)(iVar4 + 0x4d);
      uVar10 = *(uint *)(iVar4 + 0x48);
      *(char *)(iVar4 + 0x3e) = (1 < uVar11) + '\x02';
      if ((uVar11 << 4 & 0xffffffcf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))("lld_init.c",0x1bf,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = (uint)bVar1 * 0x5a;
      uVar2 = *(ushort *)(iVar5 + iVar6 + 4);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)((int)&lld_init_max_aux_dur_tab + uVar11 * 2);
      *(ushort *)(iVar5 + iVar6 + 4) = uVar2 & 0xffcf | (ushort)(uVar11 << 4);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar6 + 0x20) = (ushort)(((uint)uVar3 + uVar10 + 0x270) / 0x271) & 0xff;
      if (uVar10 < 0x4000) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar5 + iVar6 + 0x1a) = (short)(uVar10 + 1 >> 1);
      }
      else {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + iVar6 + 0x1a) = (ushort)((uVar10 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar10 = (uint)*(byte *)(iVar4 + 0x4c) << 10;
      if ((uVar10 & 0x30000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x635,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar5 + iVar6 + 0x26);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + 0x26 + iVar5) = uVar2 & 0x3ff | (ushort)uVar10;
      goto _L193;
    }
    *(undefined1 *)(iVar4 + 0x3d) = 0;
  }
  if (uVar10 < *(uint *)(iVar4 + 0x24)) {
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) - uVar10;
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x718))(1,*(code **)(_r_ip_funcs_p + 0x718));
    if (_sch_slice_params == -1) {
      *(uint *)(iVar4 + 4) =
           ((uint)*(ushort *)(iVar4 + 0x2c) - (uint)*(ushort *)(iVar4 + 0x2e)) * 2 + iVar5 &
           0xffffffc;
    }
    else {
      *(int *)(iVar4 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar4 + 8) = 0;
    *(uint *)(iVar4 + 0x24) = (uint)*(ushort *)(iVar4 + 0x2e);
  }
  iVar5 = *(int *)(iVar4 + 0x24);
  uVar10 = iVar5 * 0x4e2;
  if (_rwip_coex_cfg < uVar10) {
    uVar10 = (uint)_rwip_coex_cfg;
  }
  *(uint *)(iVar4 + 0x10) = uVar10;
  if (param_3 == 0) {
    *(undefined1 *)(iVar4 + 0x16) = DAT_00013012;
    *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(iVar4 + 4);
  }
  *(ushort *)(iVar4 + 0x14) = DAT_00013013 & 0xf | 0x6000;
  *(undefined1 *)(iVar4 + 0x3e) = 1;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar9 = (uint)bVar1 * 0x5a;
  *(short *)(iVar6 + iVar9 + 0x20) = (short)iVar5;
  iVar5 = *(int *)(iVar4 + 0x24);
  if (iVar5 << 0x10 < 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x4ab,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar8 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar6 + iVar9 + 0x1a) = (ushort)iVar5 | 0x8000;
  iVar5 = (*pcVar8)(0x400,pcVar8);
  pcVar8 = *(code **)(_r_ip_funcs_p + 0x6b0);
  *(undefined2 *)(iVar9 + 0x46 + iVar5) = 0;
  iVar5 = (*pcVar8)(iVar4,pcVar8);
  if (iVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001195c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x244);
    return;
  }
_L193:
  *(undefined1 *)(iVar4 + 0x50) = 0;
  return;
}

