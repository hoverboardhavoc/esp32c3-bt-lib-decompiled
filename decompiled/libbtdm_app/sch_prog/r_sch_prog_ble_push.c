/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int extraout_a1;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  
  if (*(char *)(param_1 + 0x19) != '\0') {
    return;
  }
  uVar9 = (ushort)*(byte *)(param_1 + 0x1c);
  uVar11 = (uint)sch_prog_env;
  bVar1 = *(byte *)(param_1 + 0x17);
  if (uVar9 != 0) {
    uVar9 = (ushort)*(byte *)(param_1 + 0x1d);
  }
  if ((bVar1 & 0xe0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x323,*(code **)(_r_plf_funcs_p + 8));
  }
  if (3 < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x324,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar10 = uVar11 * 0x10;
  *(ushort *)(iVar10 + 0xe + iVar5) = (ushort)bVar1 << 8 | uVar9;
  bVar1 = *(byte *)(param_1 + 0x18);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar10 + 8 + iVar5) = (short)((uint)bVar1 * 0x5a >> 1) + 0x200;
  uVar7 = (uint)*(byte *)(param_1 + 0x14);
  if (0x1f < uVar7) {
    uVar7 = 0x1f;
  }
  bVar1 = *(byte *)(param_1 + 0x1a);
  uVar9 = (ushort)(uVar7 << 0xb);
  uVar4 = (ushort)(param_2 << 10);
  if (*(char *)(param_1 + 0x1c) == '\0') {
    if ((bVar1 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x107,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar10) = uVar9 | uVar4 | (ushort)bVar1 << 8 | 2;
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x1e);
    bVar3 = *(byte *)(param_1 + 0x1b);
    if ((bVar2 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x106,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar1 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x107,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar3 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x108,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar10) =
         uVar9 | uVar4 | (ushort)bVar2 << 9 | (ushort)bVar1 << 8 | (ushort)bVar3 << 7 | 0x42;
  }
  uVar7 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  for (uVar8 = extraout_a1 + 0x15e; 0x270 < uVar8; uVar8 = uVar8 - 0x271) {
    uVar7 = uVar7 + 1 & 0xfffffff;
  }
  if (((*(uint *)(param_1 + 4) - uVar7 & 0xfffffff) < 0x7ffffff) &&
     ((uVar7 != *(uint *)(param_1 + 4) || (uVar8 <= *(uint *)(param_1 + 8))))) {
    kick_delay = 0;
    if (0xf < uVar11) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x19f8,*(code **)(_r_plf_funcs_p + 8));
    }
    _DAT_60031100 = uVar11 | 0x80000000;
  }
  else {
    kick_delay = 1;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar9 = *(ushort *)(iVar5 + iVar10);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = _g_bt_plf_log_level;
    *(ushort *)(iVar10 + iVar6) = uVar9 & 0xffc7 | 0x30;
    if (0 < iVar5) {
      ets_printf("BLE_ERR_%d_%d_%d_%d\n",*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                 uVar7,uVar8);
      return;
    }
  }
  return;
}

