/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_pkt_prepare_set_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_adv_ext_pkt_prepare_set_hack
               (int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,
               short *param_7,short *param_8)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte in_stack_00000000;
  byte in_stack_00000004;
  byte in_stack_00000008;
  
  iVar8 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar5 = (uint)*(byte *)(iVar8 + 0x87) * 9;
  uVar10 = (uint)in_stack_00000000 + in_stack_00000004 + 1 & 0xff;
  if (param_2 == iVar5) {
    bVar1 = *(byte *)(iVar8 + 0x93);
    iVar6 = (**(code **)(_r_modules_funcs_p + 4))(uVar10,*(undefined1 *)(iVar8 + 0x8e));
    uVar4 = (iVar6 + 0x96) * (uint)bVar1;
  }
  else {
    uVar4 = (**(code **)(_r_modules_funcs_p + 4))(uVar10,*(undefined1 *)(iVar8 + 0x90));
    if (param_2 == (uint)*(byte *)(iVar8 + 0x87) * 9 + 1) {
      *(uint *)(iVar8 + 0x70) = uVar4;
    }
  }
  uVar11 = 0;
  if (param_6 != 0) {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
    if (*(int *)(iVar6 + 0x1c) == 0) {
      uVar4 = uVar4 + 300;
    }
    else {
      uVar4 = (uVar4 - 0x96) + *(int *)(iVar6 + 0x1c);
    }
    if (uVar4 < 0x257ed5) {
      uVar11 = 0x1e;
      if (0x3bfc3 < uVar4) {
        uVar11 = 300;
      }
      uVar11 = uVar4 / uVar11 + 1;
      if (param_2 == iVar5) {
        *(short *)(iVar8 + 0x7a) = (short)uVar11;
      }
      else {
        *(short *)(iVar8 + 0x7c) = (short)uVar11;
      }
      if (uVar4 < 0x3bfc4) {
        uVar4 = uVar11 * 0x1e;
        param_6 = 0;
      }
      else {
        uVar4 = uVar11 * 300;
      }
    }
    else {
      param_6 = 0;
      uVar11 = 0;
    }
  }
  bVar1 = *(byte *)(iVar8 + 0x91);
  uVar2 = *(ushort *)(_p_lld_env + 0xd4);
  if ((bVar1 & 0xc0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
  }
  param_2 = param_2 * 0xe;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(param_2 + 8 + iVar5) =
       (ushort)(uVar2 < 0x33) << 6 | (ushort)bVar1 | (ushort)(uVar11 << 8) | (ushort)(param_6 << 7);
  uVar9 = (uint)*(byte *)(iVar8 + 0x90) << 5;
  if ((uVar9 & 0xffffff1f) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar11 >> 8 & 0xffffffe0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31d,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = param_2 + 10;
  pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar6 + iVar5) = (ushort)uVar9 | (ushort)(uVar11 >> 8);
  sVar3 = *param_7;
  iVar6 = (*pcVar7)(0x1400,pcVar7);
  *(short *)(param_2 + 0xc + iVar6) = sVar3;
  uVar11 = 0;
  *param_7 = *param_7 + (ushort)in_stack_00000008;
  if (param_5 != 0) {
    uVar11 = *(byte *)(iVar8 + 0x8c) & 1;
  }
  uVar9 = 0;
  if (param_4 != 0) {
    uVar9 = *(byte *)(iVar8 + 0x8b) & 1;
  }
  if ((param_3 & 0xfffffff0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x126,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar8 + param_2 + 2) =
       (ushort)(uVar9 << 6) | (ushort)param_3 | (ushort)(uVar10 << 8) | (ushort)(uVar11 << 7) | 0x20
  ;
  sVar3 = *param_8;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(param_2 + 4 + iVar8) = sVar3;
  *param_8 = *param_8 + (ushort)in_stack_00000004;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar8 + param_2);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar7 = *(code **)(_r_modules_funcs_p + 0x1a0);
  *(ushort *)(param_2 + iVar8) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
  iVar8 = (*pcVar7)(4,pcVar7);
  if (iVar8 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [EXT ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar8 + 4),
                 *(undefined1 *)(iVar8 + 5));
    }
    uVar10 = (uint)*(byte *)(iVar8 + 5) << 8;
    if ((uVar10 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar6 + iVar5);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar6 + iVar5) = uVar2 & 0xf0ff | (ushort)uVar10;
    bVar1 = *(byte *)(iVar8 + 4);
    iVar8 = (*pcVar7)(0x1400,pcVar7);
    uVar2 = *(ushort *)(iVar8 + iVar5);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar8 + iVar5) = uVar2 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return uVar4;
}

