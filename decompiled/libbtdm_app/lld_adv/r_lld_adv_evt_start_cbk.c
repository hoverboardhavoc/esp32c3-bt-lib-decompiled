/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
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
      uVar12 = (uint)bVar1;
      iVar10 = uVar12 * 0x5a;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar13 = 0;
      uVar14 = *(ushort *)(iVar5 + iVar10) & 0x1f;
      if (((*(ushort *)(param_1 + 0x74) & 0x13) == 0) && (*(int *)(param_1 + 0x68) != 0)) {
        if (*(char *)(param_1 + 0x94) == '\0') {
          uVar13 = 0;
          if (*(char *)(param_1 + 0x95) == '\0') {
            iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
            if (*(char *)(iVar5 + 0x18) == '\0') {
              (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x8c0,*(code **)(_r_plf_funcs_p + 8));
            }
            uVar13 = 1;
            (**(code **)(_r_ip_funcs_p + 0x1ec))
                      (*(undefined1 *)(param_1 + 0x87),*(code **)(_r_ip_funcs_p + 0x1ec));
          }
        }
        else {
          uVar13 = 0;
        }
      }
      iVar5 = *(int *)(param_1 + 0x58);
      if (iVar5 != -1) {
        iVar7 = *(int *)(param_1 + 4);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar10 + 0x20 + iVar6) = (short)((uint)((iVar5 - iVar7) * 0x8000) >> 0x10);
      }
      uVar11 = 0;
      if (*(char *)(param_1 + 0x95) != '\0') {
        bVar2 = *(byte *)(param_1 + 0x87);
        uVar15 = 0x1e;
        uVar9 = ((*(int *)(param_1 + 0x38) - *(int *)(param_1 + 4) & 0xfffffffU) * 0x271 >> 1) +
                (uint)*(ushort *)(param_1 + 0x7a) * 0x1e;
        if (uVar9 < 0x257ed5) {
          if (0x3bfc3 < uVar9) {
            uVar15 = 300;
          }
          uVar8 = uVar9 < 0x3bfc4 ^ 1;
          uVar11 = 0x1e;
          uVar15 = uVar9 / uVar15 & 0xffff;
          if (0x3bfc3 < uVar9) {
            uVar11 = 300;
          }
          uVar11 = uVar9 % uVar11;
        }
        else {
          uVar8 = 0;
          uVar15 = 0;
        }
        bVar3 = *(byte *)(param_1 + 0x91);
        uVar4 = *(ushort *)(_p_lld_env + 0xd4);
        if ((bVar3 & 0xc0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar6 = ((uint)bVar2 * 9 & 0xff) * 0xe;
        *(ushort *)(iVar6 + 8 + iVar5) =
             (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar3 | (ushort)(uVar8 << 7) |
             (ushort)((uVar15 & 0xff) << 8);
        uVar9 = (uint)*(byte *)(param_1 + 0x90) << 5;
        if ((uVar9 & 0xffffff1f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar6 + 10 + iVar5) = (ushort)(uVar15 >> 8) | (ushort)uVar9;
      }
      (**(code **)(_r_ip_funcs_p + 0x1e0))(uVar12,uVar14,*(code **)(_r_ip_funcs_p + 0x1e0));
      (**(code **)(_r_ip_funcs_p + 0x19c))(param_1,0,uVar13,*(code **)(_r_ip_funcs_p + 0x19c));
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar14,uVar12,&bStack_61,&uStack_60,*(code **)(_r_modules_funcs_p + 0x1e0));
      if (((uint)bStack_61 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x82,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar14 = *(ushort *)(iVar5 + iVar10);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar10) = uVar14 & 0xff7f | (ushort)((uint)bStack_61 << 7);
      uVar15 = (uStack_60 & 0xff) << 6;
      if ((uVar15 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar14 = *(ushort *)(iVar5 + iVar10);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = _r_ip_funcs_p;
      uStack_60 = *(uint *)(_r_ip_funcs_p + 0x1b4);
      *(ushort *)(iVar10 + iVar6) = uVar14 & 0xffbf | (ushort)uVar15;
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
      uStack_50 = uVar12;
      bStack_48 = bVar1;
      (**(code **)(iVar5 + 0x6c8))(&uStack_60,*(code **)(iVar5 + 0x6c8));
      *(undefined1 *)(param_1 + 0x89) = 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00014014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x804))(0,param_1,*(code **)(_r_ip_funcs_p + 0x804));
    return;
  }
  return;
}

