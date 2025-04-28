/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int extraout_a1;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  bVar3 = sch_prog_env;
  uVar8 = (uint)sch_prog_env;
  if (*(char *)(param_1 + 0x19) == '\0') {
    uVar9 = (ushort)*(byte *)(param_1 + 0x1c);
    if (uVar9 != 0) {
      uVar9 = (ushort)*(byte *)(param_1 + 0x1d);
    }
    uVar4 = (uint)*(byte *)(param_1 + 0x17) << 8;
    if ((uVar4 & 0xe000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x323,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar9 & 0xfffc) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x324,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar10 = uVar8 * 0x10;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar10 + 0xe + iVar6) = (ushort)uVar4 | uVar9;
    bVar1 = *(byte *)(param_1 + 0x18);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar10 + 8 + iVar6) = (short)((uint)bVar1 * 0x5a + 0x400 >> 1);
    bVar1 = *(byte *)(param_1 + 0x1a);
    uVar4 = (uint)*(byte *)(param_1 + 0x14);
    uVar9 = (ushort)(param_2 << 10);
    if (*(char *)(param_1 + 0x1c) == '\0') {
      if (0x1f < uVar4) {
        uVar4 = 0x1f;
      }
      uVar12 = (uint)bVar1 << 8;
      if ((uVar12 & 0xfffffeff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x107,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar9 = (ushort)(uVar4 << 0xb) | uVar9 | (ushort)uVar12 | 2;
    }
    else {
      bVar2 = *(byte *)(param_1 + 0x1b);
      if (0x1f < uVar4) {
        uVar4 = 0x1f;
      }
      uVar12 = (uint)*(byte *)(param_1 + 0x1e) << 9;
      if ((uVar12 & 0xfffffdff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x106,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar5 = (uint)bVar1 << 8;
      if ((uVar5 & 0xfffffeff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x107,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar11 = (uint)bVar2 << 7;
      if ((uVar11 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x108,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar9 = (ushort)(uVar4 << 0xb) | uVar9 | (ushort)uVar12 | (ushort)uVar5 | (ushort)uVar11 |
              0x42;
    }
    *(ushort *)(iVar6 + iVar10) = uVar9;
    uVar4 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    for (uVar12 = extraout_a1 + 0x15e; 0x270 < uVar12; uVar12 = uVar12 - 0x271) {
      uVar4 = uVar4 + 1 & 0xfffffff;
    }
    if (((*(uint *)(param_1 + 4) - uVar4 & 0xfffffff) < 0x7ffffff) &&
       ((*(uint *)(param_1 + 4) != uVar4 || (uVar12 <= *(uint *)(param_1 + 8))))) {
      kick_delay = 0;
      if ((bVar3 & 0xf0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x19f8,*(code **)(_r_plf_funcs_p + 8));
      }
      _DAT_60031100 = uVar8 | 0x80000000;
    }
    else {
      kick_delay = 1;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar9 = *(ushort *)(iVar6 + iVar10);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = _g_bt_plf_log_level;
      *(ushort *)(iVar10 + iVar7) = uVar9 & 0xffc7 | 0x30;
      if (0 < iVar6) {
        ets_printf("BLE_ERR_%d_%d_%d_%d\n",*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8)
                   ,uVar4,uVar12);
        return;
      }
    }
  }
  return;
}

