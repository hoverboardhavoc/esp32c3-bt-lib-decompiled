/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_ble_push
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_ble_push(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int extraout_a1;
  uint uVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  bVar4 = sch_prog_env;
  if (*(char *)(param_1 + 0x19) != '\0') {
    return;
  }
  uVar10 = (ushort)*(byte *)(param_1 + 0x1c);
  uVar9 = (uint)sch_prog_env;
  if (uVar10 != 0) {
    uVar10 = (ushort)*(byte *)(param_1 + 0x1d);
  }
  uVar7 = (uint)*(byte *)(param_1 + 0x17) << 8;
  if ((uVar7 & 0xe000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x323,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar10 & 0xfffc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x324,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = uVar9 * 0x10;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + iVar8 + 0xe) = (ushort)uVar7 | uVar10;
  bVar1 = *(byte *)(param_1 + 0x18);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  cVar2 = *(char *)(param_1 + 0x1c);
  *(short *)(iVar5 + iVar8 + 8) = (short)((uint)bVar1 * 0x5a + 0x400 >> 1);
  uVar7 = (uint)*(byte *)(param_1 + 0x14);
  bVar1 = *(byte *)(param_1 + 0x1a);
  uVar10 = (ushort)(param_2 << 10);
  if (cVar2 == '\0') {
    if (0x1f < uVar7) {
      uVar7 = 0x1f;
    }
    uVar13 = (uint)bVar1 << 8;
    if ((uVar13 & 0xfffffeff) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x107,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar8) = (ushort)(uVar7 << 0xb) | uVar10 | (ushort)uVar13 | 2;
  }
  else {
    bVar3 = *(byte *)(param_1 + 0x1b);
    if (0x1f < uVar7) {
      uVar7 = 0x1f;
    }
    uVar13 = (uint)*(byte *)(param_1 + 0x1e) << 9;
    if ((uVar13 & 0xfffffdff) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x106,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar11 = (uint)bVar1 << 8;
    if ((uVar11 & 0xfffffeff) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x107,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar12 = (uint)bVar3 << 7;
    if ((uVar12 & 0xffffff7f) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x108,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar8) =
         (ushort)(uVar7 << 0xb) | uVar10 | (ushort)uVar13 | (ushort)uVar11 | (ushort)uVar12 | 0x42;
  }
  uVar7 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  for (uVar13 = extraout_a1 + 0x15e; 0x270 < uVar13; uVar13 = uVar13 - 0x271) {
    uVar7 = uVar7 + 1 & 0xfffffff;
  }
  if (((*(uint *)(param_1 + 4) - uVar7 & 0xfffffff) < 0x7ffffff) &&
     ((*(uint *)(param_1 + 4) != uVar7 || (uVar13 <= *(uint *)(param_1 + 8))))) {
    _LANCHOR0 = 0;
    if ((bVar4 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x19f8,*(code **)(_r_plf_funcs_p + 8));
    }
    _DAT_60031100 = uVar9 | 0x80000000;
  }
  else {
    _LANCHOR0 = 1;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar10 = *(ushort *)(iVar5 + iVar8);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = _g_bt_plf_log_level;
    *(ushort *)(iVar6 + iVar8) = uVar10 & 0xffc7 | 0x30;
    if (0 < iVar5) {
      ets_printf("BLE_ERR_%d_%d_%d_%d\n",*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                 uVar7,uVar13);
      return;
    }
  }
  return;
}

