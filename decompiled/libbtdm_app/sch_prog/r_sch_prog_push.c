/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_push
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_push(undefined4 *param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  
  uVar2 = (uint)DAT_00011105;
  iVar7 = (uVar2 - 1 & 0xf) * 0x10;
  uVar8 = uVar2 - DAT_00011104 & 0xf;
  if (param_1[1] == *(int *)(&sch_prog_env + iVar7)) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x2a1,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = uVar2 * 0x10;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  if (((*(ushort *)(iVar3 + iVar6) >> 3 & 7) == 1) ||
     (iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc)),
     (*(ushort *)(iVar3 + iVar6) >> 3 & 7) == 2)) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (DAT_00011104,uVar2,"sch_prog.c",0x2a6,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (0xd < uVar8) {
    pcVar9 = *(code **)(_r_plf_funcs_p + 0x10);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar3 + (uVar2 - 2 & 0xf) * 0x10);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    (*pcVar9)((int)(uint)uVar1 >> 3 & 7,*(ushort *)(iVar3 + iVar7) >> 3 & 7,"sch_prog.c",0x2a9);
  }
  uVar5 = param_1[1];
  uVar4 = param_1[4];
  *(undefined4 *)(&sch_prog_env + iVar6) = uVar5;
  iVar7 = _r_plf_funcs_p;
  *(undefined4 *)(&r_ip_funcs_p + iVar6) = uVar4;
  pcVar9 = *(code **)(iVar7 + 0xbc);
  *(undefined4 *)(&r_modules_funcs_p + iVar6) = *param_1;
  (&g_bt_plf_log_level)[iVar6] = 1;
  iVar7 = (*pcVar9)(0,pcVar9);
  *(short *)(iVar7 + iVar6 + 2) = (short)uVar5;
  uVar1 = *(ushort *)((int)param_1 + 6);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = param_1[2];
  *(ushort *)(iVar7 + iVar6 + 4) = uVar1 & 0xfff;
  if (0x270 < uVar2) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x2b4,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar7 = param_1[2];
  if ((0x270U - iVar7 & 0xfc00) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x1f7,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = param_1[3];
  *(short *)(iVar3 + iVar6 + 6) = (short)((0x270U - iVar7) * 0x10000 >> 0x10);
  if (uVar2 < 0x8000) {
    uVar1 = (ushort)(uVar2 + 1 >> 1);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  }
  else {
    uVar2 = (uVar2 + 0x271) / 0x271;
    if ((int)(uVar2 << 0x10) < 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x249,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = (ushort)uVar2 | 0x8000;
  }
  *(ushort *)(iVar7 + iVar6 + 10) = uVar1;
  uVar2 = (uint)*(byte *)((int)param_1 + 0x16);
  if (0x1f < uVar2) {
    uVar2 = 0x1f;
  }
  uVar1 = (ushort)*(byte *)((int)param_1 + 0x15);
  if (0x1f < *(byte *)((int)param_1 + 0x15)) {
    uVar1 = 0x1f;
  }
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar9 = *(code **)(_r_ip_funcs_p + 0x7a8);
  *(ushort *)(iVar6 + 0xc + iVar7) = (ushort)(uVar2 << 8) | uVar1;
  (*pcVar9)(param_1,0xd < uVar8,pcVar9);
  DAT_00011105 = DAT_00011105 + 1 & 0xf;
  DAT_00011106 = DAT_00011106 + '\x01';
                    /* WARNING: Could not recover jumptable at 0x00010c16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2b4))(0x200);
  return;
}

