/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if ((param_1 != 0) && (_lld_scan_env != 0)) {
    iVar5 = (**(code **)(_r_modules_funcs_p + 400))(*(code **)(_r_modules_funcs_p + 400));
    if (iVar5 != 0) {
      (**(code **)(_r_ip_funcs_p + 0x79c))
                (param_1,param_2,&uStack_2c,*(code **)(_r_ip_funcs_p + 0x79c));
      bVar1 = *(byte *)(param_1 + 0x38);
      uVar7 = uStack_2c & 0xff;
      if (0xb < bVar1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar7 = uVar7 << 8;
      if ((uVar7 & 0xf000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
      }
      puVar4 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar4 = *puVar4 & 0xfffff0ff | uVar7;
      bVar1 = *(byte *)(param_1 + 0x38);
      uVar7 = uStack_2c >> 8;
      if (0xb < bVar1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar7 = uVar7 << 0x1e;
      if ((int)uVar7 < 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x294c,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar3 = uStack_2c;
      puVar4 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar4 = *puVar4 & 0xbfffffff | uVar7;
      bVar1 = *(byte *)(param_1 + 0x38);
      uVar7 = uStack_2c >> 0x18;
      if (0xb < bVar1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar3 & 0xf0000000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar3 = uStack_28;
      puVar4 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar4 = *puVar4 & 0xfffffff0 | uVar7;
      bVar1 = *(byte *)(param_1 + 0x38);
      if (0xb < bVar1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar3 << 0x1d & 0xc0000000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x295c,*(code **)(_r_plf_funcs_p + 8));
      }
      puVar4 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar4 = *puVar4 & 0xdfffffff | uVar3 << 0x1d;
      if (*(char *)(param_1 + 0x39) == '\x01') {
        bVar1 = *(byte *)(param_1 + 0x38);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar7 = (uStack_28 >> 8 & 0xff) << 8;
        uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar5);
        if ((uVar7 & 0xfffff0ff) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar5 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
        uVar2 = *(ushort *)(iVar6 + iVar5);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar6 + iVar5) = uVar2 & 0xf0ff | (ushort)uVar7;
        uVar7 = (uStack_28 >> 0x10 & 0xff) << 0xc;
        if ((uVar7 & 0xffffefff) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x333,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar2 = *(ushort *)(iVar6 + iVar5);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar6 + iVar5) = uVar2 & 0xefff | (ushort)uVar7;
      }
    }
  }
  return;
}

