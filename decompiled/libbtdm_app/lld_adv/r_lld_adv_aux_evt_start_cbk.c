/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  undefined4 uVar13;
  byte bStack_61;
  uint uStack_60;
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
      (**(code **)(_r_plf_funcs_p + 8))("lld_adv.c",0x96d,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x53);
      uVar11 = (uint)bVar1;
      iVar10 = uVar11 * 0x5a;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar13 = 0;
      uVar12 = *(ushort *)(iVar5 + iVar10) & 0x1f;
      if ((((*(ushort *)(param_1 + 0x40) & 0x13) == 0) && (*(int *)(param_1 + 0x34) != 0)) &&
         (*(char *)(param_1 + 0x60) == '\0')) {
        uVar13 = 1;
        (**(code **)(_r_ip_funcs_p + 0x1ec))
                  (*(undefined1 *)(param_1 + 0x53),*(code **)(_r_ip_funcs_p + 0x1ec));
      }
      iVar5 = *(int *)(param_1 + 0x24);
      if (iVar5 != -1) {
        iVar8 = *(int *)(param_1 + 4);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar6 + iVar10 + 0x20) = (short)((uint)((iVar5 - iVar8) * 0x8000) >> 0x10);
      }
      bVar2 = *(byte *)(param_1 + 0x5d);
      bVar3 = *(byte *)(param_1 + 0x46);
      uVar4 = *(ushort *)(_p_lld_env + 0xd4);
      if ((bVar2 & 0xc0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = (uVar11 * 9 & 0xff) * 0xe;
      *(ushort *)(iVar5 + iVar6 + 8) =
           (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | (ushort)bVar3 << 8;
      uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
      uVar9 = (uint)*(byte *)(param_1 + 0x5c) << 5;
      if ((uVar9 & 0xffffff1f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar4 & 0xffe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar7 = *(code **)(_r_ip_funcs_p + 0x1e0);
      *(ushort *)(iVar6 + 10 + iVar5) = (ushort)uVar9 | uVar4;
      (*pcVar7)(uVar11,uVar12,pcVar7);
      (**(code **)(_r_ip_funcs_p + 0x19c))
                (param_1 + -0x34,1,uVar13,*(code **)(_r_ip_funcs_p + 0x19c));
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar12,uVar11,&bStack_61,&uStack_60,*(code **)(_r_modules_funcs_p + 0x1e0));
      if (((uint)bStack_61 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x82,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = *(ushort *)(iVar5 + iVar10);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar10) = uVar12 & 0xff7f | (ushort)((uint)bStack_61 << 7);
      uVar9 = (uStack_60 & 0xff) << 6;
      if ((uVar9 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = *(ushort *)(iVar5 + iVar10);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = _r_ip_funcs_p;
      uStack_60 = *(uint *)(_r_ip_funcs_p + 0x1b4);
      *(ushort *)(iVar6 + iVar10) = uVar12 & 0xffbf | (ushort)uVar9;
      uStack_5c = *(undefined4 *)(param_1 + 4);
      uStack_4b = 0;
      uStack_54 = *(undefined4 *)(param_1 + 0x10);
      uStack_47 = 0;
      uStack_58 = 0;
      uStack_4c = *(undefined1 *)(param_1 + 0x16);
      uStack_46 = 0;
      uStack_49 = 0xf;
      uStack_44 = 0;
      uStack_50 = uVar11;
      uStack_4a = uStack_4c;
      bStack_48 = bVar1;
      (**(code **)(iVar5 + 0x6c8))(&uStack_60,*(code **)(iVar5 + 0x6c8));
      *(undefined1 *)(param_1 + 0x55) = 1;
    }
    (**(code **)(_r_ip_funcs_p + 0x808))(0,param_1,*(code **)(_r_ip_funcs_p + 0x808));
  }
  return;
}

