/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_ext_scan_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_scan_dynamic_pti_process(int param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (((param_1 != 0) && (_lld_scan_env != 0)) &&
     (iVar7 = (**(code **)(_r_modules_funcs_p + 400))(*(code **)(_r_modules_funcs_p + 400)),
     iVar7 != 0)) {
    (**(code **)(_r_ip_funcs_p + 0x79c))
              (param_1,param_2,&uStack_2c,*(code **)(_r_ip_funcs_p + 0x79c));
    uVar3 = uStack_2c;
    bVar1 = *(byte *)(param_1 + 0x38);
    uVar9 = uStack_2c & 0xff;
    if (0xb < bVar1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar3 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar4 = uStack_2c;
    puVar6 = (uint *)((bVar1 + 0x1800c4cb) * 4);
    *puVar6 = *puVar6 & 0xfffff0ff | uVar9 << 8;
    bVar1 = *(byte *)(param_1 + 0x38);
    uVar3 = uStack_2c >> 8;
    if (0xb < bVar1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar4 & 0x200) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x294c,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar6 = (uint *)((bVar1 + 0x1800c4cb) * 4);
    *puVar6 = *puVar6 & 0xbfffffff | uVar3 << 0x1e;
    bVar1 = *(byte *)(param_1 + 0x38);
    uVar3 = uStack_2c >> 0x18;
    if (0xb < bVar1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
    }
    if (0xf < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar9 = uStack_28;
    puVar6 = (uint *)((bVar1 + 0x1800c4cb) * 4);
    *puVar6 = *puVar6 & 0xfffffff0 | uVar3;
    bVar1 = *(byte *)(param_1 + 0x38);
    if (0xb < bVar1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar9 & 6) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x295c,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar6 = (uint *)((bVar1 + 0x1800c4cb) * 4);
    *puVar6 = *puVar6 & 0xdfffffff | uVar9 << 0x1d;
    if (*(char *)(param_1 + 0x39) == '\x01') {
      bVar1 = *(byte *)(param_1 + 0x38);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      bVar5 = uStack_28._1_1_;
      uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar7);
      if ((uStack_28 & 0xf000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
      uVar2 = *(ushort *)(iVar8 + iVar7);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar8 + iVar7) = uVar2 & 0xf0ff | (ushort)bVar5 << 8;
      bVar1 = uStack_28._2_1_;
      if ((uStack_28 & 0xfe0000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x333,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar8 + iVar7);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar8 + iVar7) = uVar2 & 0xefff | (ushort)bVar1 << 0xc;
    }
  }
  return;
}

