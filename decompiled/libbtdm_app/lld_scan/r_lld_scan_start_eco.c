/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_lld_scan_start_eco(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  char acStack_41 [13];
  
  acStack_41[0] = '\f';
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x7f4))
                    (1,acStack_41,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x7f4));
  if (iVar5 == 0) {
    iVar5 = r_lld_scan_start(param_1,param_2);
    acStack_41[0] = (char)iVar5;
    if (iVar5 == 0) {
      iVar5 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
      uVar3 = (uint)*(ushort *)(iVar5 + 0x20);
      if (uVar3 == 0) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
        if (*(short *)(iVar5 + 0x14) != 0) {
          _DAT_60031124 = 0x10001;
          iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
          uVar2 = *(ushort *)(iVar5 + 0x14);
          if (0x1ff < uVar2) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29ed,*(code **)(_r_plf_funcs_p + 8));
          }
          _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | (uint)uVar2;
        }
      }
      else {
        _DAT_60031124 = 0x10001;
        if (0x1ff < uVar3) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29ed,*(code **)(_r_plf_funcs_p + 8));
        }
        _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar3;
      }
      if ((acStack_41[0] == '\0') && (_lld_scan_env != 0)) {
        puVar8 = &scan_anchor_point;
        iVar5 = 0;
        do {
          iVar9 = *(int *)(_lld_scan_env + iVar5 * 4);
          if (iVar9 != 0) {
            iVar4 = (uint)*(byte *)(iVar9 + 0x38) * 0x5a;
            iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar2 = *(ushort *)(iVar6 + iVar4);
            iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar7 = *(undefined4 *)(iVar9 + 4);
            *(ushort *)(iVar4 + iVar6) = uVar2 & 0xffdf;
            *puVar8 = uVar7;
          }
          puVar8 = puVar8 + 1;
          bVar1 = iVar5 != 1;
          iVar5 = 1;
        } while (bVar1);
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x7f4))
              (0,acStack_41,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x7f4));
  }
  return acStack_41[0];
}

