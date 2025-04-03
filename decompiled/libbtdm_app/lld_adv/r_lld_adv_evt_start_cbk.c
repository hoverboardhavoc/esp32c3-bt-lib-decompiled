/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_evt_start_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  byte bStack_61;
  uint uStack_60;
  undefined4 uStack_5c;
  int iStack_58;
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
  
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x804))(1,param_1,*(code **)(_r_ip_funcs_p + 0x804));
  if (iVar5 == 0) {
    if (param_1 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld_adv.c",0x907,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x87);
      uVar13 = (uint)bVar1;
      iVar9 = uVar13 * 0x5a;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar14 = *(ushort *)(iVar5 + iVar9) & 0x1f;
      uVar12 = 0;
      if (((*(ushort *)(param_1 + 0x74) & 0x13) == 0) &&
         (uVar12 = *(ushort *)(param_1 + 0x74) & 0x13, *(int *)(param_1 + 0x68) != 0)) {
        if (*(char *)(param_1 + 0x94) == '\0') {
          uVar12 = 0;
          if (*(char *)(param_1 + 0x95) == '\0') {
            iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
            if (*(char *)(iVar5 + 0x18) == '\0') {
              (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x8c0,*(code **)(_r_plf_funcs_p + 8));
            }
            uVar12 = 1;
            (**(code **)(_r_ip_funcs_p + 0x1ec))
                      (*(undefined1 *)(param_1 + 0x87),*(code **)(_r_ip_funcs_p + 0x1ec));
          }
        }
        else {
          uVar12 = 0;
        }
      }
      iVar5 = *(int *)(param_1 + 0x58);
      if (iVar5 != -1) {
        iVar10 = *(int *)(param_1 + 4);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar6 + iVar9 + 0x20) = (short)((uint)((iVar5 - iVar10) * 0x8000) >> 0x10);
      }
      uVar11 = 0;
      if (*(char *)(param_1 + 0x95) != '\0') {
        bVar2 = *(byte *)(param_1 + 0x87);
        uVar15 = 0x1e;
        uVar8 = ((*(int *)(param_1 + 0x38) - *(int *)(param_1 + 4) & 0xfffffffU) * 0x271 >> 1) +
                (uint)*(ushort *)(param_1 + 0x7a) * 0x1e;
        if (uVar8 < 0x257ed5) {
          if (0x3bfc3 < uVar8) {
            uVar15 = 300;
          }
          uVar7 = uVar8 < 0x3bfc4 ^ 1;
          uVar11 = 0x1e;
          uVar15 = uVar8 / uVar15 & 0xffff;
          if (0x3bfc3 < uVar8) {
            uVar11 = 300;
          }
          uVar11 = uVar8 % uVar11;
        }
        else {
          uVar7 = 0;
          uVar15 = 0;
        }
        bVar3 = *(byte *)(param_1 + 0x91);
        uVar4 = *(ushort *)(_p_lld_env + 0xd4);
        if ((bVar3 & 0xc0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar6 = ((uint)bVar2 * 9 & 0xff) * 0xe;
        *(ushort *)(iVar5 + iVar6 + 8) =
             (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar3 | (ushort)(uVar7 << 7) |
             (ushort)((uVar15 & 0xff) << 8);
        uVar8 = (uint)*(byte *)(param_1 + 0x90) << 5;
        if ((uVar8 & 0xffffff1f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar6 + 10 + iVar5) = (ushort)uVar8 | (ushort)(uVar15 >> 8);
      }
      (**(code **)(_r_ip_funcs_p + 0x1e0))(uVar13,uVar14,*(code **)(_r_ip_funcs_p + 0x1e0));
      (**(code **)(_r_ip_funcs_p + 0x19c))(param_1,0,uVar12,*(code **)(_r_ip_funcs_p + 0x19c));
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar14,uVar13,&bStack_61,&uStack_60,*(code **)(_r_modules_funcs_p + 0x1e0));
      if (((uint)bStack_61 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x82,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = *(ushort *)(iVar5 + iVar9);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar9) = uVar12 & 0xff7f | (ushort)((uint)bStack_61 << 7);
      uVar15 = (uStack_60 & 0xff) << 6;
      if ((uVar15 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = *(ushort *)(iVar5 + iVar9);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = _r_ip_funcs_p;
      uStack_60 = *(uint *)(_r_ip_funcs_p + 0x1b4);
      *(ushort *)(iVar6 + iVar9) = uVar12 & 0xffbf | (ushort)uVar15;
      uStack_5c = *(undefined4 *)(param_1 + 4);
      uStack_4b = 0;
      uStack_54 = *(undefined4 *)(param_1 + 0x10);
      uStack_47 = 0;
      uStack_4c = *(undefined1 *)(param_1 + 0x16);
      uStack_46 = 0;
      uStack_44 = 0;
      uStack_4a = rwip_priority;
      uStack_49 = 0xf;
      iStack_58 = uVar11 << 1;
      uStack_50 = uVar13;
      bStack_48 = bVar1;
      (**(code **)(iVar5 + 0x6c8))(&uStack_60,*(code **)(iVar5 + 0x6c8));
      *(undefined1 *)(param_1 + 0x89) = 1;
    }
    (**(code **)(_r_ip_funcs_p + 0x804))(0,param_1,*(code **)(_r_ip_funcs_p + 0x804));
  }
  return;
}

