/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_pkt_prepare_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_adv_ext_pkt_prepare_set
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
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  byte in_stack_00000000;
  byte in_stack_00000004;
  byte in_stack_00000008;
  
  iVar9 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar5 = (uint)*(byte *)(iVar9 + 0x87) * 9;
  uVar8 = (uint)in_stack_00000000 + in_stack_00000004 + 1 & 0xff;
  if (param_2 == iVar5) {
    bVar1 = *(byte *)(iVar9 + 0x93);
    iVar6 = (**(code **)(_r_modules_funcs_p + 4))(uVar8,*(undefined1 *)(iVar9 + 0x8e));
    uVar4 = (iVar6 + 0x96) * (uint)bVar1;
  }
  else {
    uVar4 = (**(code **)(_r_modules_funcs_p + 4))(uVar8,*(undefined1 *)(iVar9 + 0x90));
    if (param_2 == (uint)*(byte *)(iVar9 + 0x87) * 9 + 1) {
      *(uint *)(iVar9 + 0x70) = uVar4;
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
        *(short *)(iVar9 + 0x7a) = (short)uVar11;
      }
      else {
        *(short *)(iVar9 + 0x7c) = (short)uVar11;
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
  bVar1 = *(byte *)(iVar9 + 0x91);
  uVar2 = *(ushort *)(_p_lld_env + 0xd4);
  if (0x3f < bVar1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
  }
  param_2 = param_2 * 0xe;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + param_2 + 8) =
       (ushort)(uVar2 < 0x33) << 6 | (ushort)bVar1 | (ushort)(param_6 << 7) |
       (ushort)((uVar11 & 0xff) << 8);
  bVar1 = *(byte *)(iVar9 + 0x90);
  if ((bVar1 & 0xf8) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
  }
  if (uVar11 >> 8 == 0x20) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31d,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = param_2 + 10;
  pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar6 + iVar5) = (ushort)bVar1 << 5 | (ushort)(uVar11 >> 8);
  sVar3 = *param_7;
  iVar6 = (*pcVar7)(0x1400,pcVar7);
  *(short *)(param_2 + 0xc + iVar6) = sVar3;
  uVar11 = 0;
  *param_7 = (ushort)in_stack_00000008 + *param_7;
  if (param_5 != 0) {
    uVar11 = *(byte *)(iVar9 + 0x8c) & 1;
  }
  uVar10 = 0;
  if (param_4 != 0) {
    uVar10 = *(byte *)(iVar9 + 0x8b) & 1;
  }
  if (0xf < param_3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x126,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar9 + param_2 + 2) =
       (ushort)(uVar10 << 6) | (ushort)param_3 | (ushort)(uVar8 << 8) | (ushort)(uVar11 << 7) | 0x20
  ;
  sVar3 = *param_8;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(param_2 + 4 + iVar9) = sVar3;
  iVar9 = _r_plf_funcs_p;
  *param_8 = (ushort)in_stack_00000004 + *param_8;
  iVar9 = (**(code **)(iVar9 + 0xbc))(0x1400,*(code **)(iVar9 + 0xbc));
  uVar2 = *(ushort *)(iVar9 + param_2);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar7 = *(code **)(_r_modules_funcs_p + 0x1a0);
  *(ushort *)(param_2 + iVar9) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
  iVar9 = (*pcVar7)(4,pcVar7);
  if (iVar9 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [EXT ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar9 + 4),
                 *(undefined1 *)(iVar9 + 5));
    }
    bVar1 = *(byte *)(iVar9 + 5);
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar6 + iVar5);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar6 + iVar5) = uVar2 & 0xf0ff | (ushort)bVar1 << 8;
    bVar1 = *(byte *)(iVar9 + 4);
    iVar9 = (*pcVar7)(0x1400,pcVar7);
    uVar2 = *(ushort *)(iVar9 + iVar5);
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar9 + iVar5) = uVar2 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return uVar4;
}

