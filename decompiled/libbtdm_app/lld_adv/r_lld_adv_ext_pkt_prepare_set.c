/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
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
  code *pcVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte in_stack_00000000;
  byte in_stack_00000004;
  byte in_stack_00000008;
  
  iVar7 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar8 = (uint)*(byte *)(iVar7 + 0x87) * 9;
  uVar10 = (uint)in_stack_00000000 + in_stack_00000004 + 1 & 0xff;
  if (param_2 == iVar8) {
    bVar1 = *(byte *)(iVar7 + 0x93);
    iVar5 = (**(code **)(_r_modules_funcs_p + 4))(uVar10,*(undefined1 *)(iVar7 + 0x8e));
    uVar4 = (iVar5 + 0x96) * (uint)bVar1;
  }
  else {
    uVar4 = (**(code **)(_r_modules_funcs_p + 4))(uVar10,*(undefined1 *)(iVar7 + 0x90));
    if (param_2 == (uint)*(byte *)(iVar7 + 0x87) * 9 + 1) {
      *(uint *)(iVar7 + 0x70) = uVar4;
    }
  }
  uVar11 = 0;
  if (param_6 != 0) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
    if (*(int *)(iVar5 + 0x1c) == 0) {
      uVar4 = uVar4 + 300;
    }
    else {
      uVar4 = (uVar4 - 0x96) + *(int *)(iVar5 + 0x1c);
    }
    if (uVar4 < 0x257ed5) {
      uVar11 = 0x1e;
      if (0x3bfc3 < uVar4) {
        uVar11 = 300;
      }
      uVar11 = uVar4 / uVar11 + 1;
      if (param_2 == iVar8) {
        *(short *)(iVar7 + 0x7a) = (short)uVar11;
      }
      else {
        *(short *)(iVar7 + 0x7c) = (short)uVar11;
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
  bVar1 = *(byte *)(iVar7 + 0x91);
  uVar2 = *(ushort *)(_p_lld_env + 0xd4);
  if ((bVar1 & 0xc0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  param_2 = param_2 * 0xe;
  *(ushort *)(iVar8 + param_2 + 8) =
       (ushort)(uVar2 < 0x33) << 6 | (ushort)bVar1 | (ushort)(uVar11 << 8) | (ushort)(param_6 << 7);
  uVar9 = (uint)*(byte *)(iVar7 + 0x90) << 5;
  if ((uVar9 & 0xffffff1f) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar11 >> 8 & 0xffffffe0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31d,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = param_2 + 10;
  pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar8 + iVar5) = (ushort)uVar9 | (ushort)(uVar11 >> 8);
  sVar3 = *param_7;
  iVar8 = (*pcVar6)(0x1400,pcVar6);
  *(short *)(iVar8 + param_2 + 0xc) = sVar3;
  *param_7 = (ushort)in_stack_00000008 + *param_7;
  uVar11 = 0;
  if (param_5 != 0) {
    uVar11 = *(byte *)(iVar7 + 0x8c) & 1;
  }
  uVar9 = 0;
  if (param_4 != 0) {
    uVar9 = *(byte *)(iVar7 + 0x8b) & 1;
  }
  if ((param_3 & 0xfffffff0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x126,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar7 + param_2 + 2) =
       (ushort)(uVar9 << 6) | (ushort)param_3 | (ushort)(uVar10 << 8) | (ushort)(uVar11 << 7) | 0x20
  ;
  sVar3 = *param_8;
  iVar7 = (*pcVar6)(0x1400,pcVar6);
  *(short *)(iVar7 + param_2 + 4) = sVar3;
  iVar7 = _r_plf_funcs_p;
  *param_8 = (ushort)in_stack_00000004 + *param_8;
  iVar7 = (**(code **)(iVar7 + 0xbc))(0x1400,*(code **)(iVar7 + 0xbc));
  uVar2 = *(ushort *)(iVar7 + param_2);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar7 + param_2) = uVar2 & 0x7fff;
  iVar7 = (**(code **)(_r_modules_funcs_p + 0x1a0))(4,*(code **)(_r_modules_funcs_p + 0x1a0));
  if (iVar7 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [EXT ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar7 + 4),
                 *(undefined1 *)(iVar7 + 5));
    }
    uVar10 = (uint)*(byte *)(iVar7 + 5) << 8;
    if ((uVar10 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar8 + iVar5);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar8 + iVar5) = uVar2 & 0xf0ff | (ushort)uVar10;
    bVar1 = *(byte *)(iVar7 + 4);
    iVar7 = (*pcVar6)(0x1400,pcVar6);
    uVar2 = *(ushort *)(iVar7 + iVar5);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + iVar5) = uVar2 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return uVar4;
}

