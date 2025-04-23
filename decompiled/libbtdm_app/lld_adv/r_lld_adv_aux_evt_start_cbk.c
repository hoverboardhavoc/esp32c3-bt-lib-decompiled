/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_aux_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_aux_evt_start_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  undefined4 uVar12;
  byte bStack_61;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  byte bStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_44;
  
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x808))(1,param_1,*(code **)(_r_ip_funcs_p + 0x808));
  if (iVar5 == 0) {
    if (param_1 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld_adv.c",0x95e,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x53);
      uVar10 = (uint)bVar1;
      iVar9 = uVar10 * 0x5a;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = 0;
      uVar11 = *(ushort *)(iVar5 + iVar9) & 0x1f;
      if ((((*(ushort *)(param_1 + 0x40) & 0x13) == 0) && (*(int *)(param_1 + 0x34) != 0)) &&
         (*(char *)(param_1 + 0x60) == '\0')) {
        uVar12 = 1;
        (**(code **)(_r_ip_funcs_p + 0x1ec))
                  (*(undefined1 *)(param_1 + 0x53),*(code **)(_r_ip_funcs_p + 0x1ec));
      }
      iVar5 = *(int *)(param_1 + 0x24);
      if (iVar5 != -1) {
        iVar7 = *(int *)(param_1 + 4);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar9 + 0x20 + iVar6) = (short)((uint)((iVar5 - iVar7) * 0x8000) >> 0x10);
      }
      bVar2 = *(byte *)(param_1 + 0x5d);
      sVar3 = *(short *)(param_1 + 0x46);
      uVar4 = *(ushort *)(_p_lld_env + 0xd4);
      if (0x3f < bVar2) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = (uVar10 * 9 & 0xff) * 0xe;
      *(ushort *)(iVar6 + 8 + iVar5) = (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | sVar3 << 8;
      bVar2 = *(byte *)(param_1 + 0x5c);
      uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
      if ((bVar2 & 0xf8) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
      }
      if (0x1f < uVar4) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar8 = *(code **)(_r_ip_funcs_p + 0x1e0);
      *(ushort *)(iVar6 + 10 + iVar5) = uVar4 | (ushort)bVar2 << 5;
      (*pcVar8)(uVar10,uVar11,pcVar8);
      (**(code **)(_r_ip_funcs_p + 0x19c))
                (param_1 + -0x34,1,uVar12,*(code **)(_r_ip_funcs_p + 0x19c));
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar11,uVar10,&bStack_61,&uStack_60,*(code **)(_r_modules_funcs_p + 0x1e0));
      if ((bStack_61 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x82,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar11 = *(ushort *)(iVar5 + iVar9);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar9) = uVar11 & 0xff7f | (ushort)bStack_61 << 7;
      if (((byte)uStack_60 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar4 = (ushort)(byte)uStack_60;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar11 = *(ushort *)(iVar5 + iVar9);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = _r_ip_funcs_p;
      uStack_60 = *(undefined4 *)(_r_ip_funcs_p + 0x1b4);
      *(ushort *)(iVar9 + iVar6) = uVar11 & 0xffbf | uVar4 << 6;
      uStack_4c = *(undefined1 *)(param_1 + 0x16);
      uStack_5c = *(undefined4 *)(param_1 + 4);
      uStack_54 = *(undefined4 *)(param_1 + 0x10);
      uStack_4b = 0;
      uStack_49 = 0xf;
      uStack_47 = 0;
      uStack_58 = 0;
      uStack_46 = 0;
      uStack_44 = 0;
      uStack_50 = uVar10;
      uStack_4a = uStack_4c;
      bStack_48 = bVar1;
      (**(code **)(iVar5 + 0x6c8))(&uStack_60,*(code **)(iVar5 + 0x6c8));
      *(undefined1 *)(param_1 + 0x55) = 1;
    }
                    /* WARNING: Could not recover jumptable at 0x0001422a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x808))(0,param_1,*(code **)(_r_ip_funcs_p + 0x808));
    return;
  }
  return;
}

