/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_ext_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_adv_dynamic_pti_process(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  byte bStack_48;
  byte bStack_47;
  byte bStack_45;
  byte bStack_44;
  byte bStack_43;
  byte bStack_42;
  
  memset(&bStack_48,0,0x18);
  uVar9 = (uint)*(byte *)(param_1 + 0x87);
  bVar1 = *(byte *)(param_1 + 0x74);
  (**(code **)(_r_ip_funcs_p + 0x75c))
            (param_1,param_2,param_3,&bStack_48,*(code **)(_r_ip_funcs_p + 0x75c));
  uVar3 = uVar9 * 9 & 0xff;
  uVar8 = uVar3 + 1 & 0xff;
  if (0xb < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((bStack_43 & 0xf0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
  }
  puVar7 = (uint *)((uVar9 + 0x1800c4cb) * 4);
  *puVar7 = *puVar7 & 0xfffffff0 | (uint)bStack_43;
  if (0xb < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
  }
  if (((uint)bStack_42 << 0x1d & 0xc0000000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295c,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar7 = *puVar7 & 0xdfffffff | (uint)bStack_42 << 0x1d;
  if (0xb < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
  }
  if (((uint)bStack_48 << 8 & 0xf000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar7 = *puVar7 & 0xfffff0ff | (uint)bStack_48 << 8;
  if (0xb < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((int)((uint)bStack_47 << 0x1e) < 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294c,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar7 = *puVar7 & 0xbfffffff | (uint)bStack_47 << 0x1e;
  uVar9 = (uint)bStack_45;
  if ((uVar9 << 8 & 0xf000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar4 = uVar3 * 0xe + 10;
  uVar2 = *(ushort *)(iVar5 + iVar4);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + iVar4) = uVar2 & 0xf0ff | (ushort)(uVar9 << 8);
  uVar3 = (uint)bStack_44;
  if ((uVar3 << 0xc & 0xffffefff) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar5 + iVar4);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + iVar4) = uVar2 & 0xefff | (ushort)(uVar3 << 0xc);
  if (((uint)bStack_45 << 8 & 0xfffff0ff) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = uVar8 * 0xe + 10;
  uVar2 = *(ushort *)(iVar4 + iVar5);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar4 + iVar5) = uVar2 & 0xf0ff | (ushort)((uint)bStack_45 << 8);
  if (((uint)bStack_44 << 0xc & 0xffffefff) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar4 + iVar5);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar6 = *(code **)(_r_ip_funcs_p + 0x760);
  *(ushort *)(iVar4 + iVar5) = uVar2 & 0xefff | (ushort)((uint)bStack_44 << 0xc);
  (*pcVar6)(bVar1 & 3,uVar8,&bStack_48,pcVar6);
  return;
}

