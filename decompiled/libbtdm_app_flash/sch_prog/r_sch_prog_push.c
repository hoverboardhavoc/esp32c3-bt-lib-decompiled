/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_push
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_prog_push(undefined4 *param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  
  uVar2 = (uint)DAT_00011101;
  iVar7 = (uVar2 - 1 & 0xf) * 0x10;
  uVar8 = uVar2 - DAT_00011100 & 0xf;
  if (param_1[1] == *(int *)(&sch_prog_env + iVar7)) {
    r_assert_err(0,"sch_prog.c",0x2a1);
  }
  iVar4 = r_emi_get_mem_addr_by_offset(0);
  iVar3 = uVar2 * 0x10;
  if (((*(ushort *)(iVar4 + iVar3) >> 3 & 7) == 1) ||
     (iVar4 = r_emi_get_mem_addr_by_offset(0), (*(ushort *)(iVar4 + iVar3) >> 3 & 7) == 2)) {
    r_assert_param(DAT_00011100,uVar2,"sch_prog.c",0x2a6);
  }
  if (0xd < uVar8) {
    iVar4 = r_emi_get_mem_addr_by_offset(0);
    uVar1 = *(ushort *)(iVar4 + (uVar2 - 2 & 0xf) * 0x10);
    iVar4 = r_emi_get_mem_addr_by_offset(0);
    r_assert_warn((int)(uint)uVar1 >> 3 & 7,*(ushort *)(iVar4 + iVar7) >> 3 & 7,"sch_prog.c",0x2a9);
  }
  uVar6 = param_1[1];
  *(undefined4 *)(r_assert_err + iVar3) = param_1[4];
  uVar5 = *param_1;
  *(undefined4 *)(&sch_prog_env + iVar3) = uVar6;
  *(undefined4 *)(r_emi_get_mem_addr_by_offset + iVar3) = uVar5;
  r_assert_param[iVar3] = (code)0x1;
  iVar7 = r_emi_get_mem_addr_by_offset(0);
  *(short *)(iVar7 + iVar3 + 2) = (short)uVar6;
  uVar1 = *(ushort *)((int)param_1 + 6);
  iVar7 = r_emi_get_mem_addr_by_offset(0);
  uVar2 = param_1[2];
  *(ushort *)(iVar7 + iVar3 + 4) = uVar1 & 0xfff;
  if (0x270 < uVar2) {
    r_assert_err(0,"sch_prog.c",0x2b4);
  }
  iVar7 = param_1[2];
  if ((0x270U - iVar7 & 0xfc00) != 0) {
    r_assert_err(0,"sch_prog.c",0x1f7);
  }
  iVar4 = r_emi_get_mem_addr_by_offset(0);
  uVar2 = param_1[3];
  *(short *)(iVar4 + iVar3 + 6) = (short)((0x270U - iVar7) * 0x10000 >> 0x10);
  if (uVar2 < 0x8000) {
    iVar7 = r_emi_get_mem_addr_by_offset(0);
    uVar1 = (ushort)(uVar2 + 1 >> 1);
  }
  else {
    uVar2 = (uVar2 + 0x271) / 0x271;
    if ((int)(uVar2 << 0x10) < 0) {
      r_assert_err(0,"sch_prog.c",0x249);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0);
    uVar1 = (ushort)uVar2 | 0x8000;
  }
  *(ushort *)(iVar7 + iVar3 + 10) = uVar1;
  uVar2 = (uint)*(byte *)((int)param_1 + 0x16);
  if (0x1f < uVar2) {
    uVar2 = 0x1f;
  }
  uVar1 = (ushort)*(byte *)((int)param_1 + 0x15);
  if (0x1f < *(byte *)((int)param_1 + 0x15)) {
    uVar1 = 0x1f;
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0);
  *(ushort *)(iVar3 + 0xc + iVar7) = (ushort)(uVar2 << 8) | uVar1;
  r_sch_prog_ble_push(param_1,0xd < uVar8);
  DAT_00011101 = DAT_00011101 + 1 & 0xf;
  DAT_00011102 = DAT_00011102 + '\x01';
  r_rwip_prevent_sleep_set(0x200);
  return;
}

